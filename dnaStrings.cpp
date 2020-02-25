#include <iostream>
#include <cctype>
#include <math.h>
#include <fstream>
//calls the main libraries to call other functions
using namespace std;

string line = "";
//makes the length of string line
float varSum = 0.0;
int countA = 0;
int countC = 0;
int countT = 0;
int countG = 0;
//initializing variables for every single count letter
int aa = 0; int ac = 0; int at = 0; int ag = 0;
int ca = 0; int cc = 0; int ct = 0; int cg = 0;
int ta = 0; int tc = 0; int tt = 0; int tg = 0;
int ga = 0; int gc = 0; int gt = 0; int gg = 0;
//initializing variable for every possible dnasequence for every double count
float lineCount = 0.0;
float dnaSum = 0.0;
float pairSum = 0.0;
//will count totals in the file, which will be used to iterate through and calculate the
//floats to calculate percentages later
float sum = 0.0;
float mean = 0.0;
float stDev = 0.0;
float variance = 0.0;
//initializing the calculation variables, floats
char dna, dna1;
//variables used
ifstream fileIn;
ofstream fileOut;
//calls the input file and output file

float meanCalc(){

  mean = dnaSum / lineCount;
  cout << "Mean: " << mean << endl;

}
//calculation for the mean, will be called for stDev/variance/gaussian later

float varianceCalc(){
//calculates the variance code, used while loop and calling it up here
  float variance = varSum / lineCount;
  cout << variance << endl;
}

float stdevCalc(){
//calculates the stDev from the output of varianceCalc
  float stDev = (sqrt(varianceCalc()));
  cout << stDev << endl;
}

int main(int argc, char **argv){

  string fileName = argv[1];
  //retrieves whatever is typed in terminal
  fileIn.open(fileName);

  bool end = true;
  while(end)
  {
//be able to allow user to continue if they want more analysis
    while (getline(fileIn, line))
    {
      lineCount++;
      //iterates through every line in the file and adds to count
      for(int i = 0; i < line.length(); ++i)
      {
        dna = tolower(line[i]);
        dna1 = tolower(line[i+1]);
        //dna1 will check the next letter to the right of dna
        //both tolower to make every letter lowercase to make checking easier
        if(dna == 'a')
        {
          countA++;
          dnaSum++;
          if(dna1 == 'a'){
            aa++;
            pairSum++;
          }
          else if (dna1 == 'c') {
            ac++;
            pairSum++;
          }
          else if (dna1 == 't') {
            at++;
            pairSum++;
          }
          else if (dna1 == 'g') {
            ag++;
            pairSum++;
          }
        }
        //dna checks for the letter 'a', iterating through each line, if it is 'a'
        //then it checks the following letter and adds it to that particular pairSum
        //nested if loops
        if(dna == 't')
        {
          countT++;
          dnaSum++;
          if(dna1 == 'a'){
            ta++;
            pairSum++;
          }
          else if (dna1 == 'c') {
            tc++;
            pairSum++;
          }
          else if (dna1 == 't') {
            tt++;
            pairSum++;
          }
          else if (dna1 == 'g') {
            tg++;
            pairSum++;
          }
        }
        //dna checks for the letter 'g', iterating through each line, if it is 'g'
        //then it checks the following letter and adds it to that particular pairSum
        //nested if loop
        if(dna == 'c')
        {
          countC++;
          dnaSum++;
          if(dna1 == 'a'){
            ca++;
            pairSum++;
          }
          else if (dna1 == 'c') {
            cc++;
            pairSum++;
          }
          else if (dna1 == 't') {
            ct++;
            pairSum++;
          }
          else if (dna1 == 'c') {
            cg++;
            pairSum++;
          }
        }
        //dna checks for the letter 'c', iterating through each line, if it is 'c'
        //then it checks the following letter and adds it to that particular pairSum
        //nested if loop
        if(dna == 'g')
        {
          countG++;
          dnaSum++;
          if(dna1 == 'a'){
            ga++;
            pairSum++;
          }
          else if (dna1 == 'c') {
            gc++;
            pairSum++;
          }
          else if (dna1 == 't') {
            gt++;
            pairSum++;
          }
          else if (dna1 == 'g') {
            gg++;
            pairSum++;
          }
        }
        //dna checks for the letter 'g', iterating through each line, if it is 'g'
        //then it checks the following letter and adds it to that particular pairSum
        //nested if loop
      }
    }
//maybe close and open file again?
    while (getline(fileIn, line))
    {
      float lineLength = line.length();
      float halfVar = pow(lineLength - meanCalc(),2);
      varSum += halfVar;
      //get line length, again
      //get length - mean()
      //add that to varSum
    }

    meanCalc();
    varianceCalc();
    stdevCalc();
    cout << "Probability of A: " << countA / dnaSum * 100 << '%' << endl;
    fileOut << "Probability of A: " << countA / dnaSum * 100 << '%' << endl;
    fileOut << "Probability of C: " << countC / dnaSum * 100 << '%' << endl;
    fileOut << "Probability of T: " << countT / dnaSum * 100 << '%' << endl;
    fileOut << "Probability of G: " << countG / dnaSum * 100 << '%' << endl;
    //calculates the probability of the single dna strands
    fileOut << "Probability of AA: " << aa / pairSum * 100 << '%' << endl;
    fileOut << "Probability of AC: " << ac / pairSum * 100 << '%' << endl;
    fileOut << "Probability of AT: " << at / pairSum * 100 << '%' << endl;
    fileOut << "Probability of AG: " << ag / pairSum * 100 << '%' << endl;
    fileOut << "Probability of CA: " << ca / pairSum * 100 << '%' << endl;
    fileOut << "Probability of CC: " << cc / pairSum * 100 << '%' << endl;
    fileOut << "Probability of CT: " << ct / pairSum * 100 << '%' << endl;
    fileOut << "Probability of CG: " << cg / pairSum * 100 << '%' << endl;
    fileOut << "Probability of TA: " << ta / pairSum * 100 << '%' << endl;
    fileOut << "Probability of TC: " << tc / pairSum * 100 << '%' << endl;
    fileOut << "Probability of TT: " << tt / pairSum * 100 << '%' << endl;
    fileOut << "Probability of TG: " << tg / pairSum * 100 << '%' << endl;
    fileOut << "Probability of GA: " << ga / pairSum * 100 << '%' << endl;
    fileOut << "Probability of GC: " << gc / pairSum * 100 << '%' << endl;
    fileOut << "Probability of GT: " << gt / pairSum * 100 << '%' << endl;
    fileOut << "Probability of GG: " << gg / pairSum * 100 << '%' << endl;
    //calculates the probability of the paired dna strands
    char userChoice;
    cout << "Here are your calculations would you like to continue? ('y', 'Y'): for yes, and anything else for no. " << endl;
    cin >> userChoice;

    //asks the user if they would like to continue more analysis, accepting multiple forms of yes
    if(userChoice == 'y' || userChoice == 'Y'){

      cout << "Enter file name: " << endl;
      cin >> fileName;
    }
    else
    {
      end = false;
    }
    //breaks the while loop if the user inputs anything besides yes, y, Y, Yes

  }

}
