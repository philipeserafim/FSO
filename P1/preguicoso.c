/*Preguiçoso até demais…
Preâmbulo
Os trabalhos remotos conseguem ser muito estressantes para todos. E quem mais está sofrendo nessa época são os pobre e bobinhos computadores. Sempre ficam fazendo operações sem parar.

Para ajudar o computador a ficar um pouco mais alegre, Fulano de tal resolveu escrever um programa um tanto quanto peculiar. O programa é um processo dorminhoco!

A ideia deste processo é que ele fica sem fazer nada (sem gastar CPU) até que receba um sinal SIGUSR1, e nesse momento ele deve escrever na tela uma linha contendo a frase "SIGUSR1 eh para aproveitar mais um pouco", e volta a fazer nada.

No entanto, quando ele recebe o sinal SIGALRM o processo deverá imprimir na tela a linha com a frase "Ai que sono, quero dormir mais um pouco", e volta, advinhe, a fazer nada.

Quando receber SIGALRM pela terceira vez, ele deverá imprimir na tela a linha com "Os incomodados que se mudem, tchau" e deve finalizar com exit status 0.

Exemplos
Exemplo 1
Supondo a seguinte ordem de sinais:

SIGUSR1
SIGALRM
SIGALRM
SIGALRM
Seu programa deverá imprimir:

SIGUSR1 eh para aproveitar mais um pouco
Ai que sono, quero dormir mais um pouco
Ai que sono, quero dormir mais um pouco
Os incomodados que se mudem, tchau
Exemplo 2
Supondo a seguinte ordem de sinais:

SIGUSR1
SIGALRM
SIGALRM
SIGUSR1
SIGALRM
Seu programa deverá imprimir:

SIGUSR1 eh para aproveitar mais um pouco
Ai que sono, quero dormir mais um pouco
Ai que sono, quero dormir mais um pouco
SIGUSR1 eh para aproveitar mais um pouco
Os incomodados que se mudem, tchau
Author: Bruno Ribas*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<signal.h>

int estado = 0;

void tratadorSinal(int s){
  if(s==SIGUSR1){
    printf("SIGUSR1 eh para aproveitar mais um pouco\n");
  }else if(s==SIGALRM && estado == 2){
    printf("Os incomodados que se mudem, tchau\n");
    exit(0);
  }else{
    printf("Ai que sono, quero dormir mais um pouco\n");
    estado++;
  }
}

int main (void){
  signal(SIGALRM, tratadorSinal);
  signal(SIGUSR1, tratadorSinal);

  while(1){
    pause();
  }

}