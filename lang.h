#ifndef LANG_H_INCLUDED
#define LANG_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib.h"
#include "uthash.h"

struct decl_var {
    const char *name;          /* key */
    struct type * var_type;
    UT_hash_handle hh;         /* makes this structure hashable */
};

struct decl_fun{
    bool is_template;
    const char * name;
    struct glob_item *it;
    UT_hash_handle hh; 
};

struct decl_proc{
    bool is_template;
    const char * name;
    struct glob_item *it;
    UT_hash_handle hh; 
};

enum BinOpType {
  T_PLUS,
  T_MINUS,
  T_MUL,
  T_DIV,
  T_MOD,
  T_LT,
  T_GT,
  T_LE,
  T_GE,
  T_EQ,
  T_NE,
  T_AND,
  T_OR
};

enum UnOpType {
  T_UMINUS,
  T_NOT
};

enum ExprType {
  T_CONST = 0,
  T_VAR,
  T_PTR,
  T_BINOP,
  T_UNOP,
  T_DEREF,
  T_ADDR_OF,
  T_FUNC
};

enum CmdType {
  T_DECL = 0,
  T_ASGN,
  T_SEQ,
  T_IF,
  T_WHILE,
  T_FOR,
  T_DO_WHILE,
  T_PROC,
  T_BREAK,
  T_CONTINUE,
  T_RETURN
};

enum GlobItemType {
  T_FUNC_DEF,
  T_TEMP_FUNC_DEF,
  T_PROC_DEF,
  T_TEMP_PROC_DEF,
  T_GLOB_VAR
};

enum TypeType {
    T_PTR_INT,
    T_PTR_FUNC,
    T_PTR_PROC,
    T_TEMPLATE_TYPE
};

struct type;

struct type_list {
    struct type * data;
    struct type_list * next;
};

struct type {
    enum TypeType t; // 0: int, 1: func, 2: proc
    union {
      struct {unsigned int num_of_ptr; } PTR_INT;
      struct {struct type * return_type; unsigned int num_of_ptr; struct type_list * arg_list; } PTR_FUNC;
      struct {unsigned int num_of_ptr; struct type_list * arg_list; } PTR_PROC;
      struct {char * typename;unsigned int num_of_ptr;} TEMPLATE_TYPE;
    } d; // data
};

struct ptr_num {
    unsigned int num_ptr;
};


struct expr;

struct expr_list {
  struct expr * data;
  struct expr_list * next;
};

struct expr {
  enum ExprType t;
  union {
    struct {unsigned int value; } CONST;
    struct {char * name; } VAR;
    struct {struct expr * arg; } PTR;
    struct {enum BinOpType op; struct expr * left; struct expr * right; } BINOP;
    struct {enum UnOpType op; struct expr * arg; } UNOP;
    struct {struct expr * arg; } DEREF;
    struct {struct expr * arg; } ADDR_OF;
    struct {char * name; struct expr_list * args; } FUNC;
  } d;
};

struct cmd {
  enum CmdType t;
  union {
    struct {struct type * type; char * name; struct cmd * body; } DECL;
    struct {struct expr * left; struct expr * right; } ASGN;
    struct {struct cmd * left; struct cmd * right; } SEQ;
    struct {struct expr * cond; struct cmd * left; struct cmd * right; } IF;
    struct {struct expr * cond; struct cmd * body; } WHILE;
    struct {struct cmd * init; struct expr * cond;
            struct cmd * incr; struct cmd * body; } FOR;
    struct {struct cmd * body; struct expr * cond; } DO_WHILE;
    struct {char * name; struct expr_list * args; } PROC;
    struct {void * none; } BREAK;
    struct {void * none; } CONTINUE;
    struct {void * none; } RETURN;
  } d;
};

struct var_list {
  struct type * cur;
  char * name;
  struct var_list * next;
};

struct type_name_list {
  char * name;
  struct type * inst_type;
  struct type_name_list * next;
};

// struct temp_var_list{
//     bool solved; // 是否已经被实例化
//     struct type * cur; // 变量类型（如果已实例化）
//     char * tpname; // typename名称（如果未实例化）
//     char * name;
//     struct temp_var_list * next;
// };

struct glob_item {
  enum GlobItemType t;
  union {
    struct {struct type * return_type; char * name; struct var_list * templates; struct var_list * args; struct cmd * body; } FUNC_DEF;
    struct {struct type_name_list* temp_types; struct type * return_type; char * name; struct var_list * templates; struct var_list * args; struct cmd * body; } TEMP_FUNC_DEF;
    struct {char * name; struct var_list * args; struct cmd * body; } PROC_DEF;
    struct {struct type_name_list* temp_types;char * name; struct var_list * templates; struct var_list * args; struct cmd * body; } TEMP_PROC_DEF;
    struct {struct type * var_type; char * name;} GLOB_VAR;
  } d;
};

struct instantiated_proc{
    char * name;
    struct type_name_list * args;
};

struct instantiated_proc_list{
    struct instantiated_proc * data;
    struct instantiated_proc_list * next;
};

struct instantiated_func{
    struct type * return_type;
    char * name;
    struct type_name_list * args;
};

struct instantiated_func_list{
    struct instantiated_func * data;
    struct instantiated_func_list * next;
};

struct glob_item_list {
  struct glob_item * data;
  struct glob_item_list * next;
};

char* StrNil();
struct type * TPNil();
struct type * TPtr_int();
struct type * TPtr_int_1(struct type * last);
struct type * TPtr_func(struct type * return_type, struct ptr_num * num_ptr, struct type_list * list);
struct type * TPtr_proc(struct ptr_num * num_ptr, struct type_list * list);
struct type * TPtr_T(char * name);
struct type * TPtr_T_1(struct type * last);
struct ptr_num * TPtrNil();
struct ptr_num * TPtr_num();
struct ptr_num * TPtr_num_1(struct ptr_num * last);
struct type_list * TTNil();
struct type_list * TTCons(struct type * cur, struct type_list * next);

struct expr_list * TENil();
struct expr_list * TECons(struct expr * data, struct expr_list * next);
struct expr * TConst(unsigned int value);
struct expr * TVar(char * name);
struct expr * TPtr(struct expr * arg);
struct expr * TBinOp(enum BinOpType op, struct expr * left,
                     struct expr * right);
struct expr * TUnOp(enum UnOpType op, struct expr * arg);
struct expr * TDeref(struct expr * arg);
struct expr * TAddrOf(struct expr * arg);
struct expr * TFunc(char * name, struct expr_list * args);
struct cmd * TDecl(struct type * type, char * name, struct cmd * body);
struct cmd * TDecl_1(struct type * return_type, struct ptr_num * num_ptr, struct type_list * list, char * name, struct cmd * body);
struct cmd * TDecl_2(struct ptr_num * num_ptr, struct type_list * list, char * name, struct cmd * body);
struct cmd * TAsgn(struct expr * left, struct expr * right);
struct cmd * TSeq(struct cmd * left, struct cmd * right);
struct cmd * TIf(struct expr * cond, struct cmd * left, struct cmd * right);
struct cmd * TWhile(struct expr * cond, struct cmd * body);
struct cmd * TFor(struct cmd * init, struct expr * cond,
                  struct cmd * incr, struct cmd * body);
struct cmd * TDoWhile(struct cmd * body, struct expr * cond);
struct cmd * TProc(char * name, struct expr_list * args);
struct cmd * TBreak();
struct cmd * TContinue();
struct cmd * TReturn();
struct var_list * TVNil();
struct var_list * TVCons(struct type * cur, char * name, struct var_list * next);
struct var_list * TVCons_1(struct type * return_type, struct ptr_num * num_ptr, struct type_list * list, char * name, struct var_list *next);
struct var_list * TVCons_2(struct ptr_num * num_ptr, struct type_list * list, char * name, struct var_list *next);
// struct temp_var_list * TTVNil();
// struct temp_var_list * TTVCons(struct type * cur, char * name, struct temp_var_list * next);
struct type_name_list * TNLNil();
struct type_name_list * TNLCons(char * name, struct type_name_list * next);
struct glob_item * TGlobVar(struct type * var_type, char * name);
struct glob_item * TGlobVar_1(struct type * return_type, struct ptr_num * num_ptr, struct type_list * list, char * name); //global var并且形式为函数指针
struct glob_item * TGlobVar_2(struct ptr_num * num_ptr, struct type_list * list, char * name); //global var并且形式为过程指针
struct glob_item * TFuncDef(struct type * return_type, char * name, struct var_list * args,
                            struct cmd * body);
struct glob_item * TTemFuncDef(struct type_name_list* temp_types, struct type * return_type, char * name, struct var_list * args,
                            struct cmd * body);
struct glob_item * TProcDef(char * name, struct var_list * args,
                            struct cmd * body);
struct glob_item * TTemProcDef(struct type_name_list* temp_types, char * name, struct var_list * args,
                            struct cmd * body);
struct glob_item_list * TGNil();
struct glob_item_list * TGCons(struct glob_item * data,
                               struct glob_item_list * next);

void print_type(struct type *t, struct decl_var *tns); 
bool cmp_type(struct type * t1, struct type * t2);
void print_type_list(struct type_list * tl);
bool cmp_type_list(struct type_list * tl1, struct type_list * tl2);
void print_type_name_list(struct type_name_list * tnl);


bool cmp_type_name_list(struct type_name_list * tnl1, struct type_name_list * tnl2);
struct type * ins_binop(enum BinOpType op, struct type * t1, struct type * t2);
struct type * ins_unop(enum UnOpType op, struct type * t);
struct type * ins_deref(struct type * t);
struct type * ins_addr_of(struct type * t);
void ins_proc(struct expr_list * el, struct glob_item * gi, struct decl_var * dv);
void ins_varname(struct type* t_temp, struct type* t_real, struct type_name_list * typenames, struct decl_var *env_typename);
struct type_list * ins_return_type_list(struct type_list * tl, struct decl_var * env_typename);
struct type * ins_return_type(struct type * t, struct decl_var * env_typename);
void ins_type_list(struct type_list * tl_temp, struct type_list * tl_real, struct type_name_list * typenames, struct decl_var *env_typename);
struct type * ins_expr(struct expr *e, struct decl_var *env_typename);
struct type * ins_fun(struct expr_list *es, struct glob_item* fun, struct decl_var *env_typename);

void print_binop(enum BinOpType op);
void print_unop(enum UnOpType op);
void print_expr(struct expr * e);
void print_expr_list(struct expr_list * es);
void print_cmd(struct cmd *c, struct decl_var *tns);
void ins_cmd(struct cmd * c, struct decl_var *env_typename);
void print_var_list(struct var_list * vs, struct decl_var *tns);
// void print_temp_var_list(struct temp_var_list * vs);
void print_glob_item(struct glob_item * g);
void ins_glob_item(struct glob_item *g, struct type_name_list *tnl);
void print_glob_item_list(struct glob_item_list * gs);
void ins_glob_item_list(struct glob_item_list *gs);

#endif // LANG_H_INCLUDED
