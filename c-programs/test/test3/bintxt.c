#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
int main(int argc, char *argv[])
{
    if(argc!=4){
         fprintf(stderr, "wrong arguments");
            return 1;
    }else if (!strcmp(argv[3], "-TB"))
    {
        FILE *fr = fopen(argv[1], "r");
        FILE *fw = fopen(argv[2], "wb");

        if (fr == NULL)
        {
            fprintf(stderr, "cant read");
            return 1;
        }
        uint16_t num;
        while (fscanf(fr, "%hd", &num) != EOF)
        {
            //printf("%d\n", num);
            fwrite(&num, sizeof(num), 1, fw);
        }
        fclose(fw);
        fclose(fr);
        printf("writing successful tb\n");
 
      //  printf("%s %s %s", argv[1], argv[2], argv[3]);
    }
    else if (!strcmp(argv[3], "-BT"))
    {
        FILE *fr = fopen(argv[1], "rb");
        FILE *fw = fopen(argv[2], "w");

        if (fr == NULL)
        {
            fprintf(stderr, "cant read");
            return 1;
        }
        uint16_t num;
        while (fread(&num,sizeof(num),1,fr ))
        {
            fprintf(fw, "%hd\n",num);
        }
        fclose(fw);
        fclose(fr); 
        printf("writing successful\n");
     //   printf("%s %s %s", argv[1], argv[2], argv[3]);
    } else{
        fprintf(stderr,"invalid input");
        return 1;
    }
    return 0;
}