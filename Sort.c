#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"


/* Para comparar as trocas e comparações entre os 3 modelos de ordenação, tivemos que criar novamente as funções 
* do HEAP só que agora para inteiros, e não structs, pois o vetor é de 1024 inteiros aleatórios. */

void InsereHeapint(int Vetor[], int pos, int valor, int *comparacoes, int *trocas) {
    Vetor[pos] = valor;
    int i = pos; 
    int temp;
    
    while (i > 0 && Vetor[(i - 1) / 2] < Vetor[i]) {
        (*comparacoes)++;
        
        temp = Vetor[(i - 1) / 2];
        Vetor[(i - 1) / 2] = Vetor[i];
        Vetor[i] = temp;
        (*trocas)++;
        
        i = (i - 1) / 2;
    }
    if (i > 0) 
        (*comparacoes)++; 
}


void Heapfyint(int Vetor[], int N, int *comparacoes, int *trocas) {
    for (int i = 1; i < N; i++)
        InsereHeapint(Vetor, i, Vetor[i], comparacoes, trocas);
}


void SacodeHeapint(int Vetor[], int N, int *comparacoes, int *trocas) {
    int i = 0; 
    int maior_idx; 
    int temp;
    
    while ((2 * i + 1) < N) {
        maior_idx = 2 * i + 1;
        
        if ((2 * i + 2) < N) {
            (*comparacoes)++; 
            if (Vetor[2 * i + 2] > Vetor[2 * i + 1])
                maior_idx = 2 * i + 2; 
        }
        
        (*comparacoes)++;
        if (Vetor[i] >= Vetor[maior_idx])
            break; 

        temp = Vetor[i];
        Vetor[i] = Vetor[maior_idx];
        Vetor[maior_idx] = temp;
        (*trocas)++;
        
        i = maior_idx;
    }
}

void HeapSortint(int Vetor[], int N, int *comparacoes, int *trocas) {
    int temp;
    
    Heapfyint(Vetor, N, comparacoes, trocas);
    
    for (int i = N - 1; i > 0; i--) {
        temp = Vetor[0];
        Vetor[0] = Vetor[i];
        Vetor[i] = temp;
        (*trocas)++;
        
        SacodeHeapint(Vetor, i, comparacoes, trocas);
    }
}


int ChecaHeapint(int Vetor[], int N) {
    for (int i = N - 1; i > 0; i--)
        if (Vetor[i] > Vetor[(i - 1) / 2])
            return 0; 
    return 1; 
}

void SelectionSort(int Vetor[], int N, int *comparacoes, int *trocas) {
    int i, j, menor_i;

    for (i = 0; i < N - 1; i++) {
        menor_i = i;
        for (j = i + 1; j < N; j++) {
            (*comparacoes)++;
            if (Vetor[j] < Vetor[menor_i]) {
                menor_i = j;
            }
        }

        if (menor_i != i) {
            int temp = Vetor[i];
            Vetor[i] = Vetor[menor_i];
            Vetor[menor_i] = temp;

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

    (*comparacoes)++;
    if (Vetor[esq] > Vetor[meio]) {
        aux = Vetor[esq]; Vetor[esq] = Vetor[meio]; Vetor[meio] = aux;
        (*trocas)++;
    }

    (*comparacoes)++;
    if (Vetor[esq] > Vetor[dir]) {
        aux = Vetor[esq]; Vetor[esq] = Vetor[dir]; Vetor[dir] = aux;
        (*trocas)++;
    }
    
    (*comparacoes)++;
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
            (*comparacoes)++; 
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
