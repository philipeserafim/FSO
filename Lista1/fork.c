#include<signal.h>
#include<sys/stat.h>
#include<stdio.h>

int i = 0;

void filho(){
  printf("Filho nº %d\n", i++);
}

int main (void){
  
  int x;

  scanf(" %d", &x);
  for(int i = 0; i < x; i++){
    if(fork()==0) filho();
  }

  return 0;
}