#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <array>
#include <time.h>
#include "methodsAuxiliars.cpp"

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
  cout << "passou1";
  srand (time(NULL));
  cout << "passou2";
    for (int i = 0; i <= 8; i++) {
      vector<int> linha = {1,2,3,4,5,6,7,8,9};
      cout << "passou3";
      shuffle (linha.begin(), linha.end(), default_random_engine(rand()));
      cout << "passou4";

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
    if (dificuldade == 1) pecasAremover = 10;
    else if (dificuldade == 2) pecasAremover = 15;
    else pecasAremover = 20;
    int linha;
    int coluna;

    while (pecasAremover != 0) {
      shuffle (coordenadas.begin(), coordenadas.end(), default_random_engine(rand()));
      linha = coordenadas[0];
      shuffle (coordenadas.begin(), coordenadas.end(), default_random_engine(rand()));
      coluna = coordenadas[0];

      if (Sudoku[linha][coluna] != 0) {
        Sudoku[linha][coluna] = 0;
        pecasAremover--;
      }

    }

    return 0;
}

int jogar(int Sudoku[9][9], int SudokuSol[9][9], int dificuldade) {

  char valorColuna;

  int linha;
  int coluna;
  int valor;
  int pecasApreencher;

  if (dificuldade == 1) pecasApreencher = 10;
  else if (dificuldade == 2) pecasApreencher = 15;
  else pecasApreencher = 20;

  while (true) { //Loop de preenchimento manual

    printSudoku(Sudoku);

    cout << "\n| Digite D0 para receber uma dica.";
    cout << "\n| Digite S0 para visualizar a solução do sudoku.";
    cout << "\n| Inserir <coluna (A a I)> <linha (1 a 9) (0 para encerrar)> : ";
    cin >> valorColuna >> linha;

    if(valorColuna == 'D' && linha == 0) {

      //Caio, gera uma funcao aqui que escolhe uma casa aleatoria vazia e adiciona o numero que encaixa nela.
    }
    else if (valorColuna == 'S' && linha == 0) {

      function_backTracking(Sudoku,0,0);
      printSudoku(Sudoku);
    }
    if(linha == 0)
      break;

    cout << "\n| Digite o valor (entre 1 e 9): ";
    cin >> valor;

    coluna = retornarColuna(valorColuna);
    linha--;

    if ((linha < 0 || linha > 8) || (coluna < 0 || coluna > 8) || (valor < 1 || valor > 9)) {
      cerr << "Valores fora do intervalo de 1 a 9!" << endl;
    }

    else if (Sudoku[linha][coluna] != 0) {
      cerr << "Lugar ja preenchido!" << endl;
    }

    else if (SudokuSol[linha][coluna] != valor) {
      cerr << "Valor no lugar errado! Tente novamente." << endl;
    }

    //Eu comentei aqui para ver se o sudoku vai possuir varias solucoes

    else {

      Sudoku[coluna][linha] = valor;
      pecasApreencher--;
      if (pecasApreencher == 0) {
        cout << "\nSudoku completo! Parabens!!";
        return 0;
      }
    }

  }

}

int criarSudokuManualmente(int sudoku[9][9]) {

  char valorColuna;

	int linha, coluna, valor;
	char operacaoInterna = 's';

cout << "\n";

	while(true){

    printSudoku(sudoku);

		cout << "\n| Inserir <coluna (A a I)> <linha (1 a 9) (0 para encerrar)> : ";
    cin >> valorColuna >> linha;

    if(linha == 0)
      break;

    coluna = retornarColuna(valorColuna);

		cout << "\nDigite o valor (entre 1 e 9): ";
		cin >> valor;

		if(sudoku[linha - 1][coluna] == 0){

			sudoku[linha - 1][coluna] = valor;

      if(verificaLinha(sudoku,valor,linha - 1,coluna) && verificaColuna(sudoku,valor,linha - 1,coluna) && verificaSetor(sudoku,valor,linha - 1,coluna)) {

      }
      else {
        sudoku[linha - 1] [coluna] = 0;
        cerr << "\nValor inserido burla as restrições básicas do sudoku!" <<endl;
      }

		}else {
			cerr << "\n(A casa ja esta preenchida!!!)\n"<< endl;
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

int jogarSudokuCompetitivo(int Sudoku[9][9], int SudokuSol[9][9]) {

  char valorColuna;

  int linha;
  int coluna;
  int valor;
  int pecasApreencher = 4;
  int tempoJ1 = 0;
  int tempoJ2 = 0;

  while (true) {

    auto start = chrono::steady_clock::now();
    while (true) { // Turno no  jogador 1

      printSudoku(Sudoku);

      cout << "\n|Turno do jogador 1!";
      cout << "\n| Inserir <linha (A a I)> <coluna (1 a 9) (0 para encerrar)> : ";
      cin >> linha >> valorColuna;

      cout << "\n| Digite o valor (entre 1 e 9): ";
      cin >> valor;

      coluna = retornarColuna(valorColuna);
      linha--;

      if ((linha < 0 || linha > 8) || (coluna < 0 || coluna > 8) || (valor < 1 || valor > 9)) {
        cerr << "Valores fora do intervalo de 1 a 9!" << endl;
      }

      else if (Sudoku[linha][coluna] != 0) {
        cerr << "Lugar ja preenchido!" << endl;
      }

      else if (SudokuSol[linha][coluna] != valor) {
        cerr << "Valor no lugar errado! Tente novamente." << endl;
      }

      else {
        auto end = chrono::steady_clock::now();
        tempoJ1 = tempoJ1 + chrono::duration_cast<chrono::seconds>(end - start).count();
        cout << "Tempo total do Jogador 1: " << tempoJ1 << " segundos.\n";
        Sudoku[linha][coluna] = valor;
        pecasApreencher--;
        if (pecasApreencher == 0) {
          if (tempoJ1 > tempoJ2) cout << "\nJogador 2 venceu!\n";
          else "\nJogador 1 venceu!\n";
          cout << "Tempo do Jogador 1: " << tempoJ1 << " segundos." << "\nTempo do Jogador 2: " << tempoJ2 << " segundos.";
          return 0;
        }
        break;
      }
    }

    start = chrono::steady_clock::now();
    while (true) { // Turno no  jogador 2
      printSudoku(Sudoku);

      cout << "\n| Turno do jogador 2!";
      cout << "\n| Inserir <linha (A a I)> <coluna (1 a 9) (0 para encerrar)> : ";
      cin >> linha >> valorColuna;

      cout << "\n| Digite o valor (entre 1 e 9): ";
      cin >> valor;

      linha = retornarColuna(valorColuna);
      coluna--;

      if ((linha < 0 || linha > 8) || (coluna < 0 || coluna > 8) || (valor < 1 || valor > 9)) {
        cerr << "Valores fora do intervalo de 1 a 9!" << endl;
      }

      else if (Sudoku[linha][coluna] != 0) {
        cerr << "Lugar ja preenchido!" << endl;
      }

      else if (SudokuSol[linha][coluna] != valor) {
        cerr << "Valor no lugar errado! Tente novamente." << endl;
      }

      else {
        auto end = chrono::steady_clock::now();
        tempoJ2 = tempoJ2 + chrono::duration_cast<chrono::seconds>(end - start).count();
        cout << "Tempo total do Jogador 2: " << tempoJ2 << " segundos.\n";
        Sudoku[linha][coluna] = valor;
        pecasApreencher--;
        if (pecasApreencher == 0) {
          if (tempoJ1 > tempoJ2) cout << "\nJogador 2 venceu!\n";
          else "\nJogador 1 venceu!\n";
          cout << "Tempo do Jogador 1: " << tempoJ1 << " segundos." << "\nTempo do Jogador 2: " << tempoJ2 << " segundos.";
          return 0;
        }
        break;
      }
    }


  }

}
