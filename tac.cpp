#include <iostream>
#include <string>
#include <stack>

using namespace std;

char first;

// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to get precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

// Function to generate three-address code for the given expression
void generateThreeAddressCode(string expr) {
    stack<char> operators;
    stack<string> operands;
    string temp;

    for (int i = 0; i < expr.length(); i++) {
        if (iswalnum(expr[i])) {
            operands.push(string(1,expr[i]));
        }

        else if (isOperator(expr[i])) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expr[i])) {
                string op2 = operands.top();
                operands.pop();
                string op1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                string res = "t" + to_string(operands.size()+1);
                operands.push(res);
                cout << res << " = " << op1 << " " << op << " " << op2 << endl;
            }
            operators.push(expr[i]);
        }

        else if (expr[i] == '(') {
            operators.push(expr[i]);
        }

        else if (expr[i] == ')') {
            while (operators.top() != '(') {
                string op2 = operands.top();
                operands.pop();
                string op1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                string res = "t" + to_string(operands.size()+1);
                operands.push(res);
                cout << res << " = " << op1 << " " << op << " " << op2 << endl;
            }
            operators.pop();
        }
    }

    while (!operators.empty()) {
        string op2 = operands.top();
        operands.pop();
        string op1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        string res = "t" + to_string(operands.size()+1);
        operands.push(res);
        cout << res << " = " << op1 << " " << op << " " << op2 << endl;
    }

    cout << first<<" = " << operands.top() << endl;
}

// Main function
int main() {
    cout<<"Enter an expression: ";
    string expr;
    getline(cin,expr);

    first = expr[0];

    expr.erase(0,4);
    generateThreeAddressCode(expr);
  return 0;
}


//x = anyexpressionwithoutspace