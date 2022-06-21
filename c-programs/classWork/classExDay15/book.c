#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#pragma warning(disable : 4996)

typedef struct Book
{
    char title[151];
    char author[101];
    unsigned pages;
    double price;
} Book;

#define COUNT 10

int randint(int, int);
double randReal(double, double);
char *randomName(char *);
void printBook(const Book *);
void printBooks(const Book *books);

int main(int argc,char* argv[])
{
    // srand(time(NULL));
    printf("%s\n",argv[1]);
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
        printf("file with this name not found");
        return 1;
    }
    for (int i = 0; i < COUNT; i++)
    {
        sprintf(buffer_out, "%25s %25s %4u %6.2lf\n", books[i].author, books[i].title, books[i].pages,books[i].price);
        fwrite(buffer_out, sizeof(char), strlen(buffer_out), fp);
    }
    pclose(fp);

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
