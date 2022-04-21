#include <stdio.h>

int main(int argc, char **argv)
{
    //printf("%s \n%s", argv[2], argv[1]);
    FILE *sourceFile, *destinationFile;
    sourceFile = fopen(argv[1], "r");
    destinationFile = fopen(argv[2], "w");
    if ((sourceFile == NULL))
        printf("File doesn't exist");
    char ch = fgetc(sourceFile);
    while (ch != EOF)
    {
        fputc(ch, destinationFile);
        ch = fgetc(sourceFile);
    }
    fclose(sourceFile);
    fclose(destinationFile);
}