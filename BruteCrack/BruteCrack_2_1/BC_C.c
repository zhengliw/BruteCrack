// BruteCrack 2.1
// Let's see how it goes
// Spoiler: It works fine, perfectly fine

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// The main crack function:
// passwd: Pass through an empty (char [])-type memory block with size of length
// length: Specify how long the cracked password should be
// charset: Which characters the password should contain, in form of a (char [])
// func: pass through a function accepting a (char []), this func will be executed
//       every time a password is ready
// index: Set the start index
// You can also let the generated passwords have the same starting sequence
// by pre-setting the passwd with some characters and setting the index to 
// the first '\0' character
void crack(char * passwd, int length, char * charset, void (*func) (const char *), int index);

void writetofile(const char * string);

char filename[FILENAME_MAX] = "";

int main(int argc, char **argv)
{
    char * usageText = "Usage: BC <length> <filename>";

    // Define charset
    char * charset = "ABCD";

    if(argc != 3)
    {
        puts("Either too many or too few CL args. Quitting...");
        return 1;
    }

    // Read wanted length from argv
    char * endptr;
    int length = strtol(argv[1], &endptr, 10);

    if(length > INT_MAX)
    {
        puts("Length is too big. Qutting...");
        return 1;
    }

    strncpy(filename, argv[2], FILENAME_MAX);

    // Open and close the file in w mode 
    // to clear it from last time
    FILE * tempptr = fopen(filename, "w");
    fclose(tempptr);

    char * passwd = malloc(length * sizeof(char));
    crack(passwd, length, charset, writetofile, 0);
    free(passwd);
    return 0;
}

void crack(char * passwd, int length, char * charset, void (*func) (const char *), int index)
{
    if(index < length)
    {
        for(int i = 0; i < strlen(charset); i++)
        {
            passwd[index] = charset[i];
            crack(passwd, length, charset, func, index + 1);
        }
    }
    else
    {
        func(passwd);
    }
}

void writetofile(const char * string)
{
    extern char filename[FILENAME_MAX];
    FILE * fp = fopen(filename, "a");
    fprintf(fp, "%s\n", string);
    fclose(fp);
}