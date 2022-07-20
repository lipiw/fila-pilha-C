#ifndef  FILA_H
#define  FILA_H

// Criando a estrutura no
typedef struct NODE{
    int pass;
    struct NODE *next;
}NODE;

// Criando a estrutura fila
typedef struct QUEUE{
    NODE *start;
    NODE *end;
}QUEUE;

// Criando a estrutura fila
typedef struct QUEUE2{
    NODE *start;
    NODE *end;
    NODE *type;
}QUEUE2;

void insert(int pass, QUEUE *q);
int  delete(QUEUE *q);
int printfQueue(int pos, QUEUE *q, int type);
int  verifyQueue(QUEUE *q, int pass);

#endif  /*FILA_H*/
