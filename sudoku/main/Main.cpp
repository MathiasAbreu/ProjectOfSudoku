#include<iostream>
#include<cstring>
#include"backtracking.cpp"

# define tamanho 4
using namespace std;

int Sudoku[9][9] = {{0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0}};

int mostrarSudoku() {

  function_backTracking(Sudoku,0,0);

  printSudoku(Sudoku);

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
             cout << "*************ESCOLHA A DIFICULDADE**************" << endl;
             cout << "1. Facil" << endl;
             cout << "2. Medio" << endl;
             cout << "3. Dificil" << endl;
             int dificuldade;
             cin >> dificuldade;
             gerador(Sudoku, dificuldade);
             jogar(Sudoku);

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
