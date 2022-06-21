#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;
void print_list(node_t* list){
    node_t* current = list;
    while (current){
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

void push(node_t** list, int data){
    node_t* n = malloc(sizeof(node_t));
    n->data = data;
    n->next = *list;
    *list = n;
}
int digitSum(int a){
    int temp = a;
    int remainder;
    int sum=0;
    while(temp !=0){
        remainder = temp%10;
        sum +=remainder;
        temp /= 10;
    }
    return sum;

}
int cmp(int a, int b)
{
    a = digitSum(a);
    b = digitSum(b);

  //  printf ("%d , %d / ",a,b);

return b-a;
}
int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}
int countEvenNumbers(node_t *head)
{
    node_t *current = head;
    int countEven = 0;
    while (current)
    {
        if (current->data % 2 == 0)
        {
            countEven++;
        }
        current = current->next;
    }
    return countEven;
}
void frontBackSplit(node_t* list, node_t** front, node_t** back){
    node_t* slow = list;
    node_t* fast = list->next;
    while (fast != NULL){
        fast = fast->next;
        if (fast  != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = list;
    *back = slow->next;
    slow->next = NULL;
}
node_t* sortedMerge(node_t* listA, node_t* listB, int(*cmp)(int, int)){
    node_t* sorted = NULL;
    if (listA == NULL){
        return listB;
    }
    if (listB == NULL){
        return listA;
    }
    if (cmp(listA->data, listB->data) > 0){
        sorted = listA;
        sorted->next = sortedMerge(listA->next, listB, cmp);
    } else {
        sorted = listB;
        sorted->next = sortedMerge(listA, listB->next, cmp);
    }
    return sorted;
}
void mergeSort(node_t** list, int(*cmp)(int, int)){
    if (*list == NULL || (*list)->next == NULL){
        return;
    }
    node_t *front = NULL, *back = NULL;
    frontBackSplit(*list, &front, &back);
    mergeSort(&front, cmp);
    mergeSort(&back, cmp);
    *list = sortedMerge(front, back, cmp);
}
void listFree(node_t** list){
    node_t *current = *list, *prev;
    while (current){
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}
int main(void)
{
    /*node_t* head1 = NULL;
    push(&head1, 100);
    push(&head1, 50);
    push(&head1, 20);
    push(&head1, 10);
    putchar('\n');
    node_t* head2 = NULL;
    push(&head2, 95);
    push(&head2, 45);
    push(&head2, 4);
    push(&head2, -35);
    node_t* sorted = sortedMerge(head1, head2, cmp);
    print_list(sorted);
    node_t* A = NULL, *B = NULL;
    frontBackSplit(sorted, &A, &B);
    print_list(A);
    print_list(B);
    */
    srand(time(NULL));
    node_t *ll = NULL;

    for (int i = 0; i < 10; i++)
    {
        push(&ll, randint(0, 100));
    }
    printf("%d\n", countEvenNumbers(ll));
        print_list(ll);



    mergeSort(&ll, cmp);
    print_list(ll);

    listFree(&ll);
    return 0;
}