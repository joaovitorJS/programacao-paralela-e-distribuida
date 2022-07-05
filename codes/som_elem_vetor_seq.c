/*
Soma dos elementos de um vetor - Sequencial
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Criar um vetor com 10 elementos numéricos inteiros randômicos
Calcular a soma deste elementos a exibir o vetor e a soma
*/

int main()
{
  /* declaração das variáveis*/
  srand(time(NULL));
  int i;
  long long int tamanho = 1000000; /*tamanho máximo para 8 Giga de memória*/
  unsigned long long int vetor[tamanho], soma = 0;

  /* entrada dos valores randômicos */
  for (i = 0; i < tamanho; i++)
  {
    vetor[i] = 1 + rand() * 10;
  }

  /* calculo da soma */
  for (i = 0; i < tamanho; i++)
  {
    soma = soma + vetor[i];
  }

  printf("\n\nSoma: %llu\n\n", soma);
  return 0;
}