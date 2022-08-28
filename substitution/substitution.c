#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Checking that there was a substitution key input
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //Checking that the sub key is a full 26 letters
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //Checking that all chars are unique by adding them all up
    int checksum = 0;
    for (int i = 0; i < 26; i++)
    {
        checksum = checksum + (int)toupper(argv[1][i]);
        //this is to catch when multiple chars are dupllicated and total stays the same
        //will only work if duplicate chars are next to each other in key
        if ((int)toupper(argv[1][i]) == (int)toupper(argv[1][i + 1]))
        {
            checksum++;
        }
    }
    //ascii value of A-Z combined is 2015
    if (checksum != 2015)
    {
        printf("Key is invalid, ensure no chars are repeated and all are A-Z.\n");
        return 1;
    }

    //Get plaintext
    string plain = get_string("plaintext: ");
    string cipher = plain;
    int plainlen = strlen(plain);
    char temp;
    int num;
    bool lower;

    for (int i = 0; i < plainlen; i++)
    {
        //Set current char to be encoded
        temp = toupper(plain[i]);
        //ensure char is A-Z
        if ((int)temp < 65 || (int)temp > 90)
        {
            continue;
        }
        //check if char is upper or lower case, if lower will be TRUE
        lower = (int)plain[i] > 96;
        //Get position in key
        num = (int)temp - 65;
        //set cipher to key pos
        cipher[i] = toupper(argv[1][num]);
        //if lowercase return to lowercase
        if (lower)
        {
            cipher[i] = tolower(cipher[i]);
        }
    }
    printf("ciphertext: %s\n", cipher);
    return 0;
}