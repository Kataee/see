#include "app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../dictionary/dictionary.h"
#include "../morse/morse.h"

#include "../utils/stringutils.h"

bool is_running = true;

bool is_exit_command(char *command) {
    return strcmp(command, ".exit") == 0;
}

void print_general_info(bool display_exit_info) {
    printf("OTJONA v%s\n", APP_VERSION);
    printf(" - `otjona`         open the dictionary application\n");
    printf(" - `otjona add`     add a new word to the dictionary\n");
    printf(" - `otjona morse`   open the morse code translator\n\n");

    if (display_exit_info) {
        printf("Type `.exit` (with a dot at the beginning) to quit the application.\n\n");
    }
}

dictionary_t *init_dictionary() {
    FILE *fin = fopen("dictionary.txt", "r");
    if (fin == NULL) {
        return NULL;
    }

    dictionary_t *dictionary = NULL;
    char line[0x210A], word[0x100], definition[0x2000];

    while (fscanf(fin, "%[^\n] ", line) != EOF) {
        char *pch = strtok(line, "@");
        strcpy(word, pch);

        pch = strtok(NULL, "@");
        if (pch != NULL) {
            strcpy(definition, pch);
        } else {
            strcpy(definition, "<no definition>");
        }

        dictionary = dictionary_insert(dictionary, word, definition);
    }

    fclose(fin);

    return dictionary;
}

void start_dictionary_app() {
    dictionary_t *dictionary = init_dictionary();
    if (dictionary == NULL) {
        printf("error: failed to load the dictionary.\n");
        exit(-1);
    }

    print_general_info(true);

    char word[0x100];

    while (is_running) {
        printf("Word: ");
        scanf("%[^\n]", word);
        getchar();

        if (is_exit_command(word)) {
            dictionary_free(dictionary);
            stop_application();
            return;
        }

        str_touppercase(word);

        dictionary_t *result = dictionary_search(dictionary, word);
        if (result == NULL) {
            printf("\n > The word \"%s\" could not be found.\n\n", word);
            continue;
        }

        dictionary_word_t *data = (dictionary_word_t *) result->data;
        printf("\n%s\n\n%s\n\n", data->word, data->definition);
    }
}

void add_word_to_dictionary() {
    dictionary_t *dictionary = init_dictionary();
    if (dictionary == NULL) {
        printf("error: failed to load the dictionary.\n");
        exit(-1);
    }

    print_general_info(false);

    char word[0x100], definition[0x2000];

    printf("Word: ");
    scanf("%[^\n]", word);
    getchar();

    if (dictionary_search(dictionary, word) != NULL) {
        printf("error: the word already exists in the dictionary.\n");
        dictionary_free(dictionary);
        exit(-2);
    }

    dictionary_free(dictionary);

    printf("Definition: ");
    scanf("%[^\n]", definition);
    getchar();

    FILE *fout = fopen("dictionary.txt", "a");
    if (fout == NULL) {
        printf("error: failed to open the dictionary file\n");
        exit(-1);
    }

    str_touppercase(word);

    fprintf(fout, "%s@%s\n", word, definition);
    fclose(fout);

    printf("Done.\n");
}

void start_morse_app() {
    morse_t *morse_table = init_morse_table();
    if (morse_table == NULL) {
        printf("error: failed to create Morse table\n");
        exit(-1);
    }

    print_general_info(true);

    char sentence[0x400];

    while (is_running) {
        printf("Sentence: ");
        scanf("%[^\n]", sentence);
        getchar();

        if (is_exit_command(sentence)) {
            morse_free(morse_table);
            stop_application();
            return;
        }

        str_tolowercase(sentence);

        printf("\nMorse code equivalent:\n\n");

        for (int i = 0; i < strlen(sentence); i++) {
            if (sentence[i] < 'a' || sentence[i] > 'z') {
                printf("[%c]", sentence[i]);
            } else {
                int weight = morse_weight_map[sentence[i] - 'a' + 1];
                morse_search(morse_table, weight);
            }

            printf("    ");
        }

        printf("\n\n");
    }
}

void start_application(int argc, char **argv) {
    if (argc < 2) {
        return start_dictionary_app();
    }

    if (strcmp(argv[1], "add") == 0) {
        return add_word_to_dictionary();
    }

    if (strcmp(argv[1], "morse") == 0) {
        return start_morse_app();
    }

    printf("Unknown command: %s.\n", argv[1]);
}

void stop_application() {
    is_running = false;
}
