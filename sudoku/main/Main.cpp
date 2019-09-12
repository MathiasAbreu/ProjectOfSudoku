#include<iostream>
#include<cstring>
#include"backtracking.cpp"

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

int main(){

   while(true){

      int operacao;
      cout << "\n| ****  SUDOKU  **** |" << endl;
      cout <<   "| 1 - Novo Jogo      |" << endl;
      cout <<   "| 2 - Inserir Jogo   |" << endl;
      cout <<   "| 3 - Ranking geral  |" << endl;
      cout <<   "| 4 - Resolver Jogo  |" << endl;
      cout <<   "| 5 - Sair           |" << endl;
      cout <<   "| Escolha a opcao: " << endl;

      cin >> operacao;
      switch(operacao){
      case 1: {

        int modo;
        cout << "| ****  ESCOLHA O MODO  **** |" << endl;
        cout << "| 1. Modo 1 jogador          |" << endl;
        cout << "| 2. Modo competitivo (1x1)  |" << endl;
        cout << "| Escolha a opcao: ";

        cin >> modo;
        if(modo == 1) {

          int dificuldade;
          cout << "| * ESCOLHA A DIFICULDADE * |" << endl;
          cout << "| 1. Modo Facil             |" << endl;
          cout << "| 2. Modo Medio             |" << endl;
          cout << "| 3. Modo Dificil           |" << endl;
          cout << "| Escolha a opcao: ";

          cin >> dificuldade;
          gerador(SudokuGerado, dificuldade);
          jogar(SudokuGerado);

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
        break;
       }

       case 3: {
           
        //mostraRankingGeral();
        break;
       }

       case 4: {
 
        break;
       }

       case 5: {

        break;
       }

       default: {
        break;
      }
    }
  }
  return 0;
}
