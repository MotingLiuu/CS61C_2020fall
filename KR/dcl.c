#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);
int getch(void);
void ungetch(int);
void errmsg(char *msg);

int tokentype;           /* type of last token */
int err_flag = 0;
char token[MAXTOKEN];    /* last token string */
char name[MAXTOKEN];     /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
char out[1000];

/* getch/ungetch buffer */
char buf[BUFSIZE];       /* buffer for ungetch */
int bufp = 0;            /* next free position in buf */

int main(void) /* convert declaration to words */
{
    while (gettoken() != EOF) {   
        strcpy(datatype, token); /* 1st token on line is the datatype */
        out[0] = '\0';
        dcl();                   /* parse rest of line */
        
        if (tokentype != '\n')
            printf("syntax error\n");
        if (err_flag) {
            while (tokentype != '\n' && tokentype != EOF) {
                gettoken();
            }
        } else {
            printf("%s: %s %s\n", name, out, datatype);
        }
    }
    return 0;
}

/* dcl: parse a declarator */
void dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*'; ) /* count *'s */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
    int type;
    if (tokentype == '(') {         /* ( dcl ) */
        dcl();
        if (tokentype != ')')
            errmsg("error: missing )\n");
    } else if (tokentype == NAME)   /* variable name */
        strcpy(name, token);
    else
        errmsg("error: expected name or (dcl)\n");
        
    while ((type = gettoken()) == PARENS || type == BRACKETS) {
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

/* gettoken: return next token */
int gettoken(void) 
{
    int c;
    char *p = token;
    
    while ((c = getch()) == ' ' || c == '\t')
        ;
        
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else
        return tokentype = c;
}

/* get a (possibly pushed-back) character */
int getch(void) 
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) 
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void errmsg(char *msg) {
    printf("%s\n", msg);
    err_flag = 1;
}