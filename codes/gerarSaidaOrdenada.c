/**
 * Gerar uma saída ordenada
 * 
 * -> Identidica as máquinas por meio do rank
 *  - rank identifica a máquina
 *  - size identifica a qtd de máquina
*/

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  int rank, size; // a variável rank identifica a máquina e a variável size identifica a quantidae de máquinas.

  int token;

  // Tudo o que estiver dentro (MPI_init e MPI_Finalize) será executado em paralelo
  MPI_Init(NULL, NULL);

  // MPI_COMM_WORLD utiliza todos os processadores
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (rank != 0)
  {
    MPI_Recv(&token, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("A máquina %d recebeu o token %d da máquina %d\n", rank, token, (rank-1));
  }
  else
  {
    token = -1;
  }
  
  MPI_Send(&token, 1, MPI_INT, ((rank+1)%size), 0, MPI_COMM_WORLD);

  if (rank == 0) 
  {
    MPI_Recv(&token, 1, MPI_INT, size-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("A máquina %d recebeu o token %d da máquina %d\n", rank, token, size-1);    
  }

  // Finaliza a parte que é executada em paralelo
  MPI_Finalize();

  return 0;
}
