#ifndef lista
#define lista
#include <stdio.h>

typedef struct paciente {
  char nome[50];
  int prioridade;
} paciente;

void InicHeap(paciente vetor[], int N);
void InsereHeap(paciente Vetor[], int pos, paciente novo);
int ChecaHeap(paciente vetor[], int N);
void RemoveHeap(paciente Vetor[], int N);
void Heapfy(paciente vetor[], int N);
void ImprimeHeap(paciente Vetor[], int N);
void HeapSort(paciente vetor[], int N);
void AlteraHeap(paciente Vetor[], int N , int indice_paciente, int nova_prioridade);
void SacodeHeap(paciente Vetor[], int N);

#endif
