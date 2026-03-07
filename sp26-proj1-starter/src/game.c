#include "game.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "snake_utils.h"

/* Helper function definitions */
static void set_board_at(game_t *game, unsigned int row, unsigned int col, char ch);
static bool is_tail(char c);
static bool is_head(char c);
static bool is_snak(char c);
static char body_to_tail(char c);
static char head_to_body(char c);
static unsigned int get_next_row(unsigned int cur_row, char c);
static unsigned int get_next_col(unsigned int cur_col, char c);
static void find_head(game_t *game, unsigned int snum);
static char next_square(game_t *game, unsigned int snum);
static void update_tail(game_t *game, unsigned int snum);
static void update_head(game_t *game, unsigned int snum);

/* Task 1 */
game_t *create_default_game() {
  // TODO: Implement this function.
  struct game_t *default_game;
  struct snake_t *default_snake;
  char **default_board;
  
  default_game = (struct game_t *)malloc(sizeof(struct game_t));
  default_snake = (struct snake_t *)malloc(sizeof(struct snake_t));
  
  default_snake->tail_row = 2;
  default_snake->tail_col = 2;
  default_snake->head_row = 2;
  default_snake->head_col = 4;
  default_snake->live = true;
  
 
  default_board = (char **)malloc(18 * sizeof(char *));
  for (int i = 0; i < 18; i++) {
    *(default_board + i) = (char *)malloc(22 * sizeof(char));
    if (i == 0 || i == 17) {
      strcpy(*(default_board + i), "####################\n");
    } else if (i == 2) {
      strcpy(*(default_board + i), "# d>D    *         #\n");
    } else {
      strcpy(*(default_board + i), "#                  #\n");
    }
  }
  
  default_game->num_rows = 18;
  default_game->num_snakes = 1;
  default_game->snakes = default_snake;
  default_game->board = default_board;

  return default_game;
}

/* Task 2 */
void free_game(game_t *game) {
  // TODO: Implement this function.
  unsigned int game_row;
  game_row = game->num_rows;
  for (int i=0; i<game_row; i++) {
    free(game->board[i]);
  }
  free(game->board);
  free(game->snakes);
  free(game);
  return;
}

/* Task 3 */
void print_board(game_t *game, FILE *fp) {
  // TODO: Implement this function.
  if (NULL == fp) {
    return;
  }
  unsigned int num_rows = game->num_rows;
  for (int i=0; i<num_rows; i++) {
    fprintf(fp, (game->board)[i]);
  }
  return;
}

/*
  Saves the current game into filename. Does not modify the game object.
  (already implemented for you).
*/
void save_board(game_t *game, char *filename) {
  FILE *f = fopen(filename, "w");
  print_board(game, f);
  fclose(f);
}

/* Task 4.1 */

/*
  Helper function to get a character from the board
  (already implemented for you).
*/
char get_board_at(game_t *game, unsigned int row, unsigned int col) { return game->board[row][col]; }

/*
  Helper function to set a character on the board
  (already implemented for you).
*/
static void set_board_at(game_t *game, unsigned int row, unsigned int col, char ch) {
  game->board[row][col] = ch;
}

/*
  Returns true if c is part of the snake's tail.
  The snake consists of these characters: "wasd"
  Returns false otherwise.
*/
static bool is_tail(char c) {
  // TODO: Implement this function.
  if (c == 'w' || c == 'a' || c == 's' || c == 'd') {
    return true;
  }
  return false;
}

/*
  Returns true if c is part of the snake's head.
  The snake consists of these characters: "WASDx"
  Returns false otherwise.
*/
static bool is_head(char c) {
  // TODO: Implement this function.
  if (c == 'W' || c == 'A' || c == 'S' || c == 'D' || c == 'x') {
    return true;
  }
  return false;
}

/*
  Returns true if c is part of the snake.
  The snake consists of these characters: "wasd^<v>WASDx"
*/
static bool is_snake(char c) {
  // TODO: Implement this function.
  if (is_tail(c) || is_head(c) || c == '^' || c == '<' || c == 'v' || c == '>') {
    return true;
  }
  return false;
}

/*
  Converts a character in the snake's body ("^<v>")
  to the matching character representing the snake's
  tail ("wasd").
*/
static char body_to_tail(char c) {
  // TODO: Implement this function.
  switch (c) {
    case '^':
      return 'w';
      break;
    case '<':
      return 'a';
      break;
    case 'v':
      return 's';
      break;
    case '>':
      return 'd';
      break;
  }
  return '?';
}

/*
  Converts a character in the snake's head ("WASD")
  to the matching character representing the snake's
  body ("^<v>").
*/
static char head_to_body(char c) {
  // TODO: Implement this function.
  switch (c) {
    case 'W':
      return '^';
      break;
    case 'A':
      return '<';
      break;
    case 'S':
      return 'v';
      break;
    case 'D':
      return '>';
      break;
  }
  return '?';
}

/*
  Returns cur_row + 1 if c is 'v' or 's' or 'S'.
  Returns cur_row - 1 if c is '^' or 'w' or 'W'.
  Returns cur_row otherwise.
*/
static unsigned int get_next_row(unsigned int cur_row, char c) {
  // TODO: Implement this function.
  switch (c) {
    case 'v':
      return cur_row + 1;
    case 's':
      return cur_row + 1;
    case 'S':
      return cur_row + 1;
    case '^':
      return cur_row - 1;
    case 'w':
      return cur_row - 1;
    case 'W':
      return cur_row - 1;
  }
  return cur_row;
}

/*
  Returns cur_col + 1 if c is '>' or 'd' or 'D'.
  Returns cur_col - 1 if c is '<' or 'a' or 'A'.
  Returns cur_col otherwise.
*/
static unsigned int get_next_col(unsigned int cur_col, char c) {
  // TODO: Implement this function.
  switch (c) {
    case '>':
      return cur_col + 1;
    case 'd':
      return cur_col + 1;
    case 'D':
      return cur_col + 1;
    case '<':
      return cur_col - 1;
    case 'a':
      return cur_col - 1;
    case 'A':
      return cur_col - 1;
  }
  return cur_col;
}

/*
  Task 4.2

  Helper function for update_game. Return the character in the cell the snake is moving into.

  This function should not modify anything.
*/
static char next_square(game_t *game, unsigned int snum) {
  // TODO: Implement this function.
  unsigned int cur_head_row, cur_head_col, next_head_row, next_head_col;
  char head_char;
  cur_head_row = game->snakes[snum].head_row;
  cur_head_col = game->snakes[snum].head_col;
  head_char = get_board_at(game, cur_head_row, cur_head_col);

  next_head_row = get_next_row(cur_head_row, head_char);
  next_head_col = get_next_col(cur_head_col, head_char);

  return get_board_at(game, next_head_row, next_head_col);
}

/*
  Task 4.3

  Helper function for update_game. Update the head...

  ...on the board: add a character where the snake is moving

  ...in the snake struct: update the row and col of the head
  Note that this function ignores food, walls, and snake bodies when moving the head.
*/
static void update_head(game_t *game, unsigned int snum) {
  // TODO: Implement this function.
  unsigned int cur_head_row, cur_head_col, next_head_row, next_head_col;
  char head_char;

  cur_head_row = game->snakes[snum].head_row;
  cur_head_col = game->snakes[snum].head_col;
  head_char = get_board_at(game, cur_head_row, cur_head_col);

  next_head_row = get_next_row(cur_head_row, head_char);
  next_head_col = get_next_col(cur_head_col, head_char);

  set_board_at(game, next_head_row, next_head_col, head_char);
  set_board_at(game, cur_head_row, cur_head_col, head_to_body(head_char));
  
  game->snakes[snum].head_row = next_head_row;
  game->snakes[snum].head_col = next_head_col;
  
  return;
}

/*
  Task 4.4

  Helper function for update_game. Update the tail...

  ...on the board: blank out the current tail, and change the new
  tail from a body character (^<v>) into a tail character (wasd)

  ...in the snake struct: update the row and col of the tail
*/
static void update_tail(game_t *game, unsigned int snum) {
  // TODO: Implement this function.
  unsigned int cur_tail_row, cur_tail_col, next_tail_row, next_tail_col;
  char tail_char;

  cur_tail_row = game->snakes[snum].tail_row;
  cur_tail_col = game->snakes[snum].tail_col;
  tail_char = get_board_at(game, cur_tail_row, cur_tail_row);

  next_tail_row = get_next_row(cur_tail_row, tail_char);
  next_tail_col = get_next_col(cur_tail_col, tail_char);

  set_board_at(game, next_tail_row, next_tail_col, body_to_tail(get_board_at(game, next_tail_row, next_tail_col)));
  set_board_at(game, cur_tail_row, cur_tail_col, ' ');
  
  game->snakes[snum].tail_row = next_tail_row;
  game->snakes[snum].tail_col = next_tail_col;

  return;
}

/* Task 4.5 */
void update_game(game_t *game, int (*add_food)(game_t *game)) {
  // TODO: Implement this function.
  unsigned int num_snakes = game->num_snakes;
  char next_sq;
  for (int i=0; i<num_snakes; i++) {
    next_sq = next_square(game, i);
    if (is_snake(next_sq) || next_sq == '#') {
      set_board_at(game, game->snakes[i].head_row, game->snakes[i].head_col, 'x');
      game->snakes[i].live = false;
    } else if (next_sq == '*') {
      update_head(game, i);
      add_food(game);
    } else {
      update_head(game, i);
      update_tail(game, i);
    }
  }
  return;
}

/* Task 5.1 */
char *read_line(FILE *fp) {
  // TODO: Implement this function.
  int MAXLEN = 1000;
  char *line = (char *)malloc(MAXLEN * sizeof(char));
  if (line == NULL) return NULL;

  if (NULL == fgets(line, MAXLEN, fp)) {
    free(line);
    return NULL;
  } 
  char *new_line = (char *)realloc(line, (strlen(line) + 1) * sizeof(char));
  if (NULL == new_line) {
    return line;
  }
  return new_line;
  
}

/* Task 5.2 */
game_t *load_board(FILE *fp) {
  // TODO: Implement this function.
  int MAXROWS = 1000;
  game_t *game = (game_t *)malloc(sizeof(game_t));
  char **board = (char **)malloc(MAXROWS * sizeof(char *));
  
  if (game == NULL || board == NULL) {
    if (game) free(game);
    if (board) free(board);
    return NULL;
  }

  unsigned int row = 0;
  while(1) {
    char *line = read_line(fp);
    if (line == NULL) {
      break;
    }
    board[row] = line;
    row++;
  }

  char **new_board = realloc(board, row * sizeof(char *));
  if (new_board != NULL) {
    board = new_board;
  }
  
  game->num_rows = row;
  game->board = board;
  game->num_snakes = 0;
  game->snakes = NULL;
  
  return game;
}

/*
  Task 6.1

  Helper function for initialize_snakes.
  Given a snake struct with the tail row and col filled in,
  trace through the board to find the head row and col, and
  fill in the head row and col in the struct.
*/
static void find_head(game_t *game, unsigned int snum) {
  // TODO: Implement this function.
  unsigned tail_row, tail_col, next_row, next_col;
  char next_char;
  tail_row = game->snakes[snum].tail_row;
  tail_col = game->snakes[snum].tail_col;
  
  next_row = tail_row;
  next_col = tail_col;
  next_char = get_board_at(game, tail_row, tail_col);
  while (1) {
    next_row = get_next_row(next_row, next_char);
    next_col = get_next_col(next_col, next_char);
    next_char = get_board_at(game, next_row, next_col);
    
    if (next_char == 'W' || next_char == 'A' || next_char == 'S' || next_char == 'D' || next_char == 'x') 
      break;
  }
  
  game->snakes[snum].head_row = next_row;
  game->snakes[snum].head_col = next_col;

  return;
}

/* Task 6.2 */
game_t *initialize_snakes(game_t *game) {
  // TODO: Implement this function.
  int MAXNUM = 1000;
  int num_snakes = 0;
  snake_t *snakes = (snake_t *)malloc(MAXNUM * sizeof(snake_t));
  if (NULL == snakes)
    return NULL;
  
  char cur_char;
  for (int i = 0; i < game->num_rows; i++) {
    for (int j = 0; (cur_char = game->board[i][j]) != '\0'; j++) {
      if (cur_char == 'w' || cur_char == 'a' || cur_char == 's' || cur_char == 'd') {
        snakes[num_snakes].live = true;
        snakes[num_snakes].tail_row = i;
        snakes[num_snakes].tail_col = j;
        num_snakes++;
      }
    }
  }
  
  snake_t *new_snakes = (snake_t *)realloc(snakes, num_snakes * sizeof(snake_t));
  if (NULL != new_snakes)
    snakes = new_snakes;
  
  game->snakes = snakes;
  game->num_snakes = num_snakes;

  for (int i = 0; i < game->num_snakes; i++) {
    find_head(game, i);
  }
  
  return game;
}
