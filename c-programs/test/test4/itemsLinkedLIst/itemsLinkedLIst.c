#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdint.h>

#define COUNT 10

typedef struct item_t
{
    uint16_t itemId;
    char discription[251];
    double weight;
    double price;
} item_t;

typedef struct node_t
{
    item_t item;
    struct node_t *next;
} node_t;

int randInt(int, int);
double randReal(double, double);
void generateSentence(char *);
void push(node_t **, item_t);
void print_list(node_t *);
double totalItemsWeight(node_t *);
node_t *minPriceItem(node_t *);
int main()
{
    srand(time(NULL));
    uint16_t itemIds = 0;
    item_t item;
    node_t *ll;
    ll = NULL;
    for (int i = 0; i < COUNT; i++)
    {
        generateSentence(item.discription);
        item.itemId = itemIds++;
        item.weight = randReal(0.100, 100.00);
        item.price = randReal(1.00, 1500.00);
        push(&ll, item);
    }
    print_list(ll);
    printf("                                                                                                         -------------------\n");
    printf("                                                                                                         weight sum = %.2lf\n", totalItemsWeight(ll));
    printf("                                                                                                     cheapest price = %.2lf\n", minPriceItem(ll)->item.price);

    return 0;
}

int randInt(int min, int max)
{
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}
void generateSentence(char *str)
{
    int wordCount = randInt(5, 10);
    int curr = 0;
    str[curr++] = randInt('A', 'Z');
    for (int i = 0; i < wordCount; i++)
    {
        int wordLength = randInt(1, 10) + curr;

        for (int j = curr; j < wordLength; j++)
        {
            str[j] = randInt('a', 'z');
            curr++;
        }
        str[curr++] = ' ';
    }
    str[curr++] = '\0';
}
void push(node_t **list, item_t data)
{
    node_t *n = malloc(sizeof(node_t));
    strcpy(n->item.discription, data.discription);
    n->item.weight = data.weight;
    n->item.price = data.price;
    n->item.itemId = data.itemId;

    n->next = *list;
    *list = n;
}
void print_list(node_t *list)
{
    if (!list)
    {
        return;
    }
    printf("%99s ", "Description");
    printf("%6s ", " number");
    printf("%8s ", " weight");
    printf("%8s ", " price");

    putchar('\n');
    node_t *current = list;

    while (current)
    {
        printf("%100s ", current->item.discription);
        printf("%6hu ", current->item.itemId);
        printf("%8.2lf ", current->item.weight);
        printf("%8.2lf ", current->item.price);
        current = current->next;
        putchar('\n');
    }
}
double totalItemsWeight(node_t *list)
{
    if (!list)
    {
        return -1;
    }
    node_t *current = list;
    int sum = 0;
    while (current)
    {
        sum += current->item.weight;
        current = current->next;
    }
    return sum;
}
node_t *minPriceItem(node_t *list)
{
    if (!list)
    {
        return NULL;
    }
    node_t *current = list;
    node_t *cheapestNode = list;

    while (current)
    {
        if (current->item.price < cheapestNode->item.price)
        {
            cheapestNode = current;
        }
        current = current->next;
    }
    return cheapestNode;
}