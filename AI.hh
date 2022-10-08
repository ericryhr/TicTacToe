#pragma once

#include "Board.hh"
#include <random>
#include <time.h>
#include <algorithm>
using namespace std;

static int OtherPlayer(int player)
{
    return (player == 1)? 2 : 1;
}

class AI
{
private:
    int jugador;
    int contrincant;

public:
    AI(int player);
    void MakeAIMove(Board taulell, int &fila, int &columna);
    int Search(Board &taulell, int player, int depth);

    //Evalua una posicio del taulell des de la perspectiva del jugador player
    static int Evaluate(Board &taulell, int player)
    {
        int playerEval = (taulell.CheckWinner(player)) ? 100 : 0;
        int enemyEval = (taulell.CheckWinner(OtherPlayer(player))) ? 100 : 0;
        int drawEval = (taulell.CheckDraw()) ? 50 : 0;

        int eval = (playerEval - enemyEval) - drawEval;

        return eval;
    }
    ~AI();
};