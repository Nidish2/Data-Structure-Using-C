#include <stdio.h>
#include <string.h>

struct record
{
    int id, flag;
    char name[20];
} ht[10];

int hash(int key)
{
    int slots = 10;
    return key % slots;
}

int main()
{
    FILE *in;
    int i, j, k, n, id, location;
    char name[20];

    printf("Enter the no. of records, less than 10\n");
    scanf("%d", &n);

    if (n <= 10)
    {
        in = fopen("5.1.1-input.txt", "r");

        if (in != NULL)
        {
            for (k = 0; k < 10; k++)    //Initialisation;
            {
                ht[k].flag = 0;
            }

            for (i = 0; i < n; i++)
            {
                fscanf(in, "%d %s", &id, name);     //Copying the data from the file;
                location = hash(id);        //hash function

                if (ht[location].flag == 0)     // we can store the data, space is available ;
                {
                    printf("The address of %d is %d\n", i + 1, location);
                    ht[location].flag = 1;
                    ht[location].id = id;
                    strcpy(ht[location].name, name);
                }
                else        //data already been stored;
                {
                    printf("Collision detected\n");

                    for (j = location + 1; j != location; j = (j + 1) % 10)     //Linear probing;
                    {
                        if (ht[j].flag == 0)        // we can store the data, space is available; 
                        {
                            printf("The address of %d records is %d\n", i + 1, j);
                            ht[j].flag = 1;
                            ht[j].id = id;
                            strcpy(ht[j].name, name);
                            break;
                        }
                    }
                }
            }

            fclose(in);

            printf("The hash table contents are \n");

            for (k = 0; k < n; k++)
            {
                if (ht[k].flag == 0)
                {
                    printf("%d -##\n", k);     //space is available 
                }
                else
                {
                    printf("%d\t%s\n", ht[k].id, ht[k].name);
                }
            }
        }
        else
        {
            printf("File not found!\n");
        }
    }
    else
    {
        printf("Invalid input: Number of records should be less than or equal to 10.\n");
    }

    return 0;
}