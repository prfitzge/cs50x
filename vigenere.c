#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This program is an implementation of the Vegenere cipher.
//It is designed to take one argument from the command line, k, and a string from inside the program
//Upon receipt of these two elements, the program will encrypt the string using the key, k.

int main(int argc, string argv[])
{

    string key;
    int keyVal;
    int keyLen;
    int textLen;

    //verifies only two arguments were provided
    if (argc != 2)
    {
        //error checking to ensure only one argument is given at the command line
        printf("Error Message: Please provide only one argument, k, at the command line. Try again.\n");
        return 1;
    }

    //code for storing argv[1] as the key & getting the key's length
    key = (argv[1]);
    keyLen = strlen(key);

    //loop to ensure the key provided is entirely alpha characters
    for (int i = 0; i < keyLen; i++)
    {
        keyVal = key[i];
        if (!isalpha(keyVal))
        {
            //error generated because a value provided in the key is not an alpha character
            printf("Error. Please provide a key containing only alpha characters. Try again.\n");
            return 1;
        }
    }


    //get the user's message
    string str = get_string("plaintext: ");
    printf("ciphertext: ");

    //define length of message
    textLen = strlen(str);

    //loop structure to parse the user's message and encrypt it
    for (int i = 0, j = 0; i < textLen; i++, j++)
    {
        //loop will iterate over two variables, i and j, until i covers the length of the user's message
        //i is used to loop through the plaintext message
        //j is used to loop through the key until the entire message is encrypted

        //reset j to recycle the key if necessary
        if (j >= keyLen)
        {
            j = 0;
        }

        //assign keyVal based on ASCII value of str[i]
        if (isupper(key[j]))
        {
            keyVal = key[j] - 'A';
        }
        else
        {
            keyVal = key[j] - 'a';
        }

        //encryption of alpha characters in the user's message
        if (isalpha(str[i]))
        {
            if (islower(str[i]))
            {
                //encryption of lowercase letters
                str[i] = ((str[i] - 'a') + keyVal) % 26 + 'a';
            }
            else
            {
                //encryption of capital letters
                str[i] = ((str[i] - 'A') + keyVal) % 26 + 'A';
            }

            //print result of encryption
            printf("%c", str[i]);
        }

        //print non-alpha characters in the user's message
        if (!isalpha(str[i]))
        {
            printf("%c", str[i]);
            //reduce the j incrementation by one to hold current position in the key
            j--;
        }

    }

    //new line to finish program
    printf("\n");
    return 0;

}
