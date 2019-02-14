#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

// Lista

typedef struct dadosdalista{
	int info;
}DadosDaLista;

typedef struct nodalista{
	DadosDaLista dados;
	struct nodalista* proximo;
} NoDaLista;

typedef struct lista
{
	int tamanho;
	NoDaLista* cabeca;	
} Lista;

// Fim da Lista
//******************************************
// Headers
Lista* criaLista(); // Cria uma Lista e a retorna
bool listaVazia(Lista* lista); // verifica se a Lista passada esta vazia
void inseriInicio(Lista* lista, DadosDaLista dado); // Inseri um dado no inicio da lista
void apagaInicio(Lista* lista); // Apaga um dado do inicio da Lista
NoDaLista* retornaNoAtravesIndice(Lista* lista, int indice); // retorna um Nó atraves de um indice
int retornaIndiceAtravesNo(Lista* lista, NoDaLista* noPassado); // retirba um Indice atraves de um No
void apagaNoAtravesIndice(Lista* lista,int indice); // apaga No atraves de um Indice
void inseriFinal(Lista* lista, DadosDaLista dado); // Inseri dado no final da Lista
void exibirLista(Lista* lista); // Imprimi a Lista 
void mostraMenu(); // Exibe Menu 
void trocaDoisNos(Lista* lista, NoDaLista* NoA , NoDaLista* NoB); // troca dois nós de lugar um com o outro.
int tratarOpcao(int* opcao); // tratar a opção digitada pelo usuario
// Fim dos Headers
//******************************************
// Funcoes da lista
Lista* criaLista(){
	Lista* lista = (Lista *) malloc(sizeof(Lista)); // Aloca a nova lista na memoria

	lista->tamanho = 0; // o tamanho da lista recebe 0 de inicio

	lista->cabeca = NULL; // cabeça da lista aponta no inicio para NULL

	return lista; // retorna a Lista criada
}

bool listaVazia(Lista* lista){
	return (lista->tamanho == 0);
}

void inseriInicio(Lista* lista, DadosDaLista dado){

	NoDaLista* novoNo = (NoDaLista *) malloc(sizeof(NoDaLista)); // alocando dinamicamente o novoNo

	novoNo->dados = dado; // o dados do novo no , recebe o dado passado;

	novoNo->proximo = lista->cabeca; // o proximo do novo nó , aponta para onde a cabeça apontava

	lista->cabeca = novoNo; // a cabeça passa a apontar para o novoNo

	lista->tamanho++; // o tamanho da lista aumenta

	printf("\n Item Adicionado com Sucesso !! \n");

}

void apagaInicio(Lista* lista){

	if(!listaVazia(lista)){ // se lista não estiver vazia
 
		NoDaLista* ponteiroAux = lista->cabeca; // cria um ponteiro aux , referenciando a cabeça da lista (primeiro elemento)

		lista->cabeca = ponteiroAux->proximo; // cabeça da lista (primeiro elemento) agora se referencia ao proximo do ponteiroAux

		free(ponteiroAux); // libera a memoria para onde ponteiroAux estava apontando

		lista->tamanho --; // diminui o tamanho da Lista

		printf("\n Item Apagado com Sucesso !! \n");

	}
}

NoDaLista* retornaNoAtravesIndice(Lista* lista, int indice){

	if(indice >= 0 && indice < lista->tamanho){ // indice tem que ser mais ou igual a 0 , e tem que ser menor que o tamanho da lista
		NoDaLista* noProcurado = lista->cabeca; // um ponteiro auxiliar , referencia a cabeça da lista (primeiro elemento)

		for (int i = 0; i < indice; i++){ // enquanto o i < indice passado
			noProcurado = noProcurado->proximo; // o ponteiro auxiliar , recebe o proximo dele mesmo.

		}

		return noProcurado; // quando a variavel i bater for igual ao indice, quer dizer que encontramos o noProcurado

	}else{
		printf("\n Indice passado nao existente !! \n");  // se indice não bater , retorna uma menssagem
		return NULL; // retorna VAZIO
	}

}

int retornaIndiceAtravesNo(Lista* lista, NoDaLista* noPassado){

	if(noPassado!=NULL){ // verifica se o nó passado não esta apontando para o NULL
		NoDaLista* ponteiro = lista->cabeca;// ponteiro auxiliar , referencia a cabeça da Lista (primeiro elemento)
		int indice  = 0; // inicia variavel indice como 0 (apotando para o primeiro da lista)
		while(ponteiro != noPassado && ponteiro != NULL){ // enqaunto o ponteiro auxiliar for diferente ao do NÓ passado E ponteiro auxiliar for diferente NULL
			ponteiro = ponteiro->proximo; // ponteiroAuxiliar , aponta para o proximo dele mesmo.
			indice++; // indice aumenta +1
		}

		if(ponteiro != NULL){ // se no final , ponteiro não tiver chegado no final da lista, ou seja diferente de NULL

			return indice; // retorna o indice
		}else{
			printf(" \n Nao existe nao com este indice na lista ! \n");
		}
	}

}

void apagaNoAtravesIndice(Lista* lista, int indice){

	if(indice == 0){
		apagaInicio(lista);
	}

	NoDaLista* noAtual = retornaNoAtravesIndice(lista, indice);

	if(noAtual != NULL){
		NoDaLista* noAnterior = retornaNoAtravesIndice(lista, indice-1);
		noAnterior->proximo = noAtual->proximo;

		free(noAtual);
		
		lista->tamanho--;
		printf("\n Item Apagado com Sucesso !! \n");
		return;
	}else{
		printf("\n Nao Existe elemento na lista com este indice !! \n");
		return;
	}
}

void inseriFinal(Lista* lista, DadosDaLista dado){

	if(listaVazia(lista)){
		inseriInicio(lista,dado);
	}
	else{

		NoDaLista* noAuxiliar = lista->cabeca;

		while(noAuxiliar->proximo != NULL ){
			noAuxiliar = noAuxiliar->proximo;

		}

		if(noAuxiliar->proximo == NULL){
			
			NoDaLista* novoNo = (NoDaLista *) malloc(sizeof(NoDaLista)); 
			novoNo->dados = dado;
			novoNo->proximo = noAuxiliar->proximo;
			noAuxiliar->proximo = novoNo;

			lista->tamanho++;

			printf("\n Item Adicionado com Sucesso !! \n");	
			return;
		}
	}	

}

void exibirLista(Lista* lista){

	if(!listaVazia(lista)){
		NoDaLista* ponteiro = lista->cabeca; // cria um ponteiro apotando para o Inicio da Lista
		int indice = 0; // cria e inicializa um indice para identificação 
		while(ponteiro != NULL){ //  equanto ponteiro for diferente de NULL

			printf("%d - %d \n",indice, ponteiro->dados.info); // Imprimi o indice e o valor
			indice++; // indice aumenta + 1
			ponteiro = ponteiro->proximo; // e o ponteiro recebe o proximo ponteiro;
		}

	}else{

		printf("\n Lista Vazia !! \n");
		return;
	}

}

void trocaDoisNos(Lista* lista, NoDaLista* NoA , NoDaLista* NoB){

	if(NoA == NoB){
		printf("\n Nao e possivel trocar o Mesmo Item ! Indices Iguais !! \n");
		return;
	}

	int indexA = retornaIndiceAtravesNo(lista, NoA);
	int indexB = retornaIndiceAtravesNo(lista, NoB);

	if (indexA > indexB){
		// garantir que o IndexA seja sempre Menor que o indexB
		// Para verificar somente se o indexA é o Head
		NoA = NoB; // trocar o Node A pelo node B
		NoB = retornaNoAtravesIndice(lista, indexA); // e faz o node B receber o node A

		indexA = indexB; // atualiza os index 
		indexB = retornaIndiceAtravesNo(lista, NoB); // utiliza o nodeB pois ele foi atualizado a cima

	}

	NoDaLista* anteriorNoB =  retornaNoAtravesIndice(lista, indexB -1 ); // pega o nó anterior ao Nó B


	if(NoA == lista->cabeca){ // se o no A for a cabeça da lista
		lista->cabeca = NoB; // colcoar no B na cabeça da lista 

	}else{
		NoDaLista* anteriorNoA = retornaNoAtravesIndice(lista, indexA - 1); // pega o Nó anterior ao Nó A
		anteriorNoA = NoB; // o proximo do anterior ao A , aponta pro Nó B
	}

	anteriorNoB->proximo = NoA; // anterior ao Nó B , recebe o No A

	NoDaLista* ponteiroAuxiliar = NoA->proximo; // Guardamos onde o nodeA aponta
	NoA->proximo = NoB->proximo; // O nosso NO A tem que apontar para onde o NO B apontava
	NoB->proximo = ponteiroAuxiliar; // e o nosso No B tem que apontar para onde nosso No A apontava
	
	printf("\n Itens trocados sucesso !! \n");
}

void mostraMenu(){

	printf("\n Seja Bem Vindo a minha Lista de Numeros !! \n");
	printf("*******************************************************\n");
	printf("Digite o numero da opcao desejada !! \n ");
	printf("*******************************************************\n");
	printf("1 - Exibir a Lista \n");
	printf("\n");
	printf("2 - Inserir Item Inicio da Lista \n");
	printf("\n");
	printf("3 - Inserir Item Fim da Lista \n");
	printf("\n");
	printf("4 - Apagar Item Inicio da Lista \n");
	printf("\n");
	printf("5 - Apagar o Item que desejar da Lista \n");
	printf("\n");
	printf("6 - Trocar dois Itens de Lugar na Lista \n");
	printf("\n");
	printf("7 - Busca Item Atraves do Indice \n");
	printf("\n");
	printf("8 - Sair \n");
}


int tratarOpcao(int* opcao){

	while(*opcao <= 0 || *opcao > 8){
		printf("Opcao Invalida !! Digite novamente \n ");
		printf("***************************************** \n");
		scanf("%d",&(*opcao));
	}

	return (*opcao);


}


// Fim das Funcoes da Lista
//******************************************
// Inicio do programa

using namespace std;

	//**** Variaveis a serem utilizadas durante o programa
	int opcao = 0; // Inicializando a opção do menu como 0
	Lista* novaLista = criaLista(); // criando a lista
	NoDaLista *nodeA;
	NoDaLista *nodeB;
	DadosDaLista novoDado;
	int item = 0; 
	int indice = 0;
	int indice2 = 0;
	//**** FIM !!


int main()
{
	
	
	while(opcao >= 0 && opcao <= 8){
		mostraMenu(); // mostrando Menu
		scanf("%d",&opcao); // lendo Opção que Usuario Digitou
		tratarOpcao(&opcao); // tratando a opção , atraves de referencia
		
		switch(opcao){
		case 1: // Exibir Lista
			system("cls");
			exibirLista(novaLista);
			
			break;
		case 2: // Inserir Item no Inicio
			system("cls");
			printf("Digite o Numero que quer Adicionar no inicio da Lista : ");
			scanf("%d",&item);
			system("cls");
			novoDado.info = item;
			inseriInicio(novaLista, novoDado);
			break;	

		case 3: // Inserir Item No Fim da Lista
			system("cls");
			printf("Digite o Numero que deseja Adicionar no Fim da Lista : ");
			scanf("%d",&item);
			system("cls");
			novoDado.info = item;
			inseriFinal(novaLista, novoDado);
			break;

		case 4: // Apagar Item Inicio da Lista
			system("cls");
			apagaInicio(novaLista);
			break;

		case 5: // Apagar o Item que desejar da Lista
			system("cls");	
			printf("Digite o Indice que se encontra o Item para Apagar : ");
			scanf("%d",&indice);
			system("cls");
			printf("\n %d ", indice);
			apagaNoAtravesIndice(novaLista, indice);
		
			break; 

		case 6: // Trocar dois Itens de Lugar na Lista
			system("cls");
			printf("Digite o PRIMEIRO INDICE , para trocar de lugar  : ");
			scanf("%d",&indice); // pegando o primeiro indice

			printf("Digite o SEGUNDO INDICE , para trocar de lugar  : ");
			printf("\n");
			scanf("%d",&indice2); // pegando o segundo indice
			
			system("cls");
			nodeA = retornaNoAtravesIndice(novaLista, indice);
			nodeB = retornaNoAtravesIndice(novaLista, indice2);
			trocaDoisNos(novaLista, nodeA , nodeB);
			break;

		case 7: // Busca Item Atraves do Indice
			system("cls");
			printf("Digite o Indice que se encontra o Item para Buscar : ");
			scanf("%d",&indice);
			system("cls");
			nodeA = retornaNoAtravesIndice(novaLista, indice);
			printf(" \n %d - %d \n ", indice , nodeA->dados.info);
			break;

		case 8: // Sair
			
			opcao = 9;
			break;
		}


	}

}
// Fim do programa

