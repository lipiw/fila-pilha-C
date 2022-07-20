#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "fila.h"

void startQueue(QUEUE *f)
{
    f->start = NULL;
    f->end = NULL;
}

void insert(int pass, QUEUE *q){
    NODE *ptr = (NODE*) malloc(sizeof(NODE));
    if(ptr == NULL){
        printf("ERRO DE ALOCAÇÃO.\n");
        return;
    } else{
        ptr->pass = pass;
        ptr->next = NULL;

        // Estou inserindo o primeiro nó?
        if(q->start == NULL){
            q->start = ptr;
        } else{
            q->end->next = ptr;
        }

        // Atualizando o final para PTR (Talvez NULL)
        q->end = ptr;
        return;
    }
}

// void insertAllOne(int pass, QUEUE2 senhas)
// {
//     NODE *ptr = (NODE*) malloc(sizeof(NODE));
//     if(ptr == NULL){
//         printf("ERRO DE ALOCAÇÃO.\n");
//         return;
//     } else{
//         ptr->pass = pass;
//         ptr->next = NULL;

//         // Estou inserindo o primeiro nó?
//         if(senhas->start == NULL){
//             senhas->start = ptr;
//         } else{
//             senhas->end->next = ptr;
//         }

//         // Atualizando o final para PTR (Talvez NULL)
//         q->end = ptr;
//         return;
//     } 
// }

int delete(QUEUE *q){
    NODE *ptr = q->start;
    int s;

    // Remover elemento do início da qila
    if(ptr != NULL){
        q->start = ptr->next;
        ptr->next = NULL;
        s = ptr->pass;
        free(ptr);
        
        if(q->start == NULL){
            q->end=NULL;
        }
        return s;
    } else{
        return 0;
    }
}

int printfQueue(int pos, QUEUE *q, int type){
    NODE *ptr = q->start;
    if(ptr != NULL){
        while(ptr != NULL){
            printf("\n");
            if(type == 1)
                printf("\t%d\t%d\tNORMAL ", pos, ptr->pass);
            if(type == 2)
                printf("\t%d\t%d\tPREFERENCIAL ", pos, ptr->pass);
            pos++;
            ptr = ptr->next;
        }
    }
    return pos;
}

int verifyQueue(QUEUE *f, int senha){
    NODE *ptr = f->start;
    int s;

     if(ptr != NULL){
        while(ptr != NULL){
            s = ptr->pass;
            if(s == senha){
                return 1;
            }else{
                ptr = ptr->next;
            }
        }
    }else
        return 0;
    return 0;
}

