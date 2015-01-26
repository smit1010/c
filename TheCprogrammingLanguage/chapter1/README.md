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
