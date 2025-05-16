// Authors: Owen Rotenberg, Tyler Tran, Jesse Dawson, Jason Luu

// Purpose: This lexical analyzer takes a text file of lexemes and generates a
// new file with the appropriate tokens.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Set of keywords
unordered_set<string> keywords = {
    "int", "return", "if", "switch", "float", "while", "else", "case",
    "char", "for", "goto", "unsigned", "main", "break", "continue", "void"
};

unordered_map<string, string> lexemes = {
    {"(", "leftParen"},
    {")", "rightParen"},
    {"[", "leftBracket"},
    {"]", "rightBracket"},
    {"{", "leftBrace"},
    {"}", "rightBrace"},
    {".", "dot"},
    {"*", "multiply"},
    {"%", "modulus"},
    {";", "semicolon"},
    {",", "comma"},
    {"+", "plus"},
    {"++", "increment"},
    {"-", "minus"},
    {"--", "decrement"},
    {"<", "lessThan"},
    {"<=", "lessThanEq"},
    {">", "greaterThan"},
    {">=", "greaterThanEq"},
    {"=", "assignment"},
    {"==", "logicEqual"},
    {"&", "bitAnd"},
    {"&&", "logicAnd"},
    {"|", "bitOr"},
    {"||", "logicOr"},
    {"!", "logicNot"},
    {"/", "divide"},
    {"//", "comment"}
};

// Processes a single line and appends found tokens into the tokens vector
void tokenizeLine(const string &line, vector<string>& tokens) {
    int i = 0;
    int n = line.size();

    while (i < n) {
        char c = line[i];

        // Skip whitespace
        if (isspace(c)) {
            i++;
            continue;
        }

        // Identifier or Keyword
        if (isalpha(c)) {
            int start = i;
            while (i < n && isalnum(line[i]))
                i++;
            string word = line.substr(start, i - start);
            // Check if the word is a keyword.
            if (keywords.find(word) != keywords.end())
                tokens.push_back(word);
            else
                tokens.push_back("identifier");
            continue;
        }

        // Number
        if (isdigit(c)) {
            int start = i;
            while (i < n && isdigit(line[i]))
                i++;
            tokens.push_back("number");
            continue;
        }

        // Comments
        if (c == '/') {
            if (i + 1 < n && line[i + 1] == '/') {
                tokens.push_back(lexemes["//"]);
                break;
            } else {
                tokens.push_back(lexemes["/"]);
                i++;
                continue;
            }
        }

        // Multi-character Operators
        if (c == '+') {
            if (i + 1 < n && line[i + 1] == '+') {
                tokens.push_back(lexemes["++"]);
                i += 2;
            } else {
                tokens.push_back(lexemes["+"]);
                i++;
            }
            continue;
        }
        if (c == '-') {
            if (i + 1 < n && line[i + 1] == '-') {
                tokens.push_back(lexemes["--"]);
                i += 2;
            } else {
                tokens.push_back(lexemes["-"]);
                i++;
            }
            continue;
        }
        if (c == '<') {
            if (i + 1 < n && line[i + 1] == '=') {
                tokens.push_back(lexemes["<="]);
                i += 2;
            } else {
                tokens.push_back(lexemes["<"]);
                i++;
            }
            continue;
        }
        if (c == '>') {
            if (i + 1 < n && line[i + 1] == '=') {
                tokens.push_back(lexemes[">="]);
                i += 2;
            } else {
                tokens.push_back(lexemes[">"]);
                i++;
            }
            continue;
        }
        if (c == '=') {
            if (i + 1 < n && line[i + 1] == '=') {
                tokens.push_back(lexemes["=="]);
                i += 2;
            } else {
                tokens.push_back(lexemes["="]);
                i++;
            }
            continue;
        }
        if (c == '&') {
            if (i + 1 < n && line[i + 1] == '&') {
                tokens.push_back(lexemes["&&"]);
                i += 2;
            } else {
                tokens.push_back(lexemes["&"]);
                i++;
            }
            continue;
        }
        if (c == '|') {
            if (i + 1 < n && line[i + 1] == '|') {
                tokens.push_back(lexemes["||"]);
                i += 2;
            } else {
                tokens.push_back(lexemes["|"]);
                i++;
            }
            continue;
        }
        if (c == '!') {
            tokens.push_back(lexemes["!"]);
            i++;
            continue;
        }

        // Single-character Tokens
        {
            string s(1, c);
            if (lexemes.find(s) != lexemes.end()) {
                tokens.push_back(lexemes[s]);
            }
            i++;
        }
    }
}

int main() {
    vector<string> lines;
    string line;

    // ========== READ INPUT FILE ==========
    // Lines are fed into the program with: ./lexical_analyzer.o < test_1.txt
    // Push command line redirected text line by line to lines vector
    while (getline(cin, line)) {
        lines.push_back(line);
    }

    // Process each line and accumulate tokens
    cout << "\n";
    for (const auto &l : lines) {
        vector<string> tokenStream;
        tokenizeLine(l, tokenStream);

        
        for (size_t i = 0; i < tokenStream.size(); i++) {
            cout << tokenStream[i];
            if (i + 1 < tokenStream.size()) {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}