/*Código Secreto
Escreva um programa, em C, que ao ser executado ele apenas instala um conjunto de tratadores de sinais e aguarda sinais.

O seu programa deve ser capaz de tratar os seguintes sinais: SIGTERM, SIGUSR1, SIGUSR2 e SIGINT.

Sempre que receber um sinal o seu programa deve imprimir na tela Recebi XX, sendo XX o código do sinal, por exemplo: Quando receber o sinal SIGTERM deverá imprimir Recebi 15.

Lembre que a função instalada para receber o sinal recebe como argumento o código do sinal. Veja o manual da função signal para lembrar de mais detalhes.

Se o seu programa receber 3 sinais na seguinte ordem: SIGINT, SIGUSR2, SIGTERM ele deverá imprimir na tela Senha acionada e se o processo receber, então SIGUSR1 ele deverá encerrar sua execução com a mensagem Tchau, tendo como exit status o valor 0. Se depois de “acionar” a senha, o processo receber um sinal diferente de SIGUSR1, o acionamento deverá ser desfeito silenciosamente.

Ou seja se o seu processo receber sinais em qualquer ordem nada deverá acionado. Se ele receber SIGINT e depois SIGUSR2 e então qualquer sinal diferente de SIGTERM a senha não pode ser destravada.

A única maneira de encerrar a execução do processo é se ele receber sinais na seguinte ordem: SIGINT SIGUSR2 SIGTERM SIGUSR1

Entrada
Não há entrada.

Saída
Exemplo 1
Se o seu processo receber os sinais na seguinte ordem:

SIGINT
SIGINT
SIGUSR1
SIGINT
SIGUSR2
SIGTERM
SIGUSR1
O seu programa deverá ter a sequência de impressão:

Recebi 2
Recebi 2
Recebi 10
Recebi 2
Recebi 12
Recebi 15
Senha acionada
Recebi 10
Tchau
Exemplo 2
Se o seu processo receber os sinais na seguinte ordem:

SIGUSR1
SIGUSR1
SIGINT
SIGUSR2
SIGTERM
SIGTERM
SIGUSR1
SIGINT
SIGUSR2
SIGTERM
SIGUSR1
O seu programa deverá ter a sequência de impressão:

Recebi 10
Recebi 10
Recebi 2
Recebi 12
Recebi 15
Senha acionada
Recebi 15
Recebi 10
Recebi 2
Recebi 12
Recebi 15
Senha acionada
Recebi 10
Tchau
Exemplo complicado
Ordem de sinais:

SIGUSR1
SIGTERM
SIGUSR1
SIGTERM
SIGINT
SIGUSR2
SIGTERM
SIGTERM
SIGTERM
SIGTERM
SIGINT
SIGTERM
SIGUSR2
SIGUSR1
SIGINT
SIGINT
SIGUSR2
SIGTERM
SIGUSR1
Saída do seu programa:

Recebi 10
Recebi 15
Recebi 10
Recebi 15
Recebi 2
Recebi 12
Recebi 15
Senha acionada
Recebi 15
Recebi 15
Recebi 15
Recebi 2
Recebi 15
Recebi 12
Recebi 10
Recebi 2
Recebi 2
Recebi 12
Recebi 15
Senha acionada
Recebi 10
Tchau
Author: Bruno Ribas*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/stat.h>

int estado = 0;
void trataSinal(int s){
  printf("Recebi %d\n", s);
  if(s == SIGINT && estado == 0){
    estado++;
  }else if(s == SIGUSR2 && estado == 1){
    estado++;
  }else if(s == SIGTERM && estado == 2){
    estado++;
    printf("Senha acionada\n");
  }else if(s == SIGINT){
    estado = 1;
  }else if(s == SIGUSR1 && estado == 3){
    printf("Tchau\n");
    exit(0);
  }else {
    estado = 0;
  }
}

int main(void){

  while(1){
    signal(SIGTERM, trataSinal);
    signal(SIGUSR1, trataSinal);
    signal(SIGUSR2, trataSinal);
    signal(SIGINT, trataSinal);
    pause();
  }
}
/*
SIGUSR1
SIGUSR1
SIGINT
SIGUSR2
SIGTERM
SIGTERM
SIGUSR1
SIGINT
SIGUSR2
SIGTERM
SIGUSR1*/