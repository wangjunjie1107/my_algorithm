#include<stdio.h>

/*

字符变量实际上并不是把该字符本身放到变量的内存单元中去，
而是将该字符对应的 ASCII 编码放到变量的存储单元中。
char的本质就是一个1字节大小的整型。

*/

int main()
{
	char ch = 'a';
	printf("sizeof(ch) = %u\n", sizeof(ch));
	
	printf("ch[%%c] = %c\n", ch); //打印字符
	printf("ch[%%d] = %d\n", ch); //打印 'a'的ASCII码值
	
	char A = 'A';
	char a = 'a';
	
	printf("a = %d\n", a);  //97
	printf("A = %d\n", A); //65
	
	printf("A = %c\n", 'a'-32); //小写a转大写A
	printf("a = %c\n", 'A'+32); //大写A转小写a
	
	ch = ' ';
	printf("空字符：%d\n", ch); //空字符ASCII的值为32
	printf("A = %c\n", 'a'-' ');//小写a转大写A
	printf("a = %c\n",'A'+' ');//大写A转小写a
	
	return 0; 
	
	
	
	
	
	
	
	
	
	
	 
	
 } 
