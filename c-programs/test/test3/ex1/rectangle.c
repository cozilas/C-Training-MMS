#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNT 10

typedef struct rectangle_t
{
    double pointA;
    double pointB;
} rectangle_t;
typedef struct node_t
{
    rectangle_t rectangle;
    struct node *next;
} node_t;

void print_list(node_t *);
void push(node_t **, rectangle_t);
double randReal(double, double);
double areaRects(node_t *);
void filterrects(node_t **, double, double);

int main()
{
    srand(time(NULL));
    rectangle_t rec;
    node_t *ll;

    for (int i = 0; i < COUNT; i++)
    {
        rec.pointA = randReal(-10.0, 10.0);
        rec.pointB = randReal(-10.0, 10.0);
        push(&ll, rec);
    }
    print_list(ll);
    areaRects(ll);
    filterrects(&ll, -1880, 0);
    printf("\n");
    areaRects(ll);
}
void print_list(node_t *list)
{
    node_t *current = list;
    while (current)
    {
        printf("%lf ", current->rectangle.pointA);
        printf("%lf ", current->rectangle.pointB);
        current = current->next;
        putchar(',');
    }
    putchar('\n');
}

void push(node_t **list, rectangle_t data)
{
    node_t *n = malloc(sizeof(node_t));
    n->rectangle.pointA = data.pointA;
    n->rectangle.pointB = data.pointB;
    n->next = *list;
    *list = n;
}
double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

double areaRects(node_t *list)
{
    node_t *curr = list;
    double area = 0;
    while (curr != NULL)
    {
        area = curr->rectangle.pointA * curr->rectangle.pointB;
        printf("%.2lf ", area);
        curr = curr->next;
    }
    return area;
}

void filterrects(node_t **head, double min, double max)
{

    double area = 0;
    while (*head)
    {
        area = (*head)->rectangle.pointA * (*head)->rectangle.pointB;
        if (min < area && max > area)
        {
            node_t *temp = *head;
            *head = (*head)->next;
            free(temp);
        }
        else
        {
            head = &(*head)->next;
        }
    }
}