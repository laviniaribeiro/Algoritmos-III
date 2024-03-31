#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Coordenadas{
    int x, y;
};

double calcularDistancia(const Coordenadas& p1, const Coordenadas& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double calcularMinimoMaterial(const vector<Coordenadas>& coordenadas) {
    double totalMaterial = 0.0;

    for (size_t i = 0; i < coordenadas.size(); i++) {
        totalMaterial += calcularDistancia(coordenadas[i], coordenadas[(i + 1) % coordenadas.size()]);
    }

    return totalMaterial;
}

int main() {
    int numReservas;
    cout << "Digite o numero de reservas florestais: ";
    cin >> numReservas;

    for (int i = 0; i < numReservas; i++) {
        int numArvores;
        cout << "Digite a quantidade de arvores na reserva " << i + 1 << ": ";
        cin >> numArvores;

        vector<Coordenadas> coordenadas;
        for (int j = 0; j < numArvores; ++j) {
            Coordenadas arvore;
            cout << "Digite as coordenadas da arvore " << j + 1 << " (x y): ";
            cin >> arvore.x >> arvore.y;
            coordenadas.push_back(arvore);
        }

        double materialRequisitado = calcularMinimoMaterial(coordenadas);
        cout << "A quantidade minima de material para cercar a reserva " << i + 1 << " e: " << materialRequisitado << endl;
    }

    return 0;
}
