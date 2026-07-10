#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOperand(char x) {
    return (x >= 'a' && x <= 'z') 
    || (x >= 'A' && x <= 'Z') 
    || (x >= '0' && x <= '9');
}

string getInfix(string exp) {
    stack<string> s;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == ' ') {
            continue;
        }

        if (isOperand(exp[i])) {
            string op;
            while (exp[i] != '\0' && isOperand(exp[i])) {
                op += exp[i];
                i++;
            }
            i--;
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
    string exp = "12 3 * 5 +";
    cout << getInfix(exp) << endl;
    return 0;
}