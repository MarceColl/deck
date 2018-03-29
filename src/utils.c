#include "utils.h"

#include <string.h>

int
trim(char *a, int len) {
        int pos_first_ch = 0;

        for(int i = 0; i < len; ++i) {
                if(a[i] == ' ')
                        pos_first_ch++;
                else
                        break;
        }

        return 3;
}

char*
path_join(const char *a, const char *b) {
        int len_a = strlen(a);
        int len_b = strlen(b);

        bool a_slash_term = FALSE;
        bool b_slash_start = FALSE;

        // We have to take into account malformed paths that have spaces
        for(int i = len_a - 1; i >= 0; --i) {
                if (a[i] == ' ')
                        continue;
                if (a[i] == '/')
                        a_slash_term = TRUE;
                else
                        break;
        }

        for(int i = 0; i < len_b; ++i) {
                if (a[i] == ' ')
                        continue;
                if (a[i] == '/')
                        b_slash_start = TRUE;
                else
                        break;
        }
}

char*
read_whole_file_to_buffer(FILE *f) {
        char *buffer = NULL;

        fseek(f, 0, SEEK_END);
        size_t length = ftell(f);
        fseek(f, 0, SEEK_SET);

        // We need a +1 to have space for the ending \0
        buffer = (char*)malloc(length+1);
        if(!buffer)
                return NULL;

        if(length != fread(buffer, sizeof(char), length, f)) {
                return NULL;
        }

        buffer[length] = '\0';

        return buffer;
}

deck_tok_t
expect(deck_file_lexer_t *l,
       DECK_FILE_TOK_TYPE type)
{

}
