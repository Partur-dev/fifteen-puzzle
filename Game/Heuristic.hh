#pragma once

class Game;

class Heuristic {
public:
    virtual unsigned int solve(const Game& game) const = 0;
    virtual ~Heuristic() = default;
};

class ManhattanDistance : public Heuristic {
public:
    unsigned int solve(const Game& game) const;
};
