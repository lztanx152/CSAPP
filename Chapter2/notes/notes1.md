# 2.1
## 2.1.2
对于一个字长为 w位的机器而言，虚拟地址的范围为 O~2^w—1,
程序最多访问2^w个字节。<br>
字长就是通俗的X位计算机/架构的X<br>
## 2.1.3
测试,本机使用小端存储:0x1234568的存储方式是78563412<br>
字节顺序(大小端)一般情况下无影响但是:<br>
1:网络传输<br>
2:阅读整数数据的字节顺序(反汇编)<br>
3:强制类型转换<br>
执行man ascii得到ascii表<br>
## 2.1.4
文本数据(字符串)不受大小端影响:<br>
"12345"的存储格式为313233343500
## 2.1.5
反编译sum.o的机器码的结果,与书上相比多了endbr64<br>
objdump -d sum.o

sum.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <sum>:
0:   f3 0f 1e fa             endbr64<br>
4:   55                      push   %rbp<br>
5:   48 89 e5                mov    %rsp,%rbp<br>
8:   89 7d fc                mov    %edi,-0x4(%rbp)<br>
b:   89 75 f8                mov    %esi,-0x8(%rbp)<br>
e:   8b 55 fc                mov    -0x4(%rbp),%edx<br>
11:   8b 45 f8                mov    -0x8(%rbp),%eax<br>
14:   01 d0                   add    %edx,%eax<br>
16:   5d                      pop    %rbp<br>
17:   c3                      ret<br>
## 2.1.7
利用三次异或运算交换指针/值:同一个值在此算法中会变成0<br>
## 2.1.9
c编译器默认对无符号数执行逻辑右移，对有符号数字执行算术右移<br>
加减法的优先级高于位移<br>

# 2.2
## 2.2.4
c语言的类型转换以位为核心<br>
## 2.2.5
#define INT_MIN (-INT_MAX - 1):直接写-2147483648的话，可能导致编译器误解为long，因为这个数字大于了int32的最大值<br>
## 2.2.6
p54的补码数的符号扩展中后面的Ω（小写的）少了一撇<br>
sx是short，unsigned y = sx其实是unsigned int sx，先转换为int，再转无符号数字<br>
## 2.2.7


