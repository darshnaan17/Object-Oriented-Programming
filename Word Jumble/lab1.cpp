/*
*****************************************
*                                       *
*     Darshan Vala                      *
*     U39780959                         *
*                                       *
*                                       *
*****************************************

The following code opens a file called dictionary.txt and reads through
all of it. It then compares the users input with the words inside the file
in order to see if any words match with the same amount of identical letters,
even if theyre in different order. This is done by using two vectors.

*/


#include <string>
#include <vector>
//#include <cctype>
#include <iostream>
#include <fstream>
using namespace std;

vector<string> findMatches(string word, vector<string> vec);
void countLetters(string word, int* count);
bool isJumble(string word1, string word2);

const int ALPHABET_SIZE = 26;
const string DICTIONARY_FILE = "dictionary.txt";

int main()
{
  ifstream inputf; // file variable

  string word; //stores input
  vector<string>pair; // finds matches
  vector<string>dictionary; // for dictionary
  int l = 0; // for index

  inputf.open(DICTIONARY_FILE, ios::in); // opens file for reading
  if(inputf.is_open())
  {
      while(inputf >> word)
      {
          dictionary.push_back(word); //adds the word to dictionary for the vector to find a pair
          //word = " ";
      }
      do
      {
          cout << "Enter a word" << endl << "Type 'quit' to stop" << endl;
          cin >> word;
          if(word != "quit") // if they type a word thats not quit
          {
              pair = findMatches(word, dictionary); // stores in pair the return

              cout << "The pairs are: " << endl;
              if(pair.size() != 0)
              {
                for(l = 0; l < pair.size(); l++)
                {
                    cout << pair[l] << endl; // prints the pairs (words)
                }
              }

              else
              {
                  cout << "There are no pairs" << endl;
              }
          }

      }while((word ) != "quit");


  }

  else
  {
      cout << "File failed to open" << endl;
      return 1;
  }

  return 0;
}


vector<string> findMatches(string word, vector<string> vec)
{
  int k = 0; //another variable for index that not j or i
  vector<string>pair; // need to initialize
  for(k = 0; k < vec.size(); k++)
  {
      if(isJumble(word, vec[k])) //  function call
      {
           pair.push_back(vec[k]); // adds word to pair
      }
  }
    return pair; //stores how many pairs
}


bool isJumble(string word1, string word2)
{
  int j = 0; // already named i for index so j is new index variable for this
  int ek[ALPHABET_SIZE] = {0}; //word1 will store here
  int be[ALPHABET_SIZE] = {0}; // word2 stored here

  countLetters(word1, ek); //function call to store counts from characters in the word
  countLetters(word2, be);

  for(j = 0; j < ALPHABET_SIZE; j++) // this loop goes through ek and be and will compare counts
  {
      if(ek[j] != be[j]) // if they are not the same count
      {
          return false;
      }

      else
      {
          //return true; was not working with this here
      }
  }
  return true;
}


void countLetters(string word, int* count)
{
  int i = 0;
  do // int i is index for words
  {
     int c = word[i]-'a'; // finds the character and stores it in c
     count[c]++; // increments the count for the character
     i++; // incremeants to the next index
  }while(word[i] != '\0'); // while we are not at null go through the word
}
