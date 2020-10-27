/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 03
 *******************************/

 #ifndef DELIMITERNODE_H_
 #define DELIMITERNODE_H_

 #include <iostream>
 using namespace std;


 class DelimiterNode
 {
 public:
   DelimiterNode();
   DelimiterNode(char newDelimiter, int newLineNumber, int charNumber);
   void SetDelimiter(char newDelimiter);
   void SetLineNumber(int newLineNumber);
   void SetCharNumber(int newCharNumber);
   char GetDelimiter();
   int  GetLineNumber();
   int  GetCharNumber();

   DelimiterNode& operator= (const DelimiterNode &other);
   friend ostream& operator<<(ostream& oFile, const DelimiterNode& node);

 private:
   char delimiter;
   int  lineNumber;
   int  charNumber;
 };


 #endif /* DELIMITERNODE_H_ */
