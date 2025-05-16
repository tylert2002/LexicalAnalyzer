#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <cctype>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <map>


using namespace std;

/*void ReadFile(ifstream &file)
{
    char val; 
    do{
        file.get(val);

        if(file.eof())
        {
            break;
        }

        cout << val << endl;
    }while(true);
}

bool validIdentifier(char* identifier)
{
    if(identifier[0] == '0' || identifier[0] == '1' || identifier[0] == '2' ||
        identifier[0] == '3' || identifier[0] == '4' || identifier[0] == '5' ||
        identifier[0] == '6' || identifier[0] == '7' || identifier[0] == '8' ||
        identifier[0] == '9' || isPunctuator(str[0]) == true)
        {
            return false;
        }
}

bool isOperators(char op)
{
    if(op == '+' || op == '-' || op == '=' || op == '/' 
        || op == '*'|| op == '>' || op == '<')
    {
        return true;
    }

    return false;

    
}

bool isKeyword(char* str)
{
    const char* keywords[] = {
        "int", "return", "if", "switch",
        "float", "while", "else", "case",
        "char", "for", "goto", "unsigned",
        "main", "break", "continue", "void",
    };

    for(int i = 0; i < 16; ++i){
        if(strcmp(keywords[i], str) == 0)
        {
            return true;
        }
    }
    return false;
}

bool isNumber(char* integer)
{
    int i = 0;

    if(integer == NULL || *integer == '\0')
    {
        return false; 
    }
    while(isdigit(integer[i]))
    {
        i++;
    }
    return integer[i] == '\0';
}

int lex(char val)
{
    switch(val){
        case '+':
    }
    

    
}*/

/*int operator_lookup_table(string str){
    std::map<string, std::string> tokensLexemes = {
        {"+", "plus"}, {"-", "minus"}, {"*", "multiply"}, {"/", "divide"},
        {".", "dot"}, {"%", "modulus"}, {"<", "lessThan"}, {">", "greaterThan"},
        {"=", "assignment"}, {";", "semicolon"}, {",", "comma"}, {"(", "leftParen"},
        {")", "rightParen"}, {"[", "leftBracket"}, {"]", "rightBracket"}, {"{","leftBrace"},
        {"}", "rightBrace"}, {"++", "increment"}, {"--", "decrement"}, {"<=", "lessThanEq"}, 
        {">=", "greaterThanEq"}, {"==", "logicEqual"}, {"&&", "logicAnd"}, {"||", "logicOr"}, 
        {"!", "logicNot"}, {"&", "bitAnd"}, {"|", "bitOr"}, {"0", "number"}, {"1", "number"}, 
        {"2", "number"}, {"3", "number"}, {"4", "number"}, {"5", "number"}, {"6", "number"},
        {"7", "number"}, {"8", "number"}, {"9", "number"}, {"a", "identifier"}, {"b", "identifier"},
        {"c", "identifier"}, {"d", "identifier"}, {"e", "identifier"}, {"f", "identifier"}, {"g", "identifier"},
        {"h", "identifier"}, {"i", "identifier"}, {"j", "identifier"}, {"k", "identifier"}, {"l", "identifier"},
        {"m", "identifier"}, {"n", "identifier"}, {"o", "identifier"}, {"p", "identifier"}, {"q", "identifier"}, 
        {"r", "identifier"}, {"s", "identifier"}, {"t", "identifier"}, {"u", "identifier"}, {"v", "identifier"}, 
        {"w", "identifier"}, {"x", "identifier"}, {"y", "identifier"}, {"z", "identifier"}, {"A", "identifier"}, 
        {"B", "identifier"}, {"C", "identifier"}, {"D", "identifier"}, {"E", "identifier"}, {"F", "identifier"}, 
        {"G", "identifier"}, {"H", "identifier"}, {"I", "identifier"}, {"J", "identifier"}, {"K", "identifier"}, 
        {"L", "identifier"}, {"M", "identifier"}, {"N", "identifier"}, {"O", "identifier"}, {"P", "identifier"}, {"Q", "identifier"}, 
        {"R", "identifier"}, {"S", "identifier"}, {"T", "identifier"}, {"U", "identifier"}, {"V", "identifier"}, 
        {"W", "identifier"}, {"X", "identifier"}, {"Y", "identifier"}, {"Z", "identifier"}, {"int", "Keywords"}, 
        {"return", "Keywords"}, {"if", "Keywords"}, {"switch", "Keywords"}, {"float", "Keywords"}, {"while", "Keywords"},
        {"else", "Keywords"}, {"case", "Keywords"}, {"char", "Keywords"}, {"for", "Keywords"}, {"goto", "Keywords"},
        {"unsigned", "Keywords"}, {"main", "Keywords"}, {"break", "Keywords"}, {"continue", "Keywords"}, {"void", "Keywords"}

    };

    if(tokensLexemes[str] == "+")
    {
        return str;
    }

    return 0;



   

}*/


int main()
{
    string str;
    std::ifstream textFile("case2.txt");
    std::map<string, std::string> tokensLexemes = {
        {"+", "plus"}, {"-", "minus"}, {"*", "multiply"}, {"/", "divide"},
        {".", "dot"}, {"%", "modulus"}, {"<", "lessThan"}, {">", "greaterThan"},
        {"=", "assignment"}, {";", "semicolon"}, {",", "comma"}, {"(", "leftParen"},
        {")", "rightParen"}, {"[", "leftBracket"}, {"]", "rightBracket"}, {"{","leftBrace"},
        {"}", "rightBrace"}, {"++", "increment"}, {"--", "decrement"}, {"<=", "lessThanEq"}, 
        {">=", "greaterThanEq"}, {"==", "logicEqual"}, {"&&", "logicAnd"}, {"||", "logicOr"}, 
        {"!", "logicNot"}, {"&", "bitAnd"}, {"|", "bitOr"}, {"0", "number"}, {"1", "number"}, 
        {"2", "number"}, {"3", "number"}, {"4", "number"}, {"5", "number"}, {"6", "number"},
        {"7", "number"}, {"8", "number"}, {"9", "number"}, {"a", "identifier"}, {"b", "identifier"},
        {"c", "identifier"}, {"d", "identifier"}, {"e", "identifier"}, {"f", "identifier"}, {"g", "identifier"},
        {"h", "identifier"}, {"i", "identifier"}, {"j", "identifier"}, {"k", "identifier"}, {"l", "identifier"},
        {"m", "identifier"}, {"n", "identifier"}, {"o", "identifier"}, {"p", "identifier"}, {"q", "identifier"}, 
        {"r", "identifier"}, {"s", "identifier"}, {"t", "identifier"}, {"u", "identifier"}, {"v", "identifier"}, 
        {"w", "identifier"}, {"x", "identifier"}, {"y", "identifier"}, {"z", "identifier"}, {"A", "identifier"}, 
        {"B", "identifier"}, {"C", "identifier"}, {"D", "identifier"}, {"E", "identifier"}, {"F", "identifier"}, 
        {"G", "identifier"}, {"H", "identifier"}, {"I", "identifier"}, {"J", "identifier"}, {"K", "identifier"}, 
        {"L", "identifier"}, {"M", "identifier"}, {"N", "identifier"}, {"O", "identifier"}, {"P", "identifier"}, {"Q", "identifier"}, 
        {"R", "identifier"}, {"S", "identifier"}, {"T", "identifier"}, {"U", "identifier"}, {"V", "identifier"}, 
        {"W", "identifier"}, {"X", "identifier"}, {"Y", "identifier"}, {"Z", "identifier"}, {"int", "Keywords"}, 
        {"return", "Keywords"}, {"if", "Keywords"}, {"switch", "Keywords"}, {"float", "Keywords"}, {"while", "Keywords"},
        {"else", "Keywords"}, {"case", "Keywords"}, {"char", "Keywords"}, {"for", "Keywords"}, {"goto", "Keywords"},
        {"unsigned", "Keywords"}, {"main", "Keywords"}, {"break", "Keywords"}, {"continue", "Keywords"}, {"void", "Keywords"}

    };
    
    if (!textFile.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    while(getline(textFile, str)){
        if(tokensLexemes[str] == "++")
        {
            std::string value = tokensLexemes[str]; 
            cout << str << ": " << value << endl;
        }
    }
    return 0;
}