#include <stdio.h>

int main(int argc, char **argv)
{
    int count = argc;
    //printf("%d\n", count);

    for (int i = 1; i <= count; i++)
    {
        FILE *inputFile;
        inputFile = fopen(argv[i], "r");

        if ((inputFile == NULL))
            printf("%s File doesn't exist\n", argv[i]);
        else
        {
            //printf("\n\n%s:\n", argv[i]);
            char ch = fgetc(inputFile);
            while (ch != EOF)
            {
                printf("%c", ch);
                ch = fgetc(inputFile);
            }
        }
        fclose(inputFile);
    }
}