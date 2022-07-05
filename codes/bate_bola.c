// programa que executa uma comunicação entre duas máquinas de forma sícrona
// Executar somente com duas máquinas.

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    const int limite_jogadas = 10;

    MPI_Init(NULL, NULL);

    int rank, size, contador = 0;
    int origem;

    MPI_Comm_rank( MPI_COMM_WORLD , &rank);
    MPI_Comm_size( MPI_COMM_WORLD , &size);


    if (size != 2) 
    {
        fprintf(stderr, "Este programa deve ser executado com o número de máquinas igual a 2 %s\n", argv[0]);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    origem = (rank + 1) % 2;
    while (contador < limite_jogadas) 
    {
        if (rank == contador % 2)
        {
            contador++;
            MPI_Send( &contador , 1, MPI_INT , origem , 0 , MPI_COMM_WORLD);
            printf("Máquina %d passou a bola para a máquina %d e incrementou o contador em %d\n", rank, origem, contador);
        }
        else
        {
            MPI_Recv(&contador, 1, MPI_INT, origem, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("A máquina %d recebeu a bola com o contador %d da máquina %d\n", rank, contador, origem);
        }
    }

    MPI_Finalize();
    return 0;
}

