#include<iostream>
#include<cstring>
# define tamanho 4
using namespace std;

int main(){

   while(1){
       cout << "*************SUDOKU**************" << endl;
       cout << "1 - Novo Jogo" << endl;
       cout << "2 - Crie seu proprio jogo" << endl;
       cout << "3 - Ranking geral" << endl;
       cout << "4 - Sair" << endl;
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
             criaModoSingleplayer();
             break

           } else if (modo == 2) {
             criaModoMultiplayer();
             break;

           } else
              cout << "Opcao invalida, tente novamente"
              break;

       }

       case 2:
       {

           insereSudoku();
           break;
       }

       case 3:
       {
           mostraRankingGeral();
           break;
       }

       case 4:
       {

           exit();
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
