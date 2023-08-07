#include "../../miniRT/includes/miniRT.h"
#include <stdio.h>

void    testMatrices_four()
{
    t_matrices matrix;
    
    matrix = create_matrices(4, 4);

    matrix.matrices[0][0] = 1;
    matrix.matrices[0][3] = 4;
    matrix.matrices[1][0] = 5.5;
    matrix.matrices[1][2] = 7.5;
    matrix.matrices[2][2] = 11;
    matrix.matrices[3][0] = 13.5;
    matrix.matrices[3][2] = 15.5;

    int i = -1;
    while (++i != 4)
    {
        int j = -1;
        while (++j != 4)
            printf("| %f ", matrix.matrices[i][j]);
        printf("\n");
    }
}

void    testMatrices_three()
{
    t_matrices matrix;
    
    matrix = create_matrices(3, 3);

    matrix.matrices[0][0] = -3;
    matrix.matrices[1][1] = -2;
    matrix.matrices[2][2] = 1;

    int i = -1;
    while (++i != 3)
    {
        int j = -1;
        while (++j != 3)
            printf("| %f ", matrix.matrices[i][j]);
        printf("\n");
    }
}

void    testMatrices_two()
{
    t_matrices matrix;

    matrix = create_matrices(2, 2);

    matrix.matrices[0][0] = 3;
    matrix.matrices[0][1] = 5;
    matrix.matrices[1][0] = 1;
    matrix.matrices[1][1] = -2;
    
    int i = -1;
    while (++i != matrix.x)
    {
        int j = -1;
        while (++j < matrix.y)
            printf("| %f ", matrix.matrices[i][j]);
        printf("\n");
    }
}

void    testeCompare()
{
    t_matrices matrix;

    matrix = create_matrices(2, 2);

    matrix.matrices[0][0] = 3;
    matrix.matrices[0][1] = 5;
    matrix.matrices[1][0] = 1;
    matrix.matrices[1][1] = -2;
    
    t_matrices matrix_2;

    matrix_2 = create_matrices(2, 2);

    matrix_2.matrices[0][0] = 3;
    matrix_2.matrices[0][1] = 5;
    matrix_2.matrices[1][0] = 1;
    matrix_2.matrices[1][1] = -2;
    
    if (compare_matrix(matrix, matrix_2))
        printf("são iguais!\n");
    else
        printf("são diferentes\n");
}

void    testeMult()
{
    t_matrices matrix;

    matrix = create_matrices(4, 4);

    matrix.matrices[0][0] = 1;
    matrix.matrices[0][1] = 2;
    matrix.matrices[0][2] = 3;
    matrix.matrices[0][3] = 4;
    matrix.matrices[1][0] = 5;
    matrix.matrices[1][1] = 6;
    matrix.matrices[1][2] = 7;
    matrix.matrices[1][3] = 8;
    matrix.matrices[2][0] = 9;
    matrix.matrices[2][1] = 8;
    matrix.matrices[2][2] = 7;
    matrix.matrices[2][3] = 6;
    matrix.matrices[3][0] = 5;
    matrix.matrices[3][1] = 4;
    matrix.matrices[3][2] = 3;
    matrix.matrices[3][3] = 2;

    t_matrices matrix_2;

    matrix_2 = create_matrices(3, 3);

    matrix_2.matrices[0][0] = -2;
    matrix_2.matrices[0][1] = 1;
    matrix_2.matrices[0][2] = 2;
    matrix_2.matrices[0][3] = 3;
    matrix_2.matrices[1][0] = 3;
    matrix_2.matrices[1][1] = 2;
    matrix_2.matrices[1][2] = 1;
    matrix_2.matrices[1][3] = -1;
    matrix_2.matrices[2][0] = 4;
    matrix_2.matrices[2][1] = 3;
    matrix_2.matrices[2][2] = 6;
    matrix_2.matrices[2][3] = 5;
    matrix_2.matrices[3][0] = 1;
    matrix_2.matrices[3][1] = 2;
    matrix_2.matrices[3][2] = 7;
    matrix_2.matrices[3][3] = 8;
    
   t_matrices m_matrix;

   m_matrix = mult_matrices(matrix, matrix_2);
   int i = -1;
    while (++i != m_matrix.x)
    {
        int j = -1;
        while (++j < m_matrix.y)
            printf("| %f ", m_matrix.matrices[i][j]);
        printf("\n");
    }
}

void    testeMultMatrixAndTuple()
{
    t_matrices matrix;

    matrix = create_matrices(4, 4);

    matrix.matrices[0][0] = 1;
    matrix.matrices[0][1] = 2;
    matrix.matrices[0][2] = 3;
    matrix.matrices[0][3] = 4;
    matrix.matrices[1][0] = 2;
    matrix.matrices[1][1] = 4;
    matrix.matrices[1][2] = 4;
    matrix.matrices[1][3] = 2;
    matrix.matrices[2][0] = 8;
    matrix.matrices[2][1] = 6;
    matrix.matrices[2][2] = 4;
    matrix.matrices[2][3] = 1;
    matrix.matrices[3][0] = 0;
    matrix.matrices[3][1] = 0;
    matrix.matrices[3][2] = 0;
    matrix.matrices[3][3] = 1;

    t_tuple t;

    t = mult_matrix_tuple(matrix, tuples(1,2,3,1));
    printf("%f,%f, %f, %f \n", t.x,t.y,t.z,t.w);
}

int main()
{
    // testMatrices_two();
    // printf("\n");
    // testMatrices_three();
    // printf("\n");
    // testMatrices_four();
    // testeMult();
    // testeCompare();
    testeMultMatrixAndTuple();
    return (0);
}