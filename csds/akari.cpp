#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<vector<int>> grid;
int GRID_SIZE;

void printGrid() {
    cout << "  \n  ";
    for (int i = 0; i < GRID_SIZE; i++) {
        if (i < 10)
            cout << " " << i;
        else
            cout << i;
    }
    cout << endl;
    for (int i = 0; i < GRID_SIZE; i++) {
        if (i < 10)
            cout << i << "  ";
        else
            cout << i << " ";
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 0 || grid[i][j] == 2) {
                cout << ". ";
            } else if (grid[i][j] == 1) {
                cout << "O ";
            } else if (grid[i][j] == -1) {
                cout << "# ";
            } else if (grid[i][j] == -2) {
                cout << "X ";
            }
        }
        cout << endl;
    }
}

void illuminateCells(int row, int col) {
    // Check horizontally
    for (int j = col + 1; j < GRID_SIZE; j++) {
        if (grid[row][j] == 0) {
            grid[row][j] = 2;
        } else if (grid[row][j] == -1) {
            break;
        }
    }
    for (int j = col - 1; j >= 0; j--) {
        if (grid[row][j] == 0) {
            grid[row][j] = 2;
        } else if (grid[row][j] == -1) {
            break;
        }
    }

    // Check vertically
    for (int i = row + 1; i < GRID_SIZE; i++) {
        if (grid[i][col] == 0) {
            grid[i][col] = 2;
        } else if (grid[i][col] == -1) {
            break;
        }
    }
    for (int i = row - 1; i >= 0; i--) {
        if (grid[i][col] == 0) {
            grid[i][col] = 2;
        } else if (grid[i][col] == -1) {
            break;
        }
    }
}

void placeLightBulb(int row, int col) {
    if (grid[row][col] == 2) {
        cout << "Cannot place light bulb here, cell is already illuminated." << endl;
    } else if (grid[row][col] == 1) {
        cout << "Cannot place light bulb here, cell already has a light bulb." << endl;
    } else if (grid[row][col] == -1) {
        cout << "Cannot place light bulb here, because it is a black cell." << endl;
    } else {
        grid[row][col] = 1;
        illuminateCells(row, col); // Illuminate the cells around the placed light bulb
    }
}

void generateBlackCells() {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < GRID_SIZE; i++) {
        int blackCellCount = rand() % (GRID_SIZE / 2); // Randomly generate up to half of the grid size black cells
        for (int j = 0; j < blackCellCount; j++) {
            int randomRow = rand() % GRID_SIZE;
            int randomCol = rand() % GRID_SIZE;
            if (grid[randomRow][randomCol] == 0) {
                grid[randomRow][randomCol] = -1; // Set the cell as a black cell
            }
        }
    }
}

bool checkWinCondition() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void setGridSize(int difficulty) {
    if (difficulty == 1) {
        GRID_SIZE = 5;
    } else if (difficulty == 2) {
        GRID_SIZE = 8;
    } else if (difficulty == 3) {
        GRID_SIZE = 12;
    } else {
        cout << "Invalid difficulty level, setting to default (Medium)." << endl;
        GRID_SIZE = 8;
    }
    grid.resize(GRID_SIZE, vector<int>(GRID_SIZE, 0));
}

int main() {
    string input;
    int row, col;
    int difficulty;

    cout << "Select difficulty level:" << endl;
    cout << "1. Easy (5x5)" << endl;
    cout << "2. Medium (8x8)" << endl;
    cout << "3. Hard (12x12)" << endl;
    cout << "Enter your choice: ";
    cin >> difficulty;

    setGridSize(difficulty);
    cin.ignore(); // To ignore the newline character left in the input buffer

    generateBlackCells(); // Generate black cells

    while (true) {
        // Clear the console (works on many terminals)
        cout << "\033[2J\033[1;1H";
        cout << "Welcome to Akari!" << endl;
        cout << "Rules: Place light bulbs to illuminate all cells. Cells with numbers indicate how many adjacent light bulbs are allowed." << endl;
        printGrid();
        cout << "Enter row and column to place a light bulb (e.g., '2 3') or 'q' to quit: ";
        getline(cin, input);

        if (input == "q") {
            break;
        } else {
            istringstream iss(input);
            if (iss >> row >> col) {
                if (row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE) {
                    placeLightBulb(row, col);

                    if (checkWinCondition()) {
                        printGrid();
                        cout << "Congratulations! You win!" << endl;
                        break;
                    }
                } else {
                    cout << "Invalid input. Row and column must be within the grid size." << endl;
                }
            } else {
                cout << "Invalid input. Please enter row and column as two integers." << endl;
            }
        }
    }

    return 0;
}
