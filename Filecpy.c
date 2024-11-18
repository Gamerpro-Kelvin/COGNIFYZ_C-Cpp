#include <stdio.h>
#include <stdlib.h>

void copyFileContents(char *sourceFileName, char *destFileName) {
    FILE *sourceFile, *destFile;
    char ch;

    // Open the source file for reading
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Error: Could not open source file '%s'.\n", sourceFileName);
        exit(1);
    }

    // Open the destination file for writing
    destFile = fopen(destFileName, "w");
    if (destFile == NULL) {
        printf("Error: Could not open destination file '%s'.\n", destFileName);
        fclose(sourceFile);
        exit(1);
    }

    // Copy the contents character by character using a pointer
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    // Close the files
    fclose(sourceFile);
    fclose(destFile);

    printf("File contents copied from '%s' to '%s' successfully.\n", sourceFileName, destFileName);
}

int main() {
    char sourceFileName[100], destFileName[100];

    // Prompt user for the source and destination file names
    printf("Enter the name of the source file: ");
    scanf("%s", sourceFileName);
    printf("Enter the name of the destination file: ");
    scanf("%s", destFileName);

    // Copy contents using a function
    copyFileContents(sourceFileName, destFileName);

    return 0;
}

