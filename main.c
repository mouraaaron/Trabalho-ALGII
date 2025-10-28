#include <stdio.h>
#include <stdlib.h>
#include "lista.h" 

#define MAXPACIENTES 10
#define TAMANHO_VETOR 1024
#define LIMITE_MAXIMO
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
        puts("\n-------------- Menu de opcoes ---------------"); // Adicionado '\n' para espaçamento
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
                    printf("ERRO: A fila de pacientes está cheia");
                break;
            case 2:
                // Checa se existe paciente para ser removido
                if (contaPacientes > 0)
                {
                    RemoveHeap(FilaPacientes, contaPacientes);
                    contaPacientes--;
                } 
				else 
                    printf("ERRO: Não há pacientes na fila de espera.\n");
                break;
            case 3:
                puts("Lista de Espera:");
                ImprimeHeap(FilaPacientes, contaPacientes);
                break;
            case 4:
                HeapSort(FilaPacientes, contaPacientes);
                break;
            case 5:
			{
				int vetor_original[TAMANHO_VETOR];
				int vetor_quick[TAMANHO_VETOR];
				int vetor_selection[TAMANHO_VETOR];
				int vetor_heap[TAMANHO_VETOR];

				// Criaçao do vetor orignial com os 1024 elementos
				for (int i=0; i<TAMANHO_VETOR; i++)
					vetor_comparacao[i] = rand() % LIMITE_MAXIMO;

				// Copia para os outros vetores do vetor original
				for (int i = 0; i < TAMANHO_COMPARACAO; i++) 
				{
        			vetor_quick[i] = vetor_original[i]; 
        			vetor_selection[i] = vetor_original[i];
					vetor_heap[i] = vetor_original[i];
    			}
				puts("Vetor de 1024 números aleatórios foi criado");

				selection_sort(int vetor_selection[], TAMANHO_COMPARACAO, &comparacoesSelection, &trocasSelection);
				quick_sort(int vetor_quick[], TAMANHO_COMPARACAO, &comparacoesQuick, &trocasQuick);
				heap_sort(int vetor_heap[], TAMANHO_COMPARACAO, &comparacoesQuick, &trocasQuick);

				puts("O número de comparacoes feitas no 
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

    
/* Funcionalidades da enfermeira
* cadastrar pacientes (insereheap)
* chamar o prox paciente (removeheap) 
* imprimir todos na sala de espera (imprimeheap)
* ordenar todos pela sua ordem de prioridade
* alterar a prioridade
* fazer a comparação das maneiras de ordenar os vetores de 1024 elementos aleatórios
*/ 
