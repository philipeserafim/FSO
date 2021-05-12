#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<math.h>
#define MAXNUM 9999999

struct struct_st{
  int n;
  pthread_t tid;
  int result;
};
sem_t maxThreads;

void * primomaluco(void *p){
  //10 multiplos maiores q 10 e menores q sqrt
  struct struct_st* a = (struct struct_st *)p;
  int raiz = sqrt(a->n);
  int divisores[10];
  int qtdDivisores = 0, posDivisores = 0;
  int num = a->n;
  
  for(int j = num; j < MAXNUM; j++){
    for(int i = 11; i < raiz; i++){
      if(num % i == 0){
        qtdDivisores++;
        divisores[posDivisores++] = i;
      }
      if(qtdDivisores == 9){
        a->result = j;
        break;
      }
    }
    if(a->result != 0){
      qtdDivisores = 0;
      posDivisores = 0;
      break;
    }
  }
}

int main(void){
  int t, n;
  struct struct_st *nums;

  scanf(" %d", &t);
  nums = malloc(sizeof(struct struct_st)*t);

  for(int i = 0; i < t; i++){
    scanf(" %d", &n);
    nums[i].n = n;
  }

  sem_init(&maxThreads, 0, 9);

  for(int i = 0; i < t; i++){
    pthread_create(&nums[i].tid, NULL, &primomaluco, (void *) &nums[i]);
    pthread_create(&nums[i+1].tid, NULL, &primomaluco, (void *) &nums[i]);
    // pthread_create(&nums[i+2].tid, NULL, &primomaluco, (void *) &nums[i]);
    // pthread_create(&nums[i+3].tid, NULL, &primomaluco, (void *) &nums[i]);
    // pthread_create(&nums[i+4].tid, NULL, &primomaluco, (void *) &nums[i]);
    // pthread_create(&nums[i+5].tid, NULL, &primomaluco, (void *) &nums[i]);
    // pthread_create(&nums[i+6].tid, NULL, &primomaluco, (void *) &nums[i]);
    // pthread_create(&nums[i+7].tid, NULL, &primomaluco, (void *) &nums[i]);
    // pthread_create(&nums[i+8].tid, NULL, &primomaluco, (void *) &nums[i]);
    // pthread_create(&nums[i+9].tid, NULL, &primomaluco, (void *) &nums[i]);
    
    pthread_join(nums[i].tid, NULL);
    pthread_join(nums[i+1].tid, NULL);
    // pthread_join(nums[i+2].tid, NULL);
    // pthread_join(nums[i+3].tid, NULL);
    // pthread_join(nums[i+4].tid, NULL);
    // pthread_join(nums[i+5].tid, NULL);
    // pthread_join(nums[i+6].tid, NULL);
    // pthread_join(nums[i+7].tid, NULL);
    // pthread_join(nums[i+8].tid, NULL);
    // pthread_join(nums[i+9].tid, NULL);
  }

  for(int i = 0; i < t; i++){
    printf("%d\n", nums[i].result);
  }

  return 0;
}