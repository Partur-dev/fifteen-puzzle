#pragma once

#include <vector>

enum class Move { UP, DOWN, LEFT, RIGHT };

class Game {
public:
    using Board = std::vector<int>;

    Game();
    Game(const Game& p);
    Game(Game&& p);

    bool operator==(const Game& p) const;
    Game& operator=(const Game& p);
    Game& operator=(Game&& p);

    bool move(Move move);
    bool move(int);

    const int& get(int index) const;
    const int& get(int row, int col) const;
    int& get(int index);
    int& get(int row, int col);
    void set(int index, int value);
    void set(int row, int col, int value);

    int inversionCount() const;

    bool isSolvable() const;
    bool isSolved() const;

    std::vector<Move> validMoves() const;
    void shuffle();
    void reset();

    int dimension() const;
    int size() const;

    Board& board();

private:
    int _blankRow {};
    int _blankCol {};
    int _dimension {};
    Board _board {};
};
