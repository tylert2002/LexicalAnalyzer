// Authors: Owen Rotenberg, Tyler Tran, Jesse Dawson, Luuser

// Purpose: This lexical analyzer takes a text file of lexemes and generates a
// new file with the appropriate tokens.

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> lines;
  std::string line;

  // ========== READ INPUT FILE ==========
  // Lines are fed into the program with: ./lexical_analyzer.o < test_1.txt
  // Push command line redirected text line by line to lines vector
  while (std::getline(std::cin, line)) {
    lines.push_back(line);
  }

  // Print each line back on a new line
  std::cout << lines.size() << " lines.\n\n";
  for (const auto& l : lines) {
    std::cout << l << "\n";
  }

  return 0;
}