#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int shared=1;

void *fun1();
void *fun2();

int main()
{
  pthread_t thread1,thread2;
  pthread_create(&thread1,NULL,fun1,NULL);
  pthread_create(&thread2,NULL,fun2,NULL);
  pthread_join(thread1,NULL);
  pthread_join(thread1,NULL);

  printf("Final value of shared: %d\n",shared);
  return 0;
}

void *fun1()
{
  int x;
  x=shared;
  printf("Value of shared variable read by Thread1: %d\n",x);
  x++;
  printf("Local update by Thread1: %d\n",x);
  sleep(1);
  shared=x;
  printf("Value of shared variable updated by Thread1: %d\n",shared);
}

void *fun2()
{
  int y;
  y=shared;
  printf("Value of shared variable read by Thread2: %d\n",y);
  y--;
  printf("Local update by Thread2: %d\n",y);
  sleep(1);
  shared=y;
  printf("Value of shared variable updated by Thread2: %d\n",shared);
}