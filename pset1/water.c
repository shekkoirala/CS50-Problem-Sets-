#include <stdio.h>
#include <cs50.h>

int GetBottles(int minutes)
{
    int bottles;
    bottles = ((1.5 * 128) / 16) * minutes;
    return bottles;
}

int main(void)
{
    printf("minutes: ");
    int minutes = GetInt();
    printf("bottles: %d\n", GetBottles(minutes));
}