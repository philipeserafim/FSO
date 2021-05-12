#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAXRANDOM 100000
sem_t maxThreads;
int v1[MAXRANDOM], v2[MAXRANDOM];
int somaglobal1 = 0, somaglobal2 = 0;
struct struct_st
{
  int mi, bi;
  int seed;
  pthread_t tid;
};

void *perguntas1(void *p)
{
  struct struct_st* a = (struct struct_st *)p;
  for (int i = 0; i < MAXRANDOM; i++)
    v1[i] = rand_r(&a->seed);
}
void *perguntas2(void *p)
{
  struct struct_st* a = (struct struct_st *)p;
  for (int i = 0; i < MAXRANDOM; i++)
    v2[i] = rand_r(&a->seed);
}

void *procura1(void *p)
{
  struct struct_st* a = (struct struct_st *)p;
  int count = 0;
  for (int i = 0; i < MAXRANDOM; i++)
  {
    if ((v1[i] % a->mi) == a->bi)
    {
      sem_wait(&maxThreads);
      count++;
      sem_post(&maxThreads);
    }
  }
  somaglobal1 += count;
}
void *procura2(void *p)
{
  struct struct_st* a = (struct struct_st *)p;
  int count = 0;
  for (int i = 0; i < MAXRANDOM; i++)
  {
    if ((v2[i] % a->mi) == a->bi)
    {
      sem_wait(&maxThreads);
      count++;
      sem_post(&maxThreads);
    }
  }
  somaglobal2 += count;
}

int main()
{
  int mi, bi;
  int seed1, seed2;
  struct struct_st t1, t2;

  sem_init(&maxThreads, 0, 1);

  scanf("%d %d", &seed1, &seed2);
  t1.seed = seed1;
  t2.seed = seed2;
  pthread_create(&t1.tid, NULL,  &perguntas1, (void*) &t1);
  pthread_create(&t2.tid, NULL,  &perguntas2, (void*) &t2);
  pthread_join(t1.tid, NULL);
  pthread_join(t2.tid, NULL);

  while (scanf(" %d %d", &mi, &bi) != -1)
  {
    t1.mi = mi;
    t1.bi = bi;
    t2.mi = mi;
    t2.bi = bi;
    pthread_create(&t1.tid, NULL, &procura1, (void*) &t1);
    pthread_create(&t2.tid, NULL, &procura2, (void*) &t2);
    pthread_join(t1.tid, NULL);
    pthread_join(t2.tid, NULL);

    printf("%d\n", somaglobal1 + somaglobal2);
    somaglobal1 = 0;
    somaglobal2 = 0;
  }
  return 0;
} 