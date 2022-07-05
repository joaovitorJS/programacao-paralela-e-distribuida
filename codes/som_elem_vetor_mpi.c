/*
Soma dos elementos de uma vetor usando mpi
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi.h>

#define tamanho 10

int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int vetor_aux[1000];

int main(int argc, char *argv[])
{
  int rank, size, elem_por_proc, elem_receb;
  int indice, i;
  int elemento_esquerda, soma, temp, origem;
  int soma_parcial;

  MPI_Status status;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (rank == 0) /* Para o processador 0 */
  {
    /*
      elem_por_proc: é a quantidade de elementos para cada processador.
      Ou seja é o tamanho do vetor divido pela quantidade de processadores disponíveis
    */
    elem_por_proc = tamanho / size;

    /*
      Se existe mais de um processador para executar a tarefa
    */
    if (size > 1) /*verifica se há mais de um processo executando*/
    {
      for (i = 0; i < size; i++) /*distribui parte dos elementos do vetor para cada processo calcular parcialmente*/
      {
        indice = i * elem_por_proc;

        MPI_Send(&elem_por_proc, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        MPI_Send(&vetor[indice], elem_por_proc, MPI_INT, i, 0, MPI_COMM_WORLD);
      }

      // o último processo adiciona os elementos restantes
      indice = i * elem_por_proc;
      elemento_esquerda = tamanho - indice;

      MPI_Send(&elemento_esquerda, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
      MPI_Send(&vetor[indice], elemento_esquerda, MPI_INT, i, 0, MPI_COMM_WORLD);
    }

    // processo rank 0 adiciona os elementos do seu subarray

    soma = 0;
    for (i = 0; i < elem_por_proc; i++)
    {
      soma += vetor[i];
    }

    // coleta das somas parciais dos demais processos
    for (i = 0; i < size; i++)
    {
      MPI_Recv(&temp, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
      origem = status.MPI_SOURCE;
      soma += tempo;
    }

    // imprime a soma final do vetor
    printf("A soma do vetor eh: %d\n", soma);
  }
  else // demais processos
  {
    MPI_Recv(&elem_receb, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

    // armazena o segmento de soma recebido em vetor auxiliar
    MPI_Recv(&vetor_aux, elem_receb, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

    // calcula a soma parcial
    soma_parcial = 0;
    for (i = 0; i < elem_receb, i++)
    {
      soma_parcial += vetor_aux[i];
    }

    // envia a soma parcial para o processo rank 0
    MPI_Send(&soma_parcial, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
  }

  MPI_Finalize();
  return 0;
}
