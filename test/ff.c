#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 200
char *s_gets(char *, int);
int lengthOfLongestSubstring(char*);
int main(void)
{
	char string[LEN];
	char child[LEN];
	printf("Please input a string here:\n");
	s_gets(string, LEN);
	printf("Your word is:\n");
	int len;

	len = (int)strlen(string);
	printf("Your word lenth is %d\n", len);
	return 0;
}

char *s_gets(char *str, int len)
{
	int i = 0;
	char *ret_val = fgets(str, len, stdin);

	if (ret_val != NULL) {
		while (str[i] != '\n'  && str[i] != '\0')
			i++;
		if (str[i] == '\n')
			str[i] = '\0';
	}
	return ret_val;
}

int lengthOfLongestSubstring(char *str)
{
	int len = (int)strlen(str);
	char temp[len] = {0};

	

	strcpy(temp, str);

	for (int i = 0; i < len; i++) {
		
	





