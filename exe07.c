#include <pthread.h>

pthread_t t0, t1, t2, t3, t4;

int turn, shared, a, b;

void *thread0()
{
  for(int i = 0; i < 100; i++)
  {
    while(turn != 0){}
    a = a + 50;
    turn = 1;
  }
  printf("Thread0: %d\n", a);
}

void *thread1()
{
  for(int i = 0; i < 100; i++)
  {
    while(turn != 1){}
    a = a + 50;
    turn = 0;
  }
  printf("Thread1: %d\n", a);
}

int main()
{
  pthread_create(&t0, NULL, thread0, NULL);
  pthread_create(&t1, NULL, thread1, NULL);
  pthread_join(t0, NULL);
  pthread_join(t1, NULL);
}
