#include "Board.hh"

char Board::symbols[3] = {' ', 'X', 'O'};

Board::Board(int mida)
{
    taulell = Taulell(mida, Fila(mida, 0));
    n = mida;
}

bool Board::CheckMove(int fila, int columna)
{
    if(fila < 0 or fila > n-1) return false;
    if(columna < 0 or columna > n-1) return false;
    return taulell[fila][columna] == 0;
}

void Board::MakeMove(int fila, int columna, int player)
{
    taulell[fila][columna] = player;
}

void Board::UnMakeMove(int fila, int columna)
{
    taulell[fila][columna] = 0;
}

vector<int> Board::GetEmptyTiles()
{
    vector<int> emptyTiles;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(taulell[i][j] == 0) emptyTiles.push_back(i*n + j);
        }
    }
    return emptyTiles;
}

bool Board::CheckWinner(int player)
{
    //Check rows & columns
    for (int i = 0; i < n; i++)
    {
        bool winnerRows = true;
        bool winnerColumns = true;
        for (int j = 0; j < n; j++)
        {
            if(taulell[i][j] != player) winnerRows = false;
            if(taulell[j][i] != player) winnerColumns = false;
        }
        if(winnerRows or winnerColumns) return true;
    }

    //Check diagonals
    bool winnerDiagonal1 = true;
    bool winnerDiagonal2 = true;

    for (int i = 0; i < n; i++)
    {
        if(taulell[i][i] != player) winnerDiagonal1 = false;
        if(taulell[n-i-1][i] != player) winnerDiagonal2 = false;
    }
    return winnerDiagonal1 or winnerDiagonal2;
}

bool Board::CheckDraw()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(taulell[i][j] == 0) return false;
        }
    }
    return true;
}

void Board::PrintBoard()
{
    cout << "-------------" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "|" << " " << symbols[taulell[i][j]] << " ";
        }
        cout << "|" << endl;
        cout << "-------------" << endl;
    }
}

int Board::ReadBoard(int columna, int fila)
{
    return taulell[fila][columna];
}

Board::~Board()
{
}
