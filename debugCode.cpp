#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOperand(char x) {
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

string getInfix(string exp) {
    stack<string> s;

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

    return s.top();
}

int main() {
    string exp = "ab*c+";
    // cout << getInfix("ab*c+");
    cout << getInfix(exp) << endl;
    return 0;
}