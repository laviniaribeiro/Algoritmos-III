#include <iostream>
using namespace std;

struct ponto{
	int x;
	int y;
};

int area_triangulo(ponto p1, ponto p2, ponto p3){
	
	return (p1.x * p2.y - p1.y * p2.x + p1.y * p3.x - p1.x * p3.y + p2.x * p3.y - p2.y * p3.x)/2;
}

int main(){
	ponto p1;
	p1.x = 1;
	p1.y = 2;
	
    ponto p2;
    p2.x = 4;
	p2.y = 4;
	
    ponto p3;
    p3.x = 4;
	p3.y = 1;
    
    ponto p;
    p.x = 3;
	p.y = 2;
    
    float tprincipal = area_triangulo(p1,p2,p3);
    
    float l1 = area_triangulo(p,p2,p3)/tprincipal; //lambda 1
    float l2 = area_triangulo(p1,p,p3)/tprincipal; //lambda 2
    float l3 = area_triangulo(p1,p2,p)/tprincipal; //lambda 3
    
    cout << "Lambda 1: " << l1 << endl;
    cout << "Lambda 2: " << l2 << endl;
    cout << "Lambda 3: " << l3 << endl;
    
    return 0;
}