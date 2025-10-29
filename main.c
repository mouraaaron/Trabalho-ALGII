#include <stdio.h>
#include <stdlib.h>
#include "lista.h" 

#define MAXPACIENTES 10
#define TAMANHO_VETOR 1024
#define LIMITE_MAXIMO 1000
struct paciente leNovoPaciente ()
{
	struct paciente novoPaciente;
        
    printf("Digite o nome do paciente: ");
    scanf("%s", novoPaciente.nome);

    printf("Digite a prioridade do paciente: ");
	scanf("%d", &novoPaciente.prioridade);
    
    return novoPaciente;
}


int main () {

    int escolha;
    int contaPacientes = 0;
	
    struct paciente FilaPacientes [MAXPACIENTES];

    // Inicializa a fila de pacientes
    inciaHeap(FilaPacientes);

	// Inicializa srand em 0 para padronizaçao dos resultados
	srand(0);
	
    // Cria um looping que continua ate o botao de saida ser pressionado
    do {
        puts("\-------------- Menu de opcoes ---------------");
        puts(" 1 - Adicionar Paciente");
        puts(" 2 - Chamar Proximo Paciente");
        puts(" 3 - Imprimir Lista de Espera");
        puts(" 4 - Ordenar Pacientes pela Prioridade" );
        puts(" 5 - Comparacao entre Heap, Quick e Selection Sort");
        puts(" 0 - Sair" );
        puts("---------------------------------------------");
        printf(" Digite o numero da operacao desejada: ");
        
        scanf("%d", &escolha);
    
        switch (escolha)
        {
            case 1:
                // Checa se e possivel adicionar mais pacientes
                if (contaPacientes < MAXPACIENTES)
                {
                    struct paciente novoPaciente = leNovoPaciente();
                    InsereHeap(FilaPacientes, contaPacientes, novoPaciente); 
                    contaPacientes++;
                } 
				else 
                    printf("A fila de pacientes está cheia, digite outro comando.");
                break;
            case 2:
                // Checa se existe paciente para ser removido
                if (contaPacientes > 0)
                {
                    RemoveHeap(FilaPacientes, contaPacientes);
                    contaPacientes--;
                } 
				else 
                    printf("Não há pacientes na fila de espera, digite outro comando.\n");
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
			{
				int vetor_original[TAMANHO_VETOR];
				int vetor_quick[TAMANHO_VETOR];
				int vetor_selection[TAMANHO_VETOR];
				int vetor_heap[TAMANHO_VETOR];

				int comparacoesSelection = 0, trocasSelection = 0;
				int comparacoesHeap = 0, trocasHeap = 0;
				int comparacoesQuick = 0, trocasQuick = 0;

				
				// Criaçao do vetor orignial com os 1024 elementos
				for (int i=0; i<TAMANHO_VETOR; i++)
					vetor_original[i] = rand() % LIMITE_MAXIMO;

				// Copia para os outros vetores do vetor original
				for (int i = 0; i < TAMANHO_VETOR; i++) 
				{
        			vetor_quick[i] = vetor_original[i]; 
        			vetor_selection[i] = vetor_original[i];
					vetor_heap[i] = vetor_original[i];
    			}
				puts("Vetor de 1024 números aleatórios foi criado");

				selection_sort(vetor_selection, TAMANHO_VETOR, &comparacoesSelection, &trocasSelection);
				quick_sort(vetor_quick, TAMANHO_VETOR, &comparacoesQuick, &trocasQuick);
				heap_sort(vetor_heap, TAMANHO_VETOR, &comparacoesHeap, &trocasHeap);

				puts("Selection Sort");
				printf("Número de comparacoes: %d\n", comparacoesSelection);
				printf("Número de trocas: %d\n\n", trocasSelection);

				puts("Heap Sort");
				printf("Número de comparacoes: %d\n", comparacoesHeap);
				printf("Número de trocas: %d\n\n", trocasHeap);

				puts("Quick Sort");
				printf("Número de comparacoes: %d\n", comparacoesQuick);
				printf("Número de trocas: %d\n\n", trocasQuick);
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
                                                                                                                                                                                                                            42,45-66     Tudo

    
