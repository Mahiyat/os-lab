#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

int shared=1;
sem_t s;

void *fun1();
void *fun2();

int main()
{
  sem_init(&s,0,1);

  pthread_t thread1,thread2;
  pthread_create(&thread1,NULL,fun1,NULL);
  pthread_create(&thread2,NULL,fun2,NULL);
  pthread_join(thread1,NULL);
  pthread_join(thread2,NULL);
  printf("Final value of shared: %d\n",shared);
  return 0;
}

void *fun1()
{
  int x;
  sem_wait(&s);
  x=shared;
  printf("Thread1 reads the value of shared variable as %d\n",x);
  x++;
  printf("Local update by Thread1: %d\n",x);
  sleep(1);
  shared=x;
  printf("Value of shared variable updated by Thread1: %d\n",shared);
  sem_post(&s);
}

void *fun2()
{
  int y;
  sem_wait(&s);
  y=shared;
  printf("Thread2 reads the value of shared variable as %d\n",y);
  y--;
  printf("Local update by Thread2: %d\n",y);
  sleep(1);
  shared=y;
  printf("Value of shared variable updated by Thread2: %d\n",shared);
  sem_post(&s);
}