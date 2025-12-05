#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkListNode
{
    char *detail;
    struct LinkListNode *next;
} LinkListNode;

typedef struct LinkList
{
    struct LinkListNode *head;
    struct LinkListNode *tail;
} LinkList;

int filterMarks(LinkListNode *head, int filterMarks);
void createLL(LinkList **head, char *value);

void createLL(LinkList **head, char *value)
{

    LinkListNode *newNode = (LinkListNode *)malloc(sizeof(LinkListNode));
    newNode->detail = (char *)malloc(sizeof(strlen(value) + 1));
    newNode->next = NULL;
    strcpy(newNode->detail, value);
    if ((*head)->head == NULL)
    {
        (*head)->head = newNode;
        (*head)->tail = newNode;
    }
    else
    {
        (*head)->tail->next = newNode;
        (*head)->tail = newNode;
    }
}

int filterMarks(LinkListNode *head, int filterMarks)
{
    int count = 0;
    
    int id;
    char* name = (char*)malloc(sizeof(strlen(head->detail)+1));
    int marks;
    LinkListNode* temp = head;
    while(temp){
        if(sscanf(temp->detail,"%d %s %d",&id,name,&marks)!=3){
            return -1;
        }
        if((marks>100||marks<0)&&(filterMarks>100||filterMarks<0)){
            return -1;
        }
        if(marks>=filterMarks){
            count++;
        }        
        temp = temp->next;
    }
    return count;
}

int main()
{
    char val[100];
    int filterCount = 0;
    printf("Enter the Filter Count ");
    scanf("%d", &filterCount);
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

    int ans = filterMarks(mainHead->head, filterCount);
    printf("\nans is %d \n", ans);

    return 0;
}
