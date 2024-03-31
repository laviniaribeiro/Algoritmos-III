#include <iostream>
using namespace std;

// exemplo tipo o do exercicio do triangulo do slide de algoritmos geometricos (1° exercicio)
struct ponto{
	int x;
	int y;
};

int area_triangulo(ponto a, ponto b, ponto c){
	return (a.x * b.y - a.y * b.x + a.y * c.x - a.x * c.y + b.x * c.y - b.y * c.x)/2; //formula para o calculo da area triang.
}

int sentido_rotacao(ponto a, ponto b, ponto c){
	int area = area_triangulo(a,b,c);
	if(area>0){ //sentido anti horario
		return 1;
	}
	else if(area<0){ //sentido horario 
		return 2;
	}
	else{
		//se a area for igual a zero os pontos sao colineares
		return 0;
	}
}

int main(){
	
	string sentidos[] = {"Colinear", "Anti-horario", "Horario"};
	
	ponto a;
	a.x = 1;
	a.y = 2;
	
	ponto b;
	b.x = 4;
	b.y = 4;
	
	ponto c;
	c.x = 4;
	c.y = 1;
	
	cout << "Area: " << area_triangulo(a,b,c) << endl;
	cout << "Sentido: " << sentidos[sentido_rotacao(a,b,c)] << endl;
	
	return 0;
}