#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

char s[MAX_SIZE];
int top = -1;

void push(char ele) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s[++top] = ele;
}

 char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s[top--];
}

int main() {
    char input;
    printf("Enter characters to push onto the stack (press Enter after each character, enter '.' to stop):\n");
    do {
        scanf(" %c", &input);  // Add space before %c to consume newline characters
        if (input != '.') {
            push(input);
        }
    } while (input != '.');

    printf("Characters popped from the stack: ");
    while (top != -1) {
        printf("%c ", pop());
    }
    return 0;
}