#include <iostream>
#include <string>
#include "automata.h"

using namespace std; 

int prev(int i, int string_size) {
  // declares and initializes a variable to be returned at the end
  int result = i;
  if (i == 0)
  {
    // returns the last string index when the current is zero
    result = (string_size - 1);
  }
  else
  {
    result = i - 1;
  }
  return result;
}


// next returns the index after i. If i is (string_size - 1), it
// should return 0.
// next and previous give us circular sequence indexing capabilities
int next(int i, int string_size) {
  int result = i;
  if (result == (string_size - 1))
  {
    result = 0;
  }
  else
  {
    result = i + 1;
  }
  return result;
  
}

string get_neighborhood(string in, int i) {
  // we start by initializing an empty string
  // to append i-1, i and i + 1 to.
  string result = in.substr(prev(i,in.length()), 1);
  result = result + in.substr(i,1);
  result = result + in.substr(next(i,in.length()), 1);
  return result;
}

char rule90(string in, int i) {
  // this gets the neighborhood of i with respect to the string inputed
  // and stores it in neighborhood
  string neighborhood = get_neighborhood(in, i);
  
  string first = neighborhood.substr(0, 1);
  
  string last = neighborhood.substr(2, 1);
  
  char result = '#';
  // XOR gate to check if we need to change the result ouput
  if ((first == last))
  {
    result = ' ';
  }
  return result;
}


// make_next_generation uses the current generation (the `in`
// parameter) and uses the `rule90` function for each cell of the
// current generation to produce a next generation string.
string make_next_generation(string in) {

  string next_gen = "";
  for(int i = 0; i < in.length(); i++)
  {
    // builds the next generation string by picking 
    // a neighborhood based off of current value of i
    next_gen = next_gen + rule90(in, i);
  }
  return next_gen;
}

void generate(string initial_state, int num_generations) {
  cout << initial_state << endl;
  for(int i = 0; i < num_generations; i++)
  {
    string next_state = make_next_generation(initial_state);
    initial_state = next_state;
    cout << next_state << endl;
     
  }
}

