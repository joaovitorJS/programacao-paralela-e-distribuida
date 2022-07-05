// Este programa apresenta o uso das funções de comunicação send e receive. Este programa basicamente faz com que a máquina 0 envie um inteiro para a máquina 1

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {

    int rank, size; // a variável rank identifica a máquina e a variável size identifica a quantidae de máquinas.

    int buffer, tag, origem, destino, qtdElementos; // a variável qtdElementos indica a quantidade de elementos que esta sendo enviada.

    MPI_Status status;

    // Tudo o que estiver dentro (MPI_init e MPI_Finalize) será executado em paralelo
    MPI_Init(&argc, &argv);

    // MPI_COMM_WORLD utiliza todos os processadores
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    tag = 10;
    origem = 0;
    destino = 1;
    qtdElementos = 1;

    if (rank == origem) 
    {
        buffer = 333;
        MPI_Send(&buffer, qtdElementos, MPI_INT, destino, tag, MPI_COMM_WORLD);
        printf("A máquina %d enviou o valor %d\n", rank, buffer);
    }

    if (rank == destino)
    {
        MPI_Recv(&buffer, qtdElementos, MPI_INT, origem, tag, MPI_COMM_WORLD, &status);
        printf("A máquina %d recebeu o valor %d\n", rank, buffer);
    }

    // Finaliza a parte que é executada em paralelo
    MPI_Finalize();

    return 0;
}       