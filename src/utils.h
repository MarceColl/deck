#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef enum {
        IDENTIFIER,
        SEPARATOR,
        URL,
        O_BRACKET,
        C_BRACKET,
        COMMA,
        INVALID,
        ENDOF
} DECK_FILE_TOK_TYPE;

typedef struct {
        DECK_FILE_TOK_TYPE type;
        char *str;
} deck_tok_t;

typedef struct {
        char *c;
} deck_file_lexer_t;

typedef uint8_t bool;
#define TRUE 1
#define FALSE 0

inline
void
print_red() {
        fprintf(stderr, "\e[0;31m");
}

inline
void
print_white() {
        fprintf(stderr, "\e[1;37m");
}

// TODO(Marce): Join two paths and return the joined path
char* path_join(const char *left, const char *right);

// Get the filename part of the path
// ex: /home/data/example.txt -> example.txt
// TODO(Marce): Implement it
char* path_get_filename(const char *path);

// Return a buffer with the whole contents of the file as a null-terminated
// string
char* read_whole_file_to_buffer(FILE *f);


deck_tok_t deck_file_get_next_tok(deck_file_lexer_t *l);

// Expect a token type, if the next token doesn't fit the type an INVALID type
// token is returned
deck_tok_t expect(deck_file_lexer_t *l,
                  DECK_FILE_TOK_TYPE type);

#endif
