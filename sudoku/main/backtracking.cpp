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

int gerador(int Sudoku[9][9], int dificuldade) {

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

    printSudoku(Sudoku);

    vector<int> coordenadas = {0,1,2,3,4,5,6,7,8};
    int pecasAremover;
    if (dificuldade == 1) pecasAremover = 40;
    else if (dificuldade == 2) pecasAremover = 50;
    else pecasAremover = 55;
    int linha;
    int coluna;

    while (pecasAremover != 0) {
      unsigned seed = chrono::system_clock::now().time_since_epoch().count();
      shuffle (coordenadas.begin(), coordenadas.end(), default_random_engine(seed));
      linha = coordenadas[0];
      seed = chrono::system_clock::now().time_since_epoch().count();
      shuffle (coordenadas.begin(), coordenadas.end(), default_random_engine(seed));
      coluna = coordenadas[0];

      if (Sudoku[linha][coluna] != 0) {
        Sudoku[linha][coluna] = 0;
        pecasAremover--;
      }

    }

    printSudoku(Sudoku);

    return 0;
}

int jogar(int Sudoku[9][9]) {
  printSudoku(Sudoku);

  while (true) {
    cout << "Digite a linha em que deseja colocar um valor" << endl;
    int linha;
    cin >> linha;
    cout << "Digite a coluna" << endl;
    int coluna;
    cin >> coluna;
    cout << "Qual o valor que deseja colocar?" << endl;
    int valor;
    cin >> valor;
    linha--;
    coluna--;

    if (linha < 0 && linha > 8 && coluna < 0 && coluna > 8 && valor < 1 && valor > 9) {
      cout << "Valores fora do intervalo de 1 a 9!" << endl;
    }

    else if (Sudoku[linha][coluna] != 0) {
      cout << "Lugar ja preenchido!" << endl;
    }

    else if (!verificarTudo(Sudoku,valor,linha,coluna)) {
      cout << "Valor no lugar errado! Tente novamente." << endl;
    }

    else {
      Sudoku[linha][coluna] = valor;

      printSudoku(Sudoku);
    }

  }

}
