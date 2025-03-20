#include <stdio.h>
#include <stdlib.h>
#define LEN 20
char *s_gets(char *, int);
int main(void)
{
	char string[LEN] = {'\0'};
	printf("Please enter here:\n");
	s_gets(string, LEN);
	printf("Your input is:\n%s\n", string);
	return 0;
}

char *s_gets(char *str, int len)
{
	int i = 0;
	char *ret_val = fgets(str, len, stdin);

	if (ret_val != NULL) {
		while (*(str + i) != '\0' && *(str + i) != '\n')
			i++;
		if (*(str + i) == '\n')
			*(str + i) = '\0';
		else
			while (getchar() != '\n');
	}
	return ret_val;
}