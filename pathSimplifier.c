#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkList {
    char *s;
    struct LinkList *next;
} LinkList;

LinkList *head = NULL;

void pathSimplifier(char *path) {
    //  CODE
}

int main() {
    char command[200];
    printf("Enter command: ");
    fgets(command, sizeof(command), stdin);

    command[strcspn(command, "\n")] = '\0';

    pathSimplifier(command);

    printf("Simplified Path: ");
    printList();

    return 0;
}
