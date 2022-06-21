#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void printNodes(Node *curr)
{
    while (curr != NULL)
    {
        printf("%d", curr->data);
        curr = curr->next;
    }
}
void pushNodeFront(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = *head;
    newNode->data = data;
    *head = newNode;
}
void pushNodeEnd(Node **head, int data)
{
    Node *curr = *head;
    while (curr != NULL)
    {
        curr = curr->next;
    }
}
int sumList(Node* curr){
    int sum = 0;
    while(curr!=NULL){
        sum++;
        curr = curr->next;        
    }
    return sum;
}
int maxList(Node* curr){
        int max = INT32_MIN;
    while(curr!=NULL){
        if(curr->data > max){
            max = curr->data;
        }
        curr = curr->next;
        
    }
    return max;
}
int main()
{
    unsigned listSize = 0;
    Node *head;

    head = (Node *)malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;

    pushNodeFront(&head, 1);
    pushNodeFront(&head, 1);
    pushNodeFront(&head, 1);
    pushNodeFront(&head, 2);
   // printNodes(head);

    printf("\n");
    
    printf("%d", maxList(head));

    return 0;
}
