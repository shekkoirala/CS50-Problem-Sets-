#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

void PrintCiphertext(string, int);
void PrintCharacter(char, int, int);

int main(int argc, char* const argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar NUMBER (A number between 1 and 25)\n");
        return 1;
    }

    int key = atoi(argv[1]);
    if (key > 26)
    {
        key %= 26;
    }

    string plaintext = GetString();
    PrintCiphertext(plaintext, key);

    return 0;
}

/* PrintCiphertext
 * ---------------
 *  prints the encrypted version of the plaintext
 *
 *  input: the string to be encrypted
 *  key: the cipher key to be used to rotate the characters
 *
 *  prints the encrypted string
*/
void PrintCiphertext(string input, int key)
{
    int i = 0;
    char character;

    while(input[i])
    {
        character = input[i];
        if(isalpha(character))
        {
            if islower(character)
            { // 3rd argument is the upper bound
                PrintCharacter(character, key, 122);
            }
            if isupper(character)
            {
                PrintCharacter(character, key, 90);
            }
        }
        else
        {
            printf("%c", character);
        }
        i++;
    }
    printf("\n");
}

/* PrintCharacter
 * --------------
 *  helper function for PrintCiphertext
 *
 *  letter: the letter to be encrypted
 *  key: the cipher key to use to encrypt the character
 *  boundary: the ascii upper bound
 *
 *  prints the encrypted character
*/
void PrintCharacter(char letter, int key, int boundary)
{
    if (letter+key > boundary)
    { // wraparound
        printf("%c", letter+key - 26);
    }
    else
    { // straight case
        printf("%c", letter+key);
    }
}