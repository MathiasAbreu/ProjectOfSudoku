#include "methods.h"

int verificaLinha(int Matriz[9][9], int numero, int linha, int coluna) {

    for(int indice = 0; indice <= 8; indice++) {

        if(Matriz[linha][indice] == numero & indice != coluna)
            return false;
    }

    return true;
}

int verificaColuna(int Matriz[9][9], int numero, int linha, int coluna) {
    
    for(int indice = 0; indice <= 8; indice++) {

        if(Matriz[indice][coluna] == numero & indice != linha)
            return false;
    }

    return true;
}

int verificaSetor(int Matriz[9][9], int numero, int linha, int coluna) {

    int setorLinha;
    int setorColuna;

    if(linha <= 2)
        setorLinha = 0;
    else if(linha > 2 & linha <= 5)
        setorLinha = 3;
    else
        setorLinha = 6;

    if(coluna <= 2)
        setorColuna = 0;
    else if(coluna > 2 & coluna <= 5)
        setorColuna = 3;
    else
        setorColuna = 6;

    for(int indiceLinha = 0; indiceLinha <= (2 + setorLinha); indiceLinha++) {
        
        for(int indiceColuna = 0; indiceColuna <= (2 + setorColuna); indiceColuna++) {

            if(Matriz[indiceLinha][indiceColuna] == numero & (indiceLinha != linha & indiceColuna != coluna))
                return false;
        }
    }

    return true;
}