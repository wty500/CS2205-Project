# CS2205-Project

项目地址：https://github.com/wty500/CS2205-Project

## 题目：带函数指针与类型多态的程序语言的词法分析、语法分析与类型多态展开

这个任务中，你需要在 WhileF 语言中加入函数指针、基本类型系统与类型多态。该语言的类型包括整数类型、某类型的指针类型与基于特定参数与返回值类型的函数指针类型，声明变量时需要使用 `var` 关键字 + 类型 + 变量名 **(已更改为直接使用类型+变量名)** ，类型多态使用类似 C++ 语言中 template 的语法表示。
- 要求1：在 WhileF 语言中加入函数指针与基本类型系统，并完成词法分析、语法分析与语法树输出。
- 要求2：进一步加入类型多态，并完成词法分析、语法分析与语法树输出。
- 要求3：实现类型检查，根据 main 函数的需要，将类型多态展开，不能展开成为有穷多个副本的，产生报错信息。

## 进度报告

目前已经完成要求1。

在我们的类型系统中，声明变量的语句类似于：

```C
int f(int a,int b){ // 普通函数
	...
}
void g(int* a,int* b){ // 普通过程
	...
}

int ***n; // 多级指针
void(**p)(int, int**); // 指向过程指针的指针p
int*(*fun)(int*, int***); // 函数指针fun

int(*)(int, int**) main(int** a, int*** b) { // 返回值为函数指针的函数
```



为了达到这个目的，在WhileF语言基础上，我们新增了类型系统，以支持多级指针和函数/过程指针的嵌套，如：

```c
struct type {
    enum TypeType t; // 0: int, 1: func, 2: proc
    union {
      struct {unsigned int num_of_ptr; } PTR_INT;
      struct {struct type * return_type; unsigned int num_of_ptr; struct type_list * arg_list; } PTR_FUNC;
      struct {unsigned int num_of_ptr; struct type_list * arg_list; } PTR_PROC;
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

## 当前效果

### 样例00 (sample_src00.jtl)

- 输入

```C
void main() {
int ***n;
***n = read_int();
int **m;
**m = ***n + 1;
write_int(**m + 2)
}
```

- 输出

```lisp
void main()
DECL(PTR(PTR(PTR(INT))),n,SEQ(ASGN(DEREF(DEREF(DEREF(VAR(n)))),FUNC(read_int)),DECL(PTR(PTR(INT)),m,SEQ(ASGN(DEREF(DEREF(VAR(m))),PLUS(DEREF(DEREF(DEREF(VAR(n)))),CONST(1))),PROC(write_int,PLUS(DEREF(DEREF(VAR(m))),CONST(2)))))))
```

  

### 样例01 (sample_src01.jtl)

- 输入

```c
int*(**n)(int(*)(int, int**), int**);

void(**p)(int, int**);

int(*)(int, int**) main(int** a, int*** b) {
int(**n)(int, int**);
int **m;
**m = ***n + 1;
write_int(**m + 2)
}

```

- 输出

```lisp
DECL(PTR(FUNPTR((FUNPTR((INT,PTR(PTR(INT))),(INT)),PTR(PTR(INT))),(PTR(INT)))),n)

DECL(PTR(PROCPTR(INT,PTR(PTR(INT)))),p)

FUNPTR((INT,PTR(PTR(INT))),(INT)) main(PTR(PTR(INT)) a,PTR(PTR(PTR(INT))) b)
DECL(PTR(FUNPTR((INT,PTR(PTR(INT))),(INT))),n,DECL(PTR(PTR(INT)),m,SEQ(ASGN(DEREF(DEREF(VAR(m))),PLUS(DEREF(DEREF(DEREF(VAR(n)))),CONST(1))),PROC(write_int,PLUS(DEREF(DEREF(VAR(m))),CONST(2))))))
```

  
