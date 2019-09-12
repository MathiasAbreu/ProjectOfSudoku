#include<iostream>
#include<cstring>
#include"algorithms.cpp"

# define tamanho 4
using namespace std;

int SudokuManual[9][9] = {
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0}};

int SudokuGerado[9][9] = {
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0}};

int SudokuGeradoSolucao[9][9] = {
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0}};

int main(){

   while(true){

      int operacao;
      cout << "\n| ****          SUDOKU             **** |" << endl;
      cout <<   "| 1 - Gerar Sudoku Automaticamente      |" << endl;
      cout <<   "| 2 - Inserir Sudoku Manualmente        |" << endl;
      cout <<   "| 3 - Sair                              |" << endl;
      cout <<   "| Escolha a opcao: ";

      cin >> operacao;
      switch(operacao){
      case 1: {

        int modo;
        cout << "\n| ****  ESCOLHA O MODO  **** |" << endl;
        cout << "| 1. Modo 1 jogador          |" << endl;
        cout << "| 2. Modo competitivo (1x1)  |" << endl;
        cout << "| Escolha a opcao: ";

        cin >> modo;
        if(modo == 1) {

          int dificuldade;
          cout << "\n| * ESCOLHA A DIFICULDADE * |" << endl;
          cout << "| 1. Modo Facil             |" << endl;
          cout << "| 2. Modo Medio             |" << endl;
          cout << "| 3. Modo Dificil           |" << endl;
          cout << "| Escolha a opcao: ";

          cin >> dificuldade;
          cout << "\n";
          gerador(SudokuGerado,SudokuGeradoSolucao, dificuldade);
          printSudoku(SudokuGeradoSolucao);
          jogar(SudokuGerado, SudokuGeradoSolucao, dificuldade);
          resetaSudoku(SudokuGerado);
          resetaSudoku(SudokuGeradoSolucao);

          break;

        } else if (modo == 2) {
          //criaModoMultiplayer();
          break;

        } else {
          cout << "Opcao invalida! Tente novamente!" << endl;;
          break;
        }

      }

       case 2: {

        criarSudokuManualmente(SudokuManual);
        resetaSudoku(SudokuManual);
        break;
       }

       case 3: {

        break;
       }

       default: {
        break;
      }
    }
  }
  return 0;
}
