#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[50];
  int prioridade;
} paciente;

void InsereHeap(paciente Vetor[], int pos, paciente novo) {
    Vetor[pos] = novo;  
    int i = pos;
    paciente temp;
    while (i > 1 && Vetor[i/2].prioridade < Vetor[i].prioridade) {
        temp = Vetor[i/2];
        Vetor[i/2] = Vetor[i];
        Vetor[i] = temp;
        i = i / 2;
    }
}

void Heapfy(paciente Vetor[], int N) {
  for (int i = 2; i <= N; i++)
    InsereHeap(Vetor, i);
}

int ChecaHeap(paciente Vetor[], int N) {
  for (int i = N; i > 1; i--)
    if (Vetor[i].prioridade > Vetor[i/2].prioridade)
      return 0;
  return 1;
}

void SacodeHeap(paciente Vetor[], int N) {
  int i = 2;
  paciente temp;
  while (i <= N) {
    if (i < N && Vetor[i].prioridade < Vetor[i+1].prioridade)
      i++;
    if (Vetor[i/2].prioridade >= Vetor[i].prioridade)
      break;
    temp = Vetor[i/2];
    Vetor[i/2] = Vetor[i];
    Vetor[i] = temp;
    i = i * 2;
  }
}

void HeapSort(paciente Vetor[], int N) {
  paciente temp;
  Heapfy(Vetor, N);
  for (int i = N; i > 1; i--) {
    temp = Vetor[1];
    Vetor[1] = Vetor[i];
    Vetor[i] = temp;
    SacodeHeap(Vetor, i - 1);
  }
}

void InicHeap(paciente Vetor[], int N) {
  for (int i = 1; i <= N; i++) {
    strcpy(Vetor[i].nome, "NULL");
    Vetor[i].prioridade = 0;
  }
}

void AlteraHeap(paciente Vetor[], int N, int indice_paciente, int nova_prioridade) {
  if (indice_paciente > N || indice_paciente < 1) {
    puts("O índice que você digitou não está correto");
    return;
  }

  if (Vetor[indice_paciente].prioridade == 0) {
    puts("Não há paciente inicializado na posição que você está tentando acessar");
    return;
  }

  Vetor[indice_paciente].prioridade = nova_prioridade;

  printf("A prioridade do paciente %s foi alterada para %d\n",
         Vetor[indice_paciente].nome, nova_prioridade);

  if (!ChecaHeap(Vetor, N)) {
    HeapSort(Vetor, N);
    printf("O Heap foi alterado\n");
  } else {
    printf("Mesmo com a alteração da prioridade, a ordem do Heap permanece a mesma.\n");
  }
}

void RemoveHeap(paciente Vetor[], int N) {
  for (int i = 1; i < N; i++) {
    strcpy(Vetor[i].nome, Vetor[i + 1].nome);
    Vetor[i].prioridade = Vetor[i + 1].prioridade;
  }
  strcpy(Vetor[N].nome, "NULL");
  Vetor[N].prioridade = 0;
  N--;

  if (!ChecaHeap(Vetor, N)) {
    HeapSort(Vetor, N);
    printf("O Heap foi alterado\n");
  } else {
    printf("Mesmo com a alteração da prioridade, a ordem do Heap permanece a mesma.\n");
  }
}

void ImprimeHeap(paciente Vetor[], int N) {
  for (int i = 1; i <= N; i++) {
    printf("Pessoa #%d:\n", i);
    printf(" Nome: %s\n", Vetor[i].nome);
    printf(" Prioridade: %d\n", Vetor[i].prioridade);
    printf("\n");
  }
}
