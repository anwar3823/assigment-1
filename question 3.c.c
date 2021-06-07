/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main (int argc, char *argv[])
{
    int lines = 0;
    int words = 0;
    int character = 0;
    char* file;
    int *l = &lines;
    int *w = &words;
    int *c = &character;

    if (argc < 2) //Insufficient number of arguments given.
        printf("usage: mywc <filename1> <filename2> <filename3> ...");
    else if (argc == 2)
    {
        file = argv[1];
        if (readFile(file, l, w, c) == 1)
        {
            printf("lines=%d\t words=%d\t characters=%d\t file=%s\n",lines,words,character,file);
        }
    }
    else
    {
        //THIS PART IS NOT FINISHED. PAY NO MIND.
        //int i;
        //for(i=1; i <= argc; i++)
        //{
        //    readFile(file, lines, words, character);
        //}
    }
}

int readFile(char *file, int *lines, int *words, int *character)
{
    FILE *fp = fopen(file, "r");
    int ch;
    int space = 1;

    if(fp == 0)
    {
        printf("Could not open file\n");
        return 0;
    }

    ch = fgetc(fp);

    while(!feof(fp))
    {
        character++;
        if(ch == ' ') //If char is a space
        {
            space == 1;
        }
        else if(ch == '\n')
        {
            lines++;
            space = 1;
        }
        else
        {
            if(space == 1)
                words++;
           space = 0;
        }
        ch = fgetc(fp);
    }
    fclose(fp);
    return 1;
}
