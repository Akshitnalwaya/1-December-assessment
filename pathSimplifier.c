#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char *s);
void pop();
void printList();
void pathSimplifier(char *path);

typedef struct LinkList
{
    char *s;
    struct LinkList *next;
} LinkList;

LinkList *head = NULL;

void push(char *s)
{
    LinkList *newNode = (LinkList *)malloc(sizeof(LinkList));
    newNode->s = (char *)malloc(strlen(s) + 1);
    strcpy(newNode->s, s);
    newNode->next = head;
    head = newNode;
}

void pop()
{
    if (head == NULL)
    {
        return;
    }
    LinkList *temp = head;
    head = head->next;
    free(temp);
}

void printList()
{
    if (head == NULL)
    {
        printf("/");
        return;
    }

    LinkList *prev = NULL, *curr = head, *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    LinkList *temp = prev;
    while (temp)
    {
        printf("/%s", temp->s);
        temp = temp->next;
    }
}

void pathSimplifier(char *path)
{
    char *token = strtok(path, "/");

    while (token != NULL)
    {
        if (strcmp(token, ".") == 0)
        {
        }
        else if (strcmp(token, "..") == 0)
        {
            pop();
        }
        else if (strlen(token) > 0)
        {
            push(token);
        }

        token = strtok(NULL, "/");
    }
}

int main()
{
    char command[200];
    printf("Enter command: ");
    fgets(command, sizeof(command), stdin);

    command[strcspn(command, "\n")] = '\0';

    pathSimplifier(command);

    printf("Simplified Path: ");
    printList();

    return 0;
}
