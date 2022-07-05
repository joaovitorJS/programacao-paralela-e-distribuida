// Este programa imprime a frase com a identificação e o total de processos envolvidos na execução

#include <mpi.h>
#include <stdio.h>

int rank;
int size;

int main(int argc, char** argv) {

    // Tudo o que estiver dentro (MPI_init e MPI_Finalize) será executado em paralelo
    MPI_Init(&argc, &argv);

    // MPI_COMM_WORLD utiliza todos os processadores
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf("E ai, sou o processador %d de um total de %d processadores\n", rank, size);

    MPI_Finalize();

    return 0;
}       

/*
EREW -> cluster
*/