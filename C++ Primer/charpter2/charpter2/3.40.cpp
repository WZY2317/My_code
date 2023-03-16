#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str1[] = "hello";
	char str2[] = "world";
	char str3[strlen(str1)+strlen(str2)-1];
	strcopy(strcat(str1, str2),str3);
	return 0;
}