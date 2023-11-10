#include <iostream>
#include <vector>
#include "ufo_functions.hpp"

using namespace std;

void greet() {
  cout << "=============" << endl;
  cout << "UFO: The Alien Abduction Game" << endl;
  cout << "=============" << endl;
  cout << "Instructions: save your friend from alien abduction by guessing the letters in the codeword." << endl;
}

int main() {
  greet();

  std::string codeword = "marsattack"; // has to be the same size
  std::string answer = "__________";   // as the answer and viceversa
  int misses = 0;

  vector<char> incorrect;
  bool guess = false;

  char letter;

  while (answer != codeword && misses < 7) {
    display_misses(misses);
    display_status(incorrect, answer);

    cout << "\nPlease enter your guess: ";
    cin >> letter;

    for (int i = 0; i < codeword.size(); i++) {
      if (letter == codeword[i]) {
        answer[i] = letter;
        guess = true;
      }
    }

    if (guess) {
      cout << "Correct! " << endl;
    } else {
      cout << "Incorrect! The tractor beam pulls the person in further. " << endl;
      incorrect.push_back(letter);

      misses++;
    }
    guess = false;
  }
  
  end_game(answer, codeword);

  return 0;

}

