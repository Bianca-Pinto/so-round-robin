#include<stdio.h>
#define TAM 10
 
int main(){
      int i, nProcessos, somaTempo = 0, x, contador = 0, quantum;
      // TAM --> tamanho do vetor, declarado para ingresso, duracao e temp
      // Deve ser pelo menos o tamanho ou maior do que o numero de tarefas
      int tempo_espera = 0, tempo_execucao = 0, ingresso[TAM], duracao[TAM], temp[TAM];
      float tempo_medio_espera, tempo_medio_execucao;

      // Inserindo o numero total de tarefas
      printf("\nInsira numero total de Processos:\t");
      scanf("%d", &nProcessos);
      x = nProcessos;

      for(i = 0; i < nProcessos; i++){
            printf("\nInsira detalhes da tarefa [t%d]\n", i + 1);
            // Inserindo o tempo de ingresso de cada tarefa
            printf("Ingresso:\t");
            scanf("%d", &ingresso[i]);
 
            // Inserindo o tempo de duracao de cada tarefa
            printf("Duracao:\t");
            scanf("%d", &duracao[i]);
 
            // Criando um vetor temporario para cada duracao
            temp[i] = duracao[i];
      }
 
      // Definicao do quantum (tempo de ciclo para o escalonamento)
      printf("\nInsira o Quantum:\t");
      scanf("%d", &quantum);

      printf("\nProcesso n\t\t Duracao\t Execucao\t Espera\n");
      for(somaTempo= 0, i = 0; x!=0;){
            // Se a duracao for menor ou igual ao quantum e maior do que 0
            if(temp[i] <= quantum && temp[i] > 0){
                  somaTempo = somaTempo + temp[i];
                  temp[i] = 0;
                  contador = 1;
            }
            // Se a duracao da tarefa for maior que o quantum
            else if(temp[i] > 0){
                  temp[i] = temp[i] - quantum;
                  somaTempo = somaTempo + quantum;
            }
            // Confere se a duracao do processo chegou ao fim
            if(temp[i] == 0 && contador == 1){
                  x--; //decrementa o numero do processo
                  printf("\nProcesso[%d] \t\t %d\t\t %d\t\t\t %d", i + 1, duracao[i], somaTempo - ingresso[i], somaTempo - ingresso[i] - duracao[i]);
                  tempo_espera = tempo_espera + somaTempo - ingresso[i] - duracao[i];
                  tempo_execucao = tempo_execucao + somaTempo - ingresso[i];
                  contador = 0;
            }
            // Confere se i chegou ao final da lista de processos
            if(i == nProcessos-1){
                  i = 0;
            }
            // Verifica se algum processo ingressou enquanto o outro estava executando
            else if(ingresso[i+1] <= somaTempo){
                  i++;
            }
            else{
                  i = 0;
            }
      }
 
      tempo_medio_execucao = (float)tempo_execucao/nProcessos;
      printf("\nTempo medio de execucao:\t%f\n", tempo_medio_execucao);

      tempo_medio_espera = (float)tempo_espera/nProcessos;
      printf("\n\nTempo medio de espera:\t%f", tempo_medio_espera);
      return 0;
}
