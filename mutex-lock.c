#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int shared=1;

void *fun1();
void *fun2();

pthread_mutex_t l;

int main()
{
  pthread_mutex_init(&l,NULL);
  
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
  printf("Thread1 is trying to acquire the lock\n");
  pthread_mutex_lock(&l);
  printf("Thread1 acquired the lock\n");
  x=shared;
  printf("Thread1 read the value of shared variable as %d\n",x);
  x++;
  printf("Local update by Thread1: %d\n",x);
  sleep(1);
  shared=x;
  printf("Thread1 updated the shared variable as %d\n",shared);
  pthread_mutex_unlock(&l);
  printf("Thread1 released the lock\n");
}

void *fun2()
{
  int y;
  printf("Thread2 is trying to acquire the lock\n");
  pthread_mutex_lock(&l);
  printf("Thread2 acquired the lock\n");
  y=shared;
  printf("Thread2 read the value of the shared variable as %d\n",y);
  y--;
  printf("Local update by Thread2: %d\n",y);
  sleep(1);
  shared=y;
  printf("Thread2 updated the shared variable as %d\n",shared);
  pthread_mutex_unlock(&l);
  printf("Thread2 released the lock\n");
}