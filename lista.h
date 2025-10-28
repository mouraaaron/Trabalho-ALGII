#ifndef lista
#define lista
#include <stdio.h>

struct paciente;

void InicHeap(int n, int vetor[]);
void InsereHeap(int n, int vetor[]);
int ChecaHeap(int vetor[]);
void RemoveHeap(int n, int vetor[]);
void Heapfy(int vetor[])
ImprimeHeap(int vetor[]);
void HeapSort(int vetor[]); 
void AlteraHeap(int vetor[]);
