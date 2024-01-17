// https://cs50.harvard.edu/x/2023/problems/3/temps/
// Practice applying sorting algorithms: Selection Sort, Bubble Sort and Merge Sort
// Some cities with the same temperature are sorted differently, it doesn't matter.
#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// Bubble Sort
void sort_cities(void)
{
    avg_temp min;
    for (int i = 0;  i < (NUM_CITIES - 1); i++)
    {
        for (int j = 0; j < (NUM_CITIES - i - 1); j++)
        {
            if (temps[j].temp < temps[j+1].temp)
            {
                min = temps[j];
                temps[j] = temps[j+1];
                temps[j+1] = min;
            }
        }
    }
}


/*
// Selection Sort
void sort_cities(void)
{
    int max, index;
    avg_temp memory;
    for (int i = 0;  i < NUM_CITIES; i++)
    {
        max = temps[i].temp;
        index = i;
        for (int j = i; j < (NUM_CITIES - 1); j++)
        {
            if (max < temps[j+1].temp)
            {
                max = temps[j+1].temp;
                index = j+1;
            }
        }
        memory = temps[index];
        temps[index] = temps[i];
        temps[i] = memory;
    }
}
*/