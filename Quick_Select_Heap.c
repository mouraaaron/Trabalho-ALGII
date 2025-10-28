#include <stdio.h>
#include <stdlib.h>
#define N 1024


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
    if (i > 1) (*comparacoes)++; // última comparação que quebrou o while
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

void quicksort(int Vetor[], int esq, int dir){
    int pos_pivo;
    if(esq<dir){
        particao(Vetor, esq, dir, *pos_pivo);
        quicksort(Vetor, esq, pos_pivo
    }
}

void particao(int vetor[]; int esq, int dir, int *pos_pivo){
    int i,j,pivo,aux;
    pivo 
}
}
