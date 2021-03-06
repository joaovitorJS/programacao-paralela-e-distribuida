// Este prograa apresenta o uso das funções de comunicação send e receive. Este programa basicamente faz com que a máquina 0 envie um inteiro para a máquina 1

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    int rank, size; // a variável rank identifica a máquina e a variável size identifica a quantidae de máquinas.
    int x, valor, tag = 10; 

    MPI_Status status;

    // Tudo o que estiver dentro (MPI_init e MPI_Finalize) será executado em paralelo
    MPI_Init(&argc, &argv);

    // MPI_COMM_WORLD utiliza todos os processadores
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    // Finaliza a parte que é executada em paralelo
    MPI_Finalize();

    return 0;
}       