#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define caesar(x) rot(13, x)
#define decaesar(x) rot(13, x)
#define decrypt_rot(x, y) rot((26-x), y)

void remove_newline_ch(char *line);
void rot(int c, char *str);

int main()
{
	char str[80] = "";

  printf("Enter sentence: ");
  fgets(str, sizeof(str), stdin);
  remove_newline_ch(str);


	printf("Original: %s\n", str);
	caesar(str);
	printf("Encrypted: %s\n", str);
	decaesar(str);
	printf("Decrypted: %s\n", str);

	return 0;
}

void rot(int c, char *str)
{
	int l = strlen(str);
	const char *alpha[2] = { "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

	int i;
	for (i = 0; i < l; i++)
	{
		if (!isalpha(str[i]))
			continue;

		str[i] = alpha[isupper(str[i])][((int)(tolower(str[i])-'a')+c)%26];
	}
}

void remove_newline_ch(char *line)
{
    int new_line = strlen(line) -1;
    if (line[new_line] == '\n')
        line[new_line] = '\0';
}
