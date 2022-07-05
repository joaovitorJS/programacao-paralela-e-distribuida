// Exemplo de programa MPI que faz uso da função broadcast

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    int rank, size; // a variável rank identifica a máquina e a variável size identifica a quantidae de máquinas.
    int i, origem, cont; 
    int buffer[4];

    MPI_Status status;
    MPI_Request request;

    // Tudo o que estiver dentro (MPI_init e MPI_Finalize) será executado em paralelo
    MPI_Init(&argc, &argv);

    // MPI_COMM_WORLD utiliza todos os processadores
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    origem = 0;
    cont = 4;

    if (rank == origem) 
    {
        for (i = 0; i < cont; i++)
        {
            buffer[i] = i;
        } 
    }

    MPI_Bcast(buffer, cont, MPI_INT, origem, MPI_COMM_WORLD);

    for (i = 0; i < cont; i++) 
    {
        printf("Máquina: %d - Valor: %d -- ", rank, buffer[i]);
    }
    printf("\n");

    // Finaliza a parte que é executada em paralelo
    MPI_Finalize();

    return 0;
}       