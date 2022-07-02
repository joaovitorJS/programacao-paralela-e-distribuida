/*
Este programa mostra o uso das funções MPI Scatter e Gather.
Neste exemplo, cada processador recebe um valor diferente do
processador raiz utilizando a função MPI_Scatter().
Os dados são somados e então devolvidos ao processador raiz
utilizando-se a função MPI_Gather().
O processador raiz imprime a soma total.
*/

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int num_nos, meu_id, mpi_err; /*variáveis globais*/

#define processador_raiz 0

void init_it(int *argc, char ***argv);
void init_it(int *argc, char ***argv)
{
  mpi_err = MPI_Init(argc, argv);
  mpi_err = MPI_Comm_size(MPI_COMM_WORLD, &num_nos);
  mpi_err = MPI_Comm_rank(MPI_COMM_WORLD, &meu_id);
}

int main(int argc, char *argv[])
{
  int *meu_vetor, *eniva_vetor, *devolve_vetor;
  int contador;
  int tamanho, i, total;
  init_it(&argc, &argv);

  /* cada processador contará os elementos a partir do processador raiz */
  contador = 4;
  meu_vetor = (int *)malloc(contador * sizeof(int));

  /* cria ps dados que serão enviados pelo processador raiz */
  if (meu_id == processador_raiz)
  {
    tamanho = contador * num_nos;
    eniva_vetor = (int *)malloc(tamanho * sizeof(int));
    devolve_vetor = (int *)malloc(num_nos * sizeof(int));
    for (i = 0; i < tamanho; i++)
    {
      eniva_vetor[i] = i;
    }
  }

  /* envia diferentes dados para cada processador */
  mpi_err = MPI_Scatter(
      eniva_vetor, contador, MPI_INT,
      meu_vetor, contador, MPI_INT,
      processador_raiz,
      MPI_COMM_WORLD);

  /* cada processador realiza uma soma local */
  total = 0;
  for (i = 0; i < contador; i++)
  {
    total = total + meu_vetor[i];
  }

  printf("meu_id= %d, total= %d\n", meu_id, total);

  /* envia a soma local para o processador raiz */
  mpi_err = MPI_Gather(
      &total, 1, MPI_INT,
      devolve_vetor, 1, MPI_INT,
      processador_raiz,
      MPI_COMM_WORLD);

  /* o processador raiz imprime a soma total */
  if (meu_id == processador_raiz)
  {
    total = 0;
    for (i = 0; i < num_nos; i++)
    {
      total = total + devolve_vetor[i];
    }
    printf("resultados de todos os processadores = %d\n", total);
  }

  mpi_err = MPI_Finalize();

  return mpi_err;
}

/*SAIDA
mpirun -np 5 ./scatter_gather

meu_id= 0, total= 6
meu_id= 2, total= 38
meu_id= 4, total= 70
meu_id= 1, total= 22
meu_id= 3, total= 54
resultados de todos os processadores = 190
*/
