#include "Solver.hh"

int Solver::search(std::deque<Game>& path, int moveCost, int threshold, const Heuristic& heuristic) {
    const Game& state = *path.rbegin();

    unsigned int h = heuristic.solve(state);

    if (h == 0)
        return 0;

    unsigned int cost = moveCost + h;
    if (cost > threshold)
        return cost;

    unsigned int min = std::numeric_limits<unsigned int>::max();

    for (Move& nextMove : state.validMoves()) {
        Game nextState {state};
        nextState.move(nextMove);

        if (std::find(path.begin(), path.end(), nextState) == path.end()) {
            path.push_back(std::move(nextState));

            unsigned int temp = search(path, moveCost + 1, threshold, heuristic);
            if (temp == 0)
                return 0;
            if (temp < min)
                min = temp;

            path.pop_back();
        }
    }

    return min;
}

void Solver::solve(const Heuristic& heuristic) {
    _startTime = std::chrono::steady_clock::now();
    _solved = false;

    if (!_game.isSolvable()) {
        _result = SolverResult::NOT_SOLVABLE;
        return;
    }

    std::deque<Game> path;
    path.push_back(_game);

    unsigned int threshold = heuristic.solve(_game);

    unsigned int result = -1;
    while (result != 0) {
        result = search(path, 0, threshold, heuristic);

        if (result == std::numeric_limits<unsigned int>::max()) {
            _result = SolverResult::NO_SOLUTION_FOUND;
            return;
        }

        threshold = result;
    }

    _path.reserve(path.size());
    std::move(std::begin(path), std::end(path), std::back_inserter(_path));

    _solved = true;
    _endTime = std::chrono::steady_clock::now();

    _result = SolverResult::OK;
}
