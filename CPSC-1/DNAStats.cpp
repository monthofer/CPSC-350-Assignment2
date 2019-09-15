/*
Name: Sarah Monthofer
Student ID: 2317035
Email: monthofer@chapman.edu
Class: CPSC 350
Assignemnt: Assignment 1

Description: read DNA strands from another file and preform statistics calculations
    then use these calcualtions to produce random strings following the same distibutions
    and print these strings to another file

*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main (int argc, char **argv) // char ** is an array of strings, argc is argument count,
{
  // make one large while loop to see if the user would like to run again
  bool notDone = true;
  while (notDone) {
    // ERROR CHECKING WITH FILE INPUTED
    //make sure the user sent in a file through command line argument
    if (argc != 2) {
      cout << "INVALID AMOUNT OF ARGUMENTS" << endl;
      return 0;
    }

    //  https://stackoverflow.com/questions/2390912/checking-for-an-empty-file-in-c
    std::ifstream file(argv[1]);
    // check if the file has issues being opened
    if (!file) {
      cout << "THE FILE YOU INPUTED CANNOT BE OPENED" << endl;
      return 0;
    }

    // https://stackoverflow.com/questions/26228424/how-to-detect-an-empty-file-in-c/26228684
    // check if the user inputed and emty file
    if (file.peek() == std::ifstream::traits_type::eof()) {
      cout << "THE FILE YOU INPUTED IS EMPTY" << endl;
      return 0;
    }

    // open file if the file exists and is not empty
    else {
      cout << "File succesfully opened!" << endl;
    }

    // create file and print results to file
    // https://stackoverflow.com/questions/478075/creating-files-in-c
    std::ofstream outfile("monthofer.txt");
    outfile << "Sarah Monthofer" << std::endl;
    outfile << "monthofer@chapman.edu" << std::endl;
    outfile << "2317035" << std::endl;
    outfile << "September 11th, 2019" << std::endl;
    outfile << std::endl;

    // calcualte sum and mean for each DNA String
    std::string line;
    // open file sent through the command line
    std::ifstream myFile(argv[1]);
    // declare variables
    float sum = 0.0, mean = 0.0;
    int numberOfLines = 0;
    int lineLength = 0;
    // itterates through each line of file as a string
    while (std::getline(myFile, line)) {
      ++numberOfLines;
      // itterate through each character of line/string - i corresponds to each character
      for (int i = 0; i < line.length(); i++) {
        lineLength = line.length();
      }
      sum += lineLength; // save the linelegth to the sum after every line
    }
    mean = (double)(sum/numberOfLines);
    numberOfLines = 0;

    // calculate the variance, and standard deviation for each DNA String
    // declare necessary variables
    double variance = 0.0;
    double standardDeviation = 0.0;
    double lineLengthMinusMean = 0.0;
    int nucleotideCount = 0;
    myFile.clear(); // reset file beggening pointer
    myFile.seekg(0, std::ios::beg); // start from beggening of file
    // itterates through each line of file as a string
    while (std::getline(myFile, line)) {
      ++numberOfLines;
      // itterate through each character of line/string - i corresponds to each character
      for (int i = 0; i < line.size(); i++) {
        nucleotideCount++;
        lineLength = line.size();
      }
      variance += pow(nucleotideCount - mean, 2);
    }

    variance = variance / sum;
    standardDeviation = pow(variance, 0.5); // calcualte the sqaure root of variance to find standard deviation
    numberOfLines = 0;

    // print statisitcs results to file monthofer.txt
    cout << "Printing results to file monthofer.txt" << endl;
    outfile << "Sum: " << sum << std::endl;
    outfile << "Mean: "<< mean << std::endl;
    outfile << "Variance: " << variance << std::endl;
    outfile << "Standard Deviation: " << standardDeviation << std::endl;
    outfile << std::endl;

    // declare all variables to calcualte the realative frequency of each line
    // and the relative frequencies of the overall file
    int aLineFreq = 0;
    int cLineFreq = 0;
    int gLineFreq = 0;
    int tLineFreq = 0;
    int aFileFreq = 0;
    int cFileFreq = 0;
    int gFileFreq = 0;
    int tFileFreq = 0;
    double aRelFreq = 0.0;
    double cRelFreq = 0.0;
    double gRelFreq = 0.0;
    double tRelFreq = 0.0;
    // double nucleotideCount = 0.0;

    // open file sent through command line
    std::ifstream myfile(argv[1]);
    myFile.clear();
    myFile.seekg(0, std::ios::beg);
    // itterates through each line of file as a string
    while (std::getline(myfile, line)) {
      numberOfLines++;
      // https://stackoverflow.com/questions/9438209/for-every-character-in-string
      // itterate through each character of line/string - i corresponds to each character
      for (int i = 0; i < line.length(); i++) {
        // convert each index of i in string to uppercase
        nucleotideCount++;
        using std::toupper;
        char curI = toupper(line.at(i));
        // check which nucleotide is at the specific index of the string
        if (curI == 'A') {
          // sum the frequency of each nucleotide for the current line/string
          aLineFreq += 1;
        }
        if (curI == 'C') {
          cLineFreq += 1;
        }
        if (curI == 'G') {
          gLineFreq += 1;
        }
        if (curI == 'T') {
          tLineFreq += 1;
        }
      }

      // calcualtes the relative frequency of each nucleotide for the give line
      double aLineRelFreq = (((double) aLineFreq / (double)line.size()));
      double cLineRelFreq = (((double) cLineFreq / (double)line.size()));
      double gLineRelFreq = (((double) gLineFreq / (double)line.size()));
      double tLineRelFreq = (((double) tLineFreq / (double)line.size()));

      // print relative frequency to output file monthofer.txt
      outfile << "Relative Frequency of Line " << numberOfLines << endl;
      outfile << "A's Line " << numberOfLines << " Relative Frequency: " << (aLineRelFreq * 100) << "% "<< endl;
      outfile << "C's Line " << numberOfLines << " Relative Frequency: " << (cLineRelFreq * 100) << "%" << endl;
      outfile << "G's Line " << numberOfLines << " Relative Frequency: " << (gLineRelFreq * 100) << "%" << endl;
      outfile << "T's Line " << numberOfLines << " Relative Frequency: " << (aLineRelFreq * 100) << "%" << endl;
      outfile << endl;

      // sum the frequency of each line into an overall file frequency of each nucleotide
      aFileFreq += aLineFreq;
      cFileFreq += cLineFreq;
      gFileFreq += gLineFreq;
      tFileFreq += tLineFreq;

      // reset all line frequencies so that calcualtions aren't messed up
      aLineFreq = 0;
      cLineFreq = 0;
      tLineFreq = 0;
      gLineFreq = 0;

    }
    numberOfLines = 0;

    // calculates the relative frequency of each nucleotide over the entire file
    aRelFreq = ((double) aFileFreq / (double) nucleotideCount) * 100;
    cRelFreq = ((double) cFileFreq / (double) nucleotideCount) * 100;
    gRelFreq = ((double) gFileFreq / (double) nucleotideCount) * 100;
    tRelFreq = ((double) tFileFreq / (double) nucleotideCount) * 100;

    // print the relative frequency of each nucloetide over the entire file to outfile monthofer1.txt
    outfile << endl;
    outfile << "RELATIVE FREQUENCY OF EACH NUCLEOTIDE IN FILE: " << endl;
    outfile << "A's Relative Frequency " << aRelFreq << "% " << std::endl;
    outfile << "C's Relative Frequency " << cRelFreq << "% " << std::endl;
    outfile << "G's Relative Frequency " << gRelFreq << "% " << std::endl;
    outfile << "T's Relative Frequency " << tRelFreq << "% " << std::endl;
    outfile << endl;

    // calcualte nucleotide bigrams
    // creates strings of each nucleotide bigram we are searching for
    string AA = "AA";
    string AC = "AC";
    string AG = "AG";
    string AT = "AT";
    string CA = "CA";
    string CC = "CC";
    string CG = "CG";
    string CT = "CT";
    string TA = "TA";
    string TC = "TC";
    string TG = "TG";
    string TT = "TT";
    string GA = "GA";
    string GC = "GC";
    string GG = "GG";
    string GT = "GT";

    // create a count for each nucleotide bigram occurance
    int AAcount = 0;
    int ACcount = 0;
    int AGcount = 0;
    int ATcount = 0;
    int CAcount = 0;
    int CCcount = 0;
    int CGcount = 0;
    int CTcount = 0;
    int TAcount = 0;
    int TCcount = 0;
    int TGcount = 0;
    int TTcount = 0;
    int GAcount = 0;
    int GCcount = 0;
    int GGcount = 0;
    int GTcount = 0;

    numberOfLines = 0;
    nucleotideCount = 0;
    myFile.clear(); // reset beggening of file pointer
    myFile.seekg(0, std::ios::beg);
    while (std::getline(myFile, line)) {
      ++numberOfLines;
      for (int i = 0; i < line.length(); i++) {
        using std::toupper;
        char curI = toupper(line.at(i));
        string paircheck = "";
        paircheck = curI;
        char nextChar = toupper(line[i + 1]);
        paircheck += nextChar;
        if (paircheck == AA)
          AAcount++;
        if (paircheck == AC)
          ACcount++;
        if (paircheck == AG)
          AGcount++;
        if (paircheck == AT)
          ATcount++;
        if (paircheck == CA)
          CAcount++;
        if (paircheck == CC)
          CCcount++;
        if (paircheck == CG)
          CGcount++;
        if (paircheck == CT)
          CTcount++;
        if (paircheck == TA)
          TAcount++;
        if (paircheck == TC)
          TCcount++;
        if (paircheck == TG)
          TGcount++;
        if (paircheck == TT)
          TTcount++;
        if (paircheck == GA)
          GAcount++;
        if (paircheck == GC)
          GCcount++;
        if (paircheck == GG)
          GGcount++;
        if (paircheck == GT)
          GTcount++;
        paircheck = "";
      }
    }

    // print the occurance of each nucleotide bigram to outfile monthofer.txt
    outfile << endl;
    outfile << "Occurrence of each Nucleotide Bigram:" << endl;
    outfile << "AA: " << ((double)AAcount / (double)sum) * 100 << "% "<< endl;
    outfile << "AC: " << ((double)ACcount / (double)sum) * 100 << "% "<< endl;
    outfile << "AT: " << ((double)ATcount / (double)sum) * 100 << "% "<< endl;
    outfile << "AG: " << ((double)AGcount / (double)sum) * 100 << "% "<< endl;
    outfile << "CA: " << ((double)CAcount / (double)sum) * 100 << "% "<< endl;
    outfile << "CT: " << ((double)CTcount / (double)sum) * 100 << "% "<< endl;
    outfile << "CG: " << ((double)CGcount / (double)sum) * 100 << "% "<< endl;
    outfile << "CC: " << ((double)CCcount / (double)sum) * 100 << "% "<< endl;
    outfile << "TT: " << ((double)TTcount / (double)sum) * 100 << "% "<< endl;
    outfile << "TA: " << ((double)TAcount / (double)sum) * 100 << "% "<< endl;
    outfile << "TC: " << ((double)TCcount / (double)sum) * 100 << "% "<< endl;
    outfile << "TG: " << ((double)TGcount / (double)sum) * 100 << "% "<< endl;
    outfile << "GG: " << ((double)GGcount / (double)sum) * 100 << "% "<< endl;
    outfile << "GA: " << ((double)GAcount / (double)sum) * 100 << "% "<< endl;
    outfile << "GC: " << ((double)GCcount / (double)sum) * 100 << "% "<< endl;
    outfile << "GT: " << ((double)GTcount / (double)sum) * 100 << "% "<< endl;
    outfile << endl;


    // Produce 1000 strings following Gaussian Distribution to outfile monthofer1.txt
    // https://rosettacode.org/wiki/Statistics/Normal_distribution
    outfile << "1000 Randomly Generated Gaussian Distribution Strings: " << endl;
    // https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
    // produce 1000 random nuclotide strings
    int randMax = 1;
    int randMin = 0;
     // not sure if this works because i never defined a constant RAND_MAX, but it was the only way strings were generated
    double randVarA = ((double) rand() / (RAND_MAX));
  	double randVarB = ((double) rand() / (RAND_MAX));
    // http://www.cplusplus.com/forum/beginner/73642/

  	double varC = (sqrt(-2 * log(randVarA))) * (cos(2 * (M_PI) * randVarB));
  	double varD = (standardDeviation * varC) + mean;

  	//For loop to iterate 1000 times
  	for(int i = 0; i < 1000; ++i) {
  		//For loop to iterate the size of double D
  		for(int j = 0; j < varD; ++j) {
  			double range = rand() % 100;
  			if(range <= aRelFreq) {
  				outfile << "A";
  			}
  			else if(range <= (cRelFreq + aRelFreq)) {
  				outfile << "C";
  			}
  			else if(range <= (tRelFreq + cRelFreq + aRelFreq)) {
  				outfile << "T";
  			}
  			else if(range <= 100) {
  				outfile << "G";
  			}
  		}
    }

    // check to see if the user has another file they would like you to go through
    string userChoice;
    cout << "Would you like to process another list of nucloetides? (y/n)" << endl;
    cin >> userChoice;
    if ((userChoice == "n") || (userChoice == "N") || (userChoice == "no")) {
      outfile.close();
      return 0;
    } else {
      cout << "sorry, I ran out of time and couln't figure this out, " << endl;
      cout << "you are going to have to exit here" << endl;
      return 0;
    }
  }
}
