# CS2205-Project

项目地址：https://github.com/wty500/CS2205-Project

## 题目：带函数指针与类型多态的程序语言的词法分析、语法分析与类型多态展开

> 这个任务中，你需要在 WhileF 语言中加入函数指针、基本类型系统与类型多态。该语言的类型包括整数类型、某类型的指针类型与基于特定参数与返回值类型的函数指针类型，声明变量时需要使用 `var` 关键字 + 类型 + 变量名，类型多态使用类似 C++ 语言中 template 的语法表示。
> - 要求1：在 WhileF 语言中加入函数指针与基本类型系统，并完成词法分析、语法分析与语法树输出。
> - 要求2：进一步加入类型多态，并完成词法分析、语法分析与语法树输出。
> - 要求3：实现类型检查，根据 main 函数的需要，将类型多态展开，不能展开成为有穷多个副本的，产生报错信息。

**目前，我们已完成全部三个要求。**

## 要求1

在我们的类型系统中，声明变量的语句类似于：（实际不能有注释）

```C
int f(int a,int b){ // 普通函数
	...
};
void g(int* a,int* b){ // 普通过程
	...
};

var int ***n; // 多级指针
var void(**p)(int, int**);    // 指向过程指针的指针p
var int*(*fun)(int*, int***); // 函数指针fun，这是一个参数为(int*, int***)，返回值为int*的函数

var int(*)(int, int**) h(int** a, int*** b) { // 返回值为函数指针的函数
    ...
};

void main(){
    ...
}
```



为了达到这个目的，在WhileF语言基础上，我们新增了类型系统，以支持多级指针和函数/过程指针的嵌套，如：

```c
struct type {
    enum TypeType t; // 0: int, 1: func, 2: proc, 3: template type
    union {
      struct {unsigned int num_of_ptr; } PTR_INT;
      struct {struct type * return_type; unsigned int num_of_ptr; struct type_list * arg_list; } PTR_FUNC;
      struct {unsigned int num_of_ptr; struct type_list * arg_list; } PTR_PROC;
      struct {char * typename;unsigned int num_of_ptr;} TEMPLATE_TYPE;
    } d; // data
};
```

我们在lang.y中为parser添加了相应的规则，如；

```
NT_TYPE:
  NT_TYPE1
  {
    $$ = ($1);
  }
| NT_TYPE TM_LEFT_PAREN NT_PTR_NUM TM_RIGHT_PAREN TM_LEFT_PAREN NT_TYPE_LIST TM_RIGHT_PAREN
  {
    $$ = (TPtr_func($1,$3,$6));
  }
;
```

并完成了相应的语法树输出代码，如：

```C
void print_type(struct type * t) {
    // ...
    case T_PTR_FUNC:
            for(int i = 0; i < t -> d.PTR_FUNC.num_of_ptr - 1; i++){
                printf("PTR(");
            }
            printf("FUNPTR");
            printf("((");
            print_type_list(t -> d.PTR_FUNC.arg_list);
            printf("),(");
            print_type(t -> d.PTR_FUNC.return_type);
            printf("))");
            for(int i = 0; i < t -> d.PTR_FUNC.num_of_ptr - 1; i++){
              printf(")");
            }
            break;
    // ...
```

## 要求2

要求2进一步加入了类型多态。

我们的类型多态语句类似于C++的template，如：

```c++
template<typename T, typename U> // 声明这是一个模板函数，用到了T和U两个typename
T fun(T a, U b) {
	...
};
```

这样语法树的输出就是

```
TEMPLATE(T,U)
TN(T) fun(a:TN(T),b:TN(U))
```

当然typename也可以出现在某一个函数指针里面，例如

```
template<typename T, typename U>
T fun(int(*a)(T), U b) {
  var int(**n)(U, T**);
  var void(*x)();
  var T m;
  m = m + 1
};
```

的输出就是

```
TEMPLATE(T,U)
TN(T) fun(a:FUNPTR((TN(T)),INT),b:TN(U))
  DECL(n:PTR(FUNPTR((TN(U),PTR(PTR(TN(T)))),INT)),DECL(x:PROCPTR(),DECL(m:TN(T),ASGN(VAR(m),PLUS(VAR(m),CONST(1))))))
```



为了达成这个目的，我们新增了`TEMPLATE_TYPE`这种类型，撰写了parser规则：

```
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
```

添加了对应的语法树接口，如：

```C++
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
```

和语法树输出，如：

```C++
case T_TEMPLATE_TYPE:
    for (int i = 0; i < t->d.TEMPLATE_TYPE.num_of_ptr; i++) {
        printf("PTR(");
    }
    printf("TN(");
    printf("%s", t->d.TEMPLATE_TYPE.typename);
    printf(")");
    for (int i = 0; i < t->d.TEMPLATE_TYPE.num_of_ptr; i++) {
        printf(")");
    }
    break;
```

## 要求3

这一问码量飙升。

本问要求实例化所有模板函数，并输出所有实例化结果。不能实例化为有穷多个副本的应产生报错信息。

考虑到模板函数可能会递归调用，且实例化类型不同，如：

```C++
template<typename T, typename U, typename V>
void fun2(T x, U y, V z){
  if(x==0) then {return} else {fun2(z*2, x*2, y*2)};
  fun2(x/2, y/2, z/2)
};
```

所以实例化必须遍历整个语法树，并类似解释器一样计算每一个函数返回值、变量、表达式的类型。

在类型检查方面，**我们规定 `int` 可以转换为任何类型；其它类型两两之间都不能转换**。从而，`x/2` 等语句是合法的，即使 `x` 是一个指针。

同时，我们要求程序必须有main函数，且返回值为`void`。合法的程序样例见`sample_srcxx.jtl`。



我们使用哈希表（采用开源项目`uthash.h`）来存储当前环境内的变量、函数声明、过程声明，以便查找；使用链表来存储已经实例化好的函数、过程副本，以备查重。

```C
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

// 当前环境变量/函数/过程声明，使用哈希表存储
struct decl_var *env_vars=NULL;
struct decl_fun *env_funs=NULL;
struct decl_proc *env_procs=NULL;
// 已经实例化过的函数/过程声明，以防递归函数重复实例化，使用链表存储
struct instantiated_proc_list *IPL;
struct instantiated_func_list *IFL;
```

接下来开始实例化。由于涉及到函数的递归调用，实例化与语法树输出不能同步进行，只能另辟蹊径，自顶向下模拟函数运行，构建出可能的递归路径，进而确定每个可能的实参类型组合。

我们新增的函数包括但不限于：

```C
bool cmp_type_name_list(struct type_name_list * tnl1, struct type_name_list * tnl2);
struct type * ins_binop(enum BinOpType op, struct type * t1, struct type * t2);
struct type * ins_unop(enum UnOpType op, struct type * t);
struct type * ins_deref(struct type * t);
struct type * ins_addr_of(struct type * t);
struct decl_var * ins_varname(struct type* t_temp, struct type* t_real, struct type_name_list * typenames, struct decl_var *env_typename);
struct type_list * ins_return_type_list(struct type_list * tl, struct decl_var * env_typename);
struct type * ins_return_type(struct type * t, struct decl_var * env_typename);
struct decl_var *  ins_type_list(struct type_list * tl_temp, struct type_list * tl_real, struct type_name_list * typenames, struct decl_var *env_typename);
struct type * ins_expr(struct expr *e, struct decl_var *env_typename);
void ins_cmd(struct cmd * c, struct decl_var *env_typename);
void ins_proc(struct expr_list * el, struct glob_item * gi, struct decl_var * dv);
struct type * ins_fun(struct expr_list *es, struct glob_item* fun, struct decl_var *env_typename);
void ins_glob_item(struct glob_item *g, struct type_name_list *tnl);
void ins_glob_item_list(struct glob_item_list *gs);
```

我们的实例化过程是：

- 首先从树的根节点出发，寻找void main，调用ins_proc；（ins指instantiate）
- ins_proc遍历procedure的每个实参，推断表达式的类型，并与形参定义的模板类型相比较，以推断出typename是什么。**如果存在一个typename未被推导，或者同时被好几个类型不一实参用到，则报错。**在推导之后，还需更新环境变量env_vars，覆盖原有大环境的声明（如有），并更新env_typename（使用哈希表存储）。然后遍历之前实例化过的所有函数，检查有无函数名完全相同、typename也完全相同的情况。如无，遍历这个procedure的body，以完成body中含有typename的类型推导。遍历完body后，还要回滚所有形参变量声明。ins_fun类似，只是还要多推导一个函数返回值。
- 对于函数或过程body的实例化，则是遍历整个语法树。在每次遇到变量时，查询环境内该变量的类型，并像简单解释器一样模拟变量的声明与析构。如果该变量类型的某一部分包含了模板，则实例化它。在每次遇到赋值语句时，模拟计算等号两边的类型，检查实例化后的类型是否一致，如不一致则报错。遇到seq、if、for等则实例化各个子部分。遇到过程、函数调用则递归实例化。
- 最后遍历由所有实例化过的过程、函数组成的链表，输出。

具体实现实在过长，请参见源代码。

## 当前效果

### 样例00 (sample_src00.jtl)

- 输入

```C
int read_int() {
  var int ***n;
 ***n = read_int()
};

void main() {
  var int ***n;
  ***n = read_int();
  var int **m;
  **m = ***n + 1
}
```

- 输出

```lisp
INT read_int()
  DECL(n:PTR(PTR(PTR(INT))),ASGN(DEREF(DEREF(DEREF(VAR(n)))),FUNC(read_int)))

void main()
  DECL(n:PTR(PTR(PTR(INT))),SEQ(ASGN(DEREF(DEREF(DEREF(VAR(n)))),FUNC(read_int)),DECL(m:PTR(PTR(INT)),ASGN(DEREF(DEREF(VAR(m))),PLUS(DEREF(DEREF(DEREF(VAR(n)))),CONST(1))))))



---Instantiation Result---
proc name: main
func name: read_int
```

  `Instantiation Result` 只是输出了各函数、过程名，说明没有模板函数被实例化。

### 样例01 (sample_src01.jtl)

- 输入

```c
template<typename T, typename U>
void fun(T x, U y){
  if(x==0) then {return} else {fun(y-1, x+1)}
};

void main(int** a, int*** b) {
  var int n;
  n = 0;
  var int **m;
  **m = n + 1;
  fun(**m + 2, m)
}

```

- 输出

```lisp
TEMPLATE(T,U)
void fun(x:TN(T),y:TN(U))
  IF(EQ(VAR(x),CONST(0)),RETURN,PROC(fun,MINUS(VAR(y),CONST(1)),PLUS(VAR(x),CONST(1))))

void main(a:PTR(PTR(INT)),b:PTR(PTR(PTR(INT))))
  DECL(n:INT,SEQ(ASGN(VAR(n),CONST(0)),DECL(m:PTR(PTR(INT)),SEQ(ASGN(DEREF(DEREF(VAR(m))),PLUS(VAR(n),CONST(1))),PROC(fun,PLUS(DEREF(DEREF(VAR(m))),CONST(2)),VAR(m))))))



---Instantiation Result---
proc name: fun
proc name: main
proc fun [T->PTR(PTR(INT)),U->INT]
proc fun [T->INT,U->PTR(PTR(INT))]
```

 ` proc fun [T->PTR(PTR(INT)),U->INT]` 指：T被实例化成了`PTR(PTR(INT))`，U被实例化成了`INT`。

由于proc内部将两个变量轮换，所以还有一个`[T->INT,U->PTR(PTR(INT))]`，这体现了多态性。

## 样例02 (sample_src02.jtl)

- 输入

```C++
template<typename T, typename U>
T fun(int(*a)(T), U b) {
  var int(**n)(U, T**);
  var void(*x)();
  var T m;
  m = m + 1
};

void main() {
  var int(*m)(int);
  var int n;
  var int k;
  k = fun(m, n)
}
```

- 输出

```
TEMPLATE(T,U)
TN(T) fun(a:FUNPTR((TN(T)),INT),b:TN(U))
  DECL(n:PTR(FUNPTR((TN(U),PTR(PTR(TN(T)))),INT)),DECL(x:PROCPTR(),DECL(m:TN(T),ASGN(VAR(m),PLUS(VAR(m),CONST(1))))))

void main()
  DECL(m:FUNPTR((INT),INT),DECL(n:INT,DECL(k:INT,ASGN(VAR(k),FUNC(fun,VAR(m),VAR(n))))))



---Instantiation Result---
proc name: main
func name: fun
func fun [T->INT,U->INT]
```

`PTR(FUNPTR((TN(U),PTR(PTR(TN(T)))),INT))` 指参数列表为`(TN(U),PTR(PTR(TN(T))))`，返回值为`INT`的函数指针的指针，符合预期。

这个程序中，虽然形参本身不是typename，但形参`int(*a)(T)` 里面包裹了`T`。我们使用递归的方式来实例化每一个形参包裹的子类型，解决了无法识别typename的难题。

## 样例04 (sample_src04.jtl)

- 输入

```C++
template<typename T, typename U>
void fun2(T x, U y){
  if(x==0) then {return} else {fun2(y-1, x+1)}
};

template<typename T, typename U>
T fun(T a, U(**b)(U,U)) {
  if(a==0||b==0)then{return}
  else{
    a=fun(a,b-1);
    fun2(b-1,a+1)
  }
};

void main(){
  var int a;
  a=1;
  var int*(**b)(int*,int*);
  b=2;
  var int c;
  c=fun(a,b)
}
```

- 输出

```
TEMPLATE(T,U)
void fun2(x:TN(T),y:TN(U))
  IF(EQ(VAR(x),CONST(0)),RETURN,PROC(fun2,MINUS(VAR(y),CONST(1)),PLUS(VAR(x),CONST(1))))

TEMPLATE(T,U)
TN(T) fun(a:TN(T),b:PTR(FUNPTR((TN(U),TN(U)),TN(U))))  IF(OR(EQ(VAR(a),CONST(0)),EQ(VAR(b),CONST(0))),RETURN,SEQ(ASGN(VAR(a),FUNC(fun,VAR(a),MINUS(VAR(b),CONST(1)))),PROC(fun2,MINUS(VAR(b),CONST(1)),PLUS(VAR(a),CONST(1)))))

void main()
DECL(a:INT,SEQ(ASGN(VAR(a),CONST(1)),DECL(b:PTR(FUNPTR((PTR(INT),PTR(INT)),PTR(INT))),SEQ(ASGN(VAR(b),CONST(2)),DECL(c:INT,ASGN(VAR(c),FUNC(fun,VAR(a),VAR(b))))))))



---Instantiation Result---
proc name: fun2
proc name: main
func name: fun
[Warning] Conversion from int to PTR(FUNPTR((PTR(INT),PTR(INT)),PTR(INT)))
proc fun2 [T->INT,U->PTR(FUNPTR((PTR(INT),PTR(INT)),PTR(INT)))]
proc fun2 [T->PTR(FUNPTR((PTR(INT),PTR(INT)),PTR(INT))),U->INT]
```

由于我们支持从int到任何类型的转换，这边报的是warning而不是error。

其余细节不再赘述，请参见各样例文件。
