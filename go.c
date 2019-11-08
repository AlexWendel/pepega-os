#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "fila.h"
#include <unistd.h>

#define MAX_PROCESS 10
#define MAX_Q 5

Fila ordenar(Fila f){
	Itemf iprocess, next_process;
	Fila ordenado = fila(MAX_PROCESS);
	int i, j, total = totalf(f);
	
	for(j = 0; j < total; j++){
		iprocess = desenfileira(f);
		for(i = 0; i < totalf(f); i++){
			
			next_process = desenfileira(f);
			
			if(iprocess->priority <= next_process->priority){
				enfileira(next_process, f);
			}else{
				enfileira(iprocess, f);
				iprocess = next_process;
			}
		}
		enfileira(iprocess, ordenado);
	}
	
		return ordenado;
	
}

int main(){
	srand(time(NULL));
    int i;
    Itemf running = NULL; // processo_
    Fila process_list = fila(MAX_PROCESS);
    Fila waiting_list = fila(MAX_PROCESS);
    Fila ready_list = fila(MAX_PROCESS);
    
    for(i = 0; i < MAX_PROCESS; i++){
    	Itemf iprocess = malloc(sizeof(struct process));
    	iprocess->priority = rand() % 5;
    	iprocess->progress = (rand() % 10) +1;
    	iprocess->q_process = 0;
    	iprocess->pid = i;
    	enfileira(iprocess, ready_list);
    	ready_list = ordenar(ready_list);
    	printf("Processo %d criado, Prioridade: %d, Progresso: %d, Quantum: %d\n", iprocess->pid, iprocess->priority, iprocess->progress, iprocess->q_process);
	}
	printf("%d\n", ready_list->total);
	

    while (1){

        
        // Mesmo que não haja, consiga um processo para ser executado
        if (!running && !vaziaf(ready_list)){
			running = desenfileira(ready_list);
			printf("Processo %d executando, total: %d\n", running->pid, ready_list->total);
			sleep(2);
		}
	
            
        //Checar se há um processo em execução, se houver: checar quantum
        if(running && running->q_process >= MAX_Q){
        	printf("Processo %d saiu de execucao\n", running->pid);
        	sleep(2);
        	running->q_process = 0;
            enfileira(running, ready_list);
            running = NULL;
            ready_list = ordenar(ready_list);
        }
        
        // O progresso do processo chegou em 0
        if (running && running->progress == 0){
        	printf("Processo %d terminou de ser executado\n", running->pid);
        	sleep(2);
			free(running);
			running = NULL;
		}
        
		if(running){
            // Decrementação do processo
            running->progress -= 1;
            running->q_process += 1; 
            printf("Processo: %d Progresso %d Quantum %d\n", running->pid, running->progress, running->q_process);
            sleep(2);
        }
        
    }
    
    return 0;
}
