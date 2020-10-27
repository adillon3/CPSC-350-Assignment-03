/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 03
 *******************************/

#include "DelimiterChecker.h"

DelimiterChecker :: DelimiterChecker()
{

}
DelimiterChecker :: ~DelimiterChecker()
{

}

//Retruns string with line number and error message
//If file is good, returns message stating the file is good


bool DelimiterChecker :: CheckFile(string fileName)
{
  string tempString;
  int    tempStringlength;
  int    lineNum = 1;
  DelimiterNode tempDelimNode;
  char   tempDelimChar;
  bool   isPerfect = true;

  ifstream inFile;
	inFile.open(fileName.c_str());

  cout << "Checking delimters...\n\n";

  while(inFile)
  {
    getline(inFile, tempString);
    tempStringlength = tempString.length();

    for(int i = 0; i < tempStringlength; ++i)
    {
      if(tempString[i] == '{' || tempString[i] == '[' || tempString[i] == '(')
      {
        DelimiterNode pushNode(tempString[i], lineNum, i);
        delimStack.Push(pushNode);
      }
      else if(tempString[i] == '}' || tempString[i] == ']' || tempString[i] == ')')
      {
        //checking that delimiters match
        if(!delimStack.IsEmpty())
        {
          tempDelimNode = delimStack.Peek();
          tempDelimChar = tempDelimNode.GetDelimiter();

          //delimiters DO NOT match
          if(tempDelimChar == '{' && tempString[i] != '}' ||
             tempDelimChar == '[' && tempString[i] != ']' ||
             tempDelimChar == '(' && tempString[i] != ')')
           {
             isPerfect = false;

             cout << "-Missing opening \'" << tempDelimChar << "\' ";

             if(tempDelimNode.GetDelimiter() == ')')
             {
               cout << "\'(\'";
             }
             else if(tempDelimNode.GetDelimiter() == ']')
             {
                 cout << "\'[\'";
             }
             else if(tempDelimNode.GetDelimiter() == '}')
             {
                 cout << "\'{\'";
             }
             cout << "for \'" << tempString[i] << "\' on line " << lineNum
                  << " at character number " << (i + 1) << endl;
           }
           //delimiters do match
           else
           {
             delimStack.Pop();
           }//END else of if(tempDelimChar == '{' && tempString[i] != '}' ...

         }//END if(!delimStack.IsEmpty())
         else
         {
           isPerfect = false;

            cout << "-Missing opening \'" << tempDelimChar << "\' ";

            if(tempDelimNode.GetDelimiter() == ')')
            {
              cout << "\'(\'";
            }
            else if(tempDelimNode.GetDelimiter() == ']')
            {
                cout << "\'[\'";
            }
            else if(tempDelimNode.GetDelimiter() == '}')
            {
                cout << "\'{\'";
            }
            cout << "for \'" << tempString[i] << "\' on line " << lineNum
                 << " at character number " << (i + 1) << endl;
         }//END else of if(!delimStack.IsEmpty())
      }//END else if(tempString[i] == '}' || tempString[i] == ']' || tempString[i] == ')')
    }//END for(int i = 0; i < tempStringlength; ++i)

    ++lineNum;
  }//END while(inFile)

  inFile.close();

  //unended delimters
  if(!delimStack.IsEmpty())
  {
    isPerfect = false;

    cout << endl;

    while(!delimStack.IsEmpty())
    {
      //getting data from stack
      tempDelimNode = delimStack.Pop();

      cout << "-Missing closing ";

      if(tempDelimNode.GetDelimiter() == '(')
      {
        cout << "\')\'";
      }
      else if(tempDelimNode.GetDelimiter() == '[')
      {
          cout << "\']\'";
      }
      else if(tempDelimNode.GetDelimiter() == '{')
      {
          cout << "\'}\'";
      }

      cout << " for " << tempDelimNode << endl;
    }
  }

  if(isPerfect)
  {
    cout << "No missing delimiters in \'" << fileName << "\'\n";
  }

  return isPerfect;
}

void DelimiterChecker :: PrintStack()
{
  delimStack.PrintStackBottomToTop();
}
