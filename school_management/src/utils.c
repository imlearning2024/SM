#include "../include/school.h"

FILE *open_file() {
    FILE *file = fopen(FILE_NAME, "ab+");
    if (file == NULL) {
        printf("\nFile couldn't open");
        return NULL;
    }
    return file;
}

FILE *open_file_readM() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nFile couldn't open");
        return NULL;
    }
    return file;
}

void clear_newlinechar() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void fix_fgets_error(char *buffer) {
    int index = strcspn(buffer, "\n");
    buffer[index] = '\0';
}

