#include <pthread.h>

#define N 10

pthread_t th0, th1;

int buffer[N], addrprod = 0, addrcons = 0;

void *produtor()
{
  int i, p = 50;

  for(i = 0; i < 20; i++)
  {
    while(((addrprod + 1)%N)==addrcons){}
    p++;
    buffer[addrprod] = p;
    addrprod = (addrprod + 1)%N;
  }
}

void *consumidor()
{
  int i, c;

  for(i = 0; i < 20; i++)
  {
    while(addrprod == addrcons){}
    c = buffer[addrcons];
    printf("Consumi o valor %d da posição %d\n", c, addrcons);
    addrcons = (addrcons + 1)%N;
  }
}

int main()
{
  pthread_create(&th0, NULL, produtor, NULL);
  pthread_create(&th1, NULL, consumidor, NULL);
  pthread_join(th0, NULL);
  pthread_join(th1, NULL);
}
