#include "Puzzle.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Takes in a puzzle as a stream of integers
// Solves and prints puzzle if solveable
int main()
{
   Puzzle sudoku;
   cin >> sudoku;
   cout << sudoku << "\n";
   if (sudoku.solve(0, 0))
      cout << sudoku;
   else
      cout << "Not solved";
}

