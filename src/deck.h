#ifndef _DECK_H_
#define _DECK_H_

#include "utils.h"

#include <stdio.h>
#include <stddef.h>

// A deck tag
typedef struct deck_tag_t {
        char *name;
} deck_tag_t;


// A deck project
typedef struct deck_project_t {
        char *name;
        char *repo_url;
        deck_tag_t *tags;
} deck_project_t;

// A workspace is a collection of tags and projects
typedef struct workspace_t {
        char *rootdir;
        char *name;

        size_t num_projects;
        deck_project_t *projects;

        size_t num_tags;
        deck_tag_t *tags;
} workspace_t;

typedef struct deck_config_t {
  // What the deck config dir is
  char *config_dir;

  // When we call the deck command from inside a workspace mountpoint the
  // working_ws will be that workspace
  workspace_t *working_ws;

  // All the workspaces defined in the config.toml file
  workspace_t *workspaces;
  uint8_t num_workspaces;

  // Debug mode outputs a lot more info about what is going on
  bool debug;
} deck_config_t;

typedef struct template_t {
} template_t;

// Contains all the data for the deck housekeeping
typedef struct deck_data_t {
        deck_config_t config;

        workspace_t *workspaces;
        size_t num_workspaces;

        template_t *templates;
        size_t num_templates;
} deck_data_t;


// Add a project to a workspace, if there is any needed information that was not
// given as a call parameter it will be asked here
void add_project_to_workspace(deck_data_t *d, workspace_t *ws);

// Handler for the `deck new` command
void new_project(deck_data_t *d);

// Parse config from config file and fill the config structure
void deck_parse_config(FILE *f, deck_config_t *c);


// Parse workspace description file
void deck_parse_deck_file(FILE *f, workspace_t *w);


#endif
