#include<stdio.h>
#include<string.h>
int main()
{
  FILE *fp=fopen("./log.txt","w");
  if(!fp)
  {
    printf("fopen error\n");
  }
  char buf[1024];
  const char *msg="hello file\n";
  while(1)
  {
    ssize_t s=fread(buf,strlen(msg),fp);
    if(s>0)
    {
      buf[s]=0;
      printf("%s",buf);
    }
    if(feof(fp))
    {
      break;
    }
  }
}
