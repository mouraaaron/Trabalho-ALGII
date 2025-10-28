#include <stdio.h>
#include <string.>
#include <stdlib.h>



void InsereHeap(paciente Vetor[], int pos, paciente novo, int *comparacoes, int *trocas) {
    Vetor[pos] = novo;
    int i = pos;
    paciente temp;
    while (i > 1 && Vetor[i/2].prioridade < Vetor[i].prioridade) {
        (*comparacoes)++;
        temp = Vetor[i/2];
        Vetor[i/2] = Vetor[i];
        Vetor[i] = temp;
        (*trocas)++;
        i = i / 2;
    }
    if (i > 1) (*comparacoes)++; // última comparação que quebrou o while
}

void Heapfy(paciente Vetor[], int N, int *comparacoes, int *trocas) {
    for (int i = 2; i <= N; i++)
        InsereHeap(Vetor, i, Vetor[i], comparacoes, trocas);
}

void SacodeHeap(paciente Vetor[], int N, int *comparacoes, int *trocas) {
    int i = 2;
    paciente temp;
    while (i <= N) {
        if (i < N) {
            (*comparacoes)++;
            if (Vetor[i].prioridade < Vetor[i+1].prioridade)
                i++;
        }
        (*comparacoes)++;
        if (Vetor[i/2].prioridade >= Vetor[i].prioridade)
            break;
        temp = Vetor[i/2];
        Vetor[i/2] = Vetor[i];
        Vetor[i] = temp;
        (*trocas)++;
        i = i * 2;
    }
}

void HeapSort(paciente Vetor[], int N, int *comparacoes, int *trocas) {
    paciente temp;
    Heapfy(Vetor, N, comparacoes, trocas);
    for (int i = N; i > 1; i--) {
        temp = Vetor[1];
        Vetor[1] = Vetor[i];
        Vetor[i] = temp;
        (*trocas)++;
        SacodeHeap(Vetor, i-1, comparacoes, trocas);
    }
}

int ChecaHeap(paciente Vetor[], int N) {
  for (int i = N; i > 1; i--)
    if (Vetor[i].prioridade > Vetor[i/2].prioridade)
      return 0;
  return 1;
}


