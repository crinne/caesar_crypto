/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Caesar cipher
 *
 *        Version:  1.0
 *       Compiler:  gcc
 *         Author:  Caspar Rinne, caspar.rinne@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>

// Constants
#define caesar(y, x) rot(y, x)
#define decaesar(y, x) rot(y, x)

// Function prototypes
void remove_newline_ch(char *line);
void rot(int c, char *str);

int main(int argc, char *argv[]) {
    
    int decrypt = 0;
    int encrypt = 0;
    int shiffer = 0;
    
    char ch;
    while ((ch = getopt(argc, argv, "des:")) != EOF)
        
        switch (ch) {
            case 'd':
                decrypt = 1;
                break;
            case 'e':
                encrypt = 1;
                break;
            case 's':
                shiffer = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Unknown option '%s'\n", optarg);
                return 1;
        }
        argc -= optind;
        argv += optind;
    
    
	char str[80] = "";	
    printf("Enter sentence: ");
    fgets(str, sizeof(str), stdin);
    remove_newline_ch(str);
    


    if (encrypt) {
        caesar(shiffer, str);
        printf("Encrypted: %s\n", str);
    }
    
    else if (decrypt) {
        decaesar(shiffer, str);
        printf("Decrypted: %s\n", str);
    }
    else {
        printf("Original: %s\n", str);
    }
  
	return 0;
}

void rot(int c, char *str)
{
	int l = strlen(str);
	const char *alpha[2] = { "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int index = 0;
	int i;
	for (i = 0; i < l; i++)
	{
		if (!isalpha(str[i]))
			continue;
			
		if (isupper(str[i]))
			index = 1;
		
		str[i] = alpha[index][((int)(tolower(str[i])-'a')+c)%26];
		index = 0;
	}
}

void remove_newline_ch(char *line)
{
    int new_line = strlen(line) -1;
    if (line[new_line] == '\n')
        line[new_line] = '\0';
}
