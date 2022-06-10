#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define COUNT 10

typedef struct
{
    char title[24];
    char author[24];
    int pageNum;
    double price;
} book;

char *firstAndSecond(char *name);
int randint(int min, int max);
double randReal(double min, double max);
char *firstName(char *name);

int compAuthor(void *book1p, void *book2p);
int compTitle(void *book1p, void *book2p);
int compPageNum(void *book1p, void *book2p);
int compPrice(void *book1p, void *book2p);
void linearSearch(book *, double);
int binarySearch(book *arr, int size, int key);

int main()
{
    srand(time(NULL));

    book books[COUNT];

    for (int i = 0; i < COUNT; i++)
    {
        firstName(books[i].title);
        firstAndSecond(books[i].author);
        books[i].pageNum = randint(5, 2000);
        books[i].price = randReal(5.0, 1000.0);

        printf("%20s %30s %5d %7.2lf\n", books[i].title, books[i].author, books[i].pageNum, books[i].price);
    }
    printf("\n");
    qsort(books, COUNT, sizeof(*books), compTitle);
    qsort(books, COUNT, sizeof(*books), compAuthor);
    qsort(books, COUNT, sizeof(*books), compPrice);
    qsort(books, COUNT, sizeof(*books), compPageNum);

        linearSearch(books, 20.50f);
    for (int i = 0; i < COUNT; i++)
    {
        printf("%20s %30s %5d %7.2lf\n", books[i].author, books[i].title, books[i].pageNum, books[i].price);
    }
    binarySearch(books, COUNT, 5);


}
int binarySearch(book *arr, int size, int key)
{
    int mid, low, high;
    size = COUNT;
    low = 1;
    high = size;
    mid = (low + high) / 2;
    int i = 0;

    while (key != arr[mid].pageNum)
    {
        i++;
        if (i == size)
        {
            return -1;
        }
        if (key <= arr[mid].pageNum)
        {
            low = 1;
            high = mid + 1;
            mid = (low + high) / 2;
        }
        else
        {
            low = mid + 1;
            high = size;
            mid = (low + high) / 2;
        }
    }

    return arr[mid].pageNum;
    printf("%d\n", key);
    return key;
}

void linearSearch(book *books, double searchingPrice)
{
    for (int i = 0; i < COUNT; i++)
    {
        if (books[i].price - searchingPrice < 0.002)
        {
            printf("%s", books[i].title);
            return;
        }
    }
    printf("\nno book found with this price\n");
}

int compAuthor(void *book1p, void *book2p)
{
    book b1 = *((book *)book1p);
    book b2 = *((book *)book2p);
    return strcmp(b1.author, b2.author);
}
int compTitle(void *book1p, void *book2p)
{
    book b1 = *((book *)book1p);
    book b2 = *((book *)book2p);
    return strcmp(b1.title, b2.title);
}
int compPageNum(void *book1p, void *book2p)
{
    book b1 = *((book *)book1p);
    book b2 = *((book *)book2p);
    return b1.pageNum - b2.pageNum;
}
int compPrice(void *book1p, void *book2p)
{
    book b1 = *((book *)book1p);
    book b2 = *((book *)book2p);

    if (fabs(b1.price - b2.price) < 000.2f)
    {
        return 0;
    }
    else if (b1.price < b2.price)
    {
        return -1;
    }
    return 1;
}

char *firstAndSecond(char *name)
{

    *name = randint('A', 'Z');
    int r = randint(5, 10);
    for (int i = 1; i < r; i++)
    {
        name[i] = randint('a', 'z');
    }
    name[r] = ' ';
    r++;
    name[r] = randint('A', 'Z');
    r++;
    int j = r;
    r += randint(5, 10);

    for (int i = j; i < r; i++)
    {
        name[i] = randint('a', 'z');
    }
    name[r] = '\0';
    return name;
}
char *firstName(char *name)
{
    *name = randint('A', 'Z');
    int r = randint(5, 10);
    for (int i = 1; i < r; i++)
    {
        name[i] = randint('a', 'z');
    }
    name[r] = '\0';
    return name;
}

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}