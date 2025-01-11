#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct State {
    int playerRow, playerCol;
    vector<pair<int, int>> boxes;
};

bool operator==(const State& a, const State& b) {
    return a.playerRow == b.playerRow &&
           a.playerCol == b.playerCol &&
           a.boxes == b.boxes;
}

struct StateHash {
    size_t operator()(const State& state) const {
        size_t hash = 17;
        hash = hash * 31 + hash<int()>(state.playerRow);
        hash = hash * 31 + hash<int()>(state.playerCol);

        for (const auto& box : state.boxes) {
            hash = hash * 31 + hash<int()>(box.first);
            hash = hash * 31 + hash<int()>(box.second);
        }

        return hash;
    }
};

bool is_valid(int row, int col, const vector<string>& board) {
    return row >= 0 && row < board.size() &&
           col >= 0 && col < board[0].size() &&
           board[row][col] != '#';
}

bool is_solved(const State& state, const vector<string>& board) {
    for (const auto& box : state.boxes) {
        if (board[box.first][box.second] != '.') {
            return false;  // Not all boxes are on targets
        }
    }
    return true;
}

void print_board(const State& state, const vector<string>& board) {
    vector<string> copy = board;

    // Mark player on the board
    copy[state.playerRow][state.playerCol] = 'P';

    // Mark boxes on the board
    for (const auto& box : state.boxes) {
        copy[box.first][box.second] = 'B';
    }

    // Print the modified board
    for (const auto& row : copy) {
        cout <<& row << endl;
    }
}

bool can_move(int row, int col, const State& state, const vector<string>& board) {
    // Check if the target cell is valid
    if (!is_valid(row, col, board)) {
        return false;
    }

    // Check if the target cell is a box
    for (const auto& box : state.boxes) {
        if (box.first == row && box.second == col) {
            // Check if the cell behind the box is empty or a target
            int new_row = row + (row - state.playerRow);
            int new_col = col + (col - state.playerCol);
            return is_valid(new_row, new_col, board) &&
                   (board[new_row][new_col] == '.' || board[new_row][new_col] == ' ');
        }
    }

    return true;
}

State move(int drow, int dcol, const State& state, const vector<string>& board) {
    State new_state = state;

    // Move player
    new_state.playerRow += drow;
    new_state.playerCol += dcol;

    // Move boxes if there is a box in the new position
    for (auto& box : new_state.boxes) {
        if (box.first == new_state.playerRow && box.second == new_state.playerCol) {
            box.first += drow;
            box.second += dcol;
            break;
        }
    }

    return new_state;
}

bool is_visited(const State& state, const unordered_set<State, StateHash>& visited) {
    return visited.find(state) != visited.end();
}

void solve_sokoban(const vector<string>& board, const State& initial_state) {
    queue<State> q;
    unordered_set<State, StateHash> visited;

    q.push(initial_state);
    visited.insert(initial_state);

    while (!q.empty()) {
        State current_state = q.front();
        q.pop();

        if (is_solved(current_state, board)) {
            cout << "Solved!" << endl;
            print_board(current_state, board);
            return;
        }

        const int directions[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

        for (const auto& dir : directions) {
            int drow = dir[0];
            int dcol = dir[1];

            if (can_move(current_state.playerRow + drow, current_state.playerCol + dcol, current_state, board)) {
                State new_state = move(drow, dcol, current_state, board);

                if (!is_visited(new_state, visited)) {
                    q.push(new_state);
                    visited.insert(new_state);
                }
            }
        }
    }

    cout << "No solution found." << endl;
}

int main() {
    vector<string> board = {
        "########",
        "#.B #",
        "#@B #",
        "#.  #",
        "#####"
    };

    State initial_state;
    initial_state.playerRow = 2;
    initial_state.playerCol = 1;
    initial_state.boxes = {{1, 2}, {2, 2}};

    solve_sokoban(board, initial_state);

    return 0;
}
