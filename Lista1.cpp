#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// **** Estrutura da LISTA ****

typedef struct dataNode { // Dados ( informa��o )
	int id; // a informa��o 
} DataNode;


typedef struct node { // n� da lista
	DataNode data; // Um dado
	struct node* next; // e uma referencia para o proximo n�
} Node;

typedef struct list { // typedef para definir a struct como um tipo
	int size; // Tamanho da lista
	Node* head; // N� cabe�a da lista ( o ponteiro que aponta para o primeiro elemento da lista
} List; // Onde podemos " renomear a lista "


// **** Estrutura da LISTA ****



// **** HEADER ****

//Definir Header das fun�oes pois uma as vezes 
//vai puxar outra ent�o � importante definir Headers antes


List* createList(); // Header
void push(List* list, DataNode data); // Header
void printList(List* list); // Header
void pop(List* list);
bool isEmpty(List* list);
Node* atPost(List* list, int index);
int indexOf(List* list, Node* node);
void erase(List* list,int index);
void insert(List* list, DataNode data, int index);
void xchgNodes(List* list, Node* nodeA, Node* nodeB);

// **** HEADER ****

// **** Fun�oes da Lista ****

List* createList(){ // Fun��o para criar a lista
	// Alocando espa�o de memoria ( dinamicamente )
	List* list = (List *)/* Cast */ malloc(sizeof(List)); 
	
	// Inicializaar o tamanho da lista para 0
	list->size = 0; // variavel size do tipo list
	
	// Cabe�a da lista inicialmente aponte para Null
	list -> head = NULL; // pois a lista esta vazia !
	
	
	return list;
}

void push(List* list, DataNode data){ // adicionar um elemento na primeira posicao

	Node* node = (Node*) malloc(sizeof(Node));
	
	node->data = data; // colocar a informa��o do node , igual a informa��o qeu passamos
	
	node->next = list->head; // o proximo no , vai ser a cabe�a da lista
	
	list->head = node; // a cabe�a da lista recebe o no que criamos
	
	list->size++; // e incrementamos o tamanho da nossa lista
}

void printList(List* list){ // fun��o que vai imprimir a nossa lista
	
	if(isEmpty(list)){  // se a lista tiver vazia
		printf("Lista Vazia \n");
		return; // sai da funcao printList
	}
	
	Node* pointer = list->head; // pointer recebe a referencia do Head
	
	while(pointer != NULL){ // Enquanto Pointer for difeerente de NULL ou seja tenha item na lista
		printf("%d ",pointer->data.id);
		
		//Como nosso pointer esta ligado com o Head do tipo list
		// e o head � um ponteiro do tipo Node* , 
		// temos total acesso ai ponteiro next do tipo node
		// que aponta para o proprio struct node
		pointer = pointer->next; 
	}
	
}

bool isEmpty(List* list){
	return (list->size == 0);
}

void pop(List* list){ // Remover o primeiro elemento da Lista
	
	if(!isEmpty(list)){
		Node* pointer = list->head; // ponteiro aux aponta para cabe�a da lista
		
		list->head = pointer->next;	// troca a cabe�a da lista para o proximo do ponteiro aux
		free(pointer); //Liberar o espa�o alocado do pointer.
		list->size--;
	}
	
}

Node* atPos(List* list, int index){ // retorna um N� atraves de um Index passado
	
	if(index >= 0 &&  index < list->size ){ // verifica se o Index � valido
		Node* node = list->head; // node recebe a referencia da cabe�a da lista
		
		for(int i = 0; i < index; i++){ // i < index , pois um n� inicia com 0.
			node = node->next; // o n� antigo , recebe o proximo N�.
		}
			return node; // retorna o N�
		
	}else{
		printf("Index invalido !! ");
		return NULL;	
	}

}

int indexOf(List* list, Node* node){ // returna o Index de um N�
	
	if(node != NULL){ // N� tem que ser diferente de NULL
		Node* pointer = list->head; // Variavel Aux recebe a referencia da Cabe�a da lista
		int index = 0; // inicializa o Index como 0 ( primeiro Elemento )
		
		while(pointer != node && pointer != NULL){ 
			pointer = pointer->next;
			index++;
		}
		
		if(pointer != NULL){
			return index;	
		}
		
	}
	
		printf("N� n�o pertence a lista! \n");
		return -1;	
	
	
}

void erase(List* list, int index){ //Apgar um N� de um Indice dado

	if(index == 0){
		pop(list);
		
	}else{
		Node* current = atPos(list,index); // retorna o N� passado atraves da Index
		
		if(current != NULL){ // se o current n� , for igual a Null n�o faz nada
			Node* previous = atPos(list,index-1); // retorna um N� antes do primeiro N�
			previous->next = current->next; // O next do n� anterior , vai apontar agora para o proximo n� que o n� current apontava
			
			free(current);	
			list->size--;	
		}
		
		
	}
		
}

void insert(List* list, DataNode data, int index){ // adiciona um novo n�, no index passado
	
	if(index == 0){ // se o index for igual a 0 , que dizer que quer colocar um novo intem na primeira posi��o
		push(list,data); // usamos a fun��o push para isso
		
	}else{
		Node* current = atPos(list,index); // pega o n� , do index passado.
		
		if(current != NULL){
			Node* previous = atPos(list,index-1); // pega o n� anterior ao passado atraves de index
			
			Node* newNode = (Node*) malloc(sizeof(Node)); // Aloca o novo No
			newNode->data = data; // coloca o dado dentro do novo no
			
			previous->next = newNode; // o next do anterior recebe o novo no
			newNode->next = current; // e o proximo do novo n� vai ser o no do index que a gnt especificou
			list->size++; // inscrementar o tamanho da lista
		}
		else{
			printf("Posi��o Invalida !! \n");
		}
		
	}
}

void xchgNodes(List* list, Node* nodeA, Node* nodeB){ // Trocar dois nos de posi��o um com o outro
	
	if(nodeA == nodeB){ // se os nos forem iguais n�o tem oque trocar
		printf("\n N�o possivel trocar dois n�s iguais. \n");
		return;
	}
	
	int indexA = indexOf(list, nodeA); // pegar index do no A 
	int indexB = indexOf(list, nodeB); // pegar index do no B
	
	if(indexA == -1 || indexB == -1){
		printf("\n N� n�o existente \n");
		return;
	}
	
	if(indexA > indexB){ 
		// garantir que o IndexA seja sempre Menor que o indexB
		// Para verificar somente se o indexA � o Head
	
		nodeA = nodeB; // trocar o Node A pelo node B
		nodeB = atPos(list,indexA); // e faz o node B receber o node A
			
		indexA = indexB; // atualiza os index
		indexB = indexOf(list,nodeB); // utiliza o nodeB pois ele foi atualizado a cima
	}
	
	Node* pb = atPos(list, indexB - 1); // pega o antior ao nodeB
	
	if(nodeA == list->head){ // se o no a for a cabe�a da lista
		list->head = nodeB; // colcoar no B na cabe�a da lista 
		
		
	}else{
		Node* pa = atPos(list, indexA - 1); // pega o anterior ao nodeA
		pa->next = nodeB; // o proximo do anterior ao A , aponta pro nodeB
	}
	
	pb->next = nodeA; // anterior ao B , recebe o NodeA
	
	Node* pointer = nodeA->next; // Guardamos onde o nodeA aponta
	nodeA->next = nodeB->next; // O nosso nodeA tem que apontar para onde o nodeB apontava
	nodeB->next = pointer; // e o nosso nodeB tem que apontar para onde nosso nodeA apontava
	
}
// **** Fun�oes da Lista ****
using namespace std;

int main(){
	// inves de chamarmos de struct list
	 List* lista = createList(); // podemos chamar somente de List
		
		DataNode data;
		
		data.id = 5;
		push(lista,data);
		
		data.id = 7;
		push(lista,data);
		
		printList(lista);
	
	
}
