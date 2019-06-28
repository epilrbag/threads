#include <pthread.h>

pthread_t t0, t1, t2, t3, t4;

int num1, num2, resultado, op;

void *servidor()
{
  if (op == 1)
    printf("Valor da soma: %d\n", (num1 + num2));
  else if(op == 2)
    printf("Valor da divisão: %d ou %d\n", (num1 / num2), (num2/num1));
  else if(op == 3)
    printf("Valor da multiplicação: %d\n", (num1 * num2));
  else if(op == 4)
    printf("Valor da subtração: %d ou %d\n", (num1 - num2), (num2 - num1));
  else
    printf("Opção invalida\n");
}

void *cliente1()
{
  num1 = 5;
  num2 = 8;
  op = 1;
}

void *cliente2()
{
  num1 = 5;
  num2 = 8;
  op = 3;
}

void *cliente3()
{
  num1 = 5;
  num2 = 8;
  op = 2;
}

void *cliente4()
{
  num1 = 5;
  num2 = 8;
  op = 4;
}

int main()
{
  pthread_create(&t4, NULL, cliente4, NULL);
  pthread_create(&t0, NULL, servidor, NULL);
  wait(0);
  pthread_create(&t3, NULL, cliente3, NULL);
  pthread_create(&t0, NULL, servidor, NULL);
  wait(0);
  pthread_create(&t2, NULL, cliente2, NULL);
  pthread_create(&t0, NULL, servidor, NULL);
  wait(0);
  pthread_create(&t1, NULL, cliente1, NULL);
  pthread_create(&t0, NULL, servidor, NULL);
  pthread_join(t4, NULL);
  pthread_join(t3, NULL);
  pthread_join(t2, NULL);
  pthread_join(t1, NULL);
  pthread_join(t0, NULL);
}
