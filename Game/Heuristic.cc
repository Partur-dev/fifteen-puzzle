#include "Heuristic.hh"
#include "Game.hh"
#include <cmath>

unsigned int ManhattanDistance::solve(const Game& game) const {
    unsigned int distance {0};

    int dimension = game.dimension();

    for (int n = 0, len = game.size(); n < len; n++) {
        if (game.get(n) == 0)
            continue;

        int realValue {game.get(n) - 1};
        if (realValue == n)
            continue;

        distance += std::abs((realValue / dimension) - (n / dimension))
                    + std::abs((realValue % dimension) - (n % dimension));
    }

    return distance;
}
