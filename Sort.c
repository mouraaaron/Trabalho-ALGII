#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"


/* Para comparar as trocas e comparações entre os 3 modelos de ordenação, tivemos que criar novamente as funções 
* do HEAP só que agora para inteiros, e não structs, pois o vetor é de 1024 inteiros aleatórios.
*/
void InsereHeapint(int Vetor[], int pos, int valor, int *comparacoes, int *trocas) {
    Vetor[pos] = valor;
    int i = pos;
    int temp;
    while (i > 1 && Vetor[i/2] < Vetor[i]) {
        (*comparacoes)++;
        temp = Vetor[i/2];
        Vetor[i/2] = Vetor[i];
        Vetor[i] = temp;
        (*trocas)++;
        i = i / 2;
    }
    if (i > 1) (*comparacoes)++; 
}

void Heapfyint(int Vetor[], int N, int *comparacoes, int *trocas) {
    for (int i = 2; i <= N; i++)
        InsereHeapint(Vetor, i, Vetor[i], comparacoes, trocas);
}

void SacodeHeapint(int Vetor[], int N, int *comparacoes, int *trocas) {
    int i = 2;
    int temp;
    while (i <= N) {
        if (i < N) {
            (*comparacoes)++;
            if (Vetor[i] < Vetor[i+1])
                i++;
        }
        (*comparacoes)++;
        if (Vetor[i/2] >= Vetor[i])
            break;
        temp = Vetor[i/2];
        Vetor[i/2] = Vetor[i];
        Vetor[i] = temp;
        (*trocas)++;
        i = i * 2;
    }
}

void HeapSortint(int Vetor[], int N, int *comparacoes, int *trocas) {
    int temp;
    Heapfyint(Vetor, N, comparacoes, trocas);
    for (int i = N; i > 1; i--) {
        temp = Vetor[1];
        Vetor[1] = Vetor[i];
        Vetor[i] = temp;
        (*trocas)++;
        SacodeHeapint(Vetor, i-1, comparacoes, trocas);
    }
}

int ChecaHeapint(int Vetor[], int N) {
    for (int i = N; i > 1; i--)
        if (Vetor[i] > Vetor[i/2])
            return 0;
    return 1;
}

void SelectionSort(int Vetor[], int N, int *comparacoes, int *trocas) {
    int i, j, menor, aux;

    for (i = 0; i < N; i++) { 
        menor = i;
        for (j = i + 1; j < N; j++) {
            (*comparacoes)++;
            if (Vetor[j] < Vetor[menor]) {
                menor = j;
            }
        } 
        if (menor != i) {
            aux = Vetor[menor];
            Vetor[menor] = Vetor[i];
            Vetor[i] = aux;
            (*trocas)++; 
        }
    }
}

void quicksort(int Vetor[], int esq, int dir, int *comparacoes, int *trocas) {
    int pos_pivo;
    
    if (esq < dir) {
        particao(Vetor, esq, dir, &pos_pivo, comparacoes, trocas);
        quicksort(Vetor, esq, pos_pivo - 1, comparacoes, trocas);
        quicksort(Vetor, pos_pivo + 1, dir, comparacoes, trocas);
    }
}

void particao(int Vetor[], int esq, int dir, int *pos_pivo, int *comparacoes, int *trocas) {
    int i, j, pivo, aux;
    int meio = esq + (dir - esq) / 2;

    if (Vetor[esq] > Vetor[meio]) {
        aux = Vetor[esq]; Vetor[esq] = Vetor[meio]; Vetor[meio] = aux;
        (*trocas)++;
    }
    if (Vetor[esq] > Vetor[dir]) {
        aux = Vetor[esq]; Vetor[esq] = Vetor[dir]; Vetor[dir] = aux;
        (*trocas)++;
    }
    if (Vetor[meio] > Vetor[dir]) {
        aux = Vetor[meio]; Vetor[meio] = Vetor[dir]; Vetor[dir] = aux;
        (*trocas)++;
    }

    aux = Vetor[esq];
    Vetor[esq] = Vetor[meio];
    Vetor[meio] = aux;
    (*trocas)++;

    pivo = Vetor[esq];

    i = esq;
    j = dir;
    
    while (i < j) {
        while ((Vetor[i] <= pivo) && (i < dir)) 
        { 
            (*comparacoes)++; 
            i++;
        }
        if (i == dir && Vetor[i] <= pivo) 
            (*comparacoes)++;
        
        while (Vetor[j] > pivo) 
        {
            (*comparacoes)++; // Contagem de comparação (Vetor[j] > pivo)
            j--;
        }
        if (i < j) 
        {
            aux = Vetor[j];
            Vetor[j] = Vetor[i];
            Vetor[i] = aux;
            (*trocas)++;
        }
    }
    Vetor[esq] = Vetor[j];
    Vetor[j] = pivo;
    (*trocas)++; 

    *pos_pivo = j;
}
