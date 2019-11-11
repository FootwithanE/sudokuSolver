#pragma once
#include <iostream>
#include <vector>

class Puzzle
{
   class Square
   {
   private:
      int value;
      bool fixed;
   public:
      Square();
      Square(int num);
      Square(int num, bool fix);
      void setValue(int num);
      int getValue() const;
      void setFixed();
      bool isFixed() const;
   };
public:
   static const int GAME_SIZE = 9;
   Puzzle();
   bool set(int x, int y, int num);
   friend std::ostream& operator<<(std::ostream& os, const Puzzle& obj);
   friend std::istream& operator>>(std::istream& is, Puzzle& obj);
   int size() const;
   int numEmpty() const;
   bool solve(int row, int col);
private:
   Square gameBoard[GAME_SIZE][GAME_SIZE];
   bool checkRowCol(int row, int col, int num) const;
   bool checkSubSquare(int row, int col, int num) const;
   bool findNextVariable(int& row, int& col);
   bool setBoard(const std::vector<int>& board);
};

