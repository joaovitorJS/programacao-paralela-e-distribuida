// Este exemplo utiliza a função MPI reduce

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

#define RAIZ 0

int main(int argc, char** argv) {

    int rank, size; // a variável rank identifica a máquina e a variável size identifica a quantidae de máquinas.
    int valores, reduced;
    int reduce = 0; 

    // Tudo o que estiver dentro (MPI_init e MPI_Finalize) será executado em paralelo
    MPI_Init(&argc, &argv);

    // MPI_COMM_WORLD utiliza todos os processadores
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    valores = rank + 1;

    MPI_Reduce( (const void*)&valores, (void*)&reduced , 1, MPI_INT, MPI_SUM , RAIZ, MPI_COMM_WORLD);
    
    if (rank == 0) {
        printf("Soma = %d", reduced);
    }

    // Finaliza a parte que é executada em paralelo
    MPI_Finalize();

    return 0;
}       