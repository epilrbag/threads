#include <pthread.h>

pthread_t t0, t1;

void *thread0()
{
  for(int i = 0; i < 10; i++)
    printf("Thread0: %d\n", i);
}

void *thread1()
{
  for(int i = 10; i < 20; i++)
    printf("Thread1: %d\n", i);
}

int main()
{
  pthread_create(&t0, NULL, thread0, NULL);
  wait(0);
  pthread_create(&t1, NULL, thread1, NULL);
  pthread_join(t0, NULL);
  pthread_join(t1, NULL);
}
