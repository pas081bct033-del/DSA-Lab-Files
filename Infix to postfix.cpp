#include <iostream>
#include <string>
using namespace std;

#define MAX 100   
char stack[MAX];
int top = -1;
void push(char c) {
    if (top == MAX - 1) {
        cout << "Stack overflow\n";
        return;
    }
    stack[++top] = c;
}

// Pop function
char pop() {
    if (top == -1) {
        cout << "Stack underflow\n";
        return -1;
    }
    return stack[top--];
}

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // Operand check: only alphabetic characters
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            postfix += ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix += pop();
            }
            pop(); // remove '('
        }
        else { // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix += pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix += pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression (alphabetic only): ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
