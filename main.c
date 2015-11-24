#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    char *word = "";
    int key = 0;
    int count = 0;
    char ch;

    while ((ch = getopt(argc, argv,"k:w:")) != EOF)
        switch (ch) {

            case 'k':
                key = atoi(optarg);
                break;
            case 'w':
                word = optarg;
                break;
        
            default: 
                fprintf(stderr, "Unknown option '%s'\n", optarg);
                return 1;
        }
        
        printf("key is here %d\n", key);
        printf("word is here %s\n", word);

        argc -= optind;
        argv += optind;

        return 0;

}
