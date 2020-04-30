#include <stdio.h>
#include <stdlib.h>


char *alphabet_position(char *text)
{
	int i, j = 0;
	const char *c;
	char *temp = "";
	for(i = 0; text ; i++)
	{
		if(islower(text[i]))			/*if its a capital letter*/
			j = toascii(text[i]) - 96;
		if(isupper(text[i]))			/*if its a small letter*/
			j = toascii(text[i]) - 64;
		//printf("%d",j);
		if(j!=0)
		{
			c = itoa(j, c, 10);
			temp = strcat(temp, c);
			j=0;
		}
	}
	text = temp;
	return text;
}


void main()
{
	char *output = alphabet_position("T");
	printf("%s", output);
	system("pause");
	return;
}
