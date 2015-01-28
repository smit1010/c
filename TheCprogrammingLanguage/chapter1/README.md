#chapter1: A Tutorial Introduction
##1.1 the only way to learn a new programming language is by writing programs in it.----k&R
    确实如此，学习一门语言的唯一方法就是用这门语言来编写程序。
##1.2 函数类型
###1.2.1 no func type 
    printHelloWorld没有指定函数类型，则函数默认返回的是int类型，而且在g++ 出现errorISO C++ 
    forbids declaration of \‘printHelloWorld’ with no type -fpermissive]，g++ 默认变异选项是-fpermissive
    gcc 则可以编译通过。
###1.2.2 转义序列表格
转义符号|意义|ASCII（十进制）
:---------------|:---------------|:---------------
\a|响铃bel|007
\b|退格backspace|008
\f|换页FF|012
\n|换行LF|010
\r|回车CR|013
\t|水平制表HT|009
\v|垂直制表VT|011
\\|代表一个反斜线字符''\'|092
\'|代表一个单引号（撇号）字|039
\"|代表一个双引号字|034
\0|空字符(NULL)|000
###1.2.3 size of object
    所有的数据类型都和硬件平台有关，具体是这依赖具体的cpu。因此保证可移植性的工程需要进行数据类型的定义。如type.h 
    if an arithmetic has one float and int ,and the int will converted to floating point
##1.3 for loop
    文中用while循环来控制，对比for来看，将循环条件的比较和改变分离不同的行，不利于阅读和理解
##1.4 magic numbers
    magic numbers convey little info, hard to change in a systematic.可读性差,扩展性差
##1.5 input and out
    EOF 是end of file 如果在linux當中,如想输入文件的尾部,则输入ctrl + d.getchar()返回值定义成int的原因是因为有足够
    的位宽来处理eof.eof的值在stdio.h定义,这个值不是恒定的,只要文件当中没有使用则可以.
##1.6 arrays
    在linux系统下,如果遇到不懂的则可以使用man memset等进行查看.
##1.7 functions
    function设计的目的就是封装过程,调用者只需要知道实现了什么功能,而不需知道实现的过程. 
    通常函数的返回值用0标准正常结束,用NoneZero表示异常退出..ANSI C 之前的函数定义形式.
    '''c
    power_old_style(base,n)
    int base, n;
    {
        PDEBUG();
    }
    '''
##1.8 arguments
    in c ,all function arguments are passed "by value".因此我们调用函数传递的参数是一个临时变量
    C语言和Fortran和pascal不同,他们是传递original argument.
    c语言的变量不能被调用函数内部进行改变,调用函数内容只是改变私有的和临时的副本.
    若需要改变变量的值,需要将变量的地址传入调用函数中,调用的函数必须将参数声明成指针
##1.9 character
    extern  可以在函数内部进行使用,但可见范围仅仅在函数体内部
    "Definition" refers to the place where the variable is created or assigned storage;
    "declaration" refers to places where the nature of the variable is stated but no storage.  
