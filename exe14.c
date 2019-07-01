#include <pthread.h>
#define NUM 1000

pthread_t t0, t1, t2, t3, t4, t5;


int vetor[NUM], result[NUM];

void *pai()
{
  for(int i = 0; i < NUM/2; i++)
    result[i] = vetor[i]*4 + 20;
}

void *filho()
{
  for(int i = NUM/2; i < NUM; i++)
    result[i] = vetor[i]*4 + 20;
}

void *exibirfilho()
{
  for(int i = NUM/2; i < NUM; i++)
    printf("Vetor[%d]: %d\n", i, result[i]);
}

void *exibirpai()
{
  for(int i = 0; i < NUM/2 ; i++)
    printf("Vetor[%d]: %d\n", i, result[i]);
}

int main()
{
  pthread_create(&t0, NULL, pai, NULL);
  pthread_create(&t1, NULL, filho, NULL);
  sleep(3);
  pthread_create(&t2, NULL, exibirpai, NULL);
  pthread_create(&t3, NULL, exibirfilho, NULL);
  pthread_join(t0, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
}
