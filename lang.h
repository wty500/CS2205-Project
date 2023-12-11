#ifndef LANG_H_INCLUDED
#define LANG_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

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
  T_PROC_DEF,
  T_GLOB_VAR
};

enum TypeType {
    T_PTR_INT,
    T_PTR_FUNC,
    T_PTR_PROC
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

struct glob_item {
  enum GlobItemType t;
  union {
    struct {struct type * return_type; char * name; struct var_list * args; struct cmd * body; } FUNC_DEF;
    struct {char * name; struct var_list * args; struct cmd * body; } PROC_DEF;
    struct {struct type * var_type; char * name;} GLOB_VAR;
  } d;
};

struct glob_item_list {
  struct glob_item * data;
  struct glob_item_list * next;
};


struct type * TPtr_int();
struct type * TPtr_int_1(struct type * last);
struct type * TPtr_func(struct type * return_type, struct ptr_num * num_ptr, struct type_list * list);
struct type * TPtr_proc(struct ptr_num * num_ptr, struct type_list * list);
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
struct glob_item * TGlobVar(struct type * var_type, char * name);
struct glob_item * TGlobVar_1(struct type * return_type, struct ptr_num * num_ptr, struct type_list * list, char * name); //global var并且形式为函数指针
struct glob_item * TGlobVar_2(struct ptr_num * num_ptr, struct type_list * list, char * name); //global var并且形式为过程指针
struct glob_item * TFuncDef(struct type * return_type, char * name, struct var_list * args,
                            struct cmd * body);
struct glob_item * TProcDef(char * name, struct var_list * args,
                            struct cmd * body);
struct glob_item_list * TGNil();
struct glob_item_list * TGCons(struct glob_item * data,
                               struct glob_item_list * next);

void print_type(struct type * t);
void print_type_list(struct type_list * tl);
void print_binop(enum BinOpType op);
void print_unop(enum UnOpType op);
void print_expr(struct expr * e);
void print_expr_list(struct expr_list * es);
void print_cmd(struct cmd * c);
void print_var_list(struct var_list * vs);
void print_glob_item(struct glob_item * g);
void print_glob_item_list(struct glob_item_list * gs);

#endif // LANG_H_INCLUDED
