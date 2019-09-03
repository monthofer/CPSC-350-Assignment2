#include <iostream>  // preprocessor directive
// goes and pulls stuff into your project
// does exactly what you tell it to do - kinda stupid

using namespace std; // namespace is a collection of things (classes, etc.)
class Quiz1
{
  public: // acessor definiton
    Quiz1(); // constructor
    ~Quiz1(); // destructor
    int countVowels(string input);
}; // terminates class definition
