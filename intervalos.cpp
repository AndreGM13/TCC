#include<stdio.h>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    FILE *arquivo;
    FILE *arquivo2;
    vector<int> intervalos, tempo0, tempo1;
    vector<double> prob0, prob1;
    double aux, c0 = 0, c1 = 0, total, largura, min, max, li;
    int valor, j0=0, j1=0;

    arquivo = fopen("tempo0", "r");
    arquivo2 = fopen("tempo1", "r");

    while (fscanf(arquivo, "%d", &valor) == 1) {
        tempo0.push_back(valor);
        }

    while (fscanf(arquivo2, "%d", &valor) == 1) {
        tempo1.push_back(valor);
        }

    if(tempo1[0] < tempo0[0])
        min = tempo1[0];
    else
        min = tempo0[0];

    if(tempo1[tempo1.size()-1] > tempo0[tempo0.size()-1])
        max = tempo1[tempo1.size()-1];
    else
        max = tempo0[tempo0.size()-1];

    max = ceil(max/10.0);     min = floor(min/10.0);

    max = max*10;           min = min*10;

    total = tempo0.size();
    aux = (max - min)/10;
    li = min;
    largura  = aux;

    for (int i = 0; i < 10; i++) {
        intervalos.push_back(aux);

        c0 = 0;
        while (j0 < tempo0.size() && tempo0[j0] <= aux) {
            if (tempo0[j0] >= li) {
                c0++;
            }
            j0++; 
        }
        prob0.push_back((double)c0 / tempo0.size());

        c1 = 0;
        while (j1 < tempo1.size() && tempo1[j1] <= aux) {
            if (tempo1[j1] >= li) {
                c1++;
            }
            j1++; 
        }
        prob1.push_back((double)c1 / tempo1.size());

        li = aux;
        aux += largura;
    }
    

}