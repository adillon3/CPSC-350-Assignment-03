/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 03
 *******************************/

 #include "DelimiterNode.h"
DelimiterNode :: DelimiterNode()
{

}
DelimiterNode :: DelimiterNode(char newDelimiter, int newLineNumber, int newCharNumber)
{
  delimiter  = newDelimiter;
  lineNumber = newLineNumber;
  charNumber = newCharNumber;
}
void DelimiterNode :: SetDelimiter(char newDelimiter)
{
  delimiter = newDelimiter;
}
void  DelimiterNode :: SetLineNumber(int newLineNumber)
{
  lineNumber = newLineNumber;
}
void  DelimiterNode :: SetCharNumber(int newCharNumber)
{
  newCharNumber = newCharNumber;
}
char DelimiterNode :: GetDelimiter()
{
  return delimiter;
}
int DelimiterNode :: GetLineNumber()
{
  return lineNumber;
}
int DelimiterNode :: GetCharNumber()
{
  return charNumber;
}


 DelimiterNode& DelimiterNode :: operator= (const DelimiterNode &other)
 {
   delimiter  = other.delimiter;
   lineNumber = other.lineNumber;
   charNumber = other.charNumber;
 }

ostream& operator<<(ostream& oFile, const DelimiterNode& node)
{
  oFile << "\'" << node.delimiter << "\' on line " << node.lineNumber
        << " at character number " << node.charNumber;
  return oFile;
}
