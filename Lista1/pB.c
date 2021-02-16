/*EOF
EOF (End Of File) representa o fim de arquivo. Enquanto se está lendo um arquivo e não existe mais conteúdo a ser lido é gerada essa informação no sistema, EOF, dizendo que o arquivo acabou.

A entrada padrão também é considerada um arquivo e em uma execução sem redirecionamento a combinação ^d (control + d) gera um EOF. Quando a acontece o redirecionamento (a execução no estilo: ./meuprograma < arquivo) o conteúdo do arquivo é enviado ao programa pela entrada padrão e quando todo o conteúdo do arquivo for consumido o EOF será gerado.

A função scanf no C, trata esse efeito. Por isso ela deve ser bem estudada. Como um resumo rápido: A função scanf retorna quantos elementos de % foram lidos com sucesso, então uma chamada do tipo:

scanf("%d %lf", &a,&b)
Retornará 2 quando ambos números forem lidos com sucesso, e:

scanf("%s %d %s %d",str1,&a,str2,&b)
Retornará 4 quando todos forem lidos com sucesso, e:

scanf("%d",&a)
Retornará 1 quando o número for lido com sucesso.

Caso o retorno de scanf for diferente da quantidade de %, significa que algum erro ocorreu, geralmente o EOF.

Segue o trecho do manual do scanf (man 3 scanf) que trata do valor de retorno da função:

RETURN VALUES
These functions return the number of input items assigned. This can be fewer than provided for, or even zero, in the event of a matching failure. Zero indicates that, although there was input available, no conversions were assigned; typically this is due to an invalid input character, such as an alphabetic character for a `%d’ conversion. The value EOF is returned if an input failure occurs before any conversion such as an end-of-file occurs. If an error or end-of-file occurs after conversion has begun, the number of conversions which were successfully completed is returned.

TAREFA
Para este problema você deverá ler diversos números e imprimir a quantidade de números lidos.

ENTRADA
A entrada é composta por um único caso de teste composta por diversas linhas e termina com EOF. Cada linha de um caso de teste possui um número inteiro N ( 0 \leq N \leq 10^7 ).

SAÍDA
A saída é composta por uma única linha contendo um número inteiro que represente a quantidade de números lidos.

EXEMPLOS
Exemplo de Entrada
2
3
4
5
6
7
8
9
Exemplo de Saída
8
Exemplo de Entrada
1000
300000
35530
3920753
3297323
Exemplo de Saída
5
Author: Bruno Ribas*/

#include<stdio.h>

int main(void){
  int qtdNum=0, x;

  while(scanf(" %d", &x)==1){
    qtdNum++;
  }
  printf("%d\n", qtdNum);
  return 0;
}