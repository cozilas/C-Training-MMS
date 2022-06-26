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
    char discription[256];
    double weight;
    double price;
} item_t;

typedef struct node_t
{
    item_t item;
    struct node_t *next;
} node_t;

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
        //printf("%lf %lf \n",current->item.price,cheapestNode->item.price);
        if (current->item.price < cheapestNode->item.price)
        {
            cheapestNode = current;
        }
        current = current->next;
    }
    return cheapestNode;
}
int main()
{
    srand(time(NULL));
    uint16_t itemIds = 0;
    item_t items[COUNT];
    for (int i = 0; i < COUNT; i++)
    {
        generateSentence(items[i].discription);
        items[i].itemId = itemIds++;
        items[i].weight = randReal(0.100, 100.00);
        items[i].price = randReal(1.00, 1500.00);
    }
    node_t *ll;
    ll = NULL;

    push(&ll, items[0]);
    push(&ll, items[1]);
    push(&ll, items[2]);
    push(&ll, items[3]);
    push(&ll, items[4]);
    push(&ll, items[5]);
    push(&ll, items[6]);
    push(&ll, items[7]);
    push(&ll, items[8]);
    push(&ll, items[9]);

    print_list(ll);
    printf("weight sum = %.2lf\n", totalItemsWeight(ll));
    printf("cheapest price = %lf\n", minPriceItem(ll)->item.price);

    return 0;
}