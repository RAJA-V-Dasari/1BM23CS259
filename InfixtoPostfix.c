#include <stdio.h>
#define size 100

void push(char x);
char pop();
int precedence(char x);
int isOperand(char x);
void infixTopostfix(char* exp);

char stack[size];
int top = -1;

void push(char x) {
    if (top == size - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;  // Return an invalid character on underflow
    } else {
        char temp = stack[top];
        top--;
        return temp;
    }
}

int precedence(char x) {
    if (x == '^') return 3;
    else if (x == '*' || x == '/') return 2;
    else if (x == '+' || x == '-') return 1;
    else return 0;
}

int isOperand(char x) {
    // Check if x is an operand (A-Z, a-z, 0-9)
    return (x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9');
}

void infixTopostfix(char* exp) {
    char postfix[size];
    int i = 0, j = 0;

    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (isOperand(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  // Discard the '('
        } else {  // Operator case
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop all the remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  // Null-terminate the postfix string
    puts(postfix);      // Print the result
}

int main() {
    printf("Enter an infix expression:\n");
    char infix[size];
    scanf("%s", infix);
    printf("The postfix expression is:\n");
    infixTopostfix(infix);
    return 0;
}



Output:

Case 1:
Enter an infix expression:
(a+b-c*d/e)
The postfix expression is:
ab+cd*e/-

Process returned 0 (0x0)   execution time : 8.609 s
Press any key to continue.


Case 2;


Enter an infix expression:
(1*2*3*(3-2+(5-7^5/3)))
The postfix expression is:
12*3*32-575^3/-+*

Process returned 0 (0x0)   execution time : 51.120 s
Press any key to continue.
