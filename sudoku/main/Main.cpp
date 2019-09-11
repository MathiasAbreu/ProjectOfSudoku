#include<iostream>
#include<cstring>
#include"backtracking.cpp"
#include"gerador.cpp"

# define tamanho 4
using namespace std;

int Sudoku[9][9] = {{0,0,5,3,6,0,0,0,0},
                    {0,0,0,7,0,0,4,0,2},
                    {3,2,9,0,0,0,0,0,0},
                    {9,8,7,0,0,0,0,0,1},
                    {5,0,0,2,0,9,0,7,3},
                    {0,0,0,0,0,1,0,6,5},
                    {0,0,0,6,5,0,0,2,0},
                    {6,3,2,0,0,0,0,8,9},
                    {0,0,0,0,0,0,7,1,6}};

int mostrarSudoku() {

  function_backTracking(Sudoku,0,0);

  for(int i = 0; i <= 8; i++) {
    printf("|%d|%d|%d|%d|%d|%d|%d|%d|%d|\n",Sudoku[i][0],Sudoku[i][1],Sudoku[i][2],Sudoku[i][3],Sudoku[i][4],Sudoku[i][5],Sudoku[i][6],Sudoku[i][7],Sudoku[i][8]);
  }

  return 0;
}

int main(){

   while(true){
       cout << "\n*************SUDOKU**************" << endl;
       cout << "1 - Novo Jogo" << endl;
       cout << "2 - Crie seu proprio jogo" << endl;
       cout << "3 - Ranking geral" << endl;
       cout << "4 - Mostrar Resultado" << endl;
       cout << "5 - Sair" << endl;
       cout << "Escolha a opcao: " << endl;
       int op;
       cin >> op;
       switch(op){
       case 1:
       {
          cout << "*************ESCOLHA O MODO**************" << endl;
          cout << "1. Modo 1 jogador" << endl;
          cout << "2. Modo competitivo (1x1)" << endl;
           int modo;
           cin >> modo;
           if(modo == 1) {
             gerador(1);
             break;

           } else if (modo == 2) {
             //criaModoMultiplayer();
             break;

           } else {
              cout << "Opcao invalida, tente novamente";
              break;
           }

       }

       case 2:
       {

           //insereSudoku();
           break;
       }

       case 3:
       {
           //mostraRankingGeral();
           break;
       }

       case 4: {

         mostrarSudoku();
         break;
       }

       case 5: {

         break;
       }

       default:
           {
             break;
           }
       }
   }
   return 0;
}
