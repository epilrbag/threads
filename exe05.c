#include <pthread.h>

long i, a, b, c;

pthread_t t0, t1;

void *thread0()
{
  for(i = 0; i < 1000000; i++)
  {
    a = a + 5;
    printf("T1: %d .Valor do A: %d\n", i, a);
  }
}

void *thread1()
{
  for(i = 0; i < 1000000; i++)
  {
    //a = a + 2;
    b = b + 7;
    printf("T2: %d .Valor do A: %d\n", i, b);
  }
}

int main()
{
  pthread_create(&t0, NULL, thread0, NULL);
  //printf("Valor de a: %d\n", a);
  sleep(10);
  pthread_create(&t1, NULL, thread1, NULL);
  sleep(10);
  printf("Soma total de a e b: %d\n", (a+b));
  pthread_join(t0, NULL);
  pthread_join(t1, NULL);
}
