#include "Puzzle.h"

Puzzle::Puzzle()
{
}
bool Puzzle::setBoard()
{
   int count = 0;
   while (count < 81) {
      for (int i = 0; i < GAME_SIZE; i++)
      {
         for (int j = 0; j < GAME_SIZE; j++)
         {
            gameBoard[i][j].setValue(0);
            count++;
         }
      }
   }
   return true;
}
Puzzle::Square::Square() : value(NULL), fixed(false)
{
}
Puzzle::Square::Square(int num) : value(num), fixed(false)
{
}
Puzzle::Square::Square(int num, bool fix) : value(num), fixed(fix)
{
}
void Puzzle::Square::setValue(int num)
{
   value = num;
}
int Puzzle::Square::getValue() const
{
   //if (value == NULL)
     // return -1;
   return value;
} // Needs work
bool Puzzle::Square::isFixed() const
{
   return fixed;
}
void Puzzle::Square::setFixed()
{
   fixed = true;
}
std::ostream& operator<<(std::ostream& os, const Puzzle& obj)
{
   // Count printing in blocks of 3
   int count = 0;
   int vertCount = 0;
   for (int i = 0; i < obj.GAME_SIZE; i++)
   {
      for (int j = 0; j < obj.GAME_SIZE; j++)
      {
         // Sub block of 3 columns found
         if (count == 3)
         {
            os << "|";
            // Start counting again
            count = 0;
         }
         os << obj.gameBoard[i][j].getValue() << " ";
         count++;
      }
      // Create separation for every 3 rows
      os << "\n";
      vertCount++;
      if (vertCount == 3 && i < 7)
      {
         os << "------+------+------\n";
         vertCount = 0;
      }
      count = 0;
   }
   return os;
}
std::istream& operator>>(std::istream& is, Puzzle& obj)
{
   
   return is;
} // Still needs work
bool Puzzle::checkRowCol(int row, int col, int num) const
{
   for (int i = 0; i < GAME_SIZE; i++)
   {
      // Checks row
      if (gameBoard[row][i].getValue() == num)
         return false;
      // Checks column
      if (gameBoard[i][col].getValue() == num)
         return false;
   }
   return true;
}
bool Puzzle::checkSubSquare(int row, int col, int num) const
{
   // Finds 'upper left' corner of sub square
   row = row / 3 * 3;
   col = col / 3 * 3;
   // checks 3x3 sub square
   for (int i = row; i < row + 3; i++)
   {
      for (int j = col; j < col + 3; j++)
      {
         if (gameBoard[i][j].getValue() == num)
            return false;
      }
   }
   return true;
}
bool Puzzle::set(int x, int y, int num)
{
   // check against game rules
   if (!checkRowCol(x, y, num) || !checkSubSquare(x, y, num) 
         || gameBoard[x][y].isFixed())
      return false;
   gameBoard[x][y].setValue(num);
   return true;
}
int Puzzle::size() const
{
   int count = 0;
   for (int i = 0; i < GAME_SIZE; i++)
   {
      for (int j = 0; j < GAME_SIZE; j++)
      {
         if (!gameBoard[i][j].isFixed())
            count++;
      }
   }
   return count;
}
int Puzzle::numEmpty() const
{
   int count = 0;
   for (int i = 0; i < GAME_SIZE; i++)
   {
      for (int j = 0; j < GAME_SIZE; j++)
      {
         if (gameBoard[i][j].getValue() == -1)
            count++;
      }
   }
   return count;
}
bool Puzzle::findNextVariable(int& row, int& col)
{
   for (row = 0; row < GAME_SIZE; row++)
      for (col = 0; col < GAME_SIZE; col++)
         if (!(gameBoard[row][col].isFixed()) && gameBoard[row][col].getValue() == 0)
            return true;
   return false;
}
bool Puzzle::solve(int row, int col)
{  
   if (!(findNextVariable(row, col)))
      return true;

   for (int i = 1; i <= 9; i++)
   {
      if (set(row, col, i))
      {
         if (solve(row, col))
            return true;
         gameBoard[row][col].setValue(0);
      }
   }
   return false;
}
