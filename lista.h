#ifndef lista
#define lista
#include <stdio.h>

typedef struct paciente {
  char nome[50];
  int prioridade;
} paciente;

/* Inicia a fila de pacientes com todos valores zerados */
void InicHeap(paciente vetor[], int N);

/* Insere um novo paciente na posição final da fila e reajusta
   a estrutura para manter a propriedade de Heap. */
void InsereHeap(paciente Vetor[], int pos, paciente novo);

/* Verifica se o vetor de pacientes atual é um Heap válido,
   retornando 1 caso verdadeiro, ou 0 caso contrário. */
int ChecaHeap(paciente vetor[], int N);

/* Remove o paciente de maior prioridade do Heap e
   reestrutura a fila para manter a propriedade de Heap. */
void RemoveHeap(paciente Vetor[], int N);

/* Reestrutura a fila, garantindo que a propriedade de Heap seja mantida. */
void Heapfy(paciente vetor[], int N);

/* Imprime todos os pacientes presentes na fila. */
void ImprimeHeap(paciente Vetor[], int N);

/* Ordena a fila de pacientes utilizando o algoritmo Heap Sort. */
void HeapSort(paciente vetor[], int N);

/* Altera a prioridade de um paciente no índice fornecido para o novo valor */
void AlteraHeap(paciente Vetor[], int N , int indice_paciente, int nova_prioridade);

/* Função auxiliar que reestrutura um elemento do Heap para garantir a validade da propriedade. */
void SacodeHeap(paciente Vetor[], int N);


#endif
