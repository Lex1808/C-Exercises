#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char in_line[1024];
    char *zip_line = NULL;
    char current_char;
    int rep_counter = 0;
    int zip_line_count = 0;
    int string_count = 0;

    printf("Enter word: ");
    while(fgets(in_line, sizeof(in_line), stdin) != NULL) {
        break;   
    }
    string_count = strlen(in_line) - 1; //remove new line symbol

    zip_line = malloc(string_count * 2 * sizeof(char));
    if (zip_line == NULL) {
        exit(EXIT_FAILURE);
    }

    char *p = &in_line[0];
    current_char = in_line[0];
    for (int i = 0; i < string_count; i++, p++) {
        if(*p == current_char) {
            rep_counter++;
        }
        else if (*p != current_char && rep_counter > 0) {
            if (rep_counter == 1) {
                zip_line_count += snprintf(zip_line + zip_line_count, string_count * 2 - zip_line_count, "%c", current_char);
            }
            else {
                zip_line_count += snprintf(zip_line + zip_line_count, string_count * 2 - zip_line_count, "%d%c", rep_counter, current_char);
            }
            current_char = *p;
            rep_counter = 1;
        }
    }
    if (rep_counter == 1) {
        zip_line_count += snprintf(zip_line + zip_line_count, string_count * 2 - zip_line_count, "%c", current_char);
    } else {
        zip_line_count += snprintf(zip_line + zip_line_count, string_count * 2 - zip_line_count, "%d%c", rep_counter, current_char);
    }

    printf("%s\n", zip_line);

    free(zip_line);
                             
    return 0;
}
