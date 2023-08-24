
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "../../miniRT/includes/miniRT.h"

void    teste_check_file()
{
    //caminho invalido
    char *arg_5[] ={"executavel", "arquivo_não_existe.txt", NULL};


    if (check_file(arg_5) == FALSE)
    {
        printf("TESTE 1 :Success --->Arquivo não existe\n");
    }
    else
        printf("ERROR TESTE 1: achou o arquivo\n");

    //não existe
    printf("\n\n\n");
    char *arg_4[] ={"executavel", "../../arquivo_não_exite.txt", NULL};



    if (check_file(arg_4) == FALSE)
    {
        printf("TESTE 2 :Success --->Arquivo não existe\n");
    }
    else
        printf("ERROR TESTE 2: achou o arquivo\n\n");

    //arquivo exite tem que abrir normal normal
    //----------------------------------
    printf("\n\n\n\n");
    char *arg_3[] ={"executavel", "../existe.rt", NULL};

    if (check_file(arg_3) == TRUE)
    {
        printf("TESTE 3 Success Abriu o arquivo\n");
    }
    else
        printf("ERROR TESTE 3 Falha ao abrir o arquivo\n");
    
    //-----------------------------
    printf("\n\n\n");
    char *arg_1[] = {"executavel", "existe.rt", NULL};

    if (check_file(arg_1) == TRUE)
    {
        printf("TESTE 4 SUCCESS: Abriu o arquivo: Success\n");
    }
    else
        printf("TESTE 4 ERROR: Falha ao abrir o arquivo\n");
    printf("\n\n\n");

    //---------------------------------------------

    char *arg_2[] = {"executavel", "outra_extensao.txt", NULL};

    if (check_file(arg_2) == FALSE)
    {
        printf("TESTE 5 SUCCESS: Extensão diferente: Success\n");
    }
    else
        printf("TESTE  ERROR: abriu arquivo com extensão diferente\n");
}

void testeRead_file()
{
    if (read_file("existe.rt"))
    {
        printf("Empty file\n");
    }
}

int main(int argc, char **argv)
{
    // teste_check_file();
    testeRead_file();
}
