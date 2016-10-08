#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool KeyIsValid(string);
void PrintCiphertext(string, string);
string MakeLowerCase(string);
void PrintCharacter(char, int, int);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere KEYWORD\n");
        return 1;
    }

    string key = argv[1];

    if (!KeyIsValid(key))
    {
        printf("Keyword must be alphabetical characters only. \n");
        return 1;
    }

    string plaintext = GetString();
    PrintCiphertext(plaintext, key);

    return 0;
}

bool KeyIsValid(string keyword)
{
    int i = 0;
    while(keyword[i])
    {
        if (!isalpha(keyword[i]))
        {
            return false;
        }
        i++;
    }
    return true;
}

/* PrintCiphertext
 * ---------------
 *  prints the encrypted version of the plaintext
 *
 *  input: the plaintext to be encrypted
 *  keyword: the word to be used to derive the keys from
 *
 *  prints the encrypted string
*/
void PrintCiphertext(string input, string keyword)
{
    char character;
    // since 'a' and 'A' are equivalent, transform the keyword into one case
    keyword = MakeLowerCase(keyword);
    int keyword_length = strlen(keyword);
    int key = 0;

    // i will track position in plaintext, j will track position in keyword
    int i = 0, j = 0;
    while(input[i])
    {
        character = input[i];
        if(isalpha(character))
        {
            // using the lower case range of ascii values
            key = (keyword[j] - 97);
            if islower(character)
            { // 3rd argument is the ascii upper bound
                PrintCharacter(character, key, 122);
            }
            if isupper(character)
            {
                PrintCharacter(character, key, 90);
            }
            // rotate the key if we get to the end of the keyword
            j = (j == keyword_length - 1) ? 0 : j + 1;
        }
        else
        { // print non-alphabetical characters as is
            printf("%c", character);
        }
        i++;
    }
    printf("\n");
}

string MakeLowerCase(string word)
{
    string lowercase_word = word;

    int i = 0;
    while(word[i])
    {
        lowercase_word[i] = tolower(word[i]);
        i++;
    }

    return lowercase_word;
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