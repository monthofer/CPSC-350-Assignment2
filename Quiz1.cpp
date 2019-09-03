#include "Quiz1.h"
#include <iostream>

using namespace std;

Quiz1::Quiz1() // constructor
{

}

Quiz1::~Quiz1() //destructor
{
  cout << "Object deleted" << endl; // endl prints out a new line
}

int Quiz1::countVowels(string input)
{
  int count = 0; // local variable because it only needs to live in the scope of this function
  for (int i = 0; i < input.size(); ++i) // for is usually for iterating
  {
    char strInput = toLower(input[i]); // in c++ you can iterate through string As its a list of characters
    if (strInput == 'a')
      count++;
    else if(strInput == 'e')
      count++;
    else if(strInput == 'i')
      count++;
    else if(strInput == 'o')
      count++;
    else if(strInput == 'u')
      count++;
  }
  return count;
}
