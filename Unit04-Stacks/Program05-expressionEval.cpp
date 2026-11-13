#include<iostream>
using namespace std;

int stack[100];
int tos = -1;

// Inserts an element into the stack
void push(int d) {
    if(tos == 99) {
        cout << "Stack Overflow";
        return;
    }

    stack[++tos] = d;
}

// Removes and returns the top element
int pop() {
    if(tos == -1) {
        cout << "Stack Underflow";
        return -1;
    }

    return stack[tos--];
}

// Evaluates the postfix expression
int evaluatePostfix(char exp[]) {

    for(int i = 0; exp[i] != '\0'; i++) {

        char ch = exp[i];

        // Push the operand into the stack
        if(ch >= '0' && ch <= '9') {
            push(ch - '0');
        }

        // Perform operation when an operator is encountered
        else {

            int b = pop();
            int a = pop();

            switch(ch) {

                case '+':
                    push(a + b);
                    break;

                case '-':
                    push(a - b);
                    break;

                case '*':
                    push(a * b);
                    break;

                case '/':
                    if(b == 0) {
                        cout << "Division by zero error";
                        return -1;
                    }
                    push(a / b);
                    break;

                case '^': {
                    int result = 1;

                    for(int j = 0; j < b; j++) {
                        result = result * a;
                    }

                    push(result);
                    break;
                }
            }
        }
    }

    return pop();
}

int main() {

    char exp[100];

    cout << "Enter Postfix Expression: ";
    cin >> exp;

    cout << "Result: " << evaluatePostfix(exp);

    return 0;
}
