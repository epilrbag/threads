#include <pthread.h>
#define NUM 20

pthread_t t0, t1;

int turn = 0;

int shared;

void *thread0()
{
  for(int i = 0; i < NUM; i++)
  {
    while(turn != 0){}
    shared = shared + 50;
    printf("Imcrementei\n");
    turn = 1;
  }
}

void *thread1()
{
  for(int i = 0; i < NUM; i++)
  {
    while(turn != 1){}
    printf("Shared: %d\n", shared);
    turn = 0;
  }
}

int main()
{
  pthread_create(&t0, NULL, thread0, NULL);
  pthread_create(&t1, NULL, thread1, NULL);
  pthread_join(t0, NULL);
  pthread_join(t1, NULL);
}
