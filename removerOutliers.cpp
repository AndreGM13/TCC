#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(int argc, char* argv[]){

    if (argc < 2){
        return 1;
    }

    string nomeArquivo = argv[1];
    FILE *arquivo;
    vector<int> bit, bitlimpo;
    int valor, aux;
    double ls, li, iqr;

    arquivo = fopen(nomeArquivo.c_str(), "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    else{

        while (fscanf(arquivo, "%d", &valor) == 1) {
        bit.push_back(valor);
        }

        fclose(arquivo);

        sort(bit.begin(), bit.end());

        aux = bit.size()/4;
        iqr = bit[3 * aux] - bit[aux];
        li = bit[aux] - (1.5 * iqr);
        ls = bit[3 * aux] + (1.5 * iqr);

        for(int i=0; i<bit.size(); i++){
            if(bit[i] > li && bit[i] < ls)
                {
                valor = bit[i];
                bitlimpo.push_back(valor);
                }
                
        }
        
        arquivo = fopen(nomeArquivo.c_str(), "w");

        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo para sobrescrita\n");
            return 1;
        }

        for(int i = 0; i < bitlimpo.size(); i++){
            fprintf(arquivo, "%d\n", bitlimpo[i]);
        }

        fclose(arquivo);
    }
}
