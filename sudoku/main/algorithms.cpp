#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <array>
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

int gerador(int Sudoku[9][9], int SudokuSol[9][9], int dificuldade) {

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

    for (int i = 0; i <= 8; i++) {
      for (int j = 0; j <= 8; j++) {
        SudokuSol[i][j] = Sudoku[i][j];
      }
    }

    vector<int> coordenadas = {0,1,2,3,4,5,6,7,8};
    int pecasAremover;
    if (dificuldade == 1) pecasAremover = 3;
    else if (dificuldade == 2) pecasAremover = 5;
    else pecasAremover = 10;
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

    return 0;
}

int jogar(int Sudoku[9][9], int SudokuSol[9][9], int dificuldade) {

  int linha;
  int coluna;
  int valor;
  int pecasApreencher;

  if (dificuldade == 1) pecasApreencher = 3;
  else if (dificuldade == 2) pecasApreencher = 5;
  else pecasApreencher = 10;

  while (true) { //Loop de preenchimento manual

    printSudoku(Sudoku);

    cout << "\n| Digite a linha (entre 1 e 9) (0 para encerrar): ";
    cin >> linha;
    cout << "\n| Digite a coluna (entre 1 e 9) (0 para encerrar): ";
    cin >> coluna;
    cout << "\n| Digite o valor (entre 1 e 9): ";
    cin >> valor;
    linha--;
    coluna--;

    if (linha < 0 && linha > 8 && coluna < 0 && coluna > 8 && valor < 1 && valor > 9) {
      cerr << "Valores fora do intervalo de 1 a 9!" << endl;
    }

    else if (Sudoku[linha][coluna] != 0) {
      cerr << "Lugar ja preenchido!" << endl;
    }

    else if (SudokuSol[linha][coluna] != valor) {
      cerr << "Valor no lugar errado! Tente novamente." << endl;
    }

    else {

      Sudoku[linha][coluna] = valor;
      pecasApreencher--;
      if (pecasApreencher == 0) {
        cout << "\nSudoku completo! Parabens!";
        return 0;
      }
    }

  }

}

int criarSudokuManualmente(int sudoku[9][9]) {

	int linha, coluna, valor;
	char operacaoInterna = 's';

cout << "\n";

	while(true){

    printSudoku(sudoku);

		cout << "\nDigite a linha (entre 1 e 9) (0 para encerrar): ";
		cin >> linha;
		cout << "\nDigite a coluna (entre 1 e 9) (0 para encerrar): ";
		cin >> coluna;
		cout << "\nDigite o valor (entre 1 e 9): ";
		cin >> valor;

    if(linha == 0 || coluna == 0) //Condição de parada do loop de preenchimento.
      break;

		if(sudoku[linha - 1][coluna - 1] == 0){
			sudoku[linha - 1][coluna - 1] = valor;
		}else{
			cout << "\n(A casa ja esta preenchida!!!)\n"<< endl;
		}
	}

	cout << "\nResolver sudoku? (s/n)" << endl;
	cin >> operacaoInterna;

	if(operacaoInterna == 's'){

		function_backTracking(sudoku,0,0);
		printSudoku(sudoku);
	}

  return 0;
}
