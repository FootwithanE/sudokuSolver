#include "Puzzle.h"

Puzzle::Square() : value(0), fixed(false)
{
}
Square::Square(int num) : value(num), fixed(false)
{
}
void Square::setValue(int num)
{
   value = value;
}
int Square::getValue()
{
   return value;
}
bool Square::isFixed()
{
   return fixed;
}