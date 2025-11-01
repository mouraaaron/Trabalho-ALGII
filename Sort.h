#include <stdio.h>
#ifndef SORT_H
#define SORT_H

/* Constrói uma estrutura de Heap a partir do Vetor
   desordenado de tamanho 'N', atualizando as contagens de comparacoes e trocas. */
void InsereHeapint(int Vetor[], int pos, int valor, int *comparacoes, int *trocas);

/* Constrói uma estrutura de Heap a partir do Vetor
   desordenado de tamanho 'N', atualizando as contagens de comparacoes e trocas. */
void Heapfyint(int Vetor[], int N, int *comparacoes, int *trocas);

/* Restaura a propriedade de Heap no subvetor de tamanho 'N',
  peneirando o elemento para baixo e atualizando as contagens de comparacoes e trocas. */
void SacodeHeapint(int Vetor[], int N, int *comparacoes, int *trocas);

/* Ordena o Vetor de tamanho 'N' utilizando o algoritmo Heap Sort,
   atualizando as contagens de comparacoes e trocas. */
void HeapSortint(int Vetor[], int N, int *comparacoes, int *trocas);

/* Verifica se o Vetor de tamanho 'N' é uma estrutura de Heap válida,
   retornando 1 caso verdadeiro, ou 0 caso contrário. */
int ChecaHeapint(int Vetor[], int N);

/* Ordena o subvetor entre as posições 'esq' e 'dir' de forma recursiva,
   aplicando o algoritmo Quick Sort e atualizando as contagens
   de comparacoes e trocas. */
void quicksort(int Vetor[], int esq, int dir, int *comparacoes, int *trocas);

/* Ordena o Vetor de tamanho 'N' utilizando o algoritmo Selection Sort,
   atualizando as contagens de comparacoes e trocas. */
void SelectionSort(int Vetor[], int N, int *comparacoes, int *trocas);

/* Função auxiliar do Quick Sort que reorganiza o subvetor para posicionar
   o elemento pivô em sua posição final correta ('*pos_pivo'), separando
   os elementos menores e maiores, e atualizando as contagens de comparacoes
   e trocas. */
void particao(int Vetor[], int esq, int dir, int *pos_pivo, int *comparacoes, int *trocas);

#endif
