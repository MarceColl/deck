#include "deck.h"
#include "utils.h"

void deck_parse_config(FILE *f, deck_config_t *c) {
        char *buf = read_whole_file_to_buffer(f);
}

void deck_parse_deck_file(FILE *f, workspace_t *w) {
        char *buf = read_whole_file_to_buffer(f);

        deck_tok_t tok;
        while(tok.type != ENDOF) {

        }
}

// Handler for the `deck new` command
void new_project(deck_data_t *d) {
  // A single workspace exists, no need to ask the user
  if(d->num_workspaces == 1) {
    add_project_to_workspace(d, &d->workspaces[0]);
  }
  // A workspace needs to exist
  else if(d->num_workspaces == 0) {
    fprintf(stderr, "First you need to create a workspace using `deck create-workspace`");
    exit(1);
  }

  // Ask the user to select a workspace to create the new project in
  fprintf(stderr, "You have several workspaces, which one "
          "do you want to create the project in?");

  for(int i = 0; i < d->num_workspaces; ++i) {
    fprintf(stderr, "  %d) %s\n", i, d->workspaces[i].name);
  }

  int sel_ws_idx;
  workspace_t *sel_ws;
  scanf("%d", &sel_ws_idx);
  sel_ws = &d->workspaces[sel_ws_idx];

  add_project_to_workspace(d, sel_ws);
}

void add_project_to_workspace(deck_data_t *d, workspace_t *ws) {}
