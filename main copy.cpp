#include "Quiz1.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  String test = "";

  cout << "please enter a string" << endl;
  cin >> test; // eat whats entered and store it in variable

  Quiz1 q; // stored on the stack

  cout << "number of command line arguments: " << argc << endl;
  cout << "the number of vowels in " << test << " is: " << q.countVowels(test) << endl;
  cout << "argv[0] is : " << argv[0] << endl;

  cout << "Program exited Succesfully" << endl;
  return 0;
}
// program accesses memory through pointers to the memory adress
// can store on heap with << q->countVowels 
