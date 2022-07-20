#include "fila.c"
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

int  menuOpcoes();
int  menuGS();
void geraSenha(int opc);
void menuCS();
void menuLF();

QUEUE *senhasPreferencial = NULL;
QUEUE *senhasRegular = NULL;
int lastPassPref = 1;

void main(){

    setlocale(LC_ALL,"portuguese");
    senhasPreferencial = (QUEUE*) malloc(sizeof(QUEUE));
    senhasRegular = (QUEUE*) malloc(sizeof(QUEUE));

    if (senhasPreferencial == NULL || senhasRegular == NULL)
    {
        printf("Erro de alocação no início da fila.\n");
        exit(-1);
    }
    else
    {    
        startQueue(senhasPreferencial);
        startQueue(senhasRegular); 
    }
    menuOpcoes();
}

//Menu de opções para o usúario
int menuOpcoes(){
    system("cls");
    printf("\n\n\n");
    printf("_________________________________\n");
    printf("\t   Sistema de Senhas\n");
    printf("\t***  Menu de Opcoes  ***\n");
    printf("\n\t1 - Geracao de Senha\n");
    printf("\n\t2 - Chamada de Senha\n");
    printf("\n\t3 - Listagem de Fila\n");
    printf("\n\n\t0 - Sair do Programa\n");
    printf("\n_________________________________\n\n");

    int opc;
    scanf("%d", &opc);

    switch(opc){
    case 0:
        exit(0);
        break;
    case 1:
        menuGS();
        break;
    case 2:
        menuCS();
        break;
    case 3:
        menuLF();
        break;
    default:
        exit(0);
        break;
    }
}

//Menu para geração de senhas
int menuGS(){
    int type;
    system("cls");
    printf("\n\n\n");
    printf("_________________________________\n");
    printf("\t   Sistema de Senhas\n");
    printf("\t***  Geracao de Senha  ***\n");
    printf("\n\t1 - Geracao de Senha NORMAL\n");
    printf("\n\t2 - Geracao de Senha PREFERENCIAL\n");
    printf("\n\t0 - Voltar ao Menu de Opcoes\n");
    printf("_________________________________\n");
    scanf("%d", &type);

    if(type == 0)
        menuOpcoes();
    else
        geraSenha(type);
}

//Método para gerar a senha de acordo com o tipo NORMAL ou PREFERENCIAL
void geraSenha(int type){
    int retorno = 0, senha, opcc;
    do{
        senha = rand() %999; 
        retorno += verifyQueue(senhasPreferencial, senha);
        retorno += verifyQueue(senhasRegular, senha);
    }while(retorno > 0);

    if(type == 1)
    {
        insert(senha, senhasRegular);
        printf("\n\tSenha do tipo NORMAL gerada: %d\n", senha);
    }
        

    else if(type == 2)
    {
        insert(senha, senhasPreferencial);
        printf("\n\tSenha do tipo PREFERENCIAL gerada: %d\n", senha);
    }

    system("pause");
    menuGS();
}


//Menu para chamar uma senha
void menuCS(){
    int senha = 1, tipo = 0, opc = 0;
    
    senha = delete(senhasPreferencial);
    lastPassPref =  senha;
    tipo = 2;

    if(lastPassPref == 0)
    {        
        senha = delete(senhasRegular);
        tipo = 1;
    }

    system("cls");
    printf("\n\n\n");
    printf("_________________________________\n");
    printf("\t   Sistema de Senhas\n");
    printf("\t***  Chamada de Senha  ***\n");

    if(!senha == 0)
    {
        printf("\n\tSenha Chamada: %d\n", senha);

        if(tipo == 2)
            printf("\n\tTipo: PREFERENCIAL\n");
        else
            printf("\n\tTipo: NORMAL\n");

        printf("\n\n\t1 - Chamar outra Senha\n");
    }
    else
        printf("\tNao ha mais senhas para chamar");

    printf("\n\t0 - Voltar ao Menu de Opcoes\n");
    printf("\n_________________________________\n\n");
    scanf("%d", &opc);

    if(opc == 1)
        menuCS(senhasPreferencial, senhasRegular);
    else
        menuOpcoes();
}

//Método para listar fila
void menuLF(){
    int pos = 1; 
    int auxPos = 0;
    system("cls");
    printf("_________________________________\n");
    printf("\t   Sistema de Senhas\n");
    printf("\t***  Listagem da Fila  ***\n");
    
    printf("\t***  SENHAS DO TIPO PREFERENCIAIS:  ***\n");
    printf("\n\tPosicao\tSenha\tTipo");
    pos = printfQueue(pos, senhasPreferencial, 2);
    printfQueue(pos, senhasRegular, 1);

    printf("\n_________________________________\n\n");
    system("pause");

    menuOpcoes();
}