#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

// Estrutura da Lista

typedef struct dadosrota{
	char parada[30];
} DadosRota;

typedef struct norota {	
	DadosRota dado;
	struct norota* proxima;
}NoRota;

typedef struct listaderotas{
	int tamanho;
	NoRota* cabeca;
}ListaDeRotas;


// Fim da Estrutura

// Headers
ListaDeRotas* criaLista(); // Cria Nova Lista
bool listaVazia(ListaDeRotas* lista); // Verifica se a lista esta vazia
void inseriRota(ListaDeRotas* lista, DadosRota dados); // Adiciona uma Rota no inicio
void apagaRota(ListaDeRotas* lista); // Apaga uma Rota no Inicio
void mostraRotas(ListaDeRotas* lista); // Exibi a lista de rotas
NoRota* retornaNoDeIndice(ListaDeRotas* lista, int indice); // retorna um Nó de uma rota Atraves de um Indice
int  retornaIndiceDeNo(ListaDeRotas* lista, NoRota* rota); // Retorna um Indice atraves de um Nó de uma rota
void apagaDeIndice(ListaDeRotas* lista, int indice); // Apaga uma Rota Atraves de um Indice
void mostraMenu(); // Mostra o Menu do sistema
int tratarOpcao(int* opcao); // tratar opcao digitada pelo usuario
// Fim Headers

// Funções
ListaDeRotas* criaLista(){
	ListaDeRotas* novaLista = (ListaDeRotas *) malloc(sizeof(ListaDeRotas)); // Alocando  espaço para nova Lista
	
	novaLista->tamanho = 0; // Inicializa o tamanho da nova lista como 0
	
	novaLista->cabeca = NULL; // cabeça da lista inicia apontando para VAZIO !
	
	return novaLista; // Retorna a nova lista criada 
}

bool listaVazia(ListaDeRotas* lista){
	
	return(lista->tamanho == 0); // retorna V ou F
}

void inseriRota(ListaDeRotas* lista, DadosRota dado){
	
	NoRota* novaRota = (NoRota *) malloc(sizeof(NoRota)); // Alocando espaço para o novo NÓ de uma rota
	
	novaRota->dado = dado; // Adicionando o novo dado
	
	novaRota->proxima = lista->cabeca; // o proximo da nova rota , aponta para onde a cabeça estava apontando
	
	lista->cabeca = novaRota; // cabeça da lista agora aponta para a nova rota
	
	lista->tamanho ++; // incrementando o tamanho da rota
	
	system("cls");
	printf("\n Nova Rota inserida com sucesso ! \n");
}

void apagaRota(ListaDeRotas* lista){
	
	if(!listaVazia(lista)){ // se a lista não estiver vazia faz:
		NoRota* ponteiroAuxiliar = lista->cabeca; // ponteiro recebe o primeiro intem da lista
		
		lista->cabeca = ponteiroAuxiliar->proxima; // cabeça  recebe o proximo do primeiro intem;
		 
		free(ponteiroAuxiliar); // liberamos o espaço do primeiro intem
		
		lista->tamanho --; //decrementando o tamanho da rota
		
	}else{
		printf("\n A lista Já esta VAZIA !! \n"); // se estiver vazia 
	}
	
	
}

void mostraRotas(ListaDeRotas* lista){
	
	if(!listaVazia(lista)){ // se a lista não estiver vazia faz :
		NoRota* ponteiroAuxiliar = lista->cabeca; // ponteiro recebe o primeiro intem da lista
		int indice = 0;
		 
		while(ponteiroAuxiliar != NULL){ // enquanto o ponteiro não for vazio
			printf("Rota %d - %s \n",indice, ponteiroAuxiliar->dado.parada); // imprimi o indice , e o valor
			
			indice++;
			ponteiroAuxiliar = ponteiroAuxiliar->proxima;
		}
		
	}else{
		printf("\n A lista esta VAZIA !! \n"); // se estiver vazia 
	}
	
}

NoRota* retornaNoDeIndice(ListaDeRotas* lista, int indice){
	
	if(!listaVazia(lista)){ // se lista não estiver vazia
		
		if(indice >= 0 && indice < lista->tamanho){ // e se o indice dado for valido faz:
			
			NoRota* ponteiro = lista->cabeca; // ponteiro recebe o primeiro intem da lista
		
			for(int i = 0; i < indice; i++){ // equanto i for menor que o indice dado faz:
				ponteiro = ponteiro->proxima; // ponteiro recebe o proximo dele mesmo
			}	
		
			return ponteiro; // retorna o ponteiro encontrado
		}
		
	}else{
		printf("\n A lista esta VAZIA !! \n"); // se estiver vazia 
		return NULL; // retorna vazio 
	}
	
}

int  retornaIndiceDeNo(ListaDeRotas* lista, NoRota* rota){
	
		if(rota != NULL){ // se rota passada não estiver vazia !
		
			NoRota* ponteiroAux = lista->cabeca; // ponteiro recebe o primeiro item da lista
			
			int indice = 0; // inicializa o indice como 0
			
			while(rota != NULL && rota != ponteiroAux){ // rota não pode estar vazia e tem que ser diferente da rota passada
				ponteiroAux = ponteiroAux->proxima; // dessa maneira percorremos toda a lista
				indice++; // indice é incrementado 
			}
			
			if(ponteiroAux != NULL){ // se o ponteio não estiver vazio
				return indice; // retorna o indice
			}
			else{
				return -1;
			}
		
		}
		
		printf("\n Rota não existente !! \n"); // se a rota passada for NULL , logo não existe
		return -1;
}

void apagaDeIndice(ListaDeRotas* lista, int indice){
	
	if(indice >= 0 && indice < lista->tamanho){ // verifica se indice passado é valido
		
		if(indice == 0){ // se indice passado for 0 , logo usuario quer apagar o primeiro da lista
			apagaRota(lista); // usamos então a função apaga rota e passamos a lista
		}else{
			NoRota* rotaAtual = retornaNoDeIndice(lista, indice); // pegamos a rota atual atraves do indice dado
			
			if(rotaAtual != NULL){ // se rota atual não estiver vazia
			
				NoRota* rotaAnterior = retornaNoDeIndice(lista, indice - 1); // pegamos rotaAnterior , diminuindo indice passado por - 1
				
				rotaAnterior->proxima = rotaAtual->proxima; // o proximo da rota anterior ,vai receber o proximo da rota Atual
				
				free(rotaAtual); // liberamos a rota Atual
				
				lista->tamanho --; // decrementando o tamanho da lista
				
				system("cls");
				printf("\n Rota apagada com sucesso ! \n");
			}
			
		}
		
	}else{
		printf("\n Indice Não existente !! \n"); // se indice não estiver na rota
		return;
		
	}
	
}

void mostraMenu(){
	
	printf("---------- Sistema Rotas de Onibus  ---------- \n");
	printf("\n-------------MENU----------------------------- \n");
	printf("\n 1 - MOSTRAR ROTAS \n");
	printf("\n 2 - ADICIONAR ROTA \n");
	printf("\n 3 - EXCLUIR ROTA \n");
	printf("\n 4 - SAIR \n");
}

int tratarOpcao(int* opcao){
	
	while(*opcao > 4 || *opcao < 1){
		printf("\n Opcao Invalida ! Digite novamente : ");
		scanf("%d", &(*opcao));
	}
	
	return *opcao;
}

// Fim Funções

using namespace std;



int main(){
	
	// Variaveis

int opcao = 0;
ListaDeRotas* novaLista = criaLista();
NoRota* rota;
DadosRota novoDado;
int indice = 0;
char novarota[30];


// Fim Variaveis
	
	while(opcao != 5){
		mostraMenu();
		scanf("%d",&opcao);
		tratarOpcao(&opcao);
		
		switch(opcao){
			case 1:
				system("cls");
				mostraRotas(novaLista);
				break;
			case 2:
				system("cls");
				printf("Digite a nova rota que deseja adicionar : ");
				scanf("%s",&novoDado.parada);
				inseriRota(novaLista,novoDado);
				break;
			case 3:
				system("cls");
				printf("Digite o indice da rota que deseja apagar : ");
				scanf("%d",&indice);
				apagaDeIndice(novaLista, indice);
				break;
			case 4:
				opcao = 5;
				break;		
		}		
	}
	
	
	getch();
}
