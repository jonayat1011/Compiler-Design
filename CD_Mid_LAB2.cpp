#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool isKeyword(const string &token) {
    string keywords[9] = {"if", "else", "while", "for", "int", "float", "double", "char", "return"};
    for (const string &keyword : keywords) {
        if (token == keyword) {
            return true;
        }
    }
    return false;
}

bool isIdentifier(const string &token) {
    if (token.empty()) {
        return false;
    }
    if (!isalpha(token[0]) && token[0] != '_') {
        return false;
    }
    for (char c : token) {
        if (!isalnum(c) && c != '_') {
            return false;
        }
    }
    return true;
}

bool isConstant(const string &token) {
    for (char c : token) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool isOperator(const string &token) {
    string operators[14] = {"+", "-", "*", "/", "%", "=", "==", "<", ">", "<=", ">=", "&&", "||"};
    for (const string &op : operators) {
        if (token == op) {
            return true;
        }
    }
    return false;
}

bool isPunctuation(const string &token) {
    string punctuations[7] = {";", ",", ".", "(", ")", "{", "}"};
    for (const string &punc : punctuations) {
        if (token == punc) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream file("test.txt"); 
    if (!file.is_open()) {
        cerr << "Unable to open file\n";
        return 1;
    }

    string line;
    int lineNum = 0;
    while (getline(file, line)) {
        lineNum++;
        string token;
        for (char c : line) {
            if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
                if (!token.empty()) {
                    if (isKeyword(token)) {
                        cout << "Line " << lineNum << ": Keyword: " << token << endl;
                    } else if (isIdentifier(token)) {
                        cout << "Line " << lineNum << ": Identifier: " << token << endl;
                    } else if (isConstant(token)) {
                        cout << "Line " << lineNum << ": Constant: " << token << endl;
                    } else if (isOperator(token)) {
                        cout << "Line " << lineNum << ": Operator: " << token << endl;
                    } else if (isPunctuation(token)) {
                        cout << "Line " << lineNum << ": Punctuation: " << token << endl;
                    } else {
                        cout << "Line " << lineNum << ": Unidentified Token: " << token << endl;
                    }
                    token.clear();
                }
            } else {
                token += c;
            }
        }
        if (!token.empty()) {
            if (isKeyword(token)) {
                cout << "Line " << lineNum << ": Keyword: " << token << endl;
            } else if (isIdentifier(token)) {
                cout << "Line " << lineNum << ": Identifier: " << token << endl;
            } else if (isConstant(token)) {
                cout << "Line " << lineNum << ": Constant: " << token << endl;
            } else if (isOperator(token)) {
                cout << "Line " << lineNum << ": Operator: " << token << endl;
            } else if (isPunctuation(token)) {
                cout << "Line " << lineNum << ": Punctuation: " << token << endl;
            } else {
                cout << "Line " << lineNum << ": Unidentified Token: " << token << endl;
            }
        }
    }
    file.close();

    return 0;
}
