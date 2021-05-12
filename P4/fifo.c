/*Substituição de Páginas - FIFO
Lucas, um jovem aluno de Engenharia de Software, é muito curioso e meticuloso. Recentemente ele aprendeu sobre os algoritmos de substituição de páginas e ficou muito curioso sobre a estratégia de fila.

O professor disse que esta estratégia de substituição de páginas sofre da anomalia de Belady, que alocando mais quadros podemos obter uma maior taxa de page faults.

Entrada
A entrada é composta por um único caso de teste contendo diversas linhas. A primeira linha possui um número inteiro N ( 3 \leq N \leq 10^5 ), a segunda linha possui N números P_i ( 1 \leq P_i \leq 10^6 ) representando a página que é acessada pelo sistema. A partir da terceira linha uma número inteiro Q (1 \leq Q \leq 10^5) será dado, indicando para quantos quadros a sequência de páginas deve ser testada.

A entrada termina em EOF.

Saída
Para cada teste de quadros você deverá imprimir uma única linha contendo a quantidade de quadros e de page faults. A última linha deve contar a string Belady detectado ou Sem anomalia caso seja identificado a anomalia de Belady para os testes feitos.

Exemplos
Exemplo de entrada
12
1 2 3 4 1 2 5 1 2 3 4 5
3
4
Saída para o exemplo acima
3 9
4 10
Belady detectado
Exemplo de entrada
12
1 2 3 4 1 2 5 1 2 3 4 5
5
6
Saída para o exemplo acima
5 5
6 5
Sem anomalia
Exemplo de entrada
30
97 67 24 35 43 69 69 63 4 99 16 49 5 77 8 77 27 58 15 45 45 43 3 30 94 37 17 12 21 184
6
5
11
9
3
16
7
19
14
Saída para o exemplo acima
6 27
5 27
11 27
9 27
3 27
16 26
7 27
19 26
14 26
Sem anomalia
Author: Bruno Ribas*/
#include<stdio.h>
#include<stdlib.h>

int fifo(int frameN, int *v, int n){
  int vetor[frameN];
  int pagefault = 0;
  int start = 0;
  int flag;
  int atual;

  for(int i = 0; i < frameN; i++){
    vetor[i] = -1;
  }

  for(int i = 0; i < n; i++){
    atual = v[i];
    flag = 0;
    for(int j = 0; j < frameN; j++){
      if(atual == vetor[j]){
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      if(start == frameN){
        vetor[0] = atual;
        start = 1;
      }
      else if(start < frameN){
        vetor[start] = atual;
        start++;
      }
      pagefault++;
    }
  }
  printf("%d %d\n", frameN, pagefault);
  return pagefault;
}

int main(void){
  int n, *p, q;
  int pf[1000005], frame[1000005], pos = 0;
  int falha = 0;

  scanf(" %d", &n);
  p = malloc(sizeof(int) * n);
  for(int i = 0; i < n; i++)
    scanf("%d", &p[i]);
  
  while(scanf("%d", &q) != -1){
    pf[pos] = fifo(q, p, n);
    frame[pos++] = q;
  }

  for(int i = 0; i < pos; i++){
    for(int j = 0; j < pos; j++)
        if(frame[i] > frame[j] && pf[i] > pf[j])
          falha = 1;
  }

  if(falha == 0)
    printf("Sem anomalia\n");
  else 
    printf("Belady detectado\n");
  return 0;
}