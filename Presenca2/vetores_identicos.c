#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int v1[10000100], v2[10000100];

struct thread_st{
  int *v;
  int tam;
  pthread_t tid;
};

int comparador(const void* a, const void* b){
  if(*(int *)a > *(int *)b) return 1;
  if(*(int *)a < *(int *)b) return -1;
  return 0;
}

void *ordenaThread(void *p){
  struct thread_st *a=(struct thread_st*)p;
  qsort(a->v, a->tam, sizeof(int), comparador);
}

int main(void){
  int n;
  int diferente = 0;

  scanf(" %d", &n);
  for(int i = 0; i < n; i++){
    scanf(" %d", &v1[i]);
  }
  for(int i = 0; i < n; i++){
    scanf(" %d", &v2[i]);
  }
  struct thread_st t1, t2;
  t1.v = v1;
  t1.tam = n;
  t2.v = v2;
  t2.tam = n;

  pthread_create(&t1.tid, NULL, ordenaThread, (void *)&t1);
  pthread_create(&t2.tid, NULL, ordenaThread, (void *)&t2);
  pthread_join(t1.tid, NULL);
  pthread_join(t2.tid, NULL);

  for(int i = 0; i < n; i++){
    if(t1.v[i] != t2.v[i]){
      diferente = 1;
    }
  }

  if(diferente == 0){
    printf("Mesmos elementos\n");
  }else{
    printf("Diferentes\n");
  }

  return 0;
}
