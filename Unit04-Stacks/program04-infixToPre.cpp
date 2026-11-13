#include<iostream>
using namespace std;

char stack[100];
int tos = -1;

void push(char ch) {
    if(tos == 99) {
        cout << "Stack Overflow";
        return;
    }

    stack[++tos] = ch;
}

char pop() {
    if(tos == -1) {
        return '\0';
    }

    return stack[tos--];
}

char peek() {
    if(tos == -1) {
        return '\0';
    }

    return stack[tos];
}

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

void reverseString(char str[]) {
    int len = 0;

    while(str[len] != '\0') {
        len++;
    }

    int start = 0;
    int end = len - 1;

    while(start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

void infixToPrefix(char infix[]) {
    char prefix[100];
    int k = 0;

    reverseString(infix);

    // Swap opening and closing brackets
    for(int i = 0; infix[i] != '\0'; i++) {
        if(infix[i] == '(') {
            infix[i] = ')';
        }
        else if(infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Convert the reversed infix expression into postfix
    for(int i = 0; infix[i] != '\0'; i++) {

        char ch = infix[i];

        if((ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= '0' && ch <= '9')) {

            prefix[k++] = ch;
        }

        else if(ch == '(') {
            push(ch);
        }

        else if(ch == ')') {
            while(tos != -1 && peek() != '(') {
                prefix[k++] = pop();
            }

            if(tos != -1) {
                pop();
            }
        }

        else {
            while(tos != -1 && peek() != '(' &&
                  (precedence(peek()) > precedence(ch) ||
                  (precedence(peek()) == precedence(ch) && ch == '^'))) {

                prefix[k++] = pop();
            }

            push(ch);
        }
    }

    while(tos != -1) {
        prefix[k++] = pop();
    }

    prefix[k] = '\0';

    // Reverse the postfix expression to get prefix
    reverseString(prefix);

    cout << "Prefix Expression: " << prefix;
}

int main() {
    char infix[100];

    cout << "Enter Infix Expression: ";
    cin >> infix;

    infixToPrefix(infix);

    return 0;
}
