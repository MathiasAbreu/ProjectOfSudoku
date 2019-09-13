using namespace std;

int verificaLinha(int Matriz[9][9], int numero, int linha, int coluna) {

    for(int indice = 0; indice <= 8; indice++) {

        if(Matriz[linha][indice] == numero && indice != coluna)
            return false;
    }

    return true;
}

int verificaColuna(int Matriz[9][9], int numero, int linha, int coluna) {

    for(int indice = 0; indice <= 8; indice++) {

        if(Matriz[indice][coluna] == numero && indice != linha)
            return false;
    }

    return true;
}

int verificaSetor(int Matriz[9][9], int numero, int linha, int coluna) {

    int setorLinha;
    int setorColuna;

    if(linha <= 2)
        setorLinha = 0;
    else if(linha > 2 && linha <= 5)
        setorLinha = 3;
    else
        setorLinha = 6;

    if(coluna <= 2)
        setorColuna = 0;
    else if(coluna > 2 && coluna <= 5)
        setorColuna = 3;
    else
        setorColuna = 6;

    for(int indiceLinha = (0 + setorLinha); indiceLinha <= (2 + setorLinha); indiceLinha++) {

        for(int indiceColuna = (0 + setorColuna); indiceColuna <= (2 + setorColuna); indiceColuna++) {

            if(Matriz[indiceLinha][indiceColuna] == numero && (indiceLinha != linha && indiceColuna != coluna))
                return false;
        }
    }

    return true;
}

int verificarTudo(int Matriz[9][9], int numero, int linha, int coluna) {
  if (verificaLinha(Matriz, numero, linha, coluna) && verificaColuna(Matriz, numero, linha, coluna) && verificaSetor(Matriz, numero, linha, coluna)) return true;
  else return false;
}

void printSudoku(int Sudoku[9][9]) {
  for(int i = 0; i <= 8; i++) {
    printf("|%d|%d|%d|%d|%d|%d|%d|%d|%d|\n",Sudoku[i][0],Sudoku[i][1],Sudoku[i][2],Sudoku[i][3],Sudoku[i][4],Sudoku[i][5],Sudoku[i][6],Sudoku[i][7],Sudoku[i][8]);
  }
  cout << "\n";
}

void resetaSudoku(int Sudoku[9][9]) {
  for (int i = 0; i <= 8; i++) {
    for (int j = 0; j <= 8; j++) {
      Sudoku[i][j] = 0;
    }
  }
}

int retornarColuna(char valorLinha) {

    switch (valorLinha) {
    case 'A': {
    
        return 0;
        break;
    }
    case 'B': {

        return 1;
        break;
    }
    case 'C': {

        return 2;
        break;
    }
    case 'D': {

        return 3;
        break;
    }
    case 'E': {

        return 4;
        break;
    }
    case 'F': {

        return 5;
        break;
    }
    case 'G': {

        return 6;
        break;
    }
    case 'H': {

        return 7;
        break;
    }
    case 'I': {

        return 8;
        break;
    }
    default:

        return 9;
        break;
    }
}

