#include <cs50.h>
#include <stdio.h>

//program designed to print side-by-side pyramids that are a user-specified height
int main(void)
{
    //prompt user for a postive integer
    int n;

    do
    {
        n = get_int("Pyramid Height: ");
    }
    while ((n < 0) || (n > 23) );

    //loop to print out the pyramid
    //print the correct number of rows
    for (int i = 0; i < n; i++)
    {

        //print the correct number of columns
        //print the pyramid left side
        for (int j = 0; j < n; j++)
        {
            //print
            if (j < (n -1 - i))
            {
                printf(" ");
            } else
            {
                printf("#");
            }
        }

        //pyramid gap
        printf("  ");

        //print the pyramid right side
        for(int j = 0; j < n; j++)
        {
            //print
            if (j <= i)
            {
                printf("#");
            }
        }
    printf("\n");
    }
}