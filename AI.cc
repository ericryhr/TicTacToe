#include "AI.hh"

AI::AI(int player)
{
    jugador = player;
    contrincant = (jugador == 1)? 2 : 1;
    srand(time(NULL));
}

void AI::MakeAIMove(Board taulell, int &fila, int &columna)
{
    vector<int> emptyMoves = taulell.GetEmptyTiles();
    for (int &move : emptyMoves)
    {
        fila = move/3;
        columna = move%3;
        taulell.MakeMove(move/3, move%3, jugador);
        int eval = -Search(taulell, contrincant, 4);
        if(eval > 0) return;
        taulell.UnMakeMove(move/3, move%3);
    }
}

int AI::Search(Board &taulell, int player, int depth)
{
    if(depth == 0) return Evaluate(taulell, player);

    vector<int> emptyMoves = taulell.GetEmptyTiles();
    if(emptyMoves.size() == 0) return Evaluate(taulell, player);

    int bestEvaluation = -200;
    for (int &move : emptyMoves)
    {
        taulell.MakeMove(move/3, move%3, jugador);
        int eval = -Search(taulell, OtherPlayer(player), depth-1);
        bestEvaluation = max(eval, bestEvaluation);
        taulell.UnMakeMove(move/3, move%3);
    }
    return bestEvaluation;
}

AI::~AI()
{
}
