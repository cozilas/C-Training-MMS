#include <stdio.h>
#include <pthread.h>
#include <string.h>
char fileName[100] ;
int cmpfunc(const void *, const void *);
void sortRow(void *);

/*
4 2
ROW 1 5 4 3 2 1
ROW 3 2 1 2 2 1
ROW 1 5 4 3 2 1
ROW 3 2 1 2 2 1
file
 */


int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    pthread_t threadArr[N];
    char row[N][100];
    int rowNum;
    int c;
    /*
        for(int i =0;i<M;i++){
            scanf("%d",&arr[i]);
        } */
    for (int i = 0; i < N; i++)
    {
        scanf("\n%[^\n]s", row[i]);
    }

    scanf("%s", fileName);
    for (int i = 0; i < N; i++)
    {
        // printf("%s\n",row[i]);
        pthread_create(&threadArr[i], NULL, &sortRow, (void *)(row[i]));
    }
    for (int i = 0; i < N; i++)
    {
        pthread_join(threadArr[i], NULL);
    }
}


int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
void sortRow(void *argp)
{
   // printf("%s",fileName);
    char *row = (char *)argp;

    printf("%s\n", row);
    char *piece = strtok(row, " ");
    // piece = strtok(row," ");
    int rowNum = 0;
    int i = 0;
    int arr[10000];
    char num[100];
    char str[10000] = "ROW ";

    while (piece != NULL)
    {
        //  printf("%s\n", piece);
        if (i == 1)
        {
            rowNum = atoi(piece);
        }
        else if (i > 1)
        {
            arr[i - 2] = atoi(piece);
        }
        piece = strtok(NULL, " ");
        i++;
    }
    sprintf(num, "%d", rowNum);
    strcat(str, num);
    qsort(arr, i - 2, sizeof(int), cmpfunc);
    for (int j = 0; j < i - 2; j++)
    {
        // printf("%d ",arr[j]);
        strcat(str, " ");
        sprintf(num, "%d", arr[j]);
        strcat(str, num);
    }
    strcat(str, "\n");
    //printf("%s", str);
    FILE *fp;
    fp = fopen(fileName, "a");
    int strIndex = 0;
    fwrite(str, 1, strlen(str), fp);
}