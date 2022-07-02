/*
Programa simples utilizando a função coletiva MPI_Barrier()
*/

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
  int rank = 0, size;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (rank == 0)
  {
    printf("\nRank 0 antes do Barrier\n"); // Bloqueia 1
    fflush(stdout);
  }

  MPI_Barrier(MPI_COMM_WORLD);

  if (rank == 1)
  {
    printf("\nRank 1 depois do Barrier\n");
    fflush(stdout);
  }

  if (rank == 2)
  {
    printf("\nRank 2 depois do Barrier\n");
    fflush(stdout);
  }

  MPI_Finalize();
  return 0;
}

/*SAIDA


Rank 0 antes do Barrier

Rank 1 depois do Barrier

Rank 2 depois do Barrier


ou

Rank 0 antes do Barrier

Rank 2 depois do Barrier

Rank 1 depois do Barrier

Mas nunca o zero entre o 1 e 2
*/