// https", //www.codewars.com/kata/577ff15ad648a14b780000e7/train/c

#include <stdio.h>
#include <string.h>

char *Dictionary[] =
{
    "english",      "Welcome",
    "czech",        "Vitejte",
    "danish",       "Velkomst",
    "dutch",        "Welkom",
    "estonian",     "Tere tulemast",
    "finnish",      "Tervetuloa",
    "flemish",      "Welgekomen",
    "french",       "Bienvenue",
    "german",       "Willkommen",
    "irish",        "Failte",
    "italian",      "Benvenuto",
    "latvian",      "Gaidits",
    "lithuanian",   "Laukiamas",
    "polish",       "Witamy",
    "spanish",      "Bienvenido",
    "swedish",      "Valkommen",
    "welsh",        "Croeso"
};

const char* greet (const char *language)
{
    if (NULL == language)
    {
        return Dictionary[1];
    }

    int i = sizeof(Dictionary) / sizeof(Dictionary[0]) - 1;
    while (i --> 0)
    {
        if ( !strcmp(Dictionary[i], language) )
        {
            return Dictionary[i+1];
        }

        i--;
    }

    return Dictionary[1];
}

int main (void)
{
    printf("%s\n", greet("finnish"));
    printf("%s\n", greet("polish"));
    printf("%s\n", greet("latvian"));
    printf("%s\n", greet("english"));
    printf("%s\n", greet("welsh"));
    printf("%s\n", greet("lithuanian"));

    return 0;
}

