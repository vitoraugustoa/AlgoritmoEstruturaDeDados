#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


using namespace std;

void mostraMenu(){
	
	printf("---- Menu Principal ---- \n");
	printf("**Digite** \n");
	printf(" 1 - Cadastrar Livros \n");
	printf(" 2 - Registrar Emprestimo \n");
	printf(" 3 - Registrar Devolucao \n");
	printf(" 9 - SAIR \n");
}

int menuCadastro(){
	int resultado;
	printf(" --- Cadastro de Livros --- \n");
	printf("Digite qualquer numero para voltar !");
		scanf("%d", &resultado);
	return(4);
}

int menuEmprestimo(){
	int resultado;
	printf(" --- Registrar Emprestimo --- \n");
	printf("Digite qualquer numero para voltar !");
	scanf("%d", &resultado);
	return(4);
}

int menuDevolucao(){
	
	int resultado;
	printf(" --- Registrar Devolucao --- \n");
	printf("Digite qualquer numero para voltar !");
	scanf("%d", &resultado);
	return(4);
}

int main (void){
	
		struct livraria
	{
		char nomeDoLivro[50];
		int numeroDoLivro;
		int estadoDoLivro;
	};
	
	int lerOpcao = 0;
	int contador = 0;
	int qntdLivros;
	int retorno;
	
	
	while (contador ==  0){
			
		mostraMenu();
		scanf("%d",&lerOpcao);
		
		
		
		switch (lerOpcao){
			case 1:
				retorno = menuCadastro();
					if(retorno == 4){
						break;	
					}
			case 2:
				retorno = menuEmprestimo();
					if(retorno == 4){
						break;	
					}
			case 3:
			 retorno = menuDevolucao();
				if(retorno == 4){
						break;	
					}
			case 9:
				contador = 9;
				break;
			default:
				break;		
		}
		
	}

	system("pause");
}
