# PPD - Algoritmos usando MPI

## Compilando seu programa MPI

Compile usando `mpicc` para programa em C e `mpic++` para programas em C++.

Exemplo: 

```bash
mpicc helloWorld.c -o helloWorld
```

## Rodando um programa MPI

1. Passo: Iniciar o `lamboot`:
    * Inicie com `lamboot <options> <hostfile>`
    * A `option` **-v** (verbose), mostra alguns mensagens extras
    * Use o comando `lamnodes` para mostrar a quantidade de computadores que estão no universo LAM

2. Paso: 

  * criar um arquivo txt
      - hosts
      - lamhosts
  * gravá-lo na pasta onde está o executável

  * o que tem nesse arquivo?
      - Estrutura
      Nome    IP da máquina

      - obs: O primeiro nome deve ser da máquina rank 0 (a máquina em que você está trabalhando)

  * Tanto o executável quanto o aqrquivo com o nome das máquinas devem estar em todos os outros presentes no cluster.

  * Para transferir os arquivos para as demais máquinas utilize o comando:
      ```bash
      scp origem destino
      ``` 

Links usados como referência

http://parallel.vub.ac.be/documentation/mpi/Cmpi.html#run

https://curc.readthedocs.io/en/latest/programming/MPI-C.html

/*Exemplos com broadcast e reduce*/
https://mpitutorial.com/tutorials/
