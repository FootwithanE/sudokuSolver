#include "Puzzle.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   Puzzle sudoku;
   sudoku.setBoard();
   cout << sudoku << "\n";
   sudoku.solve(0, 0);
   cout << sudoku << "\n";
}

