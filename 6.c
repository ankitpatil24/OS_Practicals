#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePointer;
    char data[100];

    // Open a file in write mode
    filePointer = fopen("example.txt", "w");

    if (filePointer == NULL) {
        printf("File could not be opened.\n");
        return -1;
    }

    // Write data to the file
    printf("Enter some text to write to the file: ");
    fgets(data, sizeof(data), stdin);
    fprintf(filePointer, "%s", data);

    // Close the file
    fclose(filePointer);

    // Open the same file in read mode
    filePointer = fopen("example.txt", "r");

    if (filePointer == NULL) {
        printf("File could not be opened.\n");
        return -1;
    }

    // Read data from the file
    printf("Contents of the file:\n");
    while (fgets(data, sizeof(data), filePointer) != NULL) {
        printf("%s", data);
    }

    // Close the file
    fclose(filePointer);

    return 0;
}
