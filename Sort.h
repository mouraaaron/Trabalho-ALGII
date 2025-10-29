#include <stdio.h>
#ifndef SORT_H
#define SORT_H

void InsereHeapint(int Vetor[], int pos, int valor, int *comparacoes, int *trocas);
void Heapfyint(int Vetor[], int N, int *comparacoes, int *trocas);
void SacodeHeapint(int Vetor[], int N, int *comparacoes, int *trocas);
void HeapSortint(int Vetor[], int N, int *comparacoes, int *trocas);
int ChecaHeapint(int Vetor[], int N);
void quicksort(int Vetor[], int esq, int dir, int *comparacoes, int *trocas);
void SelectionSort(int Vetor[], int N, int *comparacoes, int *trocas);
void particao(int Vetor[], int esq, int dir, int *pos_pivo, int *comparacoes, int *trocas);

#endif
