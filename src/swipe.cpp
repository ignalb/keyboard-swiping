// Juliana Pacheco
// University of Florida

#include <iostream>
#include <string>
#include <vector>
#include "src/swipe_prediction.h"

const char* unigram = "rcs/unigram_freq.csv";
const unsigned int num_of_suggestions = 4;

int main() {
  try {
    Swipe swipe(unigram);

    int code_or_num;
    std::vector<std::string> suggestions;
    std::set<char> keys;
    char key;
    while(true) {
      std::cin >> code_or_num;
      if(code_or_num < 0)
        break;
      if(code_or_num == 0) {
        suggestions = std::move(swipe.get(num_of_suggestions));
        for(const std::string& s : suggestions)
          std::cout << s << '\n';
        std::cout << std::flush;
        swipe.reset();
      } else {
        keys.clear();
        for(int i = 0; i < code_or_num; i++) {
          std::cin >> key;
          keys.insert(key);
        }
        swipe.advance(keys);
      }
    }
  } catch(const std::exception& e) {
    std::cerr << e.what();
    return -1;
  }
}