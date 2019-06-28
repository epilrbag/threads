#include <pthread.h>
#define NUM 20

pthread_t t0, t1, t2, t3, t4;

int vetorA[NUM], vetorB[NUM], somaA, somaB, somaTOTAL;

void *thread0()
{
  for(int i = 0; i < NUM; i++)
    vetorA[i] = rand()%1000;
}

void *thread1()
{
  for(int i = 0; i < NUM; i++)
    vetorB[i] = rand()%1000;
}

void *thread2()
{
  for(int i = 0; i < NUM; i++)
    somaA = somaA + vetorA[i];
}

void *thread3()
{
  for(int i = 0; i < NUM; i++)
    somaB = somaB + vetorB[i];
}

void *thread4()
{
  printf("Soma A: %d\n\n", somaA);
  printf("Soma B: %d\n\n", somaB);
  somaTOTAL = somaA + somaB;
  printf("Soma Total: %d\n\n", somaTOTAL);
}

int main()
{
  pthread_create(&t0, NULL, thread0, NULL);
  pthread_create(&t1, NULL, thread1, NULL);
  pthread_create(&t2, NULL, thread2, NULL);
  pthread_create(&t3, NULL, thread3, NULL);
  pthread_create(&t4, NULL, thread4, NULL);

  pthread_join(t0, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  pthread_join(t4, NULL);
}
