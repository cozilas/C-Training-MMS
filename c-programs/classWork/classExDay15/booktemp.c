#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct Book
{
    char title[151];
    char author[1010];
    unsigned pages;
    double price;
} Book;

typedef struct node
{
    Book book;
    struct node *next;
} node_t;

#define COUNT 5

int randint(int, int);
double randReal(double, double);
char *randomName(char *);
void printBook(const Book *);
void printBooks(const Book *books);

void push(node_t **list, Book book);
void print_list(node_t *list);

int compModelASC(const void *bp1, const void *bp2);
int compPagesASC(const void *bp1, const void *bp2);

int main(int argc, char *argv[])
{
    // srand(time(NULL));
    printf("%s\n", argv[1]);
    Book books[COUNT];

    for (int i = 0; i < COUNT; i++)
    {
        randomName(books[i].author);
        randomName(books[i].title);
        books[i].pages = randint(5, 2000);
        books[i].price = randReal(1.0, 1000.0);
    }

    FILE *fp;
    char buffer_out[256];

    fp = fopen(argv[1], "wb");
    if (fp == NULL)
    {
        fprintf(stderr, "file with this name not found");
        return 1;
    }

    for (int i = 0; i < COUNT; i++)
    {

        sprintf(buffer_out, "%25s;%25s;%6u;%8.2lf\n", books[i].author, books[i].title, books[i].pages, books[i].price);
        fwrite(buffer_out, sizeof(char), strlen(buffer_out), fp);
        printf("%s", buffer_out);
    }
    fclose(fp);

    fp = fopen(argv[1], "r");

    //    fgets(buffer_out, 1000, fp);
    // sscanf(buffer_out, "%25s %25s %4u %6.2lf\n", &book.author,&book.title,&book.pages,&book.price );
    //   printf("%s",buffer_out);

    node_t *ll = NULL;

    printf("\n");
    Book book;
    while (fgetc(fp) != EOF)
    {
        fgets(buffer_out, 1000, fp);
        sscanf(buffer_out, "%[a-zA-Z ];%[a-zA-Z ];%6u;%8lf\n", book.author, book.title, &book.pages, &book.price);
        printf("%25s;%25s;%6u;%8.2lf\n", book.author, book.title, book.pages, book.price);

        push(&ll, book);
    }
    printf("\n");
    // print_list(ll);

    qsort(books, COUNT, sizeof(books[0]), compPagesASC);
    print_list(ll);

    FILE *fpo;
    char buffer_out2[256];

    fpo = fopen("output", "w");
    if (fpo == NULL)
    {
        fprintf(stderr, "file with this name not found");
        return 1;
    }
    node_t *llo = ll;
    for (int i = 0; i < COUNT; i++)
    {

        sprintf(buffer_out2, "%25s;%25s;%6u;%8.2lf\n", llo->book.author, llo->book.title, llo->book.pages, llo->book.price);
        fwrite(buffer_out2, sizeof(char), strlen(buffer_out2), fpo);
        printf("%s", buffer_out2);
        llo = llo->next;
    }
    fclose(fp);
    return 0;
}
int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

char *randomName(char *name)
{
    // [A-Z][a-z]{5,10} [A-Z][a-z]{5,10}
    // Stanislav Ivanov
    unsigned index = 0;
    name[index++] = randint('A', 'Z');
    int n = randint(5, 10);
    for (int i = 0; i < n; i++)
    {
        name[index++] = randint('a', 'z');
    }
    name[index++] = ' ';
    n = randint(5, 10);
    name[index++] = randint('A', 'Z');
    for (int i = 0; i < n; i++)
    {
        name[index++] = randint('a', 'z');
    }
    name[index] = '\0';
    return name;
}

void printBook(const Book *b)
{
    printf("Title: %25s ", b->title);
    printf("Author: %25s ", b->author);
    printf("Pages: %4u ", b->pages);
    printf("Price: %4.2lf\n", b->price);
}

void printBooks(const Book *books)
{
    for (int i = 0; i < COUNT; i++)
    {
        printBook(books + i);
    }
}

void push(node_t **list, Book book)
{
    node_t *n = malloc(sizeof(node_t));
    strcpy(n->book.author, book.author);
    strcpy(n->book.title, book.title);

    n->book.pages = book.pages;
    n->book.price = book.price;
    n->next = *list;

    *list = n;
}
void print_list(node_t *list)
{
    node_t *current = list;
    while (current)
    {
        printf("%25s;%25s;%6u;%8.2lf\n", current->book.author, current->book.title, current->book.pages, current->book.price);
        current = current->next;
    }
    putchar('\n');
}
int compModelASC(const void *bp1, const void *bp2)
{
    Book *b1 = (Book *)bp1;
    Book *b2 = (Book *)bp2;
    return strcmp(b1->title, b2->title);
}
int compPagesASC(const void *bp1, const void *bp2)
{
    Book *b1 = (Book *)bp1;
    Book *b2 = (Book *)bp2;

    printf("%d %d\n", b1->pages, b2->pages);
    return b2->pages - b1->pages;
}