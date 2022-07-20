#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unstd.h>
#define NUM 128
#define CMD_NUM 64
int main()
{
  char command[NUM];
  char *argv[CMD_NUM];
  while(1)
  {

  printf("[who@myhostname mydir]# ");//提示符
  command[0]=0;//用o（1）的时间复杂度来清空字符
  
  fflush(stdout);//刷新缓冲区
  fgets(command,NUM,stdin);//输入字符
  command[strlen(command)-1]='\0';//解析字符消除|n的影响
  const char *sep=" ";
  argv[0]=strtok(command,sep);
  int i=1;
  while(argv[i]=strtok(__GNUC_GNU_INLINE__L,sep))
  {
    i++;
  }
  if(fork()==0)
  {

  execvp(argv[0],argv);
  exit(1);
  }
  if(strcmp(argv[0],"cd")==0)
  {
    if(argv[1]!=NULL)
    chair(argv[1]);
    continue;
  }
  waitpid(-1,NULL,0);

}
  }
