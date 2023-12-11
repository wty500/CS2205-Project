# CS2205-Project

## 带函数指针与类型多态的程序语言的词法分析、语法分析与类型多态展开

这个任务中，你需要在 WhileF 语言中加入函数指针、基本类型系统与类型多态。该语言的类型包括整数类型、某类型的指针类型与基于特定参数与返回值类型的函数指针类型，声明变量时需要使用 `var` 关键字 + 类型 + 变量名 **(已更改为类型+变量名)** ，类型多态使用类似 C++ 语言中 template 的语法表示。
- 要求1：在 WhileF 语言中加入函数指针与基本类型系统，并完成词法分析、语法分析与语法树输出。
- 要求2：进一步加入类型多态，并完成词法分析、语法分析与语法树输出。
- 要求3：实现类型检查，根据 main 函数的需要，将类型多态展开，不能展开成为有穷多个副本的，产生报错信息。