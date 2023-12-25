#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "suggestions.h"
void getSuggestion(char *suggestion) {
    printf("Enter your suggestion: ");
    scanf("%s", suggestion);
}

void countAddSaveSuggestion(const char *newSuggestion) {
    FILE *file = fopen("suggestions.txt", "r+");
    char suggestion[100];
    int count = 1;  // Start with 1 for the new suggestion

    if (file == NULL) {
        // File doesn't exist, create it and add the new suggestion
        file = fopen("suggestions.txt", "w");
        fprintf(file, "%s,%d\n", newSuggestion, count);
        fclose(file);
        return;
    }

    int found = 0;
    long pos = 0;  // To remember the position for writing
    while (fscanf(file, "%99[^,],%d\n", suggestion, &count) != EOF) {
        if (strcmp(suggestion, newSuggestion) == 0) {
            found = 1;
            fseek(file, pos, SEEK_SET);  // Move back to the start of this line
            fprintf(file, "%s,%d    \n", suggestion, count + 1);  // Overwrite with new count
            break;
        }
        pos = ftell(file);  // Update position
    }

    if (!found) {
        // If the suggestion wasn't found, add it at the end
        fprintf(file, "%s,1\n", newSuggestion);
    }

    fclose(file);
}

void displaySuggestions() {
    FILE *file = fopen("suggestions.txt", "r");
    char suggestion[100];
    int count;

    if (file == NULL) {
        printf("No suggestions available.\n");
        return;
    }

    printf("Suggestions:\n");
    while (fscanf(file, "%99[^,],%d\n", suggestion, &count) != EOF) {
        printf("%s: %d\n", suggestion, count);
    }

    fclose(file);
}
