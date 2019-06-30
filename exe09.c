#include <pthread.h>

pthread_t t0;

int shared;

void *thread0()
{
  int x;
  for(int i = 0; i < 50; i++)
  {
    x = shared;
    x = x + 3;
    shared = x;
  }
  pthread_exit((void *)shared);
}

int main()
{
  int result;
  pthread_create(&t0, NULL, thread0, NULL);
  sleep(1);
  pthread_join(t0, ((void *)&result));
  printf("O valor do resultado é: %d\n", result);
}
