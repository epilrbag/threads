#include <pthread.h>
#define NUM 1000

int vetor[NUM];

pthread_t t0, t1, t2, t3, t4, t5;

void *num_al()
{
  for(int i = 0; i < NUM; i++)
  {
    vetor[i] = rand()%100000;
    printf("Vetor[%d]: %d\n", i, vetor[i]);
  }
}

void *filho0()
{
  int end = 0;
  printf("\n");
  for(int i = 0; i < 200; i++)
  {
    end = rand()%NUM;
    printf("Filho1: vetor[%d] = %d\n", end, vetor[end]);
  }
}

void *filho1()
{
  int end = 0;
  printf("\n");
  for(int i = 200; i < 400; i++)
  {
    end = rand()%NUM;
    printf("Filho2: vetor[%d] = %d\n", end, vetor[end]);
  }
}

void *filho2()
{
  int end = 0;
  printf("\n");
  for(int i = 400; i < 600; i++)
  {
    end = rand()%NUM;
    printf("Filho3: vetor[%d] = %d\n", end, vetor[end]);
  }
}

void *filho3()
{
  int end = 0;
  printf("\n");
  for(int i = 600; i < 800; i++)
  {
    end = rand()%NUM;
    printf("Filho4: vetor[%d] = %d\n", end, vetor[end]);
  }
}

void *filho4()
{
  int end = 0;
  printf("\n");
  for(int i = 800; i < 1000; i++)
  {
    end = rand()%NUM;
    printf("Filho5: vetor[%d] = %d\n", end, vetor[end]);
  }
}

int main()
{
  pthread_create(&t0, NULL, num_al, NULL);
  sleep(3);
  pthread_create(&t1, NULL, filho0, NULL);
  sleep(3);
  pthread_create(&t2, NULL, filho1, NULL);
  sleep(3);
  pthread_create(&t3, NULL, filho2, NULL);
  sleep(3);
  pthread_create(&t4, NULL, filho3, NULL);
  sleep(3);
  pthread_create(&t5, NULL, filho4, NULL);
  pthread_join(t0, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  pthread_join(t4, NULL);
  pthread_join(t5, NULL);
}
