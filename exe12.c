#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#define NUM 1000

int vetor[NUM], end = 0;

int main()
{
  for(int i = 0; i < NUM; i++)
    vetor[i] = rand()%100000;

  int pid;
  pid = fork();

  if(pid != 0)
  {
    pid = fork();

    if(pid != 0)
    {
      end = rand()%NUM;
      printf("Eu sou o pai e meu pid é %d, eu escolhi número é %d\n", getpid(), vetor[end]);
      wait(0);
    }

    else
    {
      if(pid == 0)
      {
        end = rand()%200;
        printf("Eu sou o filho e meu pid é %d, eu escolhi número é %d\n", getpid(), vetor[end]);
        wait(0);
      }

      else
        exit(-1);
    }
  }
  else if(pid == 0)
  {
    pid = fork();

    if(pid != 0)
    {
      end = rand()%(200 < 400);
      printf("Eu sou o filho2 e meu pid é %d, eu escolhi número é %d\n", getpid(), vetor[end]);
      //wait(0);
    }

    else
    {
      if(pid == 0)
      {
        end = rand()%(400 < 600);
        printf("Eu sou o filho3 e meu pid é %d, eu escolhi número é %d\n", getpid(), vetor[end]);
        wait(0);
      }
      else
        exit(-1);
    }
  }

  else
    exit(-1);
  wait(0);
}
