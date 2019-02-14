#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stddef.h>
#include <string.h>

//Struct
typedef struct clientes{
	int id;
	char nome[15] = "";
	char endereco[15] = "";
	int telefone;
	char email[15] = "";
}Clientes;

// Fim Struct


//Header
void inseriItem(int i); 
void imprimirStruct(int i);
void removerItem(int i);
void menu();
void tratarOpcao(int *opcao);
//Fim Headers


// Funçôes
Clientes seusClientes[10];

void menu(){
	
	printf("\n___ DADOS CLIENTE ____ \n");
	printf("\n 1 - Inserir Clientes \n");
	printf("\n 2 - Imprimir Clientes \n");
	printf("\n 3 - Remover Cliente \n");
	printf("\n 4 - Sair \n");
	
}

void tratarOpcao(int *opcao){
	
	while(*opcao < 1 || *opcao > 4){
		printf("\n Opcao Invalida !! Digite novamente : ");
		scanf("%d", &(*opcao));
	}
}

void inseriItem(int i){
		
	seusClientes[i].id = i;
	
	printf("\n Digite o Nome do cliente : ");
	scanf("%s",&seusClientes[i].nome);
	
	printf("\n Digite o Endereco do cliente : ");
	scanf("%s",&seusClientes[i].endereco);	
	
	printf("\n Digite o Telefone do cliente : ");
	scanf("%d",&seusClientes[i].telefone);	
	
	printf("\n Digite o E-Mail do cliente : ");
	scanf("%s",&seusClientes[i].email);	
	
	printf("\n Cliente Inserido com sucesso !! \n");
}

void removerItem(int i){
	
	printf("-- ID Do Clientes %d --" , seusClientes[i].id);
	memset (&seusClientes[i].nome, 0, sizeof (seusClientes[i].nome ));	
	memset (&seusClientes[i].endereco, 0, sizeof (seusClientes[i].endereco ));
	memset (&seusClientes[i].telefone, 0, sizeof (seusClientes[i].telefone ));
	memset (&seusClientes[i].email, 0, sizeof (seusClientes[i].email ));
	
}

void imprimirStruct(int i){
	
	printf("ID -- %d -- \n ", seusClientes[i].id);
	printf("-- Nome : %s \n ", seusClientes[i].nome);
	printf("-- Endereco : %s \n ", seusClientes[i].endereco);
	printf("-- Telefone : %d \n ", seusClientes[i].telefone);
	printf("-- Email : %s \n ", seusClientes[i].email);
	
}

// Fim funções

// Variaveis
int opcao = 0;
int control = 0;
int id = 0;
// Fim Variaveis

using namespace std;

int main(){
		
while(opcao < 4){
	
		menu();
		scanf("%d",&opcao);
		tratarOpcao(&opcao);
	
	switch(opcao){
		case 1:
			if(control <= 10){
				inseriItem(control);
				control++;
				break;
			
			}else{
				printf("\n Banco de Dados CHEIO !! \n ");
				break;
			}
				
		case 2:
			printf("Digite o ID do cliente que deseja Imprimir : ");
			scanf("%d", &id);
			imprimirStruct(id);
			break;
		case 3:
			printf("Digite o ID do cliente que deseja Apagar : ");
			scanf("%d", &id);
			imprimirStruct(id);
			break;
			
		case 4:
			opcao = 9;
			break;			
		
	}
	
}
	
	getch();
}
