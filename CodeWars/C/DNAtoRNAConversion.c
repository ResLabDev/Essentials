/*
Deoxyribonucleic acid, DNA is the primary information storage molecule in biological systems. It is composed of four nucleic acid bases Guanine ('G'), Cytosine ('C'), Adenine ('A'), and Thymine ('T').

Ribonucleic acid, RNA, is the primary messenger molecule in cells. RNA differs slightly from DNA its chemical structure and contains no Thymine. In RNA Thymine is replaced by another nucleic acid Uracil ('U').

Create a funciton which translates a given DNA string into RNA.

For example:

dna_to_rna("GCAT"); returns "GCAU"
The input string can be of arbitrary length - in particular, it may be empty. All input is guaranteed to be valid, i.e. each input string will only ever consist of 'G', 'C', 'A' and/or 'T'.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dna_to_rna(const char *dna)
{
    if (!strlen(dna))
    {
        return "\n";
    }
    char *rna = (char *) calloc(strlen(dna) + 1, sizeof(char));

    int i = 0;
    while (dna[i] != '\0')
    {
        rna[i] = (dna[i] == 'T') ? 'U' : dna[i];
        i++;
    }

    return rna;
}

int main (void)
{
    char* res = dna_to_rna("TTTT");
    printf("%s, %d", res, strcmp(res, "UUUU"));

    return 0;
}
