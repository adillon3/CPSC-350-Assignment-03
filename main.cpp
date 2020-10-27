/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 03
 *******************************/

#include "Assign3.h"
#include "GenStack.h"
#include "DelimiterChecker.h"

int main(int argc, char* argv[])
{
  const string YES_NO_MESSAGE = "Would you like to check another file?";


  DelimiterChecker myChecker;
  string fileName;
  bool continueBool;

  //Getting input if commandline is blank
  if(argc < 2)
  {
    fileName = GetFileName();
  }
  else
  {
    fileName = argv[1];
  }

  do
  {
    CheckFileNameValid(fileName);

    continueBool = myChecker.CheckFile(fileName);

    if(continueBool == true)
    {
      //asking for another file
      cout << endl << endl;
      char continueChar = GetYesOrNoChar(YES_NO_MESSAGE);
      if(toupper(continueChar) == 'N')
      {
        continueBool = false;
      }
      else
      {
        fileName = GetFileName();
      }
    }

  }while(continueBool);

  cout << "\nThank you for using the Delimiter Checker.\n\n";

  return 0;
}
