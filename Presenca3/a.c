/*Sith vs Jedi
Darth Vader tem muitos aliados, então para uma boa continuidade do nosso desafio temos que descobrir quem pertence ao
lado negro da força.
Por isso, os rebeldes pediram para os alunos de Engenharia de Computação da UTPFR desenvolverem um portal onde
cada vez que alguém passa é gerado um número identificador. Este número é par para quem faz parte da Aliança Rebelde,
e ímpar para quem está do lado do Império Intergaláctico (simpatizantes do lado negro).
Sua tarefa é de suma importância: separar os Sith (Império) dos Jedi (Aliança), identificando se o número que o portal
gerou é par ou ímpar.
Entrada
Este problema é composto por um único caso de teste. A primeira linha contém um inteiro N (0 < N ≤ 100). As próximas
N linhas contém inteiros Xi (0 ≤ Xi ≤ 1000).
Saída
Seu programa deve imprimir Sith em caso de pertencente ao lado obscuro da força e Jedi caso contrário. Não esqueça
que a resposta deve sempre terminar com uma quebra de linha.
Exemplos
Exemplo de Entrada
3
5
2
9
Exemplo de Saída
Sith
Jedi
Sith
Author: Cristian R. Pastro*/

#include<stdio.h>
#include<stdlib.h>

int main(void){
  int n;
  int x;

  scanf(" %d", &n);
  for(int i = 0; i < n; i++){
    scanf(" %d", &x);

    if(x % 2 == 0) printf("Jedi\n");
    else printf("Sith\n");
  }

  return 0;
}