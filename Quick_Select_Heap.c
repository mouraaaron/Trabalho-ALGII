#include <stdio.h>
#include <stdlib.h>
#define N 1024


void InsereHeapInt(int Vetor[], int pos, int valor, int *comparacoes, int *trocas) {
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
    if (i > 1) (*comparacoes)++; // última comparação que quebrou o while
}

void HeapfyInt(int Vetor[], int N, int *comparacoes, int *trocas) {
    for (int i = 2; i <= N; i++)
        InsereHeapInt(Vetor, i, Vetor[i], comparacoes, trocas);
}

void SacodeHeapInt(int Vetor[], int N, int *comparacoes, int *trocas) {
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

void HeapSortInt(int Vetor[], int N, int *comparacoes, int *trocas) {
    int temp;
    HeapfyInt(Vetor, N, comparacoes, trocas);
    for (int i = N; i > 1; i--) {
        temp = Vetor[1];
        Vetor[1] = Vetor[i];
        Vetor[i] = temp;
        (*trocas)++;
        SacodeHeapInt(Vetor, i-1, comparacoes, trocas);
    }
}

int ChecaHeapInt(int Vetor[], int N) {
    for (int i = N; i > 1; i--)
        if (Vetor[i] > Vetor[i/2])
            return 0;
    return 1;
}
