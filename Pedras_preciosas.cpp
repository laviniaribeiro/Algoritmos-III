#include <iostream>
using namespace std;


struct Item {

    int valor;
    int peso;

};

int main() {

    int dp[100][100];
    int caminho[100][100];
    int n;
    int capacidade;

    Item itens[100];

    cout << "Digite a quantidade de itens: ";
    cin >> n;

    cout << "Digite a capacidade da mochila: ";
    cin >> capacidade;

    for (int i = 0; i < n; i++) {
        cin >> itens[i].valor >> itens[i].peso;
    }

    for (int j = 0; j <= capacidade; j++)
        dp[n][j] = 0;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = n - 1; i >= 0; i--)
        for (int j = 1; j <= capacidade; j++) {

            int pegar, passar;
            passar = dp[i + 1][j];

            if (j >= itens[i].peso)
                pegar = dp[i + 1][j - itens[i].peso] + itens[i].valor;

            else
                pegar = 0;

            if (pegar > passar) {
                dp[i][j] = pegar;
                path[i][j] = 1;
            }
			 
			else {
                dp[i][j] = passar;
                path[i][j] = 0;
            }

        }

    cout << dp[0][capacidade] << endl; 

    int i=0;
    int j=capacidade;

    while (i != n) {
        if (path[i][j] == 0)
            i++;
        
        else {
            cout <<"Peguei o item "<< i << endl;
            cout <<"Peso: "<<itens[i].peso << endl;
            cout <<"Valor: "<< itens[i].valor << endl;

            j -= itens[i].peso;

            i++;
        }
	}
	
	return 0;
}