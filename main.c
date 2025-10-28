#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define MAXPACIENTES 11
int main () {

	int escolha;
    int contaPacientes = 0;
    struct paciente FilaPacientes [MAXPACIENTES];

	// Inicializa a fila de pacientes
	inciaHeap(FilaPacientes);
	
	// Cria um looping que continua ate o botao de saida ser pressionado
	do {
	    puts("-------------- Menu de opcoes ---------------");
	    puts(" 1 - Adicionar Paciente ");
	    puts(" 2 - Chamar Proximo Paciente ");
	    puts(" 3 - Imprimir Lista de Espera ");
	    puts(" 4 - Ordenar Pacientes pela Prioridade " );
	    puts(" 5 - Comparacaoo entre Quick e Selection Sort ");
		puts(" 0 - Sair " );
	    puts("---------------------------------------------");
	    printf(" Digite o numero da operacao desejada: ");
	    scanf("%d", &escolha);
	
	
	    switch (escolha)
	    {
	        case 1:
	            // Checa se e possivel adicionar mais pacientes
	            if (contaPacientes < MAXPACIENTES)
	            {
	                InsereHeap(FilaPacientes, contaPacientes);
	                contaPacientes++;
	            }
	                break;
	        case 2:
	            // Checa se existe paciente para ser removido
	            if (contaPacientes != 0)
	            {
	                RemoveHeap(FilaPacientes, contaPacientes);
	                contaPacientes--;
	            }
	            break;
	        case 3:
	                ImprimeHeap(FilaPacientes, contaPacientes);
	                break;
	        case 4:
	                HeapSort(FilaPacientes, contaPacientes);
	                break;
	        case 5:
	                printf("5");
	                break;
	    }
		printf("\n");
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
