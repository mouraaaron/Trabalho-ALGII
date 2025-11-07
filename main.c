#include "lista.h" 
#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXPACIENTES 4
#define TAMANHO_VETOR 1024
#define LIMITE_MAXIMO 1025

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

				int comparacoesSelection = 0, trocasSelection = 0;
				int comparacoesHeap = 0, trocasHeap = 0;
				int comparacoesQuick = 0, trocasQuick = 0;

				
				// Criaçao do vetor orignial com os 1024 elementos
				for (int a=0; a<TAMANHO_VETOR; a++)
					vetor_original[a] = rand() % (LIMITE_MAXIMO + 1);

				// Copia para os outros vetores do vetor original
				for (int b = 0; b < TAMANHO_VETOR; b++) 
				{
        			vetor_quick[b] = vetor_original[b]; 
        			vetor_selection[b] = vetor_original[b];
					vetor_heap[b] = vetor_original[b];
    			}
                puts("Vetor de 1024 números aleatórios:");
                printf("[");
                for(int c = 0; c < TAMANHO_VETOR - 1; c++) 
                    printf("%d, ", vetor_original[c]);
                printf("%d]\n\n", vetor_original[TAMANHO_VETOR - 1]);
                


				SelectionSort(vetor_selection, TAMANHO_VETOR, &comparacoesSelection, &trocasSelection);
				quicksort(vetor_quick, 0, TAMANHO_VETOR-1, &comparacoesQuick, &trocasQuick);
				HeapSortint(vetor_heap, TAMANHO_VETOR, &comparacoesHeap, &trocasHeap);

				puts("Selection Sort");
				printf("Número de comparacoes: %d\n", comparacoesSelection);
				printf("Número de trocas: %d\n", trocasSelection);
                printf("[");
                for(int d = 0; d < TAMANHO_VETOR - 1; d++)
                    printf("%d, ", vetor_selection[d]);
                printf("%d]\n\n", vetor_selection[TAMANHO_VETOR-1]);

                puts("Heap Sort");
				printf("Número de comparacoes: %d\n", comparacoesHeap);
				printf("Número de trocas: %d\n", trocasHeap);
                printf("[");
                for(int e = 0; e < TAMANHO_VETOR - 1; e++)
                    printf("%d, ", vetor_heap[e]);
                printf("%d]\n\n", vetor_heap[TAMANHO_VETOR-1]);

				puts("Quick Sort");
				printf("Número de comparacoes: %d\n", comparacoesQuick);
				printf("Número de trocas: %d\n", trocasQuick);
                printf("[");
                for(int f = 0; f < TAMANHO_VETOR - 1; f++)
                    printf("%d, ", vetor_quick[f]);
                printf("%d]\n", vetor_quick[TAMANHO_VETOR-1]); 

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
