#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkListNode
{
    char* detail;
    struct LinkListNode *next;
} LinkListNode;

typedef struct LinkList
{
    struct LinkListNode *head;
    struct LinkListNode *tail;
} LinkList;

int filterMarks(LinkListNode *head, int filterMarks);
void createLL(LinkList **head, char *value);

void createLL(LinkList **head, char *value){
    //   CODE 
}

int filterMarks(LinkListNode *head, int filterMarks){
    //   CODE 
}



int main()
{
    char val[100];
    int filterCount = 0;
    printf("Enter the Filter Count ");
    scanf("%d",&filterCount);
    getchar();
    LinkList *mainHead = (LinkList *)malloc(sizeof(LinkList));
    mainHead->head = NULL;
    mainHead->tail = NULL;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter the detail ");
        fgets(val, sizeof(val), stdin);
        val[strcspn(val, "\n")] = 0;
        createLL(&mainHead, val);
    }

    int ans = filterMarks(mainHead->head,filterCount);
    printf("\nans is %d \n",ans);

    return 0;
}

