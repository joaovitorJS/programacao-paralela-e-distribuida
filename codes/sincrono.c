#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int x, valor, rank, size, tag = 10;

  MPI_Status status;

  MPI_Init(&argc, &argv);

  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  // executar usando duas máquinas

  x = 99999;
  if (rank == 0)
  {
    printf("Máquina %d enviando para a máquina 1\n", rank);
    printf("Valor sendo enviado %d\n", x);
    MPI_Ssend(&x, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
    printf("Máquina %d recebendo da máquina 1\n", rank);
    MPI_Recv(&x, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, &status);
    printf("Máquina %d recebendo o valor %d\n", rank, x);
  }
  else
  { // trata da máquina 1
    MPI_Recv(&x, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
    x = x + 1;
    MPI_Ssend(&x, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
  }

  MPI_Finalize();

  return 0;
}
