#pragma once

#include <vector>
#include <iostream>
using namespace std;

typedef vector<int> Fila;
typedef vector<Fila> Taulell;

class Board
{
private:
    Taulell taulell;
    int n;

public:
    static char symbols[3];

    Board(int mida);
    bool CheckMove(int fila, int columna);
    void MakeMove(int fila, int columna, int player);
    void UnMakeMove(int fila, int columna);
    vector<int> GetEmptyTiles();
    bool CheckWinner(int player);
    bool CheckDraw();
    void PrintBoard();
    int ReadBoard(int fila, int columna);
    ~Board();
};