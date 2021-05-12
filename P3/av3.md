% Aluno *Philipe Rosa Serafim*, Matrícula *160141842*

# Enunciados
 - https://moj.naquadah.com.br/contests/bcr-FSO-2020_2-avaliacao-3/prova.pdf
.
# Questão 1
Nao, caso isso viesse a ocorrer, o sistema não saberia como realizar o page in para lidar com o page fault. Tanto que quando algumas bibliotecas são atualizadas/reinstaladas é necessário reiniciar para que os processos possam identificar os novos endereços das funções.
.
# Questão 2
## Item A
### Subitem 1
0001 0000 0000 0111 (4103 ou #4103)
.
### Subitem 2
0011 0000 1010 0000 (12448 ou #30A0)
.
### Subitem 3
0110 0000 0000 0101 (24581 ou #6005)
.
### Subitem 4
Page fault
.
### Subitem 5
0010 0000 0000 0000 (8192 ou #2000)
.
## Item B
Não e Sim. Na paginação a informação não precisa ser guardada sequencialmente, o que elimina a paginação externa. E gera fragmentação interna pois as páginas possuem tamanho pre-determinado, com isso nem sempre o processo utilizará uma página por completo
.
# Questão 3
Não, caso fosse implementado em software para todo acesso à memória seria necessário tirar o processo do processador, chamar o sistema operacional e determinar se uma região de memória está disponível ou não
.
# Questão 4
## Item A
A funcao_A será executada mais rápido
.
## Item B
No momento que o loop interno da funcao_A acessa o primeiro i,j (0,0) ele realiza o page in que carrega o primeiro quadro e faz a atribuição indicada em todos os j's. Já na funcao_B, como o laço interno "fixa" o j e percorre todos os índices i, será necessário realizar o page in para atribuir apenas um índice j, com isso será realizado um page in para cada atribuição de j visto que quando ocorrer o j++, os quadros referentes ao i's iniciais já foram substituídos, o que geraria TLB miss ou page fault
.
