#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This program is an implementation of the Caesar cipher.
//It is designed to take one argument from the command line, k, and a string from inside the program
//Upon receipt of these two elements, the program will encrypt the string using the key, k.

int main(int argc, string argv[])
{
    int k;
    //need to check if
    if (argc == 2)
    {
        //code for storing argv[1] as the key, k
        k = atoi(argv[1]);
    }
    else
    {
        //error checking to ensure only one argument is given at the command line
        printf("Error Message: Please provide only one argument, k, at the command line. Try again.\n");
        return 1;
    }
    //get the user's message
    string str = get_string("Message to encrypt: ");
    printf("ciphertext: ");

    //loop structure to parse the user's message and encrypt
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        //encrypting message
        if (isalpha(str[i]))
        {
            if islower(str[i])
            {
                //print lowercase letters
                str[i] = ((str[i] - 'a') + k) % 26 + 'a';
                printf("%c", str[i]);
            }
            else
            {
                //print capital letters
                str[i] = ((str[i] - 'A') + k) % 26 + 'A';
                printf("%c", str[i]);
            }
        }
        else
        {
            //print non-alpha characters from str
            printf("%c", str[i]);
        }
    }

    //new line to finish program
    printf("\n");

}