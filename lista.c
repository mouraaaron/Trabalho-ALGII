#include <stdio.h>
#include <stdlib.h>
#inclue <string.h>
#include "lista.h"

typedef struct {
  char nome[50];
  int prioridade;
}paciente;



void InsereHeap(paciente Vetor[], int N)
{
  int aux;
  int i = N + 1;
  while (i>1 && vetor[i/2]<vetor[i])
  {  
    aux = vetor[i/2];
    vetor[i/2] = vetor[i];
    vetor[i] = aux;
    i = i/2;
  }
}

void Heapfy(paciente Vetor[], int N)
{
  int i;
  for (i=1; i<N; i++)
    InsereHeap(i, Vetor);
}

int checaHeap(paciente Vetor[], int N)
{
  int i = N;
  for (i=N; i>1; i--)
    if (Vetor[i].prioridade > Vetor[i/2].prioridade)
      return 0;
  return 1;
}

void SacodeHeap (paciente Vetor[], int N)
{
  int aux;
  int i = 2;
  while (i <= tam)
  {
    if (i<tam && Vetor[i]<Vetor[i+1])
      i++;
    if (Vetor[i/2] >= Vetor[i])
      break;
    aux = Vetor[i/2];
    Vetor[i/2] = Vetor[i];
    Vetor[i] = aux;
    i = i * 2;
  }
}

void HeapSort(paciente Vetor[], int N)
{
  int i, aux;
  Heapfy(vetor);
  for (i=N; i>1; i--)
  {
    aux = Vetor[1];
    Vetor[1] = Vetor[i];
    Vetor[i] = aux;
    SacodeHeap(i-1, Vetor);
  }
}

void InicHeap(paciente vetor[], int N){
  for(int i = 0; i < N; i++){
    strcpy(vetor[i].nome, "NULL");
    vetor[i].prioridade = 0;
    
  }
  
}


// a função alteraheap recebe o vetor, o paciente que vai ter prioridade alterada e a nova prioridade
void AlteraHeap(paciente Vetor[], int N , int indice_paciente, int nova_prioridade){
  if(indice_paciente >= N){
    puts("O índice que você digitou não está correto");
    return;
   }
  
  if(vetor[indice_paciente].prioridade == 0){ //nesse caso, o paciente desse índice não foi inicializado ainda
    puts("Não há paciente inicializado na posição que você está tentando acessar");
    return;
  }
  
  int prioridade_antiga = vetor[indice_paciente].prioridade;
  vetor[indice_paciente].prioridade = nova_prioridade;

  printf("A prioridade do paciente %s foi alterada para %d\n", vetor[indice_paciente].nome, nova_prioridade);

  if(!ChecaHeap(vetor)){
    Heapfy(vetor, N);
    printf("O Heap foi alterado\n");
  }
  else 
    printf("Mesmo com a alteração da prioridade, a ordem do Heap permanece a mesma.\n");
  
  }

void RemoveHeap(paciente Vetor[], int N, )














