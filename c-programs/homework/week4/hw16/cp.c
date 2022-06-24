#include <stdio.h>
int cpy(char *, char *);
int main(int argc, char *argv[])
{
    char *fn1 = argv[1];
    char *fn2 = argv[2];

    if (cpy(fn2, fn1) == -1) {
        perror("cpy");
        return 1;
    }
    return 0;
}
int cpy(char *fnDest, char *fnSrc)
{
    FILE *fpDest, *fpSrc;
    int c;

    if ((fpDest = fopen(fnDest, "w")) && (fpSrc = fopen(fnSrc, "r"))) {
        while ((c = getc(fpSrc)) != EOF)
        putchar(fpDest);
        fclose(fpDest);
        fclose(fpSrc);

        return 0;
    }
    return -1;
}