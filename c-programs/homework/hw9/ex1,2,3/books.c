#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define COUNT 10

typedef int (*comparef_t)(const void *, const void *);

typedef struct Book
{
    char title[151];
    char author[101];
    unsigned pages;
    double price;
} Book;

int randint(int, int);
double randReal(double, double);
char *randomName(char *);
void printBook(const Book *);
void printBooks(const Book *books);

int compAuthorASC(const void *, const void *);
int compAuthorDESC(const void *, const void *);
int compTitleASC(const void *, const void *);
int compTitleDESC(const void *, const void *);
int compPagesASC(const void *, const void *);
int compPagesDESC(const void *, const void *);
int compPriceASC(const void *, const void *);
int compPriceDESC(const void *, const void *);

void *linearSearch(const void *, const void *, size_t, size_t, int (*)(const void *, const void *));
void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));

comparef_t chooseFunction(int i, comparef_t *functions);

int main()
{
    srand(time(NULL));

    comparef_t compfunc[] = {
        compAuthorASC,
        compAuthorDESC,
        compPagesASC,
        compPagesDESC,
        compPriceASC,
        compPriceDESC,
        compPriceASC,
        compPriceDESC};
    Book books[COUNT];
    for (int i = 0; i < COUNT; i++)
    {
        randomName(books[i].author);
        randomName(books[i].title);
        books[i].pages = randint(5, 10);
        books[i].price = randReal(1.0, 2.0);
    }
    int opt;
    printf("Menu: 1 for.. 2 for....9 for exit");
    while (opt != 9)
    {
        scanf("%d", &opt);
        if (opt == 1)
        {
            qsort(books, COUNT, sizeof(books[0]), compfunc[0]);
        }
        else if (opt == 2)
        {
            qsort(books, COUNT, sizeof(books[0]), compfunc[1]);
        }
                else if (opt == 3)
        {
            qsort(books, COUNT, sizeof(books[0]), compfunc[2]);
        }
    }

    // qsort(books, COUNT, sizeof(books[0]), compfunc[opt]);
    printBooks(books);

    //   qsort(books, COUNT, sizeof(books[0]), compPagesASC);

    /*   Book key = {.author="Vazov", .price=8, .pages=8, .title="Pod igoto"};

      Book *element = linearSearch(&key, books, COUNT,  sizeof(*books), compPagesASC);
      if (!element){
          printf("Not found!\n");
      } else {
          printBook(element);
      }
   */
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

int compAuthorASC(const void *bp1, const void *bp2)
{
    Book *b1 = (Book *)bp1;
    Book *b2 = (Book *)bp2;
    return strcmp(b1->author, b2->author);
}

int compAuthorDESC(const void *bp1, const void *bp2)
{
    Book *b1 = (Book *)bp1;
    Book *b2 = (Book *)bp2;
    return strcmp(b2->author, b1->author);
}

int compTitleASC(const void *bp1, const void *bp2)
{
    Book *b1 = (Book *)bp1;
    Book *b2 = (Book *)bp2;
    return strcmp(b1->title, b2->title);
}

int compTitleDESC(const void *bp1, const void *bp2)
{
    Book *b1 = (Book *)bp1;
    Book *b2 = (Book *)bp2;
    return strcmp(b2->title, b1->title);
}

int compPagesASC(const void *bp1, const void *bp2)
{
    Book *b1 = (Book *)bp1;
    Book *b2 = (Book *)bp2;
    return b1->pages - b2->pages;
}

int compPagesDESC(const void *bp1, const void *bp2)
{
    Book *b1 = (Book *)bp1;
    Book *b2 = (Book *)bp2;
    return b2->pages - b1->pages;
}

int compPriceASC(const void *bp1, const void *bp2)
{
    Book *b1 = (Book *)bp1;
    Book *b2 = (Book *)bp2;
    if (fabs(b1->price - b2->price) < 0.001)
    {
        return 0;
    }
    else if (b1->price > b2->price)
    {
        return 1;
    }
    return -1;
}

int compPriceDESC(const void *bp1, const void *bp2)
{
    Book *b1 = (Book *)bp1;
    Book *b2 = (Book *)bp2;
    if (fabs(b1->price - b2->price) < 0.001)
    {
        return 0;
    }
    else if (b1->price < b2->price)
    {
        return 1;
    }
    return -1;
}

void *linearSearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
{
    for (int i = 0; i < nitems; i++)
    {
        if (compar(key, base + i * size) == 0)
        {
            return base + i * size;
        }
    }
    return NULL;
}
void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
{
	int lim, cmp;
	const void *p;

	for (lim = nitems; lim != 0; lim >>= 1) {
		p = base + (lim >> 1) * size;
		cmp = (*compar)(key, p);
		if (cmp == 0)
			return (void *)p;
		if (cmp > 0) {	/* key > p: move right */
			base = (const char *)p + size;
			lim--;
		} /* else move left */
	}
	return (NULL);
}
comparef_t chooseFunction(int i, comparef_t *functions)
{
    return *(functions + i);
}