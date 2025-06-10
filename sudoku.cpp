#include <bits/stdc++.h>
using namespace std;
using Board = vector<vector<int>>;
const int N = 9;
const int MAX_MISTAKES = 10;

// sudoku rules
bool isValid(const Board& b, int r, int c, int num) {
    for (int x = 0; x < N; x++)
        if (b[r][x] == num || b[x][c] == num) 
            return false;
    int br = r - r%3, bc = c - c%3;
    for (int dr = 0; dr < 3; dr++)
        for (int dc = 0; dc < 3; dc++)
            if (b[br+dr][bc+dc] == num) 
                return false;
    return true;
}

// solves the sudoku
bool solve(Board& b) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (b[r][c] == 0) {
                // Create array of numbers 1-9 and shuffle them
                vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
                shuffle(numbers.begin(), numbers.end(), mt19937{static_cast<unsigned>(time(nullptr))});
                // chooses random number each time instead of 1->9 thus creating unique sudoku each time
                for (int num : numbers) {
                    if (isValid(b, r, c, num)) {
                        b[r][c] = num;
                        if (solve(b)) 
                            return true;
                        b[r][c] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void greetPlayer() {
    cout << "\nWelcome to Sudoku!\n"
        << "You have up to " << MAX_MISTAKES 
        << " mistakes before you lose.\n\n";
}

void getPlayerInfo(string& name, int& emptyCells) {
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Choose difficulty (1=Easy, 2=Medium, 3=Hard): ";
    int diff; 
    cin >> diff; 
    cin.ignore();
    string mode;
    switch (diff) {
        case 1: emptyCells = 15;mode = "Easy"; break;
        case 2: emptyCells = 30;mode = "Medium"; break;
        case 3: emptyCells = 50;mode = "Hard"; break;
        default:
            cout << "Invalid! Defaulting to Medium.\n";
            emptyCells = 30;
            mode = "Medium";
    }
    cout << "\nHi " << name << "! You have choosen "
        << mode << " difficulty!\n"
        << "Removing " 
        << emptyCells << " cells. Good luck!\n\n";
}


Board generatePuzzle(const Board& sol, int emptyCells) {
    // 1. Copy the full solution
    Board puzzle = sol;
    // 2. Build a list of all 81 indices
    vector<int> idx(81);
    iota(idx.begin(), idx.end(), 0); // fill the idx from 0->80
    // 3. Shuffle and take the first emptyCells to clear
    shuffle(idx.begin(), idx.end(), mt19937{ static_cast<unsigned>(time(nullptr)) }); //mt19937 for random numbers , better than rand()
    for (int i = 0; i < emptyCells; ++i) {
        int r = idx[i] / N; // which of the 9 rows?
        int c = idx[i] % N; // which of the 9 cols in that row?
        puzzle[r][c] = 0;
    }
    return puzzle;
}

void printBoardWithIndices(const Board& b) {
    // 1) Print column headers
    cout << "  ";
    for (int c = 0; c < N; c++){
        if(c%3==0) cout << "  ";
        cout << c << ' ';
    }
        cout << "\n  --------+-------+------\n";

    // 2) Print each row with its index
    for (int r = 0; r < N; r++) {
        cout << r << " | "; // row index + separator
        for (int c = 0; c < N; c++) {
            // Print '.' for empty (0), or the digit otherwise
            char ch = (b[r][c] == 0 ? '.' : char('0'+b[r][c]));
            cout << ch << ' ';

            // Sub-grid vertical separators
            if (c % 3 == 2 && c != N-1)
                cout << "| ";
        }
        cout << "\n";

        // Sub-grid horizontal separators
        if (r % 3 == 2 && r != N-1)
            cout << "  --------+-------+------\n";
    }
}

// Only allow selecting cells that were empty at the start
void getPlayerMove(int& row, int& col, const Board& puzzle,const Board& initial) {
    while (true) {
        cout << "Select a cell to fill/change (row col): ";
        cin >> row >> col;
        if (row>=0 && row<N && col>=0 && col<N && initial[row][col]==0)
            return;
        cout << "Invalid! cannot change a clue or out-of-bounds.\n";
    }
}

// Now allows 0 (clear) or 1–9 (fill)
int getPlayerDigit() {
    int num;
    while (true) {
        cout << "Enter a number (1-9) or 0 to clear: ";
        cin >> num;
        if (num >= 0 && num <= 9) 
            return num;
        cout << "Must be between 0 and 9.\n";
    }
}

void playGame(Board puzzle, const Board& initial) {
    int mistakes = 0;
    int remaining = 0;
    for (auto& row : initial)
        for (int v : row)
            if (v == 0) 
                remaining++;

    while (mistakes < MAX_MISTAKES && remaining > 0) {
        printBoardWithIndices(puzzle);
        cout << "\nRemaining : " << remaining;
        cout << "\nMistakes left: " 
            << (MAX_MISTAKES - mistakes) 
            << "\n\n";

        int r, c, val;
        getPlayerMove(r, c, puzzle, initial);
        val = getPlayerDigit();

        if (val == 0) {
            // clear the cell if it was previously filled
            if (puzzle[r][c] != 0) {
                puzzle[r][c] = 0;
                remaining++;
            }
        }
        else if (isValid(puzzle, r, c, val)) {
            // if filling a previously empty cell, decrement remaining
            if (puzzle[r][c] == 0) 
                remaining--;
            puzzle[r][c] = val;
        }
        else {
            mistakes++;
            cout << "That move conflicts! Try again!\n\n";
        }
    }

    if (remaining == 0)
        cout << "Congratulations! You filled the board!\n";
    else
        cout << "Out of mistakes! Game over.\n";
}

int main() {
    // 1) Build a full solution
    Board solution(N, vector<int>(N, 0));
    solve(solution);

    // 2) Greet & get player info
    greetPlayer();
    string name;
    int emptyCells;
    getPlayerInfo(name, emptyCells);

    Board puzzle = generatePuzzle(solution, emptyCells);
    Board initialPuzzle = puzzle;  // save clues
    playGame(puzzle, initialPuzzle);
    return 0;
}