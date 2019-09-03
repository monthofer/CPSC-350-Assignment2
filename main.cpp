#include "Quiz1.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  string test = "ereurfukeknf";

  Quiz q; // stored on the stack

  cout << "number of command line arguments: " << argc << endl;
  cout << "the number of vowels in " << test << " is: " << q.countVowels(test) << endl;
  cout << "argv[0] is : " << argv[0] << endl;
}
