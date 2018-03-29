/**
 * @author Marce Coll <marce@dziban.net>
 * @file main.c
 * @description Entry point for the deck software
 *
 * Released under the GPLv3 license
 */

#include "deck.h"
#include "fs.h"

#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <inttypes.h>

#define Kilobytes(n) n*1024l
#define Megabytes(n) Kilobytes(n)*1024l
#define Gigabytes(n) Megabytes(n)*1024l

FILE*
open_config_file() {
        FILE *config_file;

        char *deck_config_dir = getenv("DECK_CONFIG_DIR");

        // Default deck config dir
        if (deck_config_dir == NULL) {
                char *home = getenv("HOME");
                deck_config_dir = path_join(home, ".config/deck/");
        }

        char *config_file_path = path_join(deck_config_dir, "config.toml");
        config_file = fopen(config_file_path, "r");
}

deck_config_t
parse_config(FILE *file) {
        // TODO(Marce): Parse the config file
        char *config_file_data = read_whole_file_to_buffer(file);
}

void
parse_workspaces(deck_config_t *config) {
}

bool
find_current_workspace(deck_config_t *config) {
}

int
main(int argc, char *argv[]) {
        // We don't want to run as root, ever.
        if((getuid() == 0) || (geteuid() == 0)) {
                fprintf(stderr, "Running deck as root is asking for problems. Aborting.\n");
                exit(1);
        }

        // Initialize memory arena for all allocation purposes.
        // deck_memory_init(Kilobytes(30), Kilobytes(30));

        FILE *config_file = open_config_file();

        // Parse main configuration file
        deck_config_t config = parse_config(config_file);

        // After the parse_workspaces call, the deck_config_t structure has the
        // array of all workspaces that the user has configured, these
        // workspace_t structures only have the mountpoint path at this point as
        // their deck files have not been parsed at this point.
        parse_workspaces(&config);

        // The find_current_workspace call attempts to find the workspace the
        // command will run on. If it can't find it it will abort and ask the
        // user to provide it in one of several ways.
        //   * Call deck from inside the mountpoint of a workspace
        //   * Specify the workspace using the -w flag
        //   * Specify a default workspace using the default_workspace config option
        //     in the config.toml file
        //
        // In the case there is only one workspace it will just select that one too
        if(!find_current_workspace(&config)) {
                fprintf(stderr, "Don't know which workspace to use\n"
                        "Either call deck from inside a workspace dir, "
                        "specify the workspace using the -w flag or "
                        "specify a default_workspace in the config.toml file\n");
                exit(1);
        }
}
