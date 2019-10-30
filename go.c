#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "fila.h"
#include "process.h"

#define MAX_PROCESS 25
#define MAX_Q 10

process_ get_next_process(Lista process_list){
    Fila *process = desenfileira(process_list);
    return process    
}

int main(){
    int n_process, q_process;

    Itemf *running = NULL; // processo_
    Fila process_list = fila(MAX_PROCESS);
    Fila waiting_list = fila(MAX_PROCESS);
    Fila ready_list = fila(MAX_PROCESS);

    while (1){

        // Mesmo que não haja, consiga um processo para ser executado
        if (!running && !vaziaf(ready_list))
            *running = desenfileira(ready_list);

        // Checar se há um processo em execução, se houver: checar quantum
        else if(running && q_process >= MAX_Q){
            enfileira(*running, ready_list);
            *running = desenfileira(ready_list);
        }
        
        // O progresso do processo chegou em 0
        if (running && running->progress == 0) free(running);
        else if(running){
            // Decrementação do processo
            running->progress -= 0.1;
            q_process += 1; 
        }
    }
    return 0;
}