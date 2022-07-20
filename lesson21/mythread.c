#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *thread_run(void* args)
{
  const char* id=(const char*)args;
  while(1)
  {
    printf("i am %s thread %d\n",id,getpid());
    sleep(1);
  }
}
int main(){

  pthread_t tid;
  pthread_create(&tid,NULL,thread_run,(void*)"thread_1");
  while(1)
  {
    printf("i am main thread %d \n",getpid());
  }
}
