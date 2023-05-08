#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countCharacters(FILE *file) {
    int count = 0;
    char ch;
    
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    
    return count;
}

int countWords(FILE *file) {
    int count = 0;
    char ch;
    int inWord = 0;
    
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == ',') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            count++;
        }
    }
    
    return count;
}

int main(int argc, char *argv[]) {
    char *parameter;
    char *filename;
    FILE *file;
    int count;
    
    if (argc != 3) {
        printf("Usage: WordCount [parameter] [input_file_name]\n");
        return 1;
    }
    
    parameter = argv[1];
    filename = argv[2];
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    if (strcmp(parameter, "-c") == 0) {
        count = countCharacters(file);
        printf("×Ö·ûÊý£º%d\n", count);
    } else if (strcmp(parameter, "-w") == 0) {
        count = countWords(file);
        printf("µ¥´ÊÊý£º%d\n", count);
    } else {
        printf("Invalid parameter.\n");
        return 1;
    }
    
    fclose(file);
    
    return 0;
}
