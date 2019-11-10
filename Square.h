#pragma once
class Square
{
private:
   int value;
   bool fixed;
public:
   Square();
   Square(int num);
   void setValue(int num);
   int getValue();
   bool isFixed();
};

