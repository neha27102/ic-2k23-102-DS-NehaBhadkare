#include<iostream>
using namespace std;

#define SIZE 100

int tos = -1;

// Inserts an operator into the stack
void push(char stack[], char ch) {
    if(tos == SIZE - 1) {
        cout << "Stack Overflow";
        return;
    }
    tos++;
    stack[tos] = ch;
}

// Removes and returns the top element
char pop(char stack[]) {
    if(tos == -1) {
        return '\0';
    }
    char ch = stack[tos];
    tos--;
    return ch;
}

// Returns the top element without removing it
char peek(char stack[]) {
    if(tos == -1) {
        return '\0';
    }
    return stack[tos];
}

// Checks operator precedence
int precedence(char ch) {
    if(ch == '^') {
        return 3;
    }
    else if(ch == '*' || ch == '/') {
        return 2;
    }
    else if(ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}

// Converts infix expression into postfix expression
void infixToPostfix(char infix[]) {
    char stack[SIZE];
    char postfix[SIZE];
    int j = 0;

    tos = -1;

    for(int i = 0; infix[i] != '\0'; i++) {

        char ch = infix[i];

        // If operand, add it directly to postfix
        if((ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= '0' && ch <= '9')) {

            postfix[j] = ch;
            j++;
        }

        // If opening bracket, push it into stack
        else if(ch == '(') {
            push(stack, ch);
        }

        // If closing bracket, pop until opening bracket
        else if(ch == ')') {
            while(tos != -1 && peek(stack) != '(') {
                postfix[j] = pop(stack);
                j++;
            }
            if(tos != -1) {
                pop(stack);
            }
        }

        // If operator, check precedence
        else if(ch == '+' || ch == '-' ||
                ch == '*' || ch == '/' || ch == '^') {

            while(tos != -1 && peek(stack) != '(' &&
                  (precedence(peek(stack)) > precedence(ch) ||
                  (precedence(peek(stack)) == precedence(ch) && ch != '^'))) {

                postfix[j] = pop(stack);
                j++;
            }

            push(stack, ch);
        }
    }

    // Pop all remaining operators
    while(tos != -1) {
        postfix[j] = pop(stack);
        j++;
    }

    postfix[j] = '\0';

    cout << "Postfix Expression: " << postfix << endl;
}

int main() {
    char infix[SIZE];

    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix);

    return 0;
}
