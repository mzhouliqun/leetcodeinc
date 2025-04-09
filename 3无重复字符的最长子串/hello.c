#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 2000
char *s_gets(char *, int);
int lengthOfLongestSubstring(char*);
int main(void)
{
	char string[LEN];
	printf("Please input a string here:\n");
	s_gets(string, LEN);
	printf("%d\n", lengthOfLongestSubstring(string));
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
	int hash[128];
	memset(hash, -1, sizeof(hash));
	int left = 0;
	int max_len = 0;

	for (int right = 0; str[right] != '\0'; right++) {
		if (hash[str[right]] >= left) {
			left = hash[str[right]] + 1;
		}
		hash[str[right]] = right;
		int current_len = right - left + 1;
		if (current_len > max_len)
			max_len = current_len;
	}
	return max_len;
}
