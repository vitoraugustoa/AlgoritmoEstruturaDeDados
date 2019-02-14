#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// **** Estrutura da LISTA ****

typedef struct dataNode { // Dados ( informação )
	int id; // a informação 
} DataNode;


typedef struct node { // nó da lista
	DataNode data; // Um dado
	struct node* next; // e uma referencia para o proximo nó
} Node;

typedef struct list { // typedef para definir a struct como um tipo
	int size; // Tamanho da lista
	Node* head; // Nó cabeça da lista ( o ponteiro que aponta para o primeiro elemento da lista
} List; // Onde podemos " renomear a lista "


// **** Estrutura da LISTA ****



// **** HEADER ****

//Definir Header das funçoes pois uma as vezes 
//vai puxar outra então é importante definir Headers antes


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

// **** Funçoes da Lista ****

List* createList(){ // Função para criar a lista
	// Alocando espaço de memoria ( dinamicamente )
	List* list = (List *)/* Cast */ malloc(sizeof(List)); 
	
	// Inicializaar o tamanho da lista para 0
	list->size = 0; // variavel size do tipo list
	
	// Cabeça da lista inicialmente aponte para Null
	list -> head = NULL; // pois a lista esta vazia !
	
	
	return list;
}

void push(List* list, DataNode data){ // adicionar um elemento na primeira posicao

	Node* node = (Node*) malloc(sizeof(Node));
	
	node->data = data; // colocar a informação do node , igual a informação qeu passamos
	
	node->next = list->head; // o proximo no , vai ser a cabeça da lista
	
	list->head = node; // a cabeça da lista recebe o no que criamos
	
	list->size++; // e incrementamos o tamanho da nossa lista
}

void printList(List* list){ // função que vai imprimir a nossa lista
	
	if(isEmpty(list)){  // se a lista tiver vazia
		printf("Lista Vazia \n");
		return; // sai da funcao printList
	}
	
	Node* pointer = list->head; // pointer recebe a referencia do Head
	
	while(pointer != NULL){ // Enquanto Pointer for difeerente de NULL ou seja tenha item na lista
		printf("%d ",pointer->data.id);
		
		//Como nosso pointer esta ligado com o Head do tipo list
		// e o head é um ponteiro do tipo Node* , 
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
		Node* pointer = list->head; // ponteiro aux aponta para cabeça da lista
		
		list->head = pointer->next;	// troca a cabeça da lista para o proximo do ponteiro aux
		free(pointer); //Liberar o espaço alocado do pointer.
		list->size--;
	}
	
}

Node* atPos(List* list, int index){ // retorna um Nó atraves de um Index passado
	
	if(index >= 0 &&  index < list->size ){ // verifica se o Index é valido
		Node* node = list->head; // node recebe a referencia da cabeça da lista
		
		for(int i = 0; i < index; i++){ // i < index , pois um nó inicia com 0.
			node = node->next; // o nó antigo , recebe o proximo Nó.
		}
			return node; // retorna o Nó
		
	}else{
		printf("Index invalido !! ");
		return NULL;	
	}

}

int indexOf(List* list, Node* node){ // returna o Index de um NÓ
	
	if(node != NULL){ // Nó tem que ser diferente de NULL
		Node* pointer = list->head; // Variavel Aux recebe a referencia da Cabeça da lista
		int index = 0; // inicializa o Index como 0 ( primeiro Elemento )
		
		while(pointer != node && pointer != NULL){ 
			pointer = pointer->next;
			index++;
		}
		
		if(pointer != NULL){
			return index;	
		}
		
	}
	
		printf("Nó não pertence a lista! \n");
		return -1;	
	
	
}

void erase(List* list, int index){ //Apgar um Nó de um Indice dado

	if(index == 0){
		pop(list);
		
	}else{
		Node* current = atPos(list,index); // retorna o Nó passado atraves da Index
		
		if(current != NULL){ // se o current nó , for igual a Null não faz nada
			Node* previous = atPos(list,index-1); // retorna um Nó antes do primeiro Nó
			previous->next = current->next; // O next do nó anterior , vai apontar agora para o proximo nó que o nó current apontava
			
			free(current);	
			list->size--;	
		}
		
		
	}
		
}

void insert(List* list, DataNode data, int index){ // adiciona um novo nó, no index passado
	
	if(index == 0){ // se o index for igual a 0 , que dizer que quer colocar um novo intem na primeira posição
		push(list,data); // usamos a função push para isso
		
	}else{
		Node* current = atPos(list,index); // pega o nó , do index passado.
		
		if(current != NULL){
			Node* previous = atPos(list,index-1); // pega o nó anterior ao passado atraves de index
			
			Node* newNode = (Node*) malloc(sizeof(Node)); // Aloca o novo No
			newNode->data = data; // coloca o dado dentro do novo no
			
			previous->next = newNode; // o next do anterior recebe o novo no
			newNode->next = current; // e o proximo do novo nó vai ser o no do index que a gnt especificou
			list->size++; // inscrementar o tamanho da lista
		}
		else{
			printf("Posição Invalida !! \n");
		}
		
	}
}

void xchgNodes(List* list, Node* nodeA, Node* nodeB){ // Trocar dois nos de posição um com o outro
	
	if(nodeA == nodeB){ // se os nos forem iguais não tem oque trocar
		printf("\n Não possivel trocar dois nós iguais. \n");
		return;
	}
	
	int indexA = indexOf(list, nodeA); // pegar index do no A 
	int indexB = indexOf(list, nodeB); // pegar index do no B
	
	if(indexA == -1 || indexB == -1){
		printf("\n Nó não existente \n");
		return;
	}
	
	if(indexA > indexB){ 
		// garantir que o IndexA seja sempre Menor que o indexB
		// Para verificar somente se o indexA é o Head
	
		nodeA = nodeB; // trocar o Node A pelo node B
		nodeB = atPos(list,indexA); // e faz o node B receber o node A
			
		indexA = indexB; // atualiza os index
		indexB = indexOf(list,nodeB); // utiliza o nodeB pois ele foi atualizado a cima
	}
	
	Node* pb = atPos(list, indexB - 1); // pega o antior ao nodeB
	
	if(nodeA == list->head){ // se o no a for a cabeça da lista
		list->head = nodeB; // colcoar no B na cabeça da lista 
		
		
	}else{
		Node* pa = atPos(list, indexA - 1); // pega o anterior ao nodeA
		pa->next = nodeB; // o proximo do anterior ao A , aponta pro nodeB
	}
	
	pb->next = nodeA; // anterior ao B , recebe o NodeA
	
	Node* pointer = nodeA->next; // Guardamos onde o nodeA aponta
	nodeA->next = nodeB->next; // O nosso nodeA tem que apontar para onde o nodeB apontava
	nodeB->next = pointer; // e o nosso nodeB tem que apontar para onde nosso nodeA apontava
	
}
// **** Funçoes da Lista ****
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
