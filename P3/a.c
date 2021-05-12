#include<stdio.h>
#include<stdlib.h>

#define PAGESIZE 4096
#define N 500000
char mat[N][PAGESIZE];

void funcao_A(char c)
{
  int i, j;
  for (i = 0; i < N; i++)
    for (j = 0; j < PAGESIZE; j++)
      mat[i][j] = c;
}
void funcao_B(char c)
{
  int i, j;
  for (j = 0; j < PAGESIZE; j++)
    for (i = 0; i < N; i++)
      mat[i][j] = c;
}
int main(void)
{
  funcao_A('*');
  // funcao_B('-');
  return 0;
}