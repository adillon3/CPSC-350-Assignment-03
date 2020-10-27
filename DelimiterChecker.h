/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 03
 *******************************/

 #ifndef DELIMITERCHECKER_H_
 #define DELIMITERCHECKER_H_

 #include <iostream>
 using namespace std;

 #include <string>
 #include <fstream>


 #include "GenStack.h"
 #include "DelimiterChecker.h"
 #include "DelimiterNode.h"


class DelimiterChecker
{
public:
  DelimiterChecker();
  ~DelimiterChecker();

  bool CheckFile(string fileName);
  void PrintStack();

private:
  void ReverseStack();

  GenStack<DelimiterNode> delimStack;
};

 #endif /* DELIMITERCHECKER_H_  */
