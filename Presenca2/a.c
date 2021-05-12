/*Vetores Idênticos
João e seu amigo pé de feijão procuram por elementos parecidos. Um certo dia, João encontrou dois conjuntos de números, o pé de feijão achou que eles pudessem ser idênticos (isto é, que possuindo o mesmo conjunto de números). No entanto, ambos não conseguem identificar rapidamente esta suposição, para tanto pediram SUA ajuda para implementar um programa PARALELO que consiga ler os dois conjuntos de números e identificar se eles são idênticos ou não.

Entrada
A entrada possui um único caso de teste. A primeira, do caso de teste, possui um inteiro N (2 \leq N \leq 10000000) representando os tamanhos dos vetores. A segunda linha, do caso teste possui N inteiros V^{1}_{i} (0 \leq V^{1}_{i} \leq 2000000000) (cabe em um int de 32 bits), e a terceida linha possui N inteiros V^{2}_{i} (0 \leq V^{2}_{i} \leq 2000000000).

Saída
A saída possui uma única linha contendo a frase Diferentes, caso os vetores não sejam idênticos (depois de ordenados), ou Mesmos elementoscaso os vetores sejam idênticos (depois de ordenados).

TAREFA
Implementar a solução utilizando o conceito de threads. O algoritmos sequencial (e ineficiente) está representado abaixo:

int main(void)
{
  le_tamvetores(TAM)
  le_v1()
  le_v2()
  Ordena(v1)
  Ordena(v2)
  Compara(v1,v2)
  if iguais; then
    print "Mesmos elementos"
  else
    print "Diferentes"
  return 0;
}
Para agilizar, você poderá utilizar a função qsort(3) (da libc) para ordenar o vetor. Mas não se engane, se não ordenar os dois vetores paralelamente, você vai levar TLE :(

Caso nunca tenha utilizado a função qsort(3) leia o seu manual.

Exemplos
Exemplo de entrada
5
5 4 3 2 1
1 2 3 4 5
Saída para o exemplo acima
Mesmos elementos
Exemplo de Entrada
5
5 4 3 2 1
1 5 2 4 3
Saída para o exemplo acima
Mesmos elementos
Exemplo de Entrada
5
1 1 3 1 1
1 1 2 1 1
Saída para o exemplo acima
Diferentes
Exemplo de Entrada
5
1 7 3 1 9
9 1 2 7 1
Saída para o exemplo acima
Diferentes
Exemplo de Entrada
5
2 7 1 1 9
9 1 2 7 1
Saída para o exemplo acima
Mesmos elementos
Author: Bruno Ribas*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int tam = 0;
int comparador(const void *a, const void *b){
  if(*(int *)a > *(int *)b) return 1;
  if(*(int *)a < *(int *)b) return -1;
  return 0;
}

void *ordenaThread(void *v){
  int *nv = (int *)v;
  qsort(nv, tam, sizeof(int), comparador);
}

int main(void){
  int n;
  int diferente = 0;
  int v1[10000100], v2[10000100];
  pthread_t tid1, tid2;

  scanf(" %d", &n);
  tam = n;
  for(int i =0; i < n; i++){
    scanf(" %d", &v1[i]);
  }
  for(int i =0; i < n; i++){
    scanf(" %d", &v2[i]);
  }

  pthread_create(&tid1, NULL, ordenaThread, (void *)v1);
  pthread_create(&tid2, NULL, ordenaThread, (void *)v2);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  for(int i = 0; i < n; i++){
    if(v1[i] != v2[i]){
      diferente = 1;
    }
  }
  if(diferente == 1){
    printf("Diferentes\n");
  }else{
    printf("Mesmos elementos\n");
  }
  return 0;
}