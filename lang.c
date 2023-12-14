#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lang.h"

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

struct var_list *new_var_list_ptr() {
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

struct type * TIdent(char * name){
    struct type *res = new_type();
    res->t = T_TEMPLATE_TYPE;
    res->d.TEMPLATE_TYPE.typename = name;
    return res;
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

struct cmd *
TDecl_1(struct type *return_type, struct ptr_num *num_ptr, struct type_list *list, char *name, struct cmd *body) {
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
    struct var_list *res = new_var_list_ptr();
    res->cur = cur;
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

void print_type(struct type *t) {
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
            printf("),(");
            print_type(t->d.PTR_FUNC.return_type);
            printf("))");
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
            printf("TN(");
            printf("%s", t->d.TEMPLATE_TYPE.typename);
            printf(")");
            break;
    }
}

void _print_type_list(struct type_list *tl) {
    if (tl == NULL) {
        return;
    }
    printf(",");
    print_type(tl->data);
    _print_type_list(tl->next);
}

void print_type_list(struct type_list *tl) {
    if (tl == NULL) {
        return;
    }
    print_type(tl->data);
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

void print_expr_list(struct expr_list *es) {
    if (es == NULL) {
        return;
    }
    printf(",");
    print_expr(es->data);
    print_expr_list(es->next);
}

void print_cmd(struct cmd *c) {
    switch (c->t) {
        case T_DECL:
            printf("DECL(");
            printf("%s:", c->d.DECL.name);
            print_type(c->d.DECL.type);
            printf(",");
            print_cmd(c->d.DECL.body);
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
            print_cmd(c->d.SEQ.left);
            printf(",");
            print_cmd(c->d.SEQ.right);
            printf(")");
            break;
        case T_IF:
            printf("IF(");
            print_expr(c->d.IF.cond);
            printf(",");
            print_cmd(c->d.IF.left);
            printf(",");
            print_cmd(c->d.IF.right);
            printf(")");
            break;
        case T_WHILE:
            printf("WHILE(");
            print_expr(c->d.WHILE.cond);
            printf(",");
            print_cmd(c->d.WHILE.body);
            printf(")");
            break;
        case T_FOR:
            printf("FOR(");
            print_cmd(c->d.FOR.init);
            printf(",");
            print_expr(c->d.FOR.cond);
            printf(",");
            print_cmd(c->d.FOR.incr);
            printf(",");
            print_cmd(c->d.FOR.body);
            printf(")");
            break;
        case T_DO_WHILE:
            printf("DO_WHILE(");
            print_cmd(c->d.DO_WHILE.body);
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

void _print_var_list(struct var_list *vs) {
    if (vs == NULL) {
        return;
    }
    printf(",");
    printf("%s:", vs->name);
    print_type(vs->cur);
    _print_var_list(vs->next);
}

void print_var_list(struct var_list *vs) {
    if (vs == NULL) {
        return;
    }
    printf("%s:", vs->name);
    print_type(vs->cur);
    _print_var_list(vs->next);
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
            print_type(g->d.FUNC_DEF.return_type);
            printf(" %s(", g->d.FUNC_DEF.name);
            print_var_list(g->d.FUNC_DEF.args);
            printf(")\n  ");
            print_cmd(g->d.FUNC_DEF.body);
            printf("\n\n");
            return;
        case T_TEMP_FUNC_DEF:
            printf("TEMPLATE(");
            print_type_name_list(g->d.TEMP_FUNC_DEF.temp_types);
            printf(")\n");
            print_type(g->d.TEMP_FUNC_DEF.return_type);
            printf(" %s(", g->d.TEMP_FUNC_DEF.name);
            print_var_list(g->d.TEMP_FUNC_DEF.args);
            printf(")\n  ");
            print_cmd(g->d.TEMP_FUNC_DEF.body);
            printf("\n\n");
            return;
        case T_PROC_DEF:
            printf("void %s(", g->d.PROC_DEF.name);
            print_var_list(g->d.PROC_DEF.args);
            printf(")\n  ");
            print_cmd(g->d.PROC_DEF.body);
            printf("\n\n");
            return;
        case T_TEMP_PROC_DEF:
            printf("TEMPLATE(");
            print_type_name_list(g->d.TEMP_PROC_DEF.temp_types);
            printf(")\n");
            printf("void %s(", g->d.TEMP_PROC_DEF.name);
            print_var_list(g->d.TEMP_PROC_DEF.args);
            printf(")\n  ");
            print_cmd(g->d.TEMP_PROC_DEF.body);
            printf("\n\n");
            return;
        case T_GLOB_VAR:
            printf("DECL(");
            print_type(g->d.GLOB_VAR.var_type);
            printf(",%s", g->d.GLOB_VAR.name);
            printf(")");
            printf("\n\n");
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

