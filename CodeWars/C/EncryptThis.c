// https://www.codewars.com/kata/5848565e273af816fb000449/train/c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 50

static void EncryptWord (const char *plain, char *cipher)
{
    int len = strlen(plain);
    sprintf(cipher, "%d", *plain);

    switch (len)
    {
        case 1: /* NOP */
        case 2:
            strncat(cipher, plain + 1, 1);
            break;
        case 3:
            strncat(cipher, plain + 2, 1);
            strncat(cipher, plain + 1, 1);
            break;
        default:
            strncat(cipher, plain + len - 1, 1);
            strncat(cipher, plain + 2, len - 3);
            strncat(cipher, plain + 1, 1);
            break;
    }
}

char *encrypt_this(const char *str)
{
    char *cipher = (char *) calloc(BUFFER_SIZE, sizeof(char));
    strcpy(cipher, "");
    char *cipherSeek = cipher;

    if ( (NULL == str) || !strcmp(str, "") ) return cipher;

    char word[strlen(str)+3];
    char buffer[BUFFER_SIZE] = {'\0'};
    char *split;
    while (*str)
    {
        if (' ' == *str)
        {
            str++;
            continue;
        }

        if ( (split = strchr(str, ' ')) != NULL)
        {
            snprintf(word, (size_t)(split - str + 1), "%s", str);
            str = split;
        }
        else
        {
            strcpy(word, str);
            str += strlen(str);
        }

        EncryptWord(word, buffer);

        if (!strcmp(cipher, ""))
        {
            cipherSeek += snprintf(cipherSeek, BUFFER_SIZE, "%s", buffer);
        }
        else
        {
            cipherSeek += snprintf(cipherSeek, BUFFER_SIZE, " %s", buffer);
        }
    }

    return cipher;
}

int main (void)
{
    char *result;

    result = encrypt_this("H");
    printf("%s\n", result);

    result = encrypt_this("He");
    printf("%s\n", result);

    result = encrypt_this("Hel");
    printf("%s\n", result);

    result = encrypt_this("Hell");
    printf("%s\n", result);

    result = encrypt_this("Hello");
    printf("%s\n", result);

    result = encrypt_this("good");
    printf("%s\n", result);

    result = encrypt_this("hello world");
    printf("%s\n", result);

    result = encrypt_this("");
    printf("%s\n", result);

    result = encrypt_this("A");
    printf("%s\n", result);

    result = encrypt_this("  Abcd   Abcd");
    printf("%s\n", result);

    free(result);

    return 0;
}
