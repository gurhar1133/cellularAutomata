#include "automata.h"
#include "automata.cpp"
#include <sstream>
using namespace std;

std::string balanced_in_middle(int n) {
  using namespace std;
  stringstream out;
  for (int i=0; i < n; i++) {
    out << " ";
  }
  out << "#";
  for (int i=0; i < n; i++) {
    out << " ";
  }
  return out.str();
}

int main() {
  // This input will
  // give a Sierpinski triangle
  // std::string in = "                                                                #                                                               ";

  
  
  std::string in= "#       #       ##      #       #";

  //std::string in = balanced_in_middle(60);
  generate(in, 100);
  return 0;
}
