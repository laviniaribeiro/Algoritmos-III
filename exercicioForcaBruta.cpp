#include <iostream>
#include <cstring>
using namespace std;

int quantidade;

//declarando dados na struct cadastro
struct cadastro{                                  //Análise RAM da funcao struct
	char nome[100];                               //1
	int matricula;                                //1
	int diaNascimento;                            //1 
	int mesNascimento;                            //1
	int anoNascimento;                            //1          Total: 5
};

//buscar aluno por matricula                                       //Analise RAM da funcao buscarPorMatricula
void buscarPorMatricula(cadastro aluno[], int matricula){          //3         
	for(int i=0; i<quantidade; i++){                               //7
		if(aluno[i].matricula == matricula){                       //4
			cout << "Nome: " << aluno[i].nome << endl;             //3
			cout << "Matricula: " << aluno[i].matricula << endl;   //3     linha 22: 7
			cout << "Data de nascimento: " << aluno[i].diaNascimento << aluno[i].mesNascimento << aluno[i].anoNascimento << endl;
			cout << "\n";                                          //1   
		}                                                          //Total: 28
	}
}

//buscar aluno por nome                                          //Analise RAM da funcao buscarPorNome
void buscarPorNome(cadastro aluno[], char nome[100]){            //3
	for(int i=0; i<quantidade; i++){                             //7
		if(strcmp(aluno[i].nome,nome)==0)                        //4
		{
			cout << "Nome: " << aluno[i].nome << endl;           //3
			cout << "Matricula: " << aluno[i].matricula << endl; //3      linha 35: 7
			cout << "Data de nascimento: " << aluno[i].diaNascimento << "/" << aluno[i].mesNascimento << "/" << aluno[i].anoNascimento << endl;
			cout << "\n";                                        //1 
		}                                                        //Total: 28
	}
}

//buscando alunor por idade                                         //Analise RAM da funcao buscarPorIdade
void buscarPorIdade(cadastro aluno[], int idade){                   //3
	for(int i=0; i<quantidade; i++){                                //7
		if((2023-aluno[i].anoNascimento) == idade){                 //5
			cout << "Nome: " << aluno[i].nome << endl;              //3
			cout << "Matricula: " << aluno[i].matricula << endl;    //3     linha 47: 7
			cout << "Data de nascimento: " << aluno[i].diaNascimento << "/" << aluno[i].mesNascimento << "/" << aluno[i].anoNascimento << endl;
			cout << "\n";                                           //1 
		}                                                           //Total: 29
	}
}

int main(){                                                          //Analise RAM int main
	char nome[100];                                                  //1
	int matricula;                                                   //1
	int i=0;                                                         //1
	int escolha;                                                     //1
	int idade;                                                       //1
	
	//fazendo interface com o usuario
	cout << "Digite a quantidade de alunos que deseja cadastrar: ";  //1
	cin >> quantidade;                                               //1
	
	cadastro aluno[quantidade];                                      //2
	
	//cadastrando alunos
	for(i=0; i<quantidade; i++){                                     //7
		cout << "Digite o nome do aluno: ";                          //1
		cin >> aluno[i].nome;                                        //3
		cout << "Digite a matricula do aluno: ";                     //1
		cin >> aluno[i].matricula;                                   //3
		cout << "Digite a data de nascimento do aluno: " << endl;    //1
		cout << "Dia: ";                                             //1
		cin >> aluno[i].diaNascimento;                               //3
		cout << "Mes: ";                                             //1
		cin >> aluno[i].mesNascimento;                               //3
		cout << "Ano: ";                                             //1
		cin >> aluno[i].anoNascimento;                               //3
	}
	
	//fazendo interface com o usuario para saber qual opcao ele quer escolher
	cout << "Escolha a opcao que voce deseja: " << endl;             //1
	cout << "1- Buscar aluno por nome." << endl;                     //1
	cout << "2- Buscar aluno por matricula." << endl;                //1
	cout << "3- Buscar aluno por idade." << endl;                    //1
	cout << "4- Sair." << endl;                                      //1
	
	cin >> escolha;                                                  //1
	
	//acoes apos o usuario escolher a opcao
	while(escolha!=4){                                               //2
		
		cin >> escolha;                                              //1
		
		switch(escolha){                                             //1
			case 1:
				cout << "Digite o nome do aluno: ";                  //1
				cin.ignore();                                        //1
				cin.getline(nome,100);                               //1
				cout << "\n";                                        //1
				
				buscarPorNome(aluno,nome);                           //3
				break;
			
			case 2:
				cout << "Digite a matricula do aluno: ";            //1
				cin >> matricula;                                   //1
				cout << "\n";                                       //1
				
				buscarPorMatricula(aluno,matricula);                //3
				break;
			
			case 3:
				cout << "Digite a idade do aluno: ";               //1
				cin >> idade;                                      //1
				cout << "\n ";                                     //1
				
				buscarPorIdade(aluno,idade);                       //3
				break;
                                                                   //Total: 66
			case 4:
				break;
		}
	}
	                         //Total das analises de RAM: 156
	return 0;
}