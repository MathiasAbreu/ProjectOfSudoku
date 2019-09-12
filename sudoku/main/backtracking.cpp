#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "methods.cpp"

using namespace std;

int function_backTracking(int Matriz[9][9], int linha, int coluna) {

    int numero = 1;

    if(Matriz[linha][coluna] == 0) {

        while(numero <= 9) {

            Matriz[linha][coluna] = numero;
            if(verificaLinha(Matriz,numero,linha,coluna) && verificaColuna(Matriz,numero,linha,coluna) && verificaSetor(Matriz,numero,linha,coluna)) {

                if(function_backTracking(Matriz,linha,coluna))
                    return true;
            }

            numero += 1;
        }

        Matriz[linha][coluna] = 0;
        return false;
    }
    else {

        if(coluna + 1 > 8) {

            if((linha + 1) <= 8)
                return function_backTracking(Matriz,linha + 1,0);
            else
                return true; //O programa visitou todas as casas do sudoku e deve ter encontrado uma solução.
        }
        else
            return function_backTracking(Matriz,linha,coluna + 1);
    }
}

int gerador(int dificuldade) {

  int Sudoku[9][9] = {{0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0}};

    for (int i = 0; i <= 8; i++) {
      vector<int> linha = {1,2,3,4,5,6,7,8,9};
      unsigned seed = chrono::system_clock::now().time_since_epoch().count();
      shuffle (linha.begin(), linha.end(), default_random_engine(seed));

      int cont = 0;
      while (cont != 9) {
        for (int j = 0; j <= 8; j++) {
          if (linha[j] != 0 && verificarTudo(Sudoku, linha[j] , i, cont)) {
            Sudoku[i][cont] = linha[j];
            linha[j] = 0;
            cont++;
          }

        }
      }

    }

    for(int i = 0; i <= 8; i++) {
      printf("|%d|%d|%d|%d|%d|%d|%d|%d|%d|\n",Sudoku[i][0],Sudoku[i][1],Sudoku[i][2],Sudoku[i][3],Sudoku[i][4],Sudoku[i][5],Sudoku[i][6],Sudoku[i][7],Sudoku[i][8]);
    }

    return 0;


}
