#include "lista.h" 
#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXPACIENTES 4
#define TAMANHO_VETOR 1024
#define LIMITE_VETOR 1025
#define TAMANHO_VETOR_MENOR 32
#define LIMITE_MAXIMO_MENOR 64

struct paciente leNovoPaciente ()
{
	struct paciente novoPaciente;
        
    printf("Digite o nome do paciente: ");
    scanf("%49s", novoPaciente.nome);

    printf("Digite a prioridade do paciente: ");
	scanf("%d", &novoPaciente.prioridade);
    
    return novoPaciente;
}


int main () {

    int escolha;
    int contaPacientes = 0;
	
    struct paciente FilaPacientes [MAXPACIENTES];

    // Inicializa a fila de pacientes
    InicHeap(FilaPacientes, MAXPACIENTES);

	// Inicializa srand em 0 para padronizaçao dos resultados
    srand(time(NULL)); 	
    // Cria um looping que continua ate o botao de saida ser pressionado
    do {
        puts("--------------------- Menu de opcoes -------------------");
        puts("|  1 - Adicionar Paciente                              |");
        puts("|  2 - Chamar Proximo Paciente                         |");
        puts("|  3 - Imprimir Lista de Espera                        |");
        puts("|  4 - Ordenar Pacientes pela Prioridade               |" );
        puts("|  5 - Alterar Prioridade do Paciente                  |" );
        puts("|  6 - Comparacao entre Heap, Quick e Selection Sort   |");
        puts("|  0 - Sair                                            |");
        puts("-------------------------------------------------------");
        printf("Digite o numero da operacao desejada: ");

        
        scanf("%d", &escolha);
        printf("\n");

        switch (escolha)
        {
            case 1:
                // Checa se e possivel adicionar mais pacientes
                if (contaPacientes < MAXPACIENTES)
                {
                    int comparacoesTotais = 0;
                    int trocasTotais = 0;
                    struct paciente novoPaciente = leNovoPaciente();
                    contaPacientes++;
                    InsereHeap(FilaPacientes, contaPacientes, novoPaciente, &comparacoesTotais, &trocasTotais ); 
                    printf("\nO novo paciente foi adicionado na fila com sucesso!\n\n");
                    break;
                } 
				else{
                    printf("A fila de pacientes está cheia, digite outro comando.\n\n");
                    break;
                }
            case 2:
                // Checa se existe paciente para ser removido
                if (contaPacientes > 0)
                {
        
                    RemoveHeap(FilaPacientes, contaPacientes);
                    contaPacientes--;
                    printf("O proximo paciente foi chamado com sucesso!\n\n");
                } 
				else 
                    printf("Não há pacientes na fila de espera, digite outro comando.\n\n");
                break;
            case 3:
                puts("Lista de Espera:");
                ImprimeHeap(FilaPacientes, contaPacientes);
                break;
            case 4:
                HeapSort(FilaPacientes, contaPacientes);
				puts("Organização dos pacientes realizada");
                break;
            case 5:
                if(contaPacientes > 0)
                {
                    int indice_paciente, nova_prioridade;
                    printf("Digite o índice do paciente que você deseja alterar a prioridade: ");
                    scanf("%d", &indice_paciente);
                    printf("Digite a nova propriedade que você deseja da-lo: ");
                    scanf("%d", &nova_prioridade);
                    AlteraHeap(FilaPacientes, contaPacientes, indice_paciente, nova_prioridade);
                    break;
                }
                else
                {    
                    printf("Não há pacientes na fila de espera, digite outro comando.\n");
                    break;
                }
            case 6:
			{
				int vetor_original[TAMANHO_VETOR];
				int vetor_quick[TAMANHO_VETOR];
				int vetor_selection[TAMANHO_VETOR];
				int vetor_heap[TAMANHO_VETOR];
				int vetor_original_menor[TAMANHO_VETOR_MENOR];
				int vetor_quick_menor[TAMANHO_VETOR_MENOR];
				int vetor_selection_menor[TAMANHO_VETOR_MENOR];
				int vetor_heap_menor[TAMANHO_VETOR_MENOR];

				int comparacoesSelection = 0, trocasSelection = 0;
				int comparacoesHeap = 0, trocasHeap = 0;
				int comparacoesQuick = 0, trocasQuick = 0;
				int comparacoesSelectionMenor = 0, trocasSelectionMenor = 0;
				int comparacoesHeapMenor = 0, trocasHeapMenor = 0;
				int comparacoesQuickMenor = 0, trocasQuickMenor = 0;
				
				// Criaçao do vetor orignial com os 1024 elementos
				for (int a=0; a<TAMANHO_VETOR; a++)
					vetor_original[a] = rand() % (LIMITE_VETOR + 1);

				// Copia para os outros vetores do vetor original
				for (int b = 0; b < TAMANHO_VETOR; b++) 
				{
        			vetor_quick[b] = vetor_original[b]; 
        			vetor_selection[b] = vetor_original[b];
					vetor_heap[b] = vetor_original[b];
                }              


				SelectionSort(vetor_selection, TAMANHO_VETOR, &comparacoesSelection, &trocasSelection);
				quicksort(vetor_quick, 0, TAMANHO_VETOR-1, &comparacoesQuick, &trocasQuick);
				HeapSortint(vetor_heap, TAMANHO_VETOR, &comparacoesHeap, &trocasHeap);

                printf("Estatisticas de ordenecao para o vetor de 1024 elementos gerados aleatoriamente:\n\n");

				puts("Selection Sort");
				printf("Número de comparacoes: %d\n", comparacoesSelection);
				printf("Número de trocas: %d\n\n", trocasSelection);

                puts("Heap Sort");
				printf("Número de comparacoes: %d\n", comparacoesHeap);
				printf("Número de trocas: %d\n\n", trocasHeap);

				puts("Quick Sort");
				printf("Número de comparacoes: %d\n", comparacoesQuick);
				printf("Número de trocas: %d\n\n\n", trocasQuick);


                puts("Agora, escolhendo um vetor menor para melhor visualizacao.\n");

                // Criaçao do vetor orignial com os 32 elementos
				for (int d=0; d<TAMANHO_VETOR_MENOR; d++)
					vetor_original_menor[d] = rand() % (LIMITE_MAXIMO_MENOR + 1);

				// Copia para os outros vetores do vetor original
				for (int e = 0; e < TAMANHO_VETOR_MENOR; e++) 
				{
        			vetor_quick_menor[e] = vetor_original_menor[e]; 
        			vetor_selection_menor[e] = vetor_original_menor[e];
					vetor_heap_menor[e] = vetor_original_menor[e];
    			}

                puts("Vetor de 32 números aleatórios:");
                printf("[");
                for(int f = 0; f < TAMANHO_VETOR_MENOR - 1; f++) 
                    printf("%d, ", vetor_original_menor[f]);
                printf("%d]\n\n", vetor_original_menor[TAMANHO_VETOR_MENOR - 1]);

                
				SelectionSort(vetor_selection_menor, TAMANHO_VETOR_MENOR, &comparacoesSelectionMenor, &trocasSelectionMenor);
				quicksort(vetor_quick_menor, 0, TAMANHO_VETOR_MENOR-1, &comparacoesQuickMenor, &trocasQuickMenor);
				HeapSortint(vetor_heap_menor, TAMANHO_VETOR_MENOR, &comparacoesHeapMenor, &trocasHeapMenor);

                puts("Selection Sort");
                printf("Número de comparacoes: %d\n", comparacoesSelectionMenor);
                printf("Número de trocas: %d\n", trocasSelectionMenor);
                printf("[");
                for(int d = 0; d < TAMANHO_VETOR_MENOR - 1; d++)
                    printf("%d, ", vetor_selection_menor[d]);
                printf("%d]\n\n", vetor_selection_menor[TAMANHO_VETOR_MENOR-1]);

                puts("Heap Sort");
                printf("Número de comparacoes: %d\n", comparacoesHeapMenor);
                printf("Número de trocas: %d\n", trocasHeapMenor);
                printf("[");
                for(int e = 0; e < TAMANHO_VETOR_MENOR - 1; e++)
                    printf("%d, ", vetor_heap_menor[e]);
                printf("%d]\n\n", vetor_heap_menor[TAMANHO_VETOR_MENOR-1]);

                puts("Quick Sort");
                printf("Número de comparacoes: %d\n", comparacoesQuickMenor);
                printf("Número de trocas: %d\n", trocasQuickMenor);
                printf("[");
                for(int f = 0; f < TAMANHO_VETOR_MENOR - 1; f++)
                    printf("%d, ", vetor_quick_menor[f]);
                printf("%d]\n\n", vetor_quick_menor[TAMANHO_VETOR_MENOR-1]);
			}	
                break;
            case 0:
                break;
            default:
                printf("Opção inválida (%d). Por favor, escolha de 0 a 5.\n", escolha);
                break;
        }
    } while (escolha != 0);

    return 0;
}
