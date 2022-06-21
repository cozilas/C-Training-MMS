#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node* next;
};

void insertAtFront(struct node**,int);
void viewList(struct node**);
void viewListFrom(struct node*);
struct node* insertafter(struct node*,int,int);
void freeMemory(struct node** last);

int main()
{
    int input,n;
    struct node* last = NULL;
    struct node* temp = NULL;

scanf("%d",&n);
   for(int i = 0;i<n;i++){
       scanf("%d",&input);
       insertAtFront(&last,input);
    }
    viewListFrom(last);
	insertafter(last,10,9);
    freeMemory(&last);
    viewListFrom(last);
	return 0;
}



void insertAtFront(struct node** last,int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	if ((*last) == NULL) {
		temp->info = data;
		temp->next = temp;
		(*last) = temp;
	}
	else {
		temp->info = data;
		temp->next = (*last)->next;
		(*last)->next = temp;
	}
}

void viewList(struct node** last)
{
	if ((*last) == NULL)
		printf("\nList is empty\n");
	else {
		struct node* temp;
		temp = (*last)->next;
		do {
			printf("%d ", temp->info);
			temp = temp->next;
		} while (temp != (*last)->next);
			putchar('\n');
	}
}
void viewListFrom(struct node* last)
{
	if (last == NULL)
		printf("\nList is empty\n");
	else {
		struct node* temp;
		temp = last->next;
		do {
			printf("%d ", temp->info);
			temp = temp->next;
		} while (temp != last->next);
		putchar('\n');
	}
}
struct node* insertafter(struct node* last,int skipCount,int data)
{
    for(int i = 0;i<skipCount;i++){
        last = last->next;
    }
    struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
    
    temp ->next  = last->next;
    last->next = temp;
	temp->info = data;

    return temp;
}
void freeMemory(struct node** last)
{
    int pos, i = 1;
    struct node *temp, *position,*first;

    temp = (*last)->next;
	position = temp;
    if (last == NULL)
        printf("\nList is empty.\n");
    else {		
        while (1) {

			position = temp->next;
            temp->next = position->next;		
            i++;
			if(position == temp)break;

        free(position);	
   		
		}
		(*last) =NULL;
    }
}