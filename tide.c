https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
////////////////////////////////////////////////////////////////////////////////
// COMP1521 23T3 --- Assignment 2: `tide', a terribly insecure (file) decryptor
// <https://www.cse.unsw.edu.au/~cs1521/23T3/assignments/ass2/index.html>
//
// 2023-10-25   v1.0    Team COMP1521 <cs1521 at cse.unsw.edu.au>
// 
// This program was written by YOUR-NAME-HERE (YOUR-ZID-HERE) on DD/MM/2023.
// (COMPLETE THE ABOVE COMMENT AND REMOVE THIS LINE FOR FREE STYLE MARKS!)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "tide.h"

// Add any extra #defines here.

// Add any extra function signatures here.

// Some provided strings which you may find useful. Do not modify.
const char *const MSG_ERROR_FILE_STAT  = "Could not stat file.\n";
const char *const MSG_ERROR_FILE_OPEN  = "Could not open file.\n";
const char *const MSG_ERROR_CHANGE_DIR = "Could not change directory.\n";
const char *const MSG_ERROR_DIRECTORY  =
    "tide does not support encrypting directories.\n";
const char *const MSG_ERROR_READ       =
    "group does not have permission to read this file.\n";
const char *const MSG_ERROR_WRITE      =
    "group does not have permission to write here.\n";
const char *const MSG_ERROR_RESERVED   =
    "'.' and '..' are reserved filenames, please search for something else.\n";

/////////////////////////////////// SUBSET 0 ///////////////////////////////////

// Print the name of the current directory.
void print_current_directory(void) {
    printf("The current directory is: %s\n", "TODO: COMPLETE ME");
}

// Change the current directory to the given pathname.
void change_current_directory(char *directory) {
    printf("Moving to %s\n", "TODO: COMPLETE ME");
}

// List the contents of the current directory.
void list_current_directory(void) {
    printf("TODO: COMPLETE ME");
}

/////////////////////////////////// SUBSET 1 ///////////////////////////////////

// Check whether the file meets the criteria to be encrypted.
bool is_encryptable(char *filename) {
    printf("TODO: COMPLETE ME");
    return false;
}

// XOR the contents of the given file with a set key, and write the result to
// a new file.
void xor_file_contents(char *src_filename, char *dest_filename) {
    printf("TODO: COMPLETE ME");
}

/////////////////////////////////// SUBSET 2 ///////////////////////////////////

// Search the current directory and its subdirectories for filenames containing
// the search string.
void search_by_filename(char *search_string) {
    printf("TODO: COMPLETE ME");
}

// Search the current directory and its subdirectories for files containing the
// provided search bytes.
void search_by_content(char *search_bytes, int size) {
    printf("TODO: COMPLETE ME");
}

/////////////////////////////////// SUBSET 3 ///////////////////////////////////

char *shift_encrypt(char *plaintext, char password[CIPHER_BLOCK_SIZE]) {
    // TODO: complete me
    return NULL;
}

char *shift_decrypt(char *ciphertext, char password[CIPHER_BLOCK_SIZE]) {
    // TODO: complete me
    return NULL;
}

void ecb_encryption(char *filename, char password[CIPHER_BLOCK_SIZE]) {
    printf("TODO: COMPLETE ME");
}

void ecb_decryption(char *filename, char password[CIPHER_BLOCK_SIZE]) {
    printf("TODO: COMPLETE ME");
}

/////////////////////////////////// SUBSET 4 ///////////////////////////////////

void cbc_encryption(char *filename, char password[CIPHER_BLOCK_SIZE]) {
    printf("TODO: COMPLETE ME");
}

void cbc_decryption(char *filename, char password[CIPHER_BLOCK_SIZE]) {
    printf("TODO: COMPLETE ME");
}

/////////////////////////////////// PROVIDED ///////////////////////////////////
// Some useful provided functions. Do NOT modify.

// Sort an array of strings in alphabetical order.
// strings:  the array of strings to sort
// count:    the number of strings in the array
// This function is to be provided to students.
void sort_strings(char *strings[], int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (strcmp(strings[i], strings[j]) < 0) {
                char *temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

// Sort an array of content_result_t in descending order of matches.
// results:  the array of pointers to content_result_t to sort
// count:    the number of pointers to content_result_t in the array
// This function is to be provided to students.
void sort_content_results(content_result *results[], int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (results[i]->matches > results[j]->matches) {
                content_result *temp = results[i];
                results[i] = results[j];
                results[j] = temp;
            } else if (results[i]->matches == results[j]->matches) {
                // If the matches are equal, sort alphabetically.
                if (strcmp(results[i]->filename, results[j]->filename) < 0) {
                    content_result *temp = results[i];
                    results[i] = results[j];
                    results[j] = temp;
                }
            }
        }
    }
}

// Generate a random string of length RAND_STR_LEN.
// Requires a seed for the random number generator.
// The same seed will always generate the same string.
// The string contains only lowercase + uppercase letters,
// and digits 0 through 9.
// The string is returned in heap-allocated memory,
// and must be freed by the caller.
char *generate_random_string(int seed) {
    if (seed != 0) {
        srand(seed);
    }
    char *alpha_num_str =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";

    char *random_str = malloc(RAND_STR_LEN);

    for (int i = 0; i < RAND_STR_LEN; i++) {
        random_str[i] = alpha_num_str[rand() % (strlen(alpha_num_str) - 1)];
    }

    return random_str;
}
