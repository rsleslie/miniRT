
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "../../miniRT/includes/miniRT.h"

// void    teste_check_file()
// {
//     //caminho invalido
//     char *arg_5[] ={"executavel", "arquivo_não_existe.txt", NULL};


//     if (check_file(arg_5) == FALSE)
//     {
//         printf("TESTE 1 :Success --->Arquivo não existe\n");
//     }
//     else
//         printf("ERROR TESTE 1: achou o arquivo\n");

//     //não existe
//     printf("\n\n\n");
//     char *arg_4[] ={"executavel", "../../arquivo_não_exite.txt", NULL};



//     if (check_file(arg_4) == FALSE)
//     {
//         printf("TESTE 2 :Success --->Arquivo não existe\n");
//     }
//     else
//         printf("ERROR TESTE 2: achou o arquivo\n\n");

//     //arquivo exite tem que abrir normal normal
//     //----------------------------------
//     printf("\n\n\n\n");
//     char *arg_3[] ={"executavel", "../existe.rt", NULL};

//     if (check_file(arg_3) == TRUE)
//     {
//         printf("TESTE 3 Success Abriu o arquivo\n");
//     }
//     else
//         printf("ERROR TESTE 3 Falha ao abrir o arquivo\n");
    
//     //-----------------------------
//     printf("\n\n\n");
//     char *arg_1[] = {"executavel", "existe.rt", NULL};

//     if (check_file(arg_1) == TRUE)
//     {
//         printf("TESTE 4 SUCCESS: Abriu o arquivo: Success\n");
//     }
//     else
//         printf("TESTE 4 ERROR: Falha ao abrir o arquivo\n");
//     printf("\n\n\n");

//     //---------------------------------------------

//     char *arg_2[] = {"executavel", "outra_extensao.txt", NULL};

//     if (check_file(arg_2) == FALSE)
//     {
//         printf("TESTE 5 SUCCESS: Extensão diferente: Success\n");
//     }
//     else
//         printf("TESTE  ERROR: abriu arquivo com extensão diferente\n");
// }

// void teste_parser()
// {
//     if (!parser("arquivos/arq_error.txt"))
//     {
//         printf("TESTE 1 OK\n");
//     }
//     else
//         printf("TEST 1 ERROR\n");

//     if (parser("arquivos/arq1.rt"))
//     {
//         printf("TESTE 2 OK\n");
//     }
//     else
//         printf("TEST 2 ERROR\n");

//     if (!parser("arquivos/arq2.rt"))
//     {
//         printf("TESTE 3 OK\n");
//     }
//     else
//         printf("TEST 3 ERROR\n");

//     if (!parser("arquivos/arq3.rt"))
//     {
//         printf("TESTE 4 OK\n");
//     }
//     else
//         printf("TEST 4 ERROR\n");

//     if (!parser("arquivos/arq4.rt"))
//     {
//         printf("TESTE 5 OK\n");
//     }
//     else
//         printf("TEST 5 ERROR\n");
// }

// void teste_camera()
// {
//     if (!parser("arquivos2/arq_error.txt"))
//     {
//         printf("TESTE 1 OK\n");
//     }
//     else
//         printf("TEST 1 ERROR\n");
//     printf("\n-----------------\n");

//     if (parser("arquivos2/arq1.rt"))
//     {
//         printf("TESTE 2 OK\n");
//     }
//     else
//         printf("TEST 2 ERROR\n");
//     printf("\n-----------------\n");

//     if (!parser("arquivos2/arq2.rt"))
//     {
//         printf("TESTE 3 OK\n");
//     }
//     else
//         printf("TEST 3 ERROR\n");
//     printf("\n-----------------\n");

//     if (!parser("arquivos2/arq3.rt"))
//     {
//         printf("TESTE 4 OK\n");
//     }
//     else
//         printf("TEST 4 ERROR\n");

//     printf("\n-----------------\n");
//     if (!parser("arquivos2/arq4.rt"))
//     {
//         printf("TESTE 5 OK\n");
//     }
//     else
//         printf("TEST 5 ERROR\n");

//       printf("\n-----------------\n");
//     if (!parser("arquivos2/arq5.rt"))
//     {
//         printf("TESTE 6 OK\n");
//     }
//     else
//         printf("TEST 6 ERROR\n");
// }

// void teste_ligth()
// {
//     if (!parser("arquivo3/arq_error.txt"))
//     {
//         printf("TESTE 1 OK\n");
//     }
//     else
//         printf("TEST 1 ERROR\n");
//     printf("\n-----------------\n");

//     if (parser("arquivo3/arq1.rt"))
//     {
//         printf("TESTE 2 OK\n");
//     }
//     else
//         printf("TEST 2 ERROR\n");
//     printf("\n-----------------\n");

//     if (!parser("arquivo3/arq2.rt"))
//     {
//         printf("TESTE 3 OK\n");
//     }
//     else
//         printf("TEST 3 ERROR\n");
//     printf("\n-----------------\n");

//     if (!parser("arquivo3/arq3.rt"))
//     {
//         printf("TESTE 4 OK\n");
//     }
//     else
//         printf("TEST 4 ERROR\n");

//     printf("\n-----------------\n");
//     if (!parser("arquivo3/arq4.rt"))
//     {
//         printf("TESTE 5 OK\n");
//     }
//     else
//         printf("TEST 5 ERROR\n");

//       printf("\n-----------------\n");
//     if (!parser("arquivo3/arq5.rt"))
//     {
//         printf("TESTE 6 OK\n");
//     }
//     else
//         printf("TEST 6 ERROR\n");
// }

// void teste_sphere()
// {

//     if (parser("arquivo3/arq1.rt"))
//     {
//         printf("TESTE 2 OK\n");
//     }
//     else
//         printf("TEST 2 ERROR\n");
//     printf("\n-----------------\n");

//     if (!parser("arquivo3/arq2.rt"))
//     {
//         printf("TESTE 3 OK\n");
//     }
//     else
//         printf("TEST 3 ERROR\n");
//     printf("\n-----------------\n");

    
// }

void tes_parser()
{
    t_objects *rt;

    rt = (t_objects *)malloc(sizeof(t_objects));
    parser(&rt, "arquivo3/arq1.rt");

    printf("ambiente: ratio %f,\ncolor %f,%f,%f\n", rt->a.ratio, rt->a.color.r,rt->a.color.g,rt->a.color.b);
    printf("camera: coordenates %f,%f,%f, vector %f,%f,%f, FOV: %i\n", rt->c.coordinates.x, rt->c.coordinates.y,rt->c.coordinates.z, rt->c.vector.x, rt->c.vector.y,rt->c.vector.z, rt->c.fov);
    printf("ligth: coordenates %f,%f,%f, ratio %f color %f,%f,%f\n\n",rt->l.coordinates.x, rt->l.coordinates.y,rt->l.coordinates.z, rt->l.brightness, rt->l.color.r,rt->l.color.g,rt->l.color.b);
    printf("csp: coordenates %f,%f,%f, diame %f color %f,%f,%f\n\n",rt->sp[0].coordinates.x, rt->sp[0].coordinates.y,rt->sp[0].coordinates.z, rt->sp[0].diameter, rt->sp[0].color.r,rt->sp[0].color.g,rt->sp[0].color.b);

}

int main(int argc, char **argv)
{
    // teste_check_file();
    // teste_parser();
    // teste_camera();
    // teste_ligth();
    // teste_sphere();
    tes_parser();
}
