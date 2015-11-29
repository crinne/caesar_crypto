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
 * ===========make
 ==========================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>

// Constants
#define caesar(x, y) rot(x, y)
#define decaesar(x, y) rot((26 - x), y)

// Function prototypes
void remove_newline_ch(char *line);
void rot(int c, char *str);
void print_usage(char *argv[]);
int check_shifer(int x);

int main(int argc, char *argv[]) {
    
    int decrypt = 0;
    int encrypt = 0;
    int shiffer = 0;

    if (argc != 3) {
        //fprintf(stderr, "You need to give 2 arguments\n");
        print_usage(argv);    
        return 1;
    }

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
        
    if (check_shifer(shiffer)) {
        fprintf(stderr, "Shiffer should be between 0 and 25\n");
        exit(1);
        
    }
    
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

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  check_shifer
 *  Description:  Checks if shoffer is between 0 and 25 in case it is it returns false (0)
                  else it returns true (1)
 * =====================================================================================
 */
int check_shifer(int x) {
    return (x < 26 && x >= 0) ? 0:1;
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

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  remove_newline_ch
 *  Description:  Checks if string ends with new line '\n' character and if it do then 
                  it replace it with '\0' char
 * =====================================================================================
 */
void remove_newline_ch(char *line)
{
    int new_line = strlen(line) -1;
    if (line[new_line] == '\n')
        line[new_line] = '\0';
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  print_usage
 *  Description:  Prints out usage
 * =====================================================================================
 */
void print_usage(char *argv[]) {

    printf("Usage: %s [option] [shiffer] \n", argv[0]);    
    printf("\nOptions:\n\n");
    printf(" -h\t\t Print usage\n");
    printf(" -d\t\t Decrypt the message\n");
    printf(" -e\t\t Encrypt the message\n");
    printf(" -s\t\t How many characters to shift\n");
}
