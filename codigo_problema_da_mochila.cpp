#include <iostream>
using namespace std;

int solucao[7][10]
int n = 4;
int peso[4] = {7,3,4,5};
int valor[4] = {42,12,40,25};

int mochila(int item, int capacidade){
	if(item >= n)
		return 0;
	
	if(solucao[item][capacidade] != -1)
		return solucao[item][capacidade];
	
	//escolhi o item atual
	int ans1 = 0;
	if(capacidade >= peso[item])
		ans1 = mochila(item+1, capacidade-peso[item]) + valor[item];
	
	//nao escolhi o item atual
	int ans2 = mochila(item+1, capacidade);
	int ans = max(ans1, ans2);
	
	solucao[item][capacidade] = ans;
	return ans;
}

int main(){
	
	for(int i=0; i<n; i++)
		for(int j=0; j<c; j++)
			solucao[i][j] = -1;
	
	cout << mochila(0, c) << endl;
}