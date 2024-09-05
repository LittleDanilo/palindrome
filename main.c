#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha {
    char vet[200];
    int topo;
} TPilha;

void create(TPilha *p) {
    p->topo = -1;
}

void destroy(TPilha *p) {
    p->topo = -1;
}

int isEmpty(TPilha *p) {
    return p->topo == -1;
}

int isFull(TPilha *p) {
    return p->topo == 200;
}

void push(TPilha *p, char x) {
    if (isFull(p)) {
        puts("overflow");
        abort();
    }
    p->topo++;
    p->vet[p->topo] = x;
}

char pop(TPilha *p) {
    if (isEmpty(p)) {
        puts("underflow");
        abort();
    }
    char aux = p->vet[p->topo];
    p->topo--;
    return aux;
}

// reverse a string
char reverse(char *arr) {
    TPilha p; // Defining the stack
    create(&p); // Creating the stack
    int arrLen = strlen(arr); // getting string length
    for (int i;i<arrLen;i++) {
        push(&p, arr[i]); // push all characters to stack
    }
    for (int i;i<arrLen;i++) {
        arr[i] = pop(&p); // remove all characters from stack
    }
}

// Check if a word is palindrome or no
int isPalindrome(char *arr) {
    char auxArr[strlen(arr)]; // copying the original string
    strcpy(auxArr, arr);
    reverse(arr); // reversing the string
    if (strcmp(arr, auxArr) == 0) return 1; // compares the two strings and returns 1 if there are no differences between them
    else return 0;
}

int main(void) {
    char arr[200];
    printf("Enter a word to see if it is a palindrome: ");
    scanf("%s", arr);
    if (isPalindrome(arr)) puts("This word is palindrome");
    else puts("It is not palindrome");
    return 0;
}