#include <stdio.h>
#include <string.h>


char *vowel_back(const char *str_in)
{
  char *r = strdup(str_in) , *p = r;
  while (*p) *p++ = "vkbaafpqistuvwnyzabtpvfghi"[*p -'a'];
  return r;
}

int main (int argv, char **argc)
{
    puts(vowel_back("testcase"));

    return 0;
}
