#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOperand(char x) {
    return (x >= 'a' && x <= 'z')
        || (x >= 'A' && x <= 'Z')
        || (x >= '0' && x <= '9');
}

string abbre(string word) {
    string caps;
    for (char c : word) {
        if (c >= 'A' && c <= 'Z') caps += c;
    }
    if (caps.length() >= 2) return caps;
    return word;
}

string getInfix(string exp) {
    stack<string> s;

    if (exp.find(' ') != string::npos) {
        string token;
        for (int i = 0; exp[i] != '\0'; i++) {
            if (exp[i] == ' ') {
                if (!token.empty()) {
                    if (isOperand(token[0])) {
                        s.push(abbre(token));
                    } else {
                        string op2 = s.top();
                        s.pop();
                        string op1 = s.top();
                        s.pop();
                        s.push("(" + op1 + token + op2 + ")");
                    }
                    token = "";
                }
            } else {
                token += exp[i];
            }
        }
        if (!token.empty()) {
            if (isOperand(token[0])) {
                s.push(abbre(token));
            } else {
                string op2 = s.top();
                s.pop();
                string op1 = s.top();
                s.pop();
                s.push("(" + op1 + token + op2 + ")");
            }
        }
    } else {
        for (int i = 0; exp[i] != '\0'; i++) {
            if (isOperand(exp[i])) {
                string op(1, exp[i]);
                s.push(op);
            } else {
                string op2 = s.top();
                s.pop();
                string op1 = s.top();
                s.pop();
                s.push("(" + op1 + exp[i] + op2 + ")");
            }
        }
    }

    return s.top();
}

int main() {
    string exp1 = "ab*c+";
    cout << getInfix(exp1) << endl;

    string exp2 = "12 3 * 5 +";
    cout << getInfix(exp2) << endl;

    string exp3 = "FirtName LastName + Section *";
    cout << getInfix(exp3) << endl;

    return 0;
}