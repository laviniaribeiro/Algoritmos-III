#include<iostream>
#include <locale.h> 
#include<string>
#include <cstdlib>
using namespace std;


/*
	Considere o tipo abstrato de dados a seguir.
	Ele representa uma habilidade que pode ser usada por um personagem em um jogo de RPG.
	Habilidades s�o usadas para superar desafios no jogo. 
	Desafios podem ser desafios mentais, f�sicos ou espirituais.
	Cada desafio tem um n�vel de dificuldade e para conseguir super�-lo, o personagem pode usar uma de suas habilidades.
	Quando a habilidade � usada, um valor aleat�rio de 1 a 20 � gerado e somado ao modificador da habilidade.
	Se o valor resultante for maio que o n�vel de dificuldade do desafio, o personagem consegue super�-lo.
	
	Cada habilidade tem um c�digo �nico e uma descri��o.
	Al�m disso � definido um atributo base (1: Mente, 2: Corpo ou 3: Esp�rito).
	Por fim � definido um modificador.
	
*/

string atributos_base[3] = {"Mental", "F�sico", "Espiritual"};

typedef struct habilidade {
	int codigo;
	string descricao;
	int atributo_base;
	int modificador;
} Habilidade;



struct Node {
	Habilidade info;
	Node * esquerda;
	Node * direita;
};

void insere_habilidade(Node *& raiz, Habilidade h){
	
	if(raiz == NULL){
		raiz = new Node;
		raiz->info = h;
		raiz->esquerda = NULL;
		raiz->direita = NULL;
	} else{
		if(h.codigo < raiz->info.codigo){
			insere_habilidade(raiz->esquerda, h);
		} else {
			insere_habilidade(raiz->direita, h);
		}
	}
}

Habilidade * busca_habilidade(Node * raiz, int codigo_habilidade){
	
	if(raiz == NULL)
		return NULL;
	
	if(raiz->info.codigo == codigo_habilidade)
		return &(raiz->info);
	
	if(codigo_habilidade < raiz->info.codigo)
		return busca_habilidade(raiz->esquerda, codigo_habilidade);
	else	
		return busca_habilidade(raiz->direita, codigo_habilidade);
	
}

//mostrando as habilidades em ordem crescente 
void exibe_info(Habilidade info){
	cout << "Codigo: " << info.codigo << endl;
    cout << "Descricao: " << info.descricao << endl;
	cout << "Atributo nase: " << atributos_base[info.atributo_base] << endl;
	cout << "Modifcador: " << info.modificador << endl;
}

void lista_em_erdem(Node * raiz){
    if(raiz->esquerda != NULL){
		lista_em_ordem(raiz->esquerda);
	}
		
	exibe_info(raiz->info);
		
	if(raiz->direita != NULL){
		lista_em_ordem(raiz->direita);
	}
}

//deletando a arvore e liberando a memoria alocada dinamicamente
void limpa_arvore(Node * &raiz){
	if(raiz->esquerda != NULL){
		limpa_arvore(raiz->esquerda);
	}
	
	if(raiz->direita != NULL){
		limpa_arvore(raiz->direita);
	}
	
	delete raiz;
	raiz = NULL;
}

//algoritmo de remocao da arvore
Node * encontra_redir_menor(Node * &raiz){
	Node * t = raiz;
	if(t->esquerda == NULL){
		raiz = raiz->direita;
		return t;
	}
	else
	{
		return encontra_redir_menor(raiz->esquerda);
	}
}

int remove_habilidade(Node * &raiz, int codigo_habilidade){
	if(raiz == NULL)
		return 1;
	Node * p;
	if(raiz->info.codigo == codigo_habilidade){
		p = raiz;
		if(raiz->esquerda == NULL){
			raiz = raiz->direita;
		}
		else
		{
			if(raiz->direita == NULL){
				raiz = raiz->esquerda;
			}
			else
			{
				p = encontra_redir_menor(raiz->direita);
				raiz->info = p->info;
			}
		}
		delete p;
		p = NULL;
		return 0;
	}
	else
	{
		if(codigo_habilidade < raiz->info.codigo){
			return remove_habilidade(raiz->esquerda, codigo_habilidade);
		}
		else{
			return remove_habilidade(raiz->direita, codigo_habilidade)
		}
	}
}


/*
	A fun��o gera_desafio cria um desafio de um tipo aleat�rio e com um valor de dificuldade de 0 a 30.
*/

typedef struct desafio{
	int dificuldade;
	int atributo_base;	
} Desafio;

Desafio gerar_desafio(){
	Desafio d;
	d.dificuldade = rand() % 30;
	d.atributo_base = rand() % 3;
	return d;
}

/*
	A fun��o rolar_d20 cria um valor aleat�rio de 0 a 20 para ser somado ao modificador quando uma habilidade for usada.
*/

int rolar_d20(){
	return (rand() % 20)+1;
}

/*
	Crie um sistema com as seguintes op��es para o usu�rio: 1> Cadastrar nova habilidade e 2> Testar habilidades.
	
	Na op��o 1, solicite que o usu�rio informe os dados sobre a habilidade a ser cadastrada. 
	Aloque mem�ria de forma din�mica para cada uma dessas habilidades e adicione em uma estrutura de dados.
	
	Na op��o 2, gere um desafio aleat�rio, usando a fun��o gerar_desafio e apresente o tipo do desafio para o usu�rio.
	Em seguida, solicite que o usu�rio informe o c�digo da habilidade a ser testada.
	Busque a habilidade na estrutura de dados.
	Por fim, verifique se a habilidade � do mesmo tipo de atributo base que o desafio.
	Se n�o for, apresente a mensagem "Essa habilidade n�o pode ser usada para esse desafio." e solicite para o usu�rio entrar com outra habilidade.
	Se for, gere um valor aleat�rio usando a fun��o rolar_d20 e some com o modificador da habilidade.
	Se o valor resultante for maior ou igual ao valor da dificuldade do desafio, apresente a mensagem "Voc� superou esse desafio!".
	Sen�o, mostre a mensagem "Voc� fracassou nesse desafio...".

	
*/
int main(){
	setlocale(LC_ALL,"");
	
	cout<<"Bem vindo ao sistema de habilidades.";
	
	Node * raiz = NULL;
	
	int op=4;
	
	do{	
		cout<<"\n\t\tMenu\n\t1> Cadastrar nova habilidade\n\t2> Testar habilidades\n\n\t3> Sair\n";
		
		
	
		do{	
			cout<<"Entre com a op��o desejada: ";
			cin >> op;
			if(op != 1 && op != 2 && op != 3)
				cout<<"Op��o inv�lida!"<<endl;	
		} while(op != 1 && op != 2 && op != 3);
		
		if(op == 1){
			// ----Cadastrar habilidade----
			cout<<"\n\tCadastro de habilidade"<<endl;
			//Solicitar dados da habilidade
			Habilidade h;
			cout<<"Insira o c�digo da habilidade:";
			cin>>h.codigo;
			cout<<"Insira a descricao da habilidade:";
			cin>>h.descricao;
			cout<<"Insira o atributo base da habilidade (1:Mental, 2:F�sico, 3:Espiritual):;
			cin>>h.atributo_base;
			cout<<"Insira o modificador da habilidade:";
			cin>>h.modificador;
			
			// Alocar mem�ria din�micamente			
			// Adicionar na estrutura de dados
			insere_habilidade(raiz, h);
			
		} else if(op ==2){
			cout<<"\n\tTeste de habilidade"<<endl;
			// -----Testar habilidade-----
			// Gerar desafio
			Desafio d = gerar_desafio();
			cout<<"Desafio entrentado: "<<atributos_base[d.atributo_base]<<endl;
			cout<<d.dificuldade<<endl;
			
			// Escolher habilidade			
			int habilidade;
			bool hvalido = true;
			Habilidade * resultado = NULL;
			do{
				cout<<"Escolha a sua habilidade: ";			
				cin>>habilidade;
				
				// Buscar habilidade na estrutura de dados
				resultado = busca_habilidade(raiz, habilidade);
				if(resultado == NULL){
					cout<<"Habilidade n�o existe!\nInsira uma habilidade v�lida.\n";
					hvalido = false;
				} else {			
				// Verificar o atributo base da habilidade
					if(resultado->atributo_base != d.atributo_base){
						cout<<"Habilidade n�o � v�lida!\nInsira uma habilidade v�lida.\n";
						hvalido = false;
					} else {
						hvalido = true;
					}
				}		
			}while(hvalido == false);
			
			
			// Rolar d20
			int valor_aleatorio = rolar_d20();
			cout<<"Resultado: "<<<valor_aleatorio<<" + ";
			
			// Somar com o modificador da habilidade
			cout<<resultado->modificador<<endl;
			
			//Verificar se superou o desafio
			if(valor_aleatorio + resultado->modificador >= d.dificuldade){
				cout<<"Voc� superou esse desafio!"<<endl;
			} else {
				cout<<"Voc� fracassou nesse desafio..."<<endl;
			}
		}
		
			
	}while(op != 3);
	
	cout << "Obrigado por utilizar o sistema de habilidades!" << endl;
	
	return 0;
}

/*
>>>>>>>>>>>>>>>Exemplo de uso:

Bem vindo ao sistema de habilidades.
                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a op��o desejada: 5
Op��o inv�lida!
Entre com a op��o desejada: 1

	   	Cadastro de Habilidade
Informe o c�digo: 1
Informe a descri��o: Chamas do patrono
Informe o atributo base (1>Mental, 2>F�sico, 3>Espiritual): 3
Informe o modificador: 5

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a op��o desejada: 1

	   	Cadastro de Habilidade
Informe o c�digo: 2
Informe a descri��o: Escalada
Informe o atributo base (1>Mental, 2>F�sico, 3>Espiritual): 3
Informe o modificador: 3

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a op��o desejada: 1

	   	Cadastro de Habilidade
Informe o c�digo: 3
Informe a descri��o: Conhecimento de hist�ria
Informe o atributo base (1>Mental, 2>F�sico, 3>Espiritual): 3
Informe o modificador: 5

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a op��o desejada: 2
		
		Teste de habilidade
Desafio entrentado: Espiritual
Escolha a sua habilidade: 1
Voc� superou esse desafio!

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a op��o desejada: 2
		
		Teste de habilidade
Desafio entrentado: F�sico
Escolha a sua habilidade: 1
Essa habilidade n�o pode ser usada para esse desafio.
Escolha a sua habilidade: 2
Voc� superou esse desafio!

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a op��o desejada: 2
		
		Teste de habilidade
Desafio entrentado: Mental
Escolha a sua habilidade: 3
Voc� fracassou nesse desafio...

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a op��o desejada: 3
Obrigado por utilizar o sistema de habilidades!


*/