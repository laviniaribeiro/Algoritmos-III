#include <iostream>
using namespace std;

struct ponto{
	int x;
	int y;
};

int area_triangulo(ponto a, ponto b, ponto p){
	return (a.x * b.y - a.y * b.x + a.y * p.x - a.x * p.y + b.x * p.y - b.y * p.x)/2; //formula para o calculo da area triang.
}

int lado(ponto a, ponto b, ponto p){
	int area = area_triangulo(a,b,p);
	if(area>0){ //ponto p esta a esquerda
		return 1;
	}
	else if(area<0){ //ponto p esta a direita 
		return -1;
	}
	else{
		//a, b e p estão alinhados
		return 0;
	}
}

int main(){
	
	string lados[] = {"Direita", "Alinhado", "Esquerda"};
	
	ponto a;
	a.x = 1;
	a.y = 2;
	
	ponto b;
	b.x = 4;
	b.y = 4;
	
	ponto p;
	p.x = 4;
	p.y = 1;
	
	cout << "Posicao do ponto P: " << lados[lado(a,p,b)+1] << endl;
	
	return 0;
}