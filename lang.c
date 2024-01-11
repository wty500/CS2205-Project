#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lang.h"

// 这要求3的难度和码量双双爆炸orz感觉跟前两问相比又上了好几个梯度
// 当前环境变量/函数/过程声明，使用哈希表存储
struct decl_var *env_vars=NULL;
struct decl_fun *env_funs=NULL;
struct decl_proc *env_procs=NULL;
// 已经实例化过的函数/过程声明，以防递归函数重复实例化，使用链表存储
struct instantiated_proc_list *IPL;
struct instantiated_func_list *IFL;

struct type *new_type() {
    struct type *res = (struct type *) malloc(sizeof(struct type));
    if (res == NULL) {
        printf("Failure in malloc.\n");
        exit(0);
    }
    return res;
}

struct type_list *new_type_list() {
    struct type_list *res = (struct type_list *) malloc(sizeof(struct type_list));
    if (res == NULL) {
        printf("Failure in malloc.\n");
        exit(0);
    }
    return res;
}

struct ptr_num *new_ptr_num() {
    struct ptr_num *res = (struct ptr_num *) malloc(sizeof(struct ptr_num));
    if (res == NULL) {
        printf("Failure in malloc.\n");
        exit(0);
    }
    return res;
}

struct expr *new_expr_ptr() {
    struct expr *res = (struct expr *) malloc(sizeof(struct expr));
    if (res == NULL) {
        printf("Failure in malloc.\n");
        exit(0);
    }
    return res;
}

struct expr_list *new_expr_list_ptr() {
    struct expr_list *res =
            (struct expr_list *) malloc(sizeof(struct expr_list));
    if (res == NULL) {
        printf("Failure in malloc.\n");
        exit(0);
    }
    return res;
}

struct cmd *new_cmd_ptr() {
    struct cmd *res = (struct cmd *) malloc(sizeof(struct cmd));
    if (res == NULL) {
        printf("Failure in malloc.\n");
        exit(0);
    }
    return res;
}

struct var_list *old_var_list_ptr() {
    struct var_list *res = (struct var_list *) malloc(sizeof(struct var_list));
    if (res == NULL) {
        printf("Failure in malloc.\n");
        exit(0);
    }
    return res;
}

struct glob_item *new_glob_item_ptr() {
    struct glob_item *res =
            (struct glob_item *) malloc(sizeof(struct glob_item));
    if (res == NULL) {
        printf("Failure in malloc.\n");
        exit(0);
    }
    return res;
}

struct glob_item_list *new_glob_item_list_ptr() {
    struct glob_item_list *res =
            (struct glob_item_list *) malloc(sizeof(struct glob_item_list));
    if (res == NULL) {
        printf("Failure in malloc.\n");
        exit(0);
    }
    return res;
}

char* StrNil(){
    return NULL;
}

struct type * TPNil(){
    return NULL;
}

struct type *TPtr_int() {
    struct type *res = new_type();
    res->t = T_PTR_INT;
    res->d.PTR_INT.num_of_ptr = 0;
    return res;
}

struct type *TPtr_int_1(struct type *last) {
    struct type *res = new_type();
    res->t = T_PTR_INT;
    res->d.PTR_INT.num_of_ptr = last->d.PTR_INT.num_of_ptr + 1;
    free(last);
    return res;
}

struct type *TPtr_func(struct type *return_type, struct ptr_num *num_ptr, struct type_list *list) {
    struct type *res = new_type();
    res->t = T_PTR_FUNC;
    res->d.PTR_FUNC.return_type = return_type;
    res->d.PTR_FUNC.num_of_ptr = num_ptr->num_ptr;
    res->d.PTR_FUNC.arg_list = list;
    return res;
}

struct type *TPtr_proc(struct ptr_num *num_ptr, struct type_list *list) {
    struct type *res = new_type();
    res->t = T_PTR_PROC;
    res->d.PTR_PROC.num_of_ptr = num_ptr->num_ptr;
    res->d.PTR_PROC.arg_list = list;
    return res;
}

struct type * TPtr_T(char * name){
    struct type *res = new_type();
    res->t = T_TEMPLATE_TYPE;
    res->d.TEMPLATE_TYPE.typename = name;
    res->d.TEMPLATE_TYPE.num_of_ptr = 0;
    return res;
}

struct type * TPtr_T_1(struct type * last){
    struct type *res = new_type();
    res->t = T_TEMPLATE_TYPE;
    res->d.TEMPLATE_TYPE.typename = last->d.TEMPLATE_TYPE.typename;
    res->d.TEMPLATE_TYPE.num_of_ptr = last->d.TEMPLATE_TYPE.num_of_ptr + 1;
    free(last);
    return res;
}

struct ptr_num *TPtrNil() {
    return NULL;
}

struct ptr_num *TPtr_num() {
    struct ptr_num *res = new_ptr_num();
    res->num_ptr = 1;
    return res;
}

struct ptr_num *TPtr_num_1(struct ptr_num *last) {
    struct ptr_num *res = new_ptr_num();
    res->num_ptr = last->num_ptr + 1;
    return res;
}

struct type_list *TTNil() {
    return NULL;
}

struct type_list *TTCons(struct type *cur, struct type_list *next) {
    struct type_list *res = new_type_list();
    res->data = cur;
    res->next = next;
    return res;
}

struct expr_list *TENil() {
    return NULL;
}

struct expr_list *TECons(struct expr *data, struct expr_list *next) {
    struct expr_list *res = new_expr_list_ptr();
    res->data = data;
    res->next = next;
    return res;
}

struct expr *TConst(unsigned int value) {
    struct expr *res = new_expr_ptr();
    res->t = T_CONST;
    res->d.CONST.value = value;
    return res;
}

struct expr *TVar(char *name) {
    struct expr *res = new_expr_ptr();
    res->t = T_VAR;
    res->d.VAR.name = name;
    return res;
}

struct expr *TPtr(struct expr *arg) {
    struct expr *res = new_expr_ptr();
    res->t = T_PTR;
    res->d.PTR.arg = arg;
    return res;
}

struct expr *TBinOp(enum BinOpType op, struct expr *left, struct expr *right) {
    struct expr *res = new_expr_ptr();
    res->t = T_BINOP;
    res->d.BINOP.op = op;
    res->d.BINOP.left = left;
    res->d.BINOP.right = right;
    return res;
}

struct expr *TUnOp(enum UnOpType op, struct expr *arg) {
    struct expr *res = new_expr_ptr();
    res->t = T_UNOP;
    res->d.UNOP.op = op;
    res->d.UNOP.arg = arg;
    return res;
}

struct expr *TDeref(struct expr *arg) {
    struct expr *res = new_expr_ptr();
    res->t = T_DEREF;
    res->d.DEREF.arg = arg;
    return res;
}

struct expr *TAddrOf(struct expr *arg) {
    struct expr *res = new_expr_ptr();
    res->t = T_ADDR_OF;
    res->d.ADDR_OF.arg = arg;
    return res;
}

struct expr *TFunc(char *name, struct expr_list *args) {
    struct expr *res = new_expr_ptr();
    res->t = T_FUNC;
    res->d.FUNC.name = name;
    res->d.FUNC.args = args;
    return res;
}

struct cmd *TDecl(struct type *type, char *name, struct cmd *body) {
    struct cmd *res = new_cmd_ptr();
    res->t = T_DECL;
    res->d.DECL.type = type;
    res->d.DECL.name = name;
    res->d.DECL.body = body;
    return res;
}

struct cmd *TDecl_1(struct type *return_type, struct ptr_num *num_ptr, struct type_list *list, char *name, struct cmd *body) {
    struct type *res = new_type();
    res->t = T_PTR_FUNC;
    res->d.PTR_FUNC.return_type = return_type;
    res->d.PTR_FUNC.num_of_ptr = num_ptr->num_ptr;
    res->d.PTR_FUNC.arg_list = list;
    struct cmd *res1 = new_cmd_ptr();
    res1->t = T_DECL;
    res1->d.DECL.name = name;
    res1->d.DECL.type = res;
    res1->d.DECL.body = body;
    return res1;
}

struct cmd *TDecl_2(struct ptr_num *num_ptr, struct type_list *list, char *name, struct cmd *body) {
    struct type *res = new_type();
    res->t = T_PTR_PROC;
    res->d.PTR_PROC.num_of_ptr = num_ptr->num_ptr;
    res->d.PTR_PROC.arg_list = list;
    struct cmd *res1 = new_cmd_ptr();
    res1->t = T_DECL;
    res1->d.DECL.name = name;
    res1->d.DECL.body = body;
    res1->d.DECL.type = res;
    return res1;
}

struct cmd *TAsgn(struct expr *left, struct expr *right) {
    struct cmd *res = new_cmd_ptr();
    res->t = T_ASGN;
    res->d.ASGN.left = left;
    res->d.ASGN.right = right;
    return res;
}

struct cmd *TSeq(struct cmd *left, struct cmd *right) {
    struct cmd *res = new_cmd_ptr();
    res->t = T_SEQ;
    res->d.SEQ.left = left;
    res->d.SEQ.right = right;
    return res;
}

struct cmd *TIf(struct expr *cond, struct cmd *left, struct cmd *right) {
    struct cmd *res = new_cmd_ptr();
    res->t = T_IF;
    res->d.IF.cond = cond;
    res->d.IF.left = left;
    res->d.IF.right = right;
    return res;
}

struct cmd *TWhile(struct expr *cond, struct cmd *body) {
    struct cmd *res = new_cmd_ptr();
    res->t = T_WHILE;
    res->d.WHILE.cond = cond;
    res->d.WHILE.body = body;
    return res;
}

struct cmd *TFor(struct cmd *init, struct expr *cond,
                 struct cmd *incr, struct cmd *body) {
    struct cmd *res = new_cmd_ptr();
    res->t = T_FOR;
    res->d.FOR.init = init;
    res->d.FOR.cond = cond;
    res->d.FOR.body = body;
    res->d.FOR.incr = incr;
    return res;
}

struct cmd *TDoWhile(struct cmd *body, struct expr *cond) {
    struct cmd *res = new_cmd_ptr();
    res->t = T_DO_WHILE;
    res->d.DO_WHILE.cond = cond;
    res->d.DO_WHILE.body = body;
    return res;
}

struct cmd *TProc(char *name, struct expr_list *args) {
    struct cmd *res = new_cmd_ptr();
    res->t = T_PROC;
    res->d.PROC.name = name;
    res->d.PROC.args = args;
    return res;
}

struct cmd *TBreak() {
    struct cmd *res = new_cmd_ptr();
    res->t = T_BREAK;
    return res;
}

struct cmd *TContinue() {
    struct cmd *res = new_cmd_ptr();
    res->t = T_CONTINUE;
    return res;
}

struct cmd *TReturn() {
    struct cmd *res = new_cmd_ptr();
    res->t = T_RETURN;
    return res;
}

struct var_list *TVNil() {
    return NULL;
}

struct var_list *TVCons(struct type *cur, char *name, struct var_list *next) {
    struct var_list *res = old_var_list_ptr();
    res->cur = cur;
    res->name = name;
    res->next = next;
    return res;
}

struct var_list *TVCons_1(struct type *return_type, struct ptr_num *num_ptr, struct type_list *list, char *name, struct var_list *next) {
    struct var_list *res = old_var_list_ptr();
    res->cur = new_type();
    res->cur->t = T_PTR_FUNC;
    res->cur->d.PTR_FUNC.num_of_ptr = num_ptr->num_ptr;
    res->cur->d.PTR_FUNC.arg_list = list;
    res->cur->d.PTR_FUNC.return_type = return_type;
    res->name = name;
    res->next = next;
    return res;
}

struct var_list *TVCons_2(struct ptr_num *num_ptr, struct type_list *list, char *name, struct var_list *next) {
    struct var_list *res = old_var_list_ptr();
    res->cur = new_type();
    res->cur->t = T_PTR_PROC;
    res->cur->d.PTR_PROC.num_of_ptr = num_ptr->num_ptr;
    res->cur->d.PTR_PROC.arg_list = list;
    res->name = name;
    res->next = next;
    return res;
}

// struct temp_var_list *TTVNil() {
//     return NULL;
// }

// struct temp_var_list * TTVCons(bool solved, struct type * cur, char * tpname, char * name, struct temp_var_list * next){
//     struct temp_var_list *res = (struct temp_var_list *) malloc(sizeof(struct temp_var_list));
//     if (res == NULL) {
//         printf("Failure in malloc.\n");
//         exit(0);
//     }
//     res->solved = solved;
//     res->cur = cur;
//     res->tpname = tpname;
//     res->name = name;
//     res->next = next;
//     return res;
// }

struct type_name_list * TNLNil(){
    return NULL;
}

struct type_name_list * TNLCons(char * name, struct type_name_list * next){
    struct type_name_list *res = (struct type_name_list *) malloc(sizeof(struct type_name_list));
    if (res == NULL) {
        printf("Failure in malloc.\n");
        exit(0);
    }
    res->name = name;
    res->next = next;
    return res;
}


struct glob_item *TFuncDef(struct type *return_type, char *name, struct var_list *args,
                           struct cmd *body) {
    struct glob_item *res = new_glob_item_ptr();
    res->d.FUNC_DEF.return_type = return_type;
    res->t = T_FUNC_DEF;
    res->d.FUNC_DEF.name = name;
    res->d.FUNC_DEF.args = args;
    res->d.FUNC_DEF.body = body;
    return res;
}

struct glob_item * TTemFuncDef(struct type_name_list* temp_types, struct type * return_type, char * name, struct var_list * args,
                            struct cmd * body){
    struct glob_item *res = new_glob_item_ptr();
    res->d.TEMP_FUNC_DEF.temp_types = temp_types;
    res->d.TEMP_FUNC_DEF.return_type = return_type;
    res->t = T_TEMP_FUNC_DEF;
    res->d.TEMP_FUNC_DEF.name = name;
    res->d.TEMP_FUNC_DEF.args = args;
    res->d.TEMP_FUNC_DEF.body = body;
    return res;
}

struct glob_item *TProcDef(char *name, struct var_list *args,
                           struct cmd *body) {
    struct glob_item *res = new_glob_item_ptr();
    res->t = T_PROC_DEF;
    res->d.PROC_DEF.name = name;
    res->d.PROC_DEF.args = args;
    res->d.PROC_DEF.body = body;
    return res;
}

struct glob_item * TTemProcDef(struct type_name_list* temp_types, char * name, struct var_list * args,
                            struct cmd * body){
    struct glob_item *res = new_glob_item_ptr();
    res->d.TEMP_PROC_DEF.temp_types = temp_types;
    res->t = T_TEMP_PROC_DEF;
    res->d.TEMP_PROC_DEF.name = name;
    res->d.TEMP_PROC_DEF.args = args;
    res->d.TEMP_PROC_DEF.body = body;
    return res;
}
struct glob_item *TGlobVar(struct type *var_type, char *name) {
    struct glob_item *res = new_glob_item_ptr();
    res->t = T_GLOB_VAR;
    res->d.GLOB_VAR.var_type = var_type;
    res->d.GLOB_VAR.name = name;
    return res;
}

struct glob_item *TGlobVar_1(struct type *return_type, struct ptr_num *num_ptr, struct type_list *list, char *name) {
    struct type *res = new_type();
    res->t = T_PTR_FUNC;
    res->d.PTR_FUNC.return_type = return_type;
    res->d.PTR_FUNC.num_of_ptr = num_ptr->num_ptr;
    res->d.PTR_FUNC.arg_list = list;
    struct glob_item *res1 = new_glob_item_ptr();
    res1->t = T_GLOB_VAR;
    res1->d.GLOB_VAR.var_type = res;
    res1->d.GLOB_VAR.name = name;
    return res1;
}

struct glob_item *TGlobVar_2(struct ptr_num *num_ptr, struct type_list *list, char *name) {
    struct type *res = new_type();
    res->t = T_PTR_PROC;
    res->d.PTR_PROC.num_of_ptr = num_ptr->num_ptr;
    res->d.PTR_PROC.arg_list = list;
    struct glob_item *res1 = new_glob_item_ptr();
    res1->t = T_GLOB_VAR;
    res1->d.GLOB_VAR.var_type = res;
    res1->d.GLOB_VAR.name = name;
    return res1;
}

struct glob_item_list *TGNil() {
    return NULL;
}

struct glob_item_list *TGCons(struct glob_item *data,
                              struct glob_item_list *next) {
    struct glob_item_list *res = new_glob_item_list_ptr();
    res->data = data;
    res->next = next;
    return res;
}

void print_binop(enum BinOpType op) {
    switch (op) {
        case T_PLUS:
            printf("PLUS");
            break;
        case T_MINUS:
            printf("MINUS");
            break;
        case T_MUL:
            printf("MUL");
            break;
        case T_DIV:
            printf("DIV");
            break;
        case T_MOD:
            printf("MOD");
            break;
        case T_LT:
            printf("LT");
            break;
        case T_GT:
            printf("GT");
            break;
        case T_LE:
            printf("LE");
            break;
        case T_GE:
            printf("GE");
            break;
        case T_EQ:
            printf("EQ");
            break;
        case T_NE:
            printf("NE");
            break;
        case T_AND:
            printf("AND");
            break;
        case T_OR:
            printf("OR");
            break;
    }
}

void print_unop(enum UnOpType op) {
    switch (op) {
        case T_UMINUS:
            printf("UMINUS");
            break;
        case T_NOT:
            printf("NOT");
            break;
    }
}

void print_type(struct type *t, struct decl_var *tns) {
    switch (t->t) {
        case T_PTR_INT:
            for (int i = 0; i < t->d.PTR_INT.num_of_ptr; i++) {
                printf("PTR(");
            }
            printf("INT");
            for (int i = 0; i < t->d.PTR_INT.num_of_ptr; i++) {
                printf(")");
            }
            break;
        case T_PTR_FUNC:
            for (int i = 0; i + 1 < t->d.PTR_FUNC.num_of_ptr; i++) {
                printf("PTR(");
            }
            printf("FUNPTR");
            printf("((");
            print_type_list(t->d.PTR_FUNC.arg_list);
            printf("),");
            print_type(t->d.PTR_FUNC.return_type, tns);
            printf(")");
            for (int i = 0; i + 1 < t->d.PTR_FUNC.num_of_ptr; i++) {
                printf(")");
            }
            break;
        case T_PTR_PROC:
            for (int i = 0; i + 1 < t->d.PTR_PROC.num_of_ptr; i++) {
                printf("PTR(");
            }
            printf("PROCPTR");
            printf("(");
            print_type_list(t->d.PTR_PROC.arg_list);
            printf(")");
            for (int i = 0; i + 1 < t->d.PTR_PROC.num_of_ptr; i++) {
                printf(")");
            }
            break;
        case T_TEMPLATE_TYPE:
            for (int i = 0; i < t->d.TEMPLATE_TYPE.num_of_ptr; i++) {
                printf("PTR(");
            }
            if(tns){
                struct decl_var * s;
                HASH_FIND_STR(tns, t->d.TEMPLATE_TYPE.typename, s);
                if(s){
                    print_type(s->var_type, tns);
                }
                else{
                    printf("Error24 when printing the type of %s\n", t->d.TEMPLATE_TYPE.typename);
                    exit(0);
                }
                break;
            }
            printf("TN(");
            printf("%s", t->d.TEMPLATE_TYPE.typename);
            printf(")");
            for (int i = 0; i < t->d.TEMPLATE_TYPE.num_of_ptr; i++) {
                printf(")");
            }
            break;
    }
}

bool cmp_type(struct type * t1, struct type * t2){ // 比较两个类型是否完全相同
    if(t1->t != t2->t){
        return false;
    }
    switch (t1->t) {
        case T_PTR_INT:
            return t1->d.PTR_INT.num_of_ptr == t2->d.PTR_INT.num_of_ptr;
        case T_PTR_FUNC:
            return t1->d.PTR_FUNC.num_of_ptr == t2->d.PTR_FUNC.num_of_ptr
                && cmp_type(t1->d.PTR_FUNC.return_type, t2->d.PTR_FUNC.return_type)
                && cmp_type_list(t1->d.PTR_FUNC.arg_list, t2->d.PTR_FUNC.arg_list);
        case T_PTR_PROC:
            return t1->d.PTR_PROC.num_of_ptr == t2->d.PTR_PROC.num_of_ptr
                && cmp_type_list(t1->d.PTR_PROC.arg_list, t2->d.PTR_PROC.arg_list);
        case T_TEMPLATE_TYPE:
            return t1->d.TEMPLATE_TYPE.num_of_ptr == t2->d.TEMPLATE_TYPE.num_of_ptr
                && strcmp(t1->d.TEMPLATE_TYPE.typename, t2->d.TEMPLATE_TYPE.typename) == 0;
    }
}

bool cmp_type_list(struct type_list * tl1, struct type_list * tl2){
    if(tl1 == NULL && tl2 == NULL){
        return true;
    }
    if(tl1 == NULL || tl2 == NULL){
        return false;
    }
    return cmp_type(tl1->data, tl2->data) && cmp_type_list(tl1->next, tl2->next);
}

bool cmp_type_name_list(struct type_name_list * tnl1, struct type_name_list * tnl2){ // 比较两个类型名列表是否完全相同（包括类型、顺序和名称）
    if(tnl1 == NULL && tnl2 == NULL){
        return true;
    }
    if(tnl1 == NULL || tnl2 == NULL){
        return false;
    }
    return cmp_type(tnl1->inst_type, tnl2->inst_type) && strcmp(tnl1->name, tnl2->name) == 0 && cmp_type_name_list(tnl1->next, tnl2->next);
}

void _print_type_list(struct type_list *tl) { // 多一个逗号
    if (tl == NULL) {
        return;
    }
    printf(",");
    print_type(tl->data, NULL);
    _print_type_list(tl->next);
}

void print_type_list(struct type_list *tl) {
    if (tl == NULL) {
        return;
    }
    print_type(tl->data, NULL);
    _print_type_list(tl->next);
}

void _print_type_name_list(struct type_name_list *tnl) {
    if (tnl == NULL) {
        return;
    }
    printf(",");
    printf("%s", tnl->name);
    _print_type_name_list(tnl->next);
}

void print_type_name_list(struct type_name_list *tnl) {
    if (tnl == NULL) {
        return;
    }
    printf("%s", tnl->name);
    _print_type_name_list(tnl->next);
}

void print_expr(struct expr *e) {
    switch (e->t) {
        case T_CONST:
            printf("CONST(%d)", e->d.CONST.value);
            break;
        case T_VAR:
            printf("VAR(%s)", e->d.VAR.name);
            break;
        case T_PTR:
            printf("PTR(");
            print_expr(e->d.PTR.arg);
            printf(")");
            break;
        case T_BINOP:
            print_binop(e->d.BINOP.op);
            printf("(");
            print_expr(e->d.BINOP.left);
            printf(",");
            print_expr(e->d.BINOP.right);
            printf(")");
            break;
        case T_UNOP:
            print_unop(e->d.UNOP.op);
            printf("(");
            print_expr(e->d.UNOP.arg);
            printf(")");
            break;
        case T_DEREF:
            printf("DEREF(");
            print_expr(e->d.DEREF.arg);
            printf(")");
            break;
        case T_ADDR_OF:
            printf("ADDR_OF(");
            print_expr(e->d.ADDR_OF.arg);
            printf(")");
            break;
        case T_FUNC:
            printf("FUNC(%s", e->d.FUNC.name);
            print_expr_list(e->d.FUNC.args);
            printf(")");
            break;
    }
}

struct type * ins_binop(enum BinOpType op, struct type * t1, struct type * t2) { // 根据二元运算符和两个操作数的类型，推导出结果的类型。认为常数可以类型转换
    switch (op) {
        case T_PLUS:
        case T_MINUS:
        case T_MUL:
        case T_DIV:
        case T_MOD:
            if (cmp_type(t1, t2)) {
                struct type *t = (struct type *) malloc(sizeof(struct type));
                t->t = t1->t;
                t->d = t1->d;
                return t;
            }
            else if (t1->t == 0 && t1->d.PTR_INT.num_of_ptr == 0) {
                struct type *t = (struct type *) malloc(sizeof(struct type));
                t->t = t2->t;
                t->d = t2->d;
                return t;
            }
            else if (t2->t == 0 && t2->d.PTR_INT.num_of_ptr == 0) {
                struct type *t = (struct type *) malloc(sizeof(struct type));
                t->t = t1->t;
                t->d = t1->d;
                return t;
            }
            else {
                printf("Error1 when instantiating the type of ");
                print_type(t1, NULL);
                printf(" \'some binop\' ");
                print_type(t2, NULL);
                exit(0);
            }
        case T_AND:
        case T_OR:
        case T_EQ:
        case T_NE:
            return TPtr_int();
        case T_GE:
        case T_GT:
        case T_LE:
        case T_LT:
            if (cmp_type(t1, t2)) {
                return TPtr_int();
            }
            else if (t1->t == 0 && t1->d.PTR_INT.num_of_ptr == 0) {
                return TPtr_int();
            }
            else if (t2->t == 0 && t2->d.PTR_INT.num_of_ptr == 0) {
                return TPtr_int();
            }
            else {
                printf("Error2 when instantiating the type of ");
                print_type(t1, NULL);
                printf(" \'some binop\' ");
                print_type(t2, NULL);
                exit(0);
            }
    }
}

struct type * ins_unop(enum UnOpType op, struct type * t) { // 根据一元运算符和操作数的类型，推导出结果的类型。将bool认为是int
    switch (op) {
        case T_UMINUS: {
            struct type *t1 = (struct type *) malloc(sizeof(struct type));
            t1->t = t->t;
            t1->d = t1->d;
            return t1;
        }
        case T_NOT:
            return TPtr_int();
    }
}

struct type * ins_deref(struct type * t) { // 推导出解引用的结果类型
    switch (t->t) {
        case T_PTR_INT:
            if (t->d.PTR_INT.num_of_ptr > 0) {
                struct type * t1 = (struct type *) malloc(sizeof(struct type));
                t1->t = 0;
                t1->d.PTR_INT.num_of_ptr = t->d.PTR_INT.num_of_ptr - 1;
                return t1;
            }
            else {
                printf("Error3 when instantiating the type of deref of ");
                print_type(t, NULL);
                exit(0);
            }
        case T_PTR_FUNC:
            if (t->d.PTR_FUNC.num_of_ptr > 0) {
                struct type * t1 = (struct type *) malloc(sizeof(struct type));
                t1->t = 1;
                t1->d.PTR_FUNC.num_of_ptr = t->d.PTR_FUNC.num_of_ptr - 1;
                t1->d.PTR_FUNC.return_type = t->d.PTR_FUNC.return_type;
                t1->d.PTR_FUNC.arg_list = t->d.PTR_FUNC.arg_list;
                return t1;
            }
            else {
                printf("Error4 when instantiating the type of deref of ");
                print_type(t, NULL);
                exit(0);
            }
        case T_PTR_PROC:
            if (t->d.PTR_PROC.num_of_ptr > 0) {
                struct type * t1 = (struct type *) malloc(sizeof(struct type));
                t1->t = 2;
                t1->d.PTR_PROC.num_of_ptr = t->d.PTR_PROC.num_of_ptr - 1;
                t1->d.PTR_PROC.arg_list = t->d.PTR_PROC.arg_list;
                return t1;
            }
            else {
                printf("Error5 when instantiating the type of deref of ");
                print_type(t, NULL);
                exit(0);
            }
    }
}

struct type * ins_addr_of(struct type * t) { // 推导出取地址的结果类型
    switch (t->t) {
        case T_PTR_INT: {
            struct type *t1 = (struct type *) malloc(sizeof(struct type));
            t1->t = 0;
            t1->d.PTR_INT.num_of_ptr = t->d.PTR_INT.num_of_ptr + 1;
            return t1;
        }
        case T_PTR_FUNC: {
            struct type *t1 = (struct type *) malloc(sizeof(struct type));
            t1->t = 1;
            t1->d.PTR_FUNC.num_of_ptr = t->d.PTR_FUNC.num_of_ptr + 1;
            t1->d.PTR_FUNC.return_type = t->d.PTR_FUNC.return_type;
            t1->d.PTR_FUNC.arg_list = t->d.PTR_FUNC.arg_list;
            return t1;
        }
        case T_PTR_PROC: {
            struct type *t1 = (struct type *) malloc(sizeof(struct type));
            t1->t = 2;
            t1->d.PTR_PROC.num_of_ptr = t->d.PTR_PROC.num_of_ptr + 1;
            t1->d.PTR_PROC.arg_list = t->d.PTR_PROC.arg_list;
            return t1;
        }
    }
}

// ins指instantiate，即实例化一个procedure
// 本函数将遍历procedure的每个实参，推断表达式的类型，并与形参定义的模板类型相比较，以推断出typename是什么
// 如果存在一个typename未被推导，或者同时被好几个类型不一实参用到，则报错
// 在推导之后，还需更新环境变量env_vars，覆盖原有大环境的声明（如有）；同时更新env_typename（使用哈希表存储）。
// 然后遍历之前实例化过的所有函数，检查有无函数名完全相同、typename也完全相同的情况。如无，遍历这个procedure的body，以完成body中含有typename的类型推导
// 遍历完body后还要回滚所有形参变量声明
void ins_proc(struct expr_list * es, struct glob_item * proc, struct decl_var * env_typename) {
    if (es == NULL || proc->t!=T_TEMP_PROC_DEF) {
        return;
    }
    struct type_name_list * head = NULL, *tail = head;
    for(struct type_name_list * tnl_it = proc->d.TEMP_PROC_DEF.temp_types; tnl_it != NULL; tnl_it = tnl_it->next){
        struct type_name_list * temp = malloc(sizeof(struct type_name_list));
        temp->inst_type = NULL;
        temp->name = tnl_it->name;
        temp->next = NULL;
        if(head == NULL){
            head = temp;
            tail = head;
        }
        else{
            tail->next = temp;
            tail = tail->next;
        }
    }
    struct decl_var *new_env_typename = NULL;
    struct expr_list * es_1 = es;
    struct var_list * new_vars=NULL, *new_vars_tail=new_vars;
    struct var_list * old_vars=NULL, *old_vars_tail=old_vars;
    for (struct var_list * it = proc->d.TEMP_PROC_DEF.args; it != NULL; it = it->next, es_1 = es_1->next) {
        if(es_1==NULL){
            printf("Error57 when instantiating the type of %s\n", proc->d.TEMP_PROC_DEF.name);
            exit(0);
        }
        struct type * t1 = ins_expr(es_1->data, env_typename);
        new_env_typename = ins_varname(it->cur, t1, head, new_env_typename);
        struct decl_var *s;
        HASH_FIND_STR(env_vars, it->name , s);
        if(s){
            struct var_list *old_var = malloc(sizeof(struct decl_var));
            old_var->name = it->name;
            old_var->cur = s->var_type;
            if(old_vars==NULL){
                old_vars = old_var;
                old_vars_tail = old_vars;
            }
            else{
                old_vars_tail->next = old_var;
                old_vars_tail = old_vars_tail->next;
            }
            struct var_list *new_var = malloc(sizeof(struct decl_var));
            new_var->name = it->name;
            new_var->cur = t1;
            if(new_vars==NULL){
                new_vars = new_var;
                new_vars_tail = new_vars;
            }
            else{
                new_vars_tail->next = new_var;
                new_vars_tail = new_vars_tail->next;
            }
        }
        else{
            struct decl_var *new_var = malloc(sizeof(struct decl_var));
            new_var->name = it->name;
            new_var->var_type = t1;
            HASH_ADD_KEYPTR(hh, env_vars, new_var->name, strlen(new_var->name), new_var);
            struct var_list *delete_flag = malloc(sizeof(struct decl_var));
            delete_flag->name = it->name;
            delete_flag->cur = NULL;
            if(old_vars==NULL){
                old_vars = delete_flag;
                old_vars_tail = old_vars;
            }
            else{
                old_vars_tail->next = delete_flag;
                old_vars_tail = old_vars_tail->next;
            }
        }
    }
    for(struct var_list* it = new_vars; it != NULL; it = it->next){
        struct decl_var *s;
        HASH_FIND_STR(env_vars, it->name, s);
        if(s){
            s->var_type = it->cur;
        }
        else{
            printf("Error56 when instantiating the type of %s\n", proc->d.TEMP_PROC_DEF.name);
            exit(0);
        }
    }
    for(struct type_name_list * tnl_it = head; tnl_it != NULL; tnl_it = tnl_it->next){
        if(tnl_it->inst_type == NULL){
            printf("Error58 when instantiating the type of %s\n", proc->d.TEMP_PROC_DEF.name);
            exit(0);
        }
    }
    int flag=1;
    for (struct instantiated_proc_list *ipl = IPL; ipl != NULL; ipl = ipl->next) {
        if (strcmp(ipl->data->name, proc->d.TEMP_PROC_DEF.name) == 0) {
            flag=0;
            for (struct type_name_list *it1 = ipl->data->args, *it2 = head; it1 != NULL && it2 != NULL; it1 = it1->next, it2 = it2->next) {
                if (!cmp_type(it1->inst_type, it2->inst_type)) {
                    flag=1;
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
    }
    if(flag) {
        struct instantiated_proc_list *ipl = malloc(sizeof(struct instantiated_proc_list));
        struct instantiated_proc *new_proc = malloc(sizeof(struct instantiated_proc));
        new_proc->name = proc->d.TEMP_PROC_DEF.name;
        new_proc->args = head;
        ipl->data = new_proc;
        ipl->next = IPL;
        IPL = ipl;
        ins_cmd(proc->d.TEMP_PROC_DEF.body, new_env_typename);
    }
    free(new_env_typename);
    for(struct var_list * it = old_vars; it != NULL; it = it->next){
        struct decl_var *s;
        HASH_FIND_STR(env_vars, it->name, s);
        if(it->cur == NULL){
            HASH_DEL(env_vars, s);
            free(s);
        }
        else{
            s->var_type = it->cur;
        }
    }
    return;


    // 历史遗留
    // for(struct type_name_list * tnl_it = proc->d.TEMP_PROC_DEF.temp_types; tnl_it != NULL; tnl_it = tnl_it->next) {
    //     bool flag = false; //false表示当前模板还未匹配到类型
    //     struct expr_list * es_1 = es;
    //     for (struct var_list * it = proc->d.TEMP_PROC_DEF.args; it != NULL; it = it->next, es_1 = es_1->next) {
    //         if (it->cur->t == T_TEMPLATE_TYPE && strcmp(it->cur->d.TEMPLATE_TYPE.typename, tnl_it->name) == 0) {
    //             struct type * t1 = ins_expr(es->data, env_typename);
    //             if (!flag) {
    //                 flag = true;
    //                 tail = malloc(sizeof(struct type_name_list));
    //                 tail->inst_type = t1;
    //                 tail->name = tnl_it->name;
    //                 tail = tail->next;
    //                 struct type * t2 = malloc(sizeof (struct type));
    //                 t2->t = t1->t;
    //                 t2->d = t1->d;
    //                 tnl_it->inst_type = t2;
    //             }
    //             else {
    //                 for (struct type_name_list *tnl_it_1 = head; tnl_it_1 != tail->next; tnl_it_1 = tnl_it_1->next) {
    //                     if (strcmp(tnl_it_1->name, tnl_it->name) == 0 && !cmp_type(tnl_it_1->inst_type, t1)) {
    //                         printf("Error10 when instantiating the process %s\n", proc->d.TEMP_PROC_DEF.name);
    //                         exit(0);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

}

// 实例化一个形参列表，在ins_return_type实例化函数指针时需要用到
struct type_list * ins_return_type_list(struct type_list * tl, struct decl_var * env_typename) {
    if (tl == NULL) {
        return NULL;
    }
    struct type_list * head = NULL, *tail = head;
    for (struct type_list * it = tl; it != NULL; it = it->next) {
        struct type * t1 = ins_return_type(it->data, env_typename);
        if (head == NULL) {
            head = malloc(sizeof(struct type_list));
            head->data = t1;
            tail = head;
        }
        else {
            tail->next = malloc(sizeof(struct type_list));
            tail->next->data = t1;
            tail = tail->next;
        }
    }
    return head;
}

// 实例化单个包含了typename的类型
struct type * ins_return_type(struct type * t, struct decl_var * env_typename) {
    switch (t->t) {
        case T_PTR_INT:
            return t;
        case T_PTR_FUNC: {
            struct type *res = (struct type *) malloc(sizeof(struct type));
            res->t = T_PTR_FUNC;
            res->d.PTR_FUNC.num_of_ptr = t->d.PTR_FUNC.num_of_ptr;
            res->d.PTR_FUNC.return_type = ins_return_type(t->d.PTR_FUNC.return_type, env_typename);
            res->d.PTR_FUNC.arg_list = ins_return_type_list(t->d.PTR_FUNC.arg_list, env_typename);
            return res;
            // struct ptr_num *num_ptr = (struct ptr_num *) malloc(sizeof(struct ptr_num));
            // num_ptr->num_ptr = t->d.PTR_FUNC.num_of_ptr;
            // return TPtr_func(ins_return_type(t->d.PTR_FUNC.return_type, num_ptr, env_typename), , ins_return_type_list(t->d.PTR_FUNC.arg_list, env_typename));
        }
        case T_PTR_PROC: {
            struct type *res1 = (struct type *) malloc(sizeof(struct type));
            res1->t = T_PTR_PROC;
            res1->d.PTR_PROC.num_of_ptr = t->d.PTR_PROC.num_of_ptr;
            res1->d.PTR_PROC.arg_list = ins_return_type_list(t->d.PTR_PROC.arg_list, env_typename);
            return res1;
            // struct ptr_num *num_ptr = (struct ptr_num *) malloc(sizeof(struct ptr_num));
            // num_ptr->num_ptr = t->d.PTR_PROC.num_of_ptr;
            // return TPtr_proc(num_ptr, ins_return_type(t->d.PTR_PROC.arg_list, env_typename));
        }
        case T_TEMPLATE_TYPE: {
            struct decl_var *s;
            HASH_FIND_STR(env_typename, t->d.TEMPLATE_TYPE.typename, s);
            if (s) {
                return s->var_type;
            } else {
                printf("Error41 when instantiating the type of %s\n", t->d.TEMPLATE_TYPE.typename);
                exit(0);
            }
        }
    }
}

// 推断一个表达式结果的真正类型，实现方式类似解释器
struct type * ins_expr(struct expr *e, struct decl_var *env_typename){
    switch (e->t) {
        case T_CONST:
            return TPtr_int();
        case T_VAR: {
            struct decl_var *s;
            HASH_FIND_STR(env_vars, e->d.VAR.name, s);
            if (s) {
                return s->var_type;
            } else {
                printf("Error47 when instantiating the type of %s\n", e->d.VAR.name);
                exit(0);
            }
        }
        case T_PTR:
            return TPtr_int_1(ins_expr(e->d.PTR.arg, env_typename));
        case T_BINOP:
            return ins_binop(e->d.BINOP.op, ins_expr(e->d.BINOP.left, env_typename), ins_expr(e->d.BINOP.right, env_typename));
        case T_UNOP:
            return ins_unop(e->d.UNOP.op, ins_expr(e->d.UNOP.arg, env_typename));
        case T_DEREF:
            return ins_deref(ins_expr(e->d.DEREF.arg, env_typename));
        case T_ADDR_OF:
            return ins_addr_of(ins_expr(e->d.ADDR_OF.arg, env_typename));
        case T_FUNC: {
            struct decl_fun *f;
            HASH_FIND_STR(env_funs, e->d.FUNC.name, f);
            if (f) {
                  return ins_fun(e->d.FUNC.args, f->it, env_typename);
                  // 历史遗留，已经都挪到ins_fun里面去了
//                struct type_name_list *inst_args = ins_fun(e->d.FUNC.args, f->it, env_typename);
//                struct instantiated_func_list *list_it;
//                for (list_it = IFL; list_it != NULL && list_it->data!=NULL; list_it = list_it->next) {
//                    if (strcmp(list_it->data->name, e->d.FUNC.name) == 0) {
//                        if (cmp_type_name_list(list_it->data->args, inst_args)) {
//                            return list_it->data->return_type;
//                        }
//                    }
//                }
//                struct instantiated_func_list *new_func_it = (struct instantiated_func_list *) malloc(
//                        sizeof(struct instantiated_func_list));
//                new_func_it->next = NULL;
//                struct instantiated_func *new_func = (struct instantiated_func *) malloc(
//                        sizeof(struct instantiated_func));
//                new_func->name = e->d.FUNC.name;
//                new_func->args = inst_args;
//                if (f->is_template) {
//                    new_func->return_type = ins_return_type(f->it->d.TEMP_FUNC_DEF.return_type, env_typename);
//                    // struct decl_var *realt = NULL;
//                    // HASH_FIND_STR(env_typename, f->it->d.TEMP_FUNC_DEF.return_type->d.TEMPLATE_TYPE.typename, realt);
//                    // if (realt) {
//                    //     new_func->return_type = realt->var_type;
//                    // } else {
//                    //     printf("Error8 when instantiating the type of %s\n", e->d.FUNC.name);
//                    //     exit(0);
//                    // }
//                } else {
//                    new_func->return_type = f->it->d.FUNC_DEF.return_type;
//                }
//                new_func_it->data = new_func;
//                list_it=IFL;
//                IFL = new_func_it;
//                IFL->next = list_it;
////                ins_glob_item(f->it, inst_args);
//                return new_func->return_type;
            } else {
                printf("Error9 when instantiating the type of %s\n", e->d.FUNC.name);
                exit(0);
            }
        }
    }
}

void print_expr_list(struct expr_list *es) {
    if (es == NULL) {
        return;
    }
    printf(",");
    print_expr(es->data);
    print_expr_list(es->next);
}

// 对照着t_real，把t_temp里面的所有typename都推断出来，并且更新env_typename
// 如果t_temp里面有typename没有被推断出来，或者与先前被推断出来的类型不一致，则报错
struct decl_var * ins_varname(struct type* t_temp, struct type* t_real, struct type_name_list * typenames, struct decl_var *env_typename){
    if(t_temp->t==T_TEMPLATE_TYPE){
        struct decl_var *s;
        HASH_FIND_STR(env_typename, t_temp->d.TEMPLATE_TYPE.typename, s);
        if(s){
            struct type* t1=malloc(sizeof(struct type));
            t1->t=s->var_type->t;
            t1->d=s->var_type->d;
            switch(t1->t){
                case T_PTR_INT:
                    t1->d.PTR_INT.num_of_ptr += t_temp->d.TEMPLATE_TYPE.num_of_ptr;
                    break;
                case T_PTR_FUNC:
                    t1->d.PTR_FUNC.num_of_ptr += t_temp->d.TEMPLATE_TYPE.num_of_ptr;
                    break;
                case T_PTR_PROC:
                    t1->d.PTR_PROC.num_of_ptr += t_temp->d.TEMPLATE_TYPE.num_of_ptr;
                    break;
            }
            if(cmp_type(t1, t_real)){
                return env_typename;
            }
            else{
                printf("Error50 when instantiating the type of %s\n", t_temp->d.TEMPLATE_TYPE.typename);
                exit(0);
            }
        }
        else{
            int flag=0;
            struct type_name_list * tnl_it;
            for(tnl_it = typenames; tnl_it != NULL; tnl_it = tnl_it->next){
                if(strcmp(tnl_it->name, t_temp->d.TEMPLATE_TYPE.typename) == 0){
                    if(tnl_it->inst_type==NULL){
                        struct type* t1=malloc(sizeof(struct type));
                        t1->t=t_real->t;
                        t1->d=t_real->d;
                        switch (t1->t) {
                            case T_PTR_INT:
                                if(t1->d.PTR_INT.num_of_ptr < t_temp->d.TEMPLATE_TYPE.num_of_ptr){
                                    printf("Error59 when instantiating the type of %s\n", t_temp->d.TEMPLATE_TYPE.typename);
                                    exit(0);
                                }
                                t1->d.PTR_INT.num_of_ptr -= t_temp->d.TEMPLATE_TYPE.num_of_ptr;
                                break;
                            case T_PTR_FUNC:
                                if(t1->d.PTR_FUNC.num_of_ptr < t_temp->d.TEMPLATE_TYPE.num_of_ptr){
                                    printf("Error60 when instantiating the type of %s\n", t_temp->d.TEMPLATE_TYPE.typename);
                                    exit(0);
                                }
                                t1->d.PTR_FUNC.num_of_ptr -= t_temp->d.TEMPLATE_TYPE.num_of_ptr;
                                break;
                            case T_PTR_PROC:
                                if(t1->d.PTR_PROC.num_of_ptr < t_temp->d.TEMPLATE_TYPE.num_of_ptr){
                                    printf("Error61 when instantiating the type of %s\n", t_temp->d.TEMPLATE_TYPE.typename);
                                    exit(0);
                                }
                                t1->d.PTR_PROC.num_of_ptr -= t_temp->d.TEMPLATE_TYPE.num_of_ptr;
                                break;
                        }
                        tnl_it->inst_type = t1;
                        flag=1;
                        break;
                    }
                    else{
                        printf("Error51 when instantiating the type of %s\n", t_temp->d.TEMPLATE_TYPE.typename);
                        exit(0);
                    }
                }
            }
            if(!flag){
                printf("Error67 when instantiating the type of %s\n", t_temp->d.TEMPLATE_TYPE.typename);
                exit(0);
            }
            s=malloc(sizeof(struct decl_var));
            s->var_type = tnl_it->inst_type;
            s->name = t_temp->d.TEMPLATE_TYPE.typename;
            HASH_ADD_KEYPTR(hh, env_typename, s->name, strlen(s->name), s);
            return env_typename;
        }
    }
    else if(t_temp->t!=t_real->t){
        printf("Error52 when instantiating the type of %s\n", t_temp->d.TEMPLATE_TYPE.typename);
        exit(0);
    }
    else{
        switch (t_temp->t) {
            case T_PTR_INT:
                if(t_temp->d.PTR_INT.num_of_ptr != t_real->d.PTR_INT.num_of_ptr){
                    printf("Error53 when instantiating the type of %s\n", t_temp->d.TEMPLATE_TYPE.typename);
                    exit(0);
                }
                break;
            case T_PTR_FUNC:
                if(t_temp->d.PTR_FUNC.num_of_ptr != t_real->d.PTR_FUNC.num_of_ptr){
                    printf("Error54 when instantiating the type of %s\n", t_temp->d.TEMPLATE_TYPE.typename);
                    exit(0);
                }
                env_typename = ins_varname(t_temp->d.PTR_FUNC.return_type, t_real->d.PTR_FUNC.return_type, typenames, env_typename);
                env_typename = ins_type_list(t_temp->d.PTR_FUNC.arg_list, t_real->d.PTR_FUNC.arg_list, typenames, env_typename);
                break;
            case T_PTR_PROC:
                if(t_temp->d.PTR_PROC.num_of_ptr != t_real->d.PTR_PROC.num_of_ptr){
                    printf("Error55 when instantiating the type of %s\n", t_temp->d.TEMPLATE_TYPE.typename);
                    exit(0);
                }
                env_typename = ins_type_list(t_temp->d.PTR_PROC.arg_list, t_real->d.PTR_PROC.arg_list, typenames, env_typename);
                break;
        }

    }
    return env_typename;
}

// 对整个形参列表都对照着实参（表达式结果）推断一遍typename。
struct decl_var * ins_type_list(struct type_list * tl_temp, struct type_list * tl_real, struct type_name_list * typenames, struct decl_var *env_typename){
    if(tl_temp == NULL && tl_real == NULL){
        return env_typename;
    }
    if(tl_temp == NULL || tl_real == NULL){
        printf("Error56 when instantiating the type of %s\n", tl_temp->data->d.TEMPLATE_TYPE.typename);
        exit(0);
    }
    env_typename = ins_varname(tl_temp->data, tl_real->data, typenames, env_typename);
    return ins_type_list(tl_temp->next, tl_real->next, typenames, env_typename);
}

// 与实例化procedure类似，返回值为函数的返回值类型
struct type * ins_fun(struct expr_list *es, struct glob_item* fun, struct decl_var *env_typename){
    if(es == NULL||fun->t==T_FUNC_DEF){
        return fun->d.FUNC_DEF.return_type;
    }
    struct type_name_list * head = NULL, * tail = head;
    for(struct type_name_list * tnl_it = fun->d.TEMP_FUNC_DEF.temp_types; tnl_it != NULL; tnl_it = tnl_it->next){
        struct type_name_list * temp = malloc(sizeof(struct type_name_list));
        temp->inst_type = NULL;
        temp->name = tnl_it->name;
        temp->next = NULL;
        if(head == NULL){
            head = temp;
            tail = head;
        }
        else{
            tail->next = temp;
            tail = tail->next;
        }
    }
    struct decl_var *new_env_typename = NULL;
    struct expr_list * es_1 = es;
    struct var_list * old_vars=NULL, *old_vars_tail=old_vars;
    struct var_list * new_vars=NULL, *new_vars_tail=new_vars;
    for (struct var_list * it = fun->d.TEMP_FUNC_DEF.args; it != NULL; it = it->next, es_1 = es_1->next) {
        if(es_1==NULL){
            printf("Error57 when instantiating the type of %s\n", fun->d.TEMP_FUNC_DEF.name);
            exit(0);
        }
        struct type * t1 = ins_expr(es_1->data, env_typename);
        new_env_typename = ins_varname(it->cur, t1, head, new_env_typename);
        struct decl_var *s;
        HASH_FIND_STR(env_vars, it->name , s);
        if(s){
            struct var_list *old_var = malloc(sizeof(struct decl_var));
            old_var->name = it->name;
            old_var->cur = s->var_type;
            if(old_vars==NULL){
                old_vars = old_var;
                old_vars_tail = old_vars;
            }
            else{
                old_vars_tail->next = old_var;
                old_vars_tail = old_vars_tail->next;
            }
            struct var_list *new_var = malloc(sizeof(struct decl_var));
            new_var->name = it->name;
            new_var->cur = t1;
            if(new_vars==NULL){
                new_vars = new_var;
                new_vars_tail = new_vars;
            }
            else{
                new_vars_tail->next = new_var;
                new_vars_tail = new_vars_tail->next;
            }
        }
        else{
            struct decl_var *new_var = malloc(sizeof(struct decl_var));
            new_var->name = it->name;
            new_var->var_type = t1;
            HASH_ADD_KEYPTR(hh, env_vars, new_var->name, strlen(new_var->name), new_var);
            struct var_list *delete_flag = malloc(sizeof(struct decl_var));
            delete_flag->name = it->name;
            delete_flag->cur = NULL;
            if(old_vars==NULL){
                old_vars = delete_flag;
                old_vars_tail = old_vars;
            }
            else{
                old_vars_tail->next = delete_flag;
                old_vars_tail = old_vars_tail->next;
            }
        }
    }
    for(struct var_list* it = new_vars; it != NULL; it = it->next){
        struct decl_var *s;
        HASH_FIND_STR(env_vars, it->name, s);
        if(s){
            s->var_type = it->cur;
        }
        else{
            printf("Error56 when instantiating the type of %s\n", fun->d.TEMP_FUNC_DEF.name);
            exit(0);
        }
    }
    for(struct type_name_list * tnl_it = head; tnl_it != NULL; tnl_it = tnl_it->next){
        if(tnl_it->inst_type == NULL){
            printf("Error58 when instantiating the type of %s: unused typename %s\n", fun->d.TEMP_FUNC_DEF.name, tnl_it->name);
            exit(0);
        }
    }
    int flag=1;
    for (struct instantiated_func_list *ifl = IFL; ifl != NULL; ifl = ifl->next) {
        if (strcmp(ifl->data->name, fun->d.TEMP_FUNC_DEF.name) == 0) {
            flag=0;
            for (struct type_name_list *it1 = ifl->data->args, *it2 = head; it1 != NULL && it2 != NULL; it1 = it1->next, it2 = it2->next) {
                if (!cmp_type(it1->inst_type, it2->inst_type)) {
                    flag=1;
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
    }
    struct instantiated_func * new_func = malloc(sizeof(struct instantiated_func));
    new_func->name = fun->d.TEMP_FUNC_DEF.name;
    new_func->args = head;
    new_func->return_type = ins_return_type(fun->d.TEMP_FUNC_DEF.return_type, new_env_typename);
    if(flag) {
        struct instantiated_func_list *ifl = malloc(sizeof(struct instantiated_func_list));
        ifl->data = new_func;
        ifl->next = IFL;
        IFL = ifl;
        ins_cmd(fun->d.TEMP_FUNC_DEF.body, new_env_typename);
    }
    free(new_env_typename);
    for(struct var_list * it = old_vars; it != NULL; it = it->next){
        struct decl_var *s;
        HASH_FIND_STR(env_vars, it->name, s);
        if(it->cur == NULL){
            HASH_DEL(env_vars, s);
            free(s);
        }
        else{
            s->var_type = it->cur;
        }
    }
    return new_func->return_type;

    // 历史遗留
    // for(struct type_name_list * tnl_it = fun->d.TEMP_FUNC_DEF.temp_types; tnl_it != NULL; tnl_it = tnl_it->next) {
    //     bool flag = false; //false表示当前模板还未匹配到类型
    //     struct expr_list * es_1 = es;
    //     for (struct var_list * it = fun->d.TEMP_FUNC_DEF.args; it != NULL; it = it->next, es_1 = es_1->next) {
    //         if (it->cur->t == T_TEMPLATE_TYPE && strcmp(it->cur->d.TEMPLATE_TYPE.typename, tnl_it->name) == 0) {
    //             struct type * t1 = ins_expr(es->data, env_typename);
    //             switch (t1->t) {
    //                 case 0:
    //                     if (it->cur->d.TEMPLATE_TYPE.num_of_ptr > t1->d.PTR_INT.num_of_ptr){
    //                         printf("Error30 when instantiating the type of %s\n", tnl_it->name);
    //                         exit(0);
    //                     }
    //                     else{
    //                         t1->d.PTR_INT.num_of_ptr -= it->cur->d.TEMPLATE_TYPE.num_of_ptr;
    //                     }
    //                 case 1:
    //                     if (it->cur->d.TEMPLATE_TYPE.num_of_ptr > t1->d.PTR_FUNC.num_of_ptr){
    //                         printf("Error31 when instantiating the type of %s\n", tnl_it->name);
    //                         exit(0);
    //                     }
    //                     else{
    //                         t1->d.PTR_FUNC.num_of_ptr -= it->cur->d.TEMPLATE_TYPE.num_of_ptr;
    //                     }
    //                 case 2:
    //                     if (it->cur->d.TEMPLATE_TYPE.num_of_ptr > t1->d.PTR_PROC.num_of_ptr){
    //                         printf("Error31 when instantiating the type of %s\n", tnl_it->name);
    //                         exit(0);
    //                     }
    //                     else{
    //                         t1->d.PTR_PROC.num_of_ptr -= it->cur->d.TEMPLATE_TYPE.num_of_ptr;
    //                     }
    //             }
    //             if (!flag) {
    //                 flag = true;
    //                 tail = malloc(sizeof(struct type_name_list));
    //                 tail->inst_type = t1;
    //                 tail->name = tnl_it->name;
    //                 tail = tail->next;
    //                 struct type * t2 = malloc(sizeof (struct type));
    //                 t2->t = t1->t;
    //                 t2->d = t1->d;
    //                 tnl_it->inst_type = t2;
    //             }
    //             else {
    //                 for (struct type_name_list *tnl_it_1 = head; tnl_it_1 != tail->next; tnl_it_1 = tnl_it_1->next) {
    //                     if (strcmp(tnl_it_1->name, tnl_it->name) == 0 && !cmp_type(tnl_it_1->inst_type, t1)) {
    //                         printf("Error10 when instantiating the function %s\n", fun->d.TEMP_FUNC_DEF.name);
    //                         exit(0);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
}

void print_cmd(struct cmd *c, struct decl_var *tns) {
    switch (c->t) {
        case T_DECL:
            printf("DECL(");
            printf("%s:", c->d.DECL.name);
            struct decl_var *realt=NULL;
            if(c->d.DECL.type->t==T_TEMPLATE_TYPE){
                HASH_FIND_STR(tns, c->d.DECL.type->d.TEMPLATE_TYPE.typename, realt);
            }
            if(realt)
                print_type(realt->var_type, tns);
            else
                print_type(c->d.DECL.type, tns);
            printf(",");
            struct decl_var * s;
            HASH_FIND_STR(env_vars, c->d.DECL.name, s);
            if(s){
                struct type * t = s->var_type;
                if(realt)
                    s->var_type = realt->var_type;
                else
                    s->var_type = c->d.DECL.type;
                print_cmd(c->d.DECL.body, tns);
                s->var_type = t;
            }
            else{
                s=(struct decl_var *)malloc(sizeof(struct decl_var));
                s->name = c->d.DECL.name;
                if(realt)
                    s->var_type = realt->var_type;
                else
                    s->var_type = c->d.DECL.type;
                HASH_ADD_KEYPTR(hh, env_vars, s->name, strlen(s->name), s);
                print_cmd(c->d.DECL.body, tns);
                HASH_DEL(env_vars, s);
                free(s);
            }
            printf(")");
            break;
        case T_ASGN:
            printf("ASGN(");
            print_expr(c->d.ASGN.left);
            printf(",");
            print_expr(c->d.ASGN.right);
            printf(")");
            break;
        case T_SEQ:
            printf("SEQ(");
            print_cmd(c->d.SEQ.left, tns);
            printf(",");
            print_cmd(c->d.SEQ.right, tns);
            printf(")");
            break;
        case T_IF:
            printf("IF(");
            print_expr(c->d.IF.cond);
            printf(",");
            print_cmd(c->d.IF.left, tns);
            printf(",");
            print_cmd(c->d.IF.right, tns);
            printf(")");
            break;
        case T_WHILE:
            printf("WHILE(");
            print_expr(c->d.WHILE.cond);
            printf(",");
            print_cmd(c->d.WHILE.body, tns);
            printf(")");
            break;
        case T_FOR:
            printf("FOR(");
            print_cmd(c->d.FOR.init, tns);
            printf(",");
            print_expr(c->d.FOR.cond);
            printf(",");
            print_cmd(c->d.FOR.incr, tns);
            printf(",");
            print_cmd(c->d.FOR.body, tns);
            printf(")");
            break;
        case T_DO_WHILE:
            printf("DO_WHILE(");
            print_cmd(c->d.DO_WHILE.body, tns);
            printf(",");
            print_expr(c->d.DO_WHILE.cond);
            printf(")");
            break;
        case T_PROC:
            printf("PROC(%s", c->d.PROC.name);
            print_expr_list(c->d.PROC.args);
            printf(")");
            break;
        case T_BREAK:
            printf("BREAK");
            break;
        case T_CONTINUE:
            printf("CONTINUE");
            break;
        case T_RETURN:
            printf("RETURN");
            break;
    }
}

// 实例化函数体
void ins_cmd(struct cmd * c, struct decl_var *env_typename){
    switch (c->t) {
        case T_DECL: {
            struct decl_var *realt = NULL;
            if (c->d.DECL.type->t == T_TEMPLATE_TYPE) {
                HASH_FIND_STR(env_typename, c->d.DECL.type->d.TEMPLATE_TYPE.typename, realt);
            }
            struct decl_var *s;
            HASH_FIND_STR(env_vars, c->d.DECL.name, s);
            if (s) {
                struct type *t = s->var_type;
                if (realt)
                    s->var_type = realt->var_type;
                else
                    s->var_type = c->d.DECL.type;
                ins_cmd(c->d.DECL.body, env_typename);
                s->var_type = t;
            } else {
                s = (struct decl_var *) malloc(sizeof(struct decl_var));
                s->name = c->d.DECL.name;
                if (realt)
                    s->var_type = realt->var_type;
                else
                    s->var_type = c->d.DECL.type;
                HASH_ADD_KEYPTR(hh, env_vars, s->name, strlen(s->name), s);
                ins_cmd(c->d.DECL.body, env_typename);
                HASH_DEL(env_vars, s);
                free(s);
            }
        }
            break;
        case T_ASGN: {
            struct type *t1 = ins_expr(c->d.ASGN.left, env_typename);
            struct type *t2 = ins_expr(c->d.ASGN.right, env_typename);
            if (t1->t != t2->t) {
                if (t2->t == T_PTR_INT && t2->d.PTR_INT.num_of_ptr == 0) {
                    printf("[Warning] Conversion from int to ");
                    print_type(t1, env_typename);
                    printf("\n");
                } else {
                    printf("Error28: Cannot convert from ");
                    print_type(t2, env_typename);
                    printf(" to ");
                    print_type(t1, env_typename);
                    printf("\n");
                    exit(0);
                }
            }
            break;
        }
        case T_SEQ:
            ins_cmd(c->d.SEQ.left, env_typename);
            ins_cmd(c->d.SEQ.right, env_typename);
            break;
        case T_IF:
            ins_expr(c->d.IF.cond, env_typename);
            ins_cmd(c->d.IF.left, env_typename);
            ins_cmd(c->d.IF.right, env_typename);
            break;
        case T_WHILE:
            ins_expr(c->d.WHILE.cond, env_typename);
            ins_cmd(c->d.WHILE.body, env_typename);
            break;
        case T_FOR:
            ins_cmd(c->d.FOR.init, env_typename);
            ins_expr(c->d.FOR.cond, env_typename);
            ins_cmd(c->d.FOR.incr, env_typename);
            ins_cmd(c->d.FOR.body, env_typename);
            break;
        case T_DO_WHILE:
            ins_cmd(c->d.DO_WHILE.body, env_typename);
            ins_expr(c->d.DO_WHILE.cond, env_typename);
            break;
        case T_PROC: {
            struct decl_proc *p;
            HASH_FIND_STR(env_procs, c->d.PROC.name, p);
            if (p) {
                  ins_proc(c->d.PROC.args, p->it, env_typename);
//                struct type_name_list *inst_args = ins_proc(c->d.PROC.args, p->it, env_typename);
//                struct instantiated_proc_list *list_it;
//                bool flag = 0;
//                for (list_it = IPL; list_it != NULL; list_it = list_it->next) {
//                    if (strcmp(list_it->data->name, c->d.PROC.name) == 0) {
//                        if (cmp_type_name_list(list_it->data->args, inst_args)) {
//                            flag = 1;
//                            break;
//                        }
//                    }
//                }
//                if (flag)break;
//                struct instantiated_proc_list *new_list_it = malloc(sizeof(struct instantiated_proc_list));
//                new_list_it->next = NULL;
//                struct instantiated_proc *new_data = malloc(sizeof(struct instantiated_proc));
//                new_data->name = c->d.PROC.name;
//                new_data->args = inst_args;
//                new_list_it->data = new_data;
//                list_it=IPL;
//                IPL = new_list_it;
//                IPL->next = list_it;
//                ins_glob_item(p->it, inst_args);
            } else {
                printf("\nError11: procedure %s not declared\n\n", c->d.PROC.name);
                exit(0);
            }
        }
            break;
        case T_BREAK:
            break;
        case T_CONTINUE:
            break;
        case T_RETURN:
            break;
    }
}

void _print_var_list(struct var_list *vs, struct decl_var *tns) {
    if (vs == NULL) {
        return;
    }
    printf(",");
    printf("%s:", vs->name);
    print_type(vs->cur, tns);
    _print_var_list(vs->next, tns);
}

void print_var_list(struct var_list *vs, struct decl_var *tns) {
    if (vs == NULL) {
        return;
    }
    printf("%s:", vs->name);
    print_type(vs->cur, tns);
    _print_var_list(vs->next, tns);
}

// void _print_temp_var_list(struct temp_var_list *vs) {
//     if (vs == NULL) {
//         return;
//     }
//     printf(",");
//     printf("%s:", vs->name);
//     if (vs->solved) {
//         print_type(vs->cur);
//     } else {
//         printf("%s", vs->tpname);
//     }
//     _print_temp_var_list(vs->next);
// }

void print_glob_item(struct glob_item *g) {
    switch (g->t) {
        case T_FUNC_DEF:
            print_type(g->d.FUNC_DEF.return_type, NULL);
            printf(" %s(", g->d.FUNC_DEF.name);
            print_var_list(g->d.FUNC_DEF.args, NULL);
            printf(")\n  ");
            struct decl_fun *f;
            HASH_FIND_STR(env_funs, g->d.FUNC_DEF.name, f);
            if(f){
                printf("\nError12: redeclaration of function %s\n\n", g->d.FUNC_DEF.name);
                exit(0);
            }
            f=(struct decl_fun *)malloc(sizeof(struct decl_fun));
            f->is_template = false;
            f->it = g;
            f->name = g->d.FUNC_DEF.name;
            HASH_ADD_KEYPTR(hh, env_funs, f->name, strlen(f->name), f);
            print_cmd(g->d.FUNC_DEF.body, NULL);
            printf("\n\n");
            return;
        case T_TEMP_FUNC_DEF:
            printf("TEMPLATE(");
            print_type_name_list(g->d.TEMP_FUNC_DEF.temp_types);
            printf(")\n");
            struct decl_fun *f1;
            HASH_FIND_STR(env_funs, g->d.TEMP_FUNC_DEF.name, f1);
            if(f1){
                printf("\nError13: redeclaration of function %s\n\n", g->d.TEMP_FUNC_DEF.name);
                exit(0);
            }
            f1=(struct decl_fun *)malloc(sizeof(struct decl_fun));
            f1->is_template = true;
            f1->it = g;
            f1->name = g->d.TEMP_FUNC_DEF.name;
            HASH_ADD_KEYPTR(hh, env_funs, f1->name, strlen(f1->name), f1);
            print_type(g->d.TEMP_FUNC_DEF.return_type, NULL);
            printf(" %s(", g->d.TEMP_FUNC_DEF.name);
            print_var_list(g->d.TEMP_FUNC_DEF.args, NULL);
            printf(")\n  ");
            print_cmd(g->d.TEMP_FUNC_DEF.body, NULL);
            printf("\n\n");
            return;
        case T_PROC_DEF:
            printf("void %s(", g->d.PROC_DEF.name);
            print_var_list(g->d.PROC_DEF.args, NULL);
            printf(")\n  ");
            struct decl_proc *p;
            HASH_FIND_STR(env_procs, g->d.PROC_DEF.name, p);
            if(p){
                printf("\nError14: redeclaration of procedure %s\n\n", g->d.PROC_DEF.name);
                exit(0);
            }
            p=(struct decl_proc *)malloc(sizeof(struct decl_proc));
            p->is_template = false;
            p->it = g;
            p->name = g->d.PROC_DEF.name;
            HASH_ADD_KEYPTR(hh, env_procs, p->name, strlen(p->name), p);
            print_cmd(g->d.PROC_DEF.body,NULL);
            printf("\n\n");
            return;
        case T_TEMP_PROC_DEF:
            printf("TEMPLATE(");
            print_type_name_list(g->d.TEMP_PROC_DEF.temp_types);
            printf(")\n");
            struct decl_proc *p1;
            HASH_FIND_STR(env_procs, g->d.TEMP_PROC_DEF.name, p1);
            if(p1){
                printf("\nError15: redeclaration of procedure %s\n\n", g->d.TEMP_PROC_DEF.name);
                exit(0);
            }
            p1=(struct decl_proc *)malloc(sizeof(struct decl_proc));
            p1->is_template = true;
            p1->it = g;
            p1->name = g->d.TEMP_PROC_DEF.name;
            HASH_ADD_KEYPTR(hh, env_procs, p1->name, strlen(p1->name), p1);
            printf("void %s(", g->d.TEMP_PROC_DEF.name);
            print_var_list(g->d.TEMP_PROC_DEF.args, NULL);
            printf(")\n  ");
            print_cmd(g->d.TEMP_PROC_DEF.body, NULL);
            printf("\n\n");
            return;
        case T_GLOB_VAR:
            printf("DECL(");
            printf("%s:", g->d.GLOB_VAR.name);
            print_type(g->d.GLOB_VAR.var_type, NULL);
            printf(")");
            struct decl_var *s;
            HASH_FIND_STR(env_vars, g->d.GLOB_VAR.name, s);
            if(s){
                printf("\nError16: redeclaration of variable %s\n\n", g->d.GLOB_VAR.name);
                exit(0);
            }
            s=(struct decl_var *)malloc(sizeof(struct decl_var));
            s->name = g->d.GLOB_VAR.name;
            s->var_type = g->d.GLOB_VAR.var_type;
            HASH_ADD_KEYPTR(hh, env_vars, s->name, strlen(s->name), s);
            printf("\n\n");
            return;
    }
}

// 实例化函数体。现在应该是可以直接调用ins_fun和ins_proc了，只有main函数要用到这个
void ins_glob_item(struct glob_item *g, struct type_name_list *tnl){
    switch(g->t){
        case T_FUNC_DEF:
            ins_cmd(g->d.FUNC_DEF.body, NULL);
            return;
        case T_TEMP_FUNC_DEF:
            printf("Error62: ins_glob_item should not be called in this way\n");
            exit(0);
//        {
//            struct decl_var *tns = NULL;
//            for (struct type_name_list *it = tnl; it != NULL; it = it->next) {
//                if (it->inst_type == NULL) {
//                    printf("Error17: template type %s not instantiated in function %s\n", it->name,
//                           g->d.TEMP_FUNC_DEF.name);
//                    exit(0);
//                }
//                struct decl_var *tn;
//                HASH_FIND_STR(tns, it->name, tn);
//                if (tn) {
//                    printf("Error18: redeclaration of template type %s in function %s\n", it->name,
//                           g->d.TEMP_FUNC_DEF.name);
//                    exit(0);
//                }
//                tn = (struct decl_var *) malloc(sizeof(struct decl_var));
//                tn->name = it->name;
//                tn->var_type = it->inst_type;
//                HASH_ADD_KEYPTR(hh, tns, tn->name, strlen(tn->name), tn);
//            }
//            for (struct instantiated_func_list *ifl = IFL; ifl != NULL; ifl = ifl->next) {
//                if (strcmp(ifl->data->name, g->d.TEMP_FUNC_DEF.name) == 0) {
//                    for (struct type_name_list *it1 = ifl->data->args, *it2 = tnl;
//                         it1 != NULL && it2 != NULL; it1 = it1->next, it2 = it2->next) {
//                        if (!cmp_type(it1->inst_type, it2->inst_type)) {
//                            ins_cmd(g->d.TEMP_FUNC_DEF.body, tns);
//                            return;
//                        }
//                    }
//                }
//            }
//        }
            return;
        case T_PROC_DEF:
            ins_cmd(g->d.PROC_DEF.body, NULL);
            return;
        case T_TEMP_PROC_DEF:
            printf("Error62: ins_glob_item should not be called in this way\n");
            exit(0);
//        {
//            struct decl_var *tns1 = NULL;
//            for (struct type_name_list *it = tnl; it != NULL; it = it->next) {
//                if (it->inst_type == NULL) {
//                    printf("Error19: template type %s not instantiated in procedure %s\n", it->name,
//                           g->d.TEMP_PROC_DEF.name);
//                    exit(0);
//                }
//                struct decl_var *tn;
//                HASH_FIND_STR(tns1, it->name, tn);
//                if (tn) {
//                    printf("Error20: redeclaration of template type %s in procedure %s\n", it->name,
//                           g->d.TEMP_PROC_DEF.name);
//                    exit(0);
//                }
//                tn = (struct decl_var *) malloc(sizeof(struct decl_var));
//                tn->name = it->name;
//                tn->var_type = it->inst_type;
//                HASH_ADD_KEYPTR(hh, tns1, tn->name, strlen(tn->name), tn);
//            }
//            for (struct instantiated_proc_list *ipl = IPL; ipl != NULL; ipl = ipl->next) {
//                if (strcmp(ipl->data->name, g->d.TEMP_PROC_DEF.name) == 0) {
//                    for (struct type_name_list *it1 = ipl->data->args, *it2 = tnl;
//                         it1 != NULL && it2 != NULL; it1 = it1->next, it2 = it2->next) {
//                        if (!cmp_type(it1->inst_type, it2->inst_type)) {
//                            printf(" %s(", g->d.TEMP_PROC_DEF.name);
//                            print_var_list(g->d.TEMP_PROC_DEF.args, tns1);
//                            printf(")\n  ");
//                            print_cmd(g->d.TEMP_PROC_DEF.body, tns1);
//                            printf("\n\n");
//                            ins_cmd(g->d.TEMP_PROC_DEF.body, tns1);
//                            return;
//                        }
//                    }
//                }
//            }
//        }
            return;
        case T_GLOB_VAR:
            return;
    }
}

void print_glob_item_list(struct glob_item_list *gs) {
    if (gs == NULL) {
        return;
    }
    print_glob_item(gs->data);
    print_glob_item_list(gs->next);
}

void ins_glob_item_list(struct glob_item_list *gs) {
    struct decl_proc *p;
    for (p = env_procs; p != NULL; p= p->hh.next) {
        printf("proc name: %s\n", p->name);
    }
    struct decl_fun *f;
    for (f = env_funs; f != NULL; f= f->hh.next) {
        printf("func name: %s\n", f->name);
    }
    HASH_FIND_STR(env_procs, "main", p);
    if (p == NULL) {
        printf("Error21: no main function!\n");
        exit(0);
    }
    IPL=NULL;
    IFL=NULL;
    ins_glob_item(p->it, NULL);
    for(struct instantiated_proc_list* ipl = IPL; ipl!=NULL; ipl=ipl->next){
        struct decl_proc *f;
        HASH_FIND_STR(env_procs, ipl->data->name, f);
        if(f==NULL){
            printf("Error22 in instantiation: no procedure %s\n", ipl->data->name);
            exit(0);
        }
        printf("proc %s [", ipl->data->name);
        for(struct type_name_list* it=ipl->data->args;it!=NULL;it=it->next){
            if(it!=ipl->data->args)
                printf(",");
            printf("%s->", it->name);
            print_type(it->inst_type, NULL);
        }
        printf("]\n");
    }
    for(struct instantiated_func_list* ifl = IFL; ifl!=NULL; ifl=ifl->next){
        struct decl_fun *f;
        HASH_FIND_STR(env_funs, ifl->data->name, f);
        if(f==NULL){
            printf("Error23 in instantiation: no function %s\n", ifl->data->name);
            exit(0);
        }
        printf("func %s [", ifl->data->name);
        for(struct type_name_list* it=ifl->data->args;it!=NULL;it=it->next){
            if(it!=ifl->data->args)
                printf(",");
            printf("%s->", it->name);
            print_type(it->inst_type, NULL);
        }
        printf("]\n");
    }
}
