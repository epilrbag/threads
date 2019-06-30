#include <pthread.h>
#include <semaphore.h>

pthread_t t0, t1;

sem_t s0;

int a = 0;

void *thread0()
{
  int i, x;

  for(i = 0; i < 100000; i++)
  {
    //sem_wait(&s0);
    x = a;
    x = x + 2;
    a = x;
    printf("Thread0: %d\n", a);
    sem_post(&s0);
  }
}

void *thread1()
{
  int i, x;

  for(i = 0; i < 100000; i++)
  {
    sem_wait(&s0);
    x = a;
    x = x + 5;
    a = x;
    printf("Thread1: %d\n", a);
    //sem_post(&s0);
  }
}

int main()
{
  sem_init(&s0, 0, 1);
  pthread_create(&t0, NULL, thread0, NULL);
  pthread_create(&t1, NULL, thread1, NULL);
  pthread_join(t0, NULL);
  pthread_join(t1, NULL);
}
