#include <iostream>
#include "AI.hh"
#include "Board.hh"
using namespace std;

void PlayerTurn(Board &taulell, AI &player2, int jugadorActual);

void AITurn(Board &taulell, AI &player2, int jugadorActual);

int main()
{
    Board taulell(3);
    AI player2(2);
    taulell.PrintBoard();
    PlayerTurn(taulell, player2, 1);
}

void PlayerTurn(Board &taulell, AI &player2, int jugadorActual)
{
    int fila, columna;

    cout << "Torn del jugador " << Board::symbols[jugadorActual] << endl;
    cout << "Escull fila (0, 1, 2)" << endl;
    cin >> fila;
    cout << "Escull columna (0, 1, 2)" << endl;
    cin >> columna;
    
    while(!taulell.CheckMove(fila, columna))
    {
        cout << "Error: moviment il·legal" << endl;
        cout << "Escull fila (0, 1, 2)" << endl;
        cin >> fila;
        cout << "Escull columna (0, 1, 2)" << endl;
        cin >> columna;
    }
    taulell.MakeMove(fila, columna, jugadorActual);

    taulell.PrintBoard();
    if(taulell.CheckWinner(jugadorActual)) cout << "GUANYA EL JUGADOR " << Board::symbols[jugadorActual] << endl;
    else if(taulell.CheckDraw()) cout << "EMPATO " << endl;
    else AITurn(taulell, player2, 2);
}

void AITurn(Board &taulell, AI &player2, int jugadorActual)
{
    int fila, columna;
    player2.MakeAIMove(taulell, fila, columna);
    
    taulell.MakeMove(fila, columna, jugadorActual);

    taulell.PrintBoard();
    if(taulell.CheckWinner(jugadorActual)) cout << "GUANYA EL JUGADOR " << Board::symbols[jugadorActual] << endl;
    else if(taulell.CheckDraw()) cout << "EMPATO " << endl;
    else PlayerTurn(taulell, player2, 1);
}