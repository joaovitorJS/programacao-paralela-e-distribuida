// Este programa faz somente imprimir na tela o hello word 

#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {

    // Tudo o que estiver dentro (MPI_init e MPI_Finalize) será executado em paralelo
    MPI_Init(&argc, &argv);
        printf("Hello World!\n");
    MPI_Finalize();

    return 0;
}       