%{
	// this part is copied to the beginning of the parser 
	#include <stdio.h>
	#include "lang.h"
	#include "lexer.h"
	void yyerror(char *);
	int yylex(void);
        struct glob_item_list * root;
%}

%union {
unsigned int n;
char * i;
struct expr * e;
struct type * t;
struct type_list * tl;
// struct temp_var_list * tvl;
struct ptr_num * pn;
struct expr_list * el;
struct var_list * vl;
struct type_name_list * tnl;
struct glob_item * gi;
struct glob_item_list * gil;
struct cmd * c;
void * none;
}

// Terminals
%token <n> TM_NAT   // 常数
%token <i> TM_IDENT // 变量名
%token <none> TM_LEFT_BRACE TM_RIGHT_BRACE
%token <none> TM_LEFT_PAREN TM_RIGHT_PAREN
%token <none> TM_SEMICOL TM_COMMA
%token <none> TM_TEMPLATE TM_TYPENAME
%token <none> TM_VAR TM_PROC_DEF
%token <none> TM_CONTINUE TM_BREAK TM_RETURN
%token <none> TM_INT TM_IF TM_THEN TM_ELSE TM_WHILE TM_DO TM_FOR
%token <none> TM_ASGNOP
%token <none> TM_OR
%token <none> TM_AND
%token <none> TM_NOT
%token <none> TM_LT TM_LE TM_GT TM_GE TM_EQ TM_NE
%token <none> TM_PLUS TM_MINUS
%token <none> TM_MUL TM_DIV TM_MOD
%token <none> TM_UMINUS TM_DEREF TM_ADDR_OF

// Nonterminals
%type <gil> NT_WHOLE
%type <c> NT_CMD
/* %type <e> NT_P_IDENT // pointer to pointer to ... to ident */
%type <t> NT_TYPE // int, int*, int** ...... and all kinds of pointer to function
%type <t> NT_TYPE1 // int, int*, int** ......
%type <t> NT_intTYPE // T, T*, T** ......
%type <t> NT_TTYPE
%type <pn> NT_PTR_NUM // the number of *
%type <tl> NT_TYPE_LIST
%type <e> NT_EXPR0
%type <e> NT_EXPR1
%type <e> NT_EXPR
%type <el> NT_EXPR_LIST
%type <vl> NT_VAR_LIST
%type <tnl> NT_TYPENAME_LIST
/* %type <tvl> NT_TMP_VAR_LIST */
%type <gi> NT_GLOBAL_ITEM
%type <gil> NT_GLOBAL_ITEM_LIST

// Priority
%right TM_SEMICOL TM_COMMA
%nonassoc TM_ASGNOP
%left TM_OR
%left TM_AND
%left TM_LT TM_LE TM_GT TM_GE TM_EQ TM_NE
%left TM_PLUS TM_MINUS
%left TM_MUL TM_DIV TM_MOD
%left TM_NOT
%left TM_LEFT_PAREN TM_RIGHT_PAREN
%right TM_UMINUS TM_DEREF TM_ADDR_OF

%%

NT_WHOLE:
  NT_GLOBAL_ITEM_LIST
  {
    $$ = ($1);
    root = $$;
  }
;

NT_GLOBAL_ITEM_LIST:
  NT_GLOBAL_ITEM TM_SEMICOL NT_GLOBAL_ITEM_LIST
  {
    $$ = (TGCons($1,$3));
  }
| NT_GLOBAL_ITEM
  {
    $$ = (TGCons($1,TGNil()));
  }
;

NT_PTR_NUM:
  TM_MUL
  {
  $$ = (TPtr_num());
  }
| NT_PTR_NUM TM_MUL
  {
  $$ = (TPtr_num_1($1));
  }

NT_TYPE_LIST:
  NT_TYPE TM_COMMA NT_TYPE_LIST
  {
    $$ = (TTCons($1,$3));
  }
| NT_TYPE
  {
    $$ = (TTCons($1,TTNil()));
  }
;

NT_TYPE: // int, int*, int** ......, T, T*, T** ......, and all kinds of pointer to function
  NT_TYPE1
  {
    $$ = ($1);
  }
| NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN
  {
    $$ = (TPtr_func($1,$3,$6));
  }
| TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN
  {
    $$ = (TPtr_proc($3,$6));
  }
;

NT_TYPE1: // int, int*, int** or T, T*, T** ......
  NT_intTYPE
  {
    $$ = ($1);
  }
| NT_TTYPE
  {
    $$ = ($1);
  }
;

NT_intTYPE:
  NT_intTYPE TM_MUL
  {
    $$ = (TPtr_int_1($1));
  }
| TM_INT
  {
    $$ = (TPtr_int());
  }
;

NT_TTYPE:
  NT_TTYPE TM_MUL
  {
    $$ = (TPtr_T_1($1));
  }
| TM_IDENT
  {
    $$ = (TPtr_T($1));
  }
;


NT_VAR_LIST:
  NT_TYPE1 TM_IDENT TM_COMMA NT_VAR_LIST
  {
    $$ = (TVCons($1,$2,$4));
  }
| NT_TYPE1 TM_IDENT
  {
    $$ = (TVCons($1,$2,TVNil()));
  }
| NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN TM_RIGHT_PAREN
  {
    $$ = (TVCons_1($1,$3,TTNil(),$4,TVNil()));
  }
| NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN
  {
    $$ = (TVCons_1($1,$3,$7,$4,TVNil()));
  }
| NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN TM_RIGHT_PAREN TM_COMMA NT_VAR_LIST
  {
    $$ = (TVCons_1($1,$3,TTNil(),$4,$9));
  }
| NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN TM_COMMA NT_VAR_LIST
  {
    $$ = (TVCons_1($1,$3,$7,$4,$10));
  }
| TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN TM_RIGHT_PAREN
  {
    $$ = (TVCons_2($3,TTNil(),$4,TVNil()));
  }
| TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN
  {
    $$ = (TVCons_2($3,$7,$4,TVNil()));
  }
| TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN TM_RIGHT_PAREN TM_COMMA NT_VAR_LIST
  {
    $$ = (TVCons_2($3,TTNil(),$4,$9));
  }
| TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN TM_COMMA NT_VAR_LIST
  {
    $$ = (TVCons_2($3,$7,$4,$10));
  }
;

/* NT_TMP_VAR_LIST:
  NT_TYPE1 TM_IDENT TM_COMMA NT_TMP_VAR_LIST
  {
    $$ = (TTVCons(1,$1,StrNil(),$2,$4));
  }
| NT_TYPE1 TM_IDENT
  {
    $$ = (TTVCons(1,$1,StrNil(),$2,TTVNil()));
  }
| TM_IDENT TM_COL TM_IDENT TM_COMMA NT_TMP_VAR_LIST
  {
    $$ = (TTVCons(0,TPNil(),$1,$3,$5));
  }
  | TM_IDENT TM_COL TM_IDENT
  {
    $$ = (TTVCons(0,TPNil(),$1,$3,TTVNil()));
  }
; */

NT_EXPR_LIST:
  NT_EXPR TM_COMMA NT_EXPR_LIST
  {
    $$ = (TECons($1,$3));
  }
| NT_EXPR
  {
    $$ = (TECons($1,TENil()));
  }
;

NT_TYPENAME_LIST:
  TM_TYPENAME TM_IDENT TM_COMMA NT_TYPENAME_LIST
  {
    $$ = (TNLCons($2,$4));
  }
| TM_TYPENAME TM_IDENT
  {
    $$ = (TNLCons($2,TNLNil()));
  }
;

NT_GLOBAL_ITEM:
  TM_VAR NT_TYPE1 TM_IDENT
  {
    $$ = (TGlobVar($2,$3));
  }
| TM_VAR NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN TM_RIGHT_PAREN
  {
    $$ = (TGlobVar_1($2,$4,TTNil(),$5));
  }
| TM_VAR NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN
  {
    $$ = (TGlobVar_1($2,$4,$8,$5));
  }
| TM_VAR TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN TM_RIGHT_PAREN
  {
    $$ = (TGlobVar_2($4,TTNil(),$5));
  }
| TM_VAR TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN
  {
    $$ = (TGlobVar_2($4,$8,$5));
  }
| TM_TEMPLATE TM_LT NT_TYPENAME_LIST TM_GT NT_TYPE TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE
  {
    $$ = (TTemFuncDef($3,$5,$6,TVNil(),$10));
  }
| TM_TEMPLATE TM_LT NT_TYPENAME_LIST TM_GT NT_TYPE TM_IDENT TM_LEFT_PAREN NT_VAR_LIST TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE
  {
    $$ = (TTemFuncDef($3,$5,$6,$8,$11));
  }
| TM_TEMPLATE TM_LT NT_TYPENAME_LIST TM_GT TM_PROC_DEF TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE
  {
    $$ = (TTemProcDef($3,$6,TVNil(),$10));
  }
| TM_TEMPLATE TM_LT NT_TYPENAME_LIST TM_GT TM_PROC_DEF TM_IDENT TM_LEFT_PAREN NT_VAR_LIST TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE
  {
    $$ = (TTemProcDef($3,$6,$8,$11));
  }
| NT_TYPE TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE
  {
    $$ = (TFuncDef($1,$2,TVNil(),$6));
  }
| NT_TYPE TM_IDENT TM_LEFT_PAREN NT_VAR_LIST TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE
  {
    $$ = (TFuncDef($1,$2,$4,$7));
  }
| TM_PROC_DEF TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE
  {
    $$ = (TProcDef($2,TVNil(),$6));
  }
| TM_PROC_DEF TM_IDENT TM_LEFT_PAREN NT_VAR_LIST TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE
  {
    $$ = (TProcDef($2,$4,$7));
  }
;

NT_CMD:
  TM_VAR NT_TYPE1 TM_IDENT TM_SEMICOL NT_CMD
  {
    $$ = (TDecl($2,$3,$5));
  }
| TM_VAR NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN TM_RIGHT_PAREN TM_SEMICOL NT_CMD
  {
    $$ = (TDecl_1($2,$4,TTNil(),$5,$10));
  }
| TM_VAR NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN TM_SEMICOL NT_CMD
  {
    $$ = (TDecl_1($2,$4,$8,$5,$11));
  }
| TM_VAR TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN TM_RIGHT_PAREN TM_SEMICOL NT_CMD
  {
    $$ = (TDecl_2($4,TTNil(),$5,$10));
  }
| TM_VAR TM_PROC_DEF TM_LEFT_PAREN NT_PTR_NUM TM_IDENT TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN TM_SEMICOL NT_CMD
  {
    $$ = (TDecl_2($4,$8,$5,$11));
  }
| NT_EXPR TM_ASGNOP NT_EXPR
  {
    $$ = (TAsgn($1,$3));
  }
| NT_CMD TM_SEMICOL NT_CMD
  {
    $$ = (TSeq($1,$3));
  }
| TM_IF TM_LEFT_PAREN NT_EXPR TM_RIGHT_PAREN TM_THEN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE TM_ELSE TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE
  {
    $$ = (TIf($3,$7,$11));
  }
| TM_WHILE TM_LEFT_PAREN NT_EXPR TM_RIGHT_PAREN TM_DO TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE
  {
    $$ = (TWhile($3,$7));
  }
| TM_FOR TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE TM_LEFT_PAREN NT_EXPR TM_RIGHT_PAREN TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE
  {
    $$ = (TFor($3,$6,$9,$12));
  }
| TM_DO TM_LEFT_BRACE NT_CMD TM_RIGHT_BRACE TM_WHILE TM_LEFT_PAREN NT_EXPR TM_RIGHT_PAREN
  {
    $$ = (TDoWhile($3,$7));
  }
| TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN
  {
    $$ = (TProc($2,TENil()));
  }
| TM_IDENT TM_LEFT_PAREN NT_EXPR_LIST TM_RIGHT_PAREN
  {
    $$ = (TProc($2,$3));
  }
| TM_BREAK
  {
    $$ = (TBreak());
  }
| TM_CONTINUE
  {
    $$ = (TContinue());
  }
| TM_RETURN
  {
    $$ = (TReturn());
  }
;

/* NT_P_IDENT:
  TM_MUL NT_P_IDENT
  {
    $$ = (TPtr($2));
  }
| TM_IDENT
  {
    $$ = (TVar($1));
  } */

NT_EXPR0: // 原子表达式
  TM_NAT
  {
    $$ = (TConst($1));
  }
| TM_LEFT_PAREN NT_EXPR TM_RIGHT_PAREN
  {
    $$ = ($2);
  }
| TM_IDENT
  {
    $$ = (TVar($1));
  }
| TM_IDENT TM_LEFT_PAREN TM_RIGHT_PAREN
  {
    $$ = (TFunc($1,TENil()));
  }
| TM_IDENT TM_LEFT_PAREN NT_EXPR_LIST TM_RIGHT_PAREN
  {
    $$ = (TFunc($1,$3));
  }
;

NT_EXPR1:
  TM_NOT NT_EXPR
  {
    $$ = (TUnOp(T_NOT,$2));
  }
| NT_EXPR0
  {
    $$ = ($1);
  }
;


NT_EXPR:
  NT_EXPR1
  {
    $$ = ($1);
  }
| TM_MINUS NT_EXPR %prec TM_UMINUS
  {
    $$ = (TUnOp(T_UMINUS,$2));
  }
| TM_MUL NT_EXPR  %prec TM_DEREF
  {
    $$ = (TDeref($2));
  }
| TM_ADDR_OF NT_EXPR
  {
    $$ = (TAddrOf($2));
  }
| NT_EXPR TM_MUL NT_EXPR
  {
    $$ = (TBinOp(T_MUL,$1,$3));
  }
| NT_EXPR TM_PLUS NT_EXPR
  {
    $$ = (TBinOp(T_PLUS,$1,$3));
  }
| NT_EXPR TM_MINUS NT_EXPR
  {
    $$ = (TBinOp(T_MINUS,$1,$3));
  }
| NT_EXPR TM_DIV NT_EXPR
  {
    $$ = (TBinOp(T_DIV,$1,$3));
  }
| NT_EXPR TM_MOD NT_EXPR
  {
    $$ = (TBinOp(T_MOD,$1,$3));
  }
| NT_EXPR TM_LT NT_EXPR
  {
    $$ = (TBinOp(T_LT,$1,$3));
  }
| NT_EXPR TM_GT NT_EXPR
  {
    $$ = (TBinOp(T_GT,$1,$3));
  }
| NT_EXPR TM_LE NT_EXPR
  {
    $$ = (TBinOp(T_LE,$1,$3));
  }
| NT_EXPR TM_GE NT_EXPR
  {
    $$ = (TBinOp(T_GE,$1,$3));
  }
| NT_EXPR TM_EQ NT_EXPR
  {
    $$ = (TBinOp(T_EQ,$1,$3));
  }
| NT_EXPR TM_NE NT_EXPR
  {
    $$ = (TBinOp(T_NE,$1,$3));
  }
| NT_EXPR TM_AND NT_EXPR
  {
    $$ = (TBinOp(T_AND,$1,$3));
  }
| NT_EXPR TM_OR NT_EXPR
  {
    $$ = (TBinOp(T_OR,$1,$3));
  }
;


%%

void yyerror(char* s)
{
    fprintf(stderr , "%s\n",s);
}
