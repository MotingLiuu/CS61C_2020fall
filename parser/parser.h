extern int stack[100];
extern int tokens[100];
extern char out[1000];
enum {NAME, PARENTS, BARCKETS};


int gettoken(char *); // get next token from input and reutrn the type of token
char pop(void);
void push(char c);
int getch(void);

void dcl(void);
void direct_dcl(void);


