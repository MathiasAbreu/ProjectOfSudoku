#include <iostream>
#include "methods.cpp"

int function_backTracking(int Matriz[9][9], int numeroAnterior, int linha, int coluna) {

    int numero = 1;

    if(Matriz[linha][coluna] == 0) {

        while(numero <= 9) {

            if(numero != numeroAnterior) {

                Matriz[linha][coluna] = numero;
                if(verificaLinha(Matriz,numero,linha,coluna) & verificaColuna(Matriz,numero,linha,coluna) & verificaSetor(Matriz,numero,linha,coluna)) {

                    if(function_backTracking(Matriz,numero,linha,coluna))
                        return true;
                }
                else
                    numero += 1;
            }
            else
                numero += 1;
        }

        return false;
    }
    else {

        if(linha + 1 > 8) {

            if(coluna + 1 <= 8)
                return function_backTracking(Matriz,0,0,coluna + 1);
            else
                return true;
            
        }
        else
            return function_backTracking(Matriz,numeroAnterior,linha + 1,coluna);
    }
}
