#include <pthread.h>
#define NUM 50

void *printID(void *tid)
{
  printf("Olá, sou a thread %d\n", (int) tid);
  pthread_exit(NULL);
}

int main()
{
  pthread_t threads[NUM];
  int i, status;

  for(i = 0; i < NUM; i++)
  {
    status = pthread_create(&threads[i], NULL, printID, (void *)i);
    if(status != 0)
    {
      printf("Erro na criação da thread %d\n", i);
      exit(-1);
    }
    sleep(1);
  }

  for(i = 0; i < NUM; i++)
    pthread_join(threads[i], NULL);
  return 0;
}
