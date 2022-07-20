#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
void handler(int signo)
{
  while(1)
  {
    printf("signo:%d",signo);
    sleep(1);
  }
}
int main()
{
  struct sigaction act;
  memset(&act,0,sizeof(act));
  act.sa_handler=handler;
  sigemptyset(&act.sa_mask);
  sigaddset(&act.sa_mask,3);
  sigaction(2,&act,NULL);
  while(1)
  {
    printf("hello\n");
    sleep(1);
  }
  return 0;
  
}
//void show_pending(sigset_t *pending)
//{
//  int i;
//  for( i=1;i<=31;i++)  {
//    if(sigismember(pending,i))
//    {
//      printf("1");
//
//    }else{
//      printf("0");
//    }
//
//  }
//  printf("\n");
//}
//int main()
//{
//  sigset_t i_set,o_set;
//  sigemptyset(&i_set);
//  sigemptyset(&o_set);
//  sigaddset(&i_set,2);
//  
//  sigaddset(&i_set,9);
//  sigprocmask(SIG_SETMASK,&i_set,&o_set);
//  sigset_t pending;
//  int count=0;
//  while(1)
//  {
//    sigemptyset(&pending);
//    sigpending(&pending);
//    show_pending(&pending);
//    //printf("hello world\n");
//    sleep(1);
//    count++;
//    if(count==20)
//    {
//      sigprocmask(SIG_SETMASK,&o_set,NULL);
//      printf("2 signal remove, now can appendn\n");
//    }
//  }
//  return 0;
//}
