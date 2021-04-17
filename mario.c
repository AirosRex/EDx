#include <cs50.h>
#include <stdio.h>

int get_pos_int(void);
int main(void)
{
    int height = get_pos_int();
    int blocks = 1;
    
    while (height >0)
    {
        //Empty Space
        for (int x=height-1;x>0;x--)
            {
             printf(" ");
            }

        //First blocks
        for (int y=blocks;y > 0;y--)
                {
                printf("X");
                 }

         // Mind the gap
         printf(" ");

         // Second set of blocks
         for (int y=blocks;y>0;y--)
                {
                printf("X");
                 }

            printf("\n");
            height--;
            blocks++;
    }
}

  // Makes sure a positive number is given
int get_pos_int(void)
{
    int n;
    do
    {
        n = get_int("Positive Integer: ");
    }
    while (n<1);
    return n;
}
