// Exercício 1: Implementar a função broadcast usando Send e Recive

#include <stdio.h>
#include <mpi.h>

void JOAO_Bcast(void* buffer, int cont, MPI_Datatype datatype, int origem, MPI_Comm comm)
{ 
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == origem)
    {        
        MPI_Send(&buffer, 1, datatype, 1, 0, comm);
    }
    else
    {
        MPI_Recv(&buffer, 1, datatype , origem, 0, comm , 0);
    }
    
}


int main( int argc, char *argv[])
{
    int rank, size;
    int i, origem, cont; 
    int buffer[4];


    MPI_Init(&argc, &argv);
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

    JOAO_Bcast(buffer, cont, MPI_INT, origem, MPI_COMM_WORLD);
    
    for (i = 0; i < cont; i++) 
    {
        printf("Máquina: %d - Valor: %d -- ", rank, buffer[i]);
    }
    printf("\n");

    MPI_Finalize();
    
    return 0;
}