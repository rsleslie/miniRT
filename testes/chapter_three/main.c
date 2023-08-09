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

    matrix_2 = create_matrices(4, 4);

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

void    testIdentityMatrix()
{
    t_matrices matrix;
    t_matrices teste_resultado;

    matrix = create_matrices(4, 4);
    teste_resultado = identity_matrix(matrix);
    if (compare_matrix(matrix, teste_resultado))
        printf("Successful function!\n");
    else
        printf("Unsucessful function!\n");
}

void    teste_transpose()
{
    t_matrices  origin_matrix;
    t_matrices  transposing_matrix;

    origin_matrix = create_matrices(4, 4);
    origin_matrix.matrices[0][0] = 0;
    origin_matrix.matrices[0][1] = 9;
    origin_matrix.matrices[0][2] = 3;
    origin_matrix.matrices[0][3] = 0;
    origin_matrix.matrices[1][0] = 9;
    origin_matrix.matrices[1][1] = 8;
    origin_matrix.matrices[1][2] = 0;
    origin_matrix.matrices[1][3] = 8;
    origin_matrix.matrices[2][0] = 1;
    origin_matrix.matrices[2][1] = 8;
    origin_matrix.matrices[2][2] = 5;
    origin_matrix.matrices[2][3] = 3;
    origin_matrix.matrices[3][0] = 0;
    origin_matrix.matrices[3][1] = 0;
    origin_matrix.matrices[3][2] = 5;
    origin_matrix.matrices[3][3] = 8;

    transposing_matrix = transpose(origin_matrix);
    int line = -1;
    while (++line < transposing_matrix.x)
    {
        int col = -1; 
        while (++col < transposing_matrix.y)
            printf("| %f ", transposing_matrix.matrices[line][col]);
        printf("\n");
    }
}

void    testeDeterminant()
{
    t_matrices  m;

    m = create_matrices(2 ,2);
    m.matrices[0][0] = 1;
    m.matrices[0][1] = 5;
    m.matrices[1][0] = -3;
    m.matrices[1][1] = 2;

    if (equal(determinant(m), 17))
        printf("Success!!\n");
    else
        printf("Failure!\n");

}

void    testeSubmatrix()
{
    t_matrices  m;
    t_matrices  result;
    int         col;

    m = create_matrices(3, 3);
    m.matrices[0][0] = 1;
    m.matrices[0][1] = 5;
    m.matrices[0][2] = 0;
    m.matrices[1][0] = -3;
    m.matrices[1][1] = 2;
    m.matrices[1][2] = 7;
    m.matrices[2][0] = 0;
    m.matrices[2][1] = 6;
    m.matrices[2][2] = -3;
    
    result = submatrix(m, 0, 2);
    int line = -1;
    while (++line < result.x)
    {
        col = -1;
        while (++col < result.y)
            printf("| %f ", result.matrices[line][col]);
        printf("\n");
    }

    printf("\n\n");
    //-------------------
    t_matrices  m2;
    t_matrices  result2;

    m2 = create_matrices(4, 4);
    m2.matrices[0][0] = -6;
    m2.matrices[0][1] = 1;
    m2.matrices[0][2] = 1;
    m2.matrices[0][3] = 6;
    m2.matrices[1][0] = -8;
    m2.matrices[1][1] = 5;
    m2.matrices[1][2] = 8;
    m2.matrices[1][3] = 6;
    m2.matrices[2][0] = -1;
    m2.matrices[2][1] = 0;
    m2.matrices[2][2] = 8;
    m2.matrices[2][3] = 2;
    m2.matrices[3][0] = -7;
    m2.matrices[3][1] = 1;
    m2.matrices[3][2] = -1;
    m2.matrices[3][3] = 1;

    result2 = submatrix(m2, 2, 1);
   line = -1;
    while (++line < result2.x)
    {
        col = -1;
        while (++col < result2.y)
            printf("| %f ", result2.matrices[line][col]);
        printf("\n");
    }
}

void    testeMinor()
{
    t_matrices a;
    t_matrices b;
    float   d_etermiant;

    a = create_matrices(3, 3);
    a.matrices[0][0] = 3;
    a.matrices[0][1] = 5;
    a.matrices[0][2] = 0;
    a.matrices[1][0] = 2;
    a.matrices[1][1] = -1;
    a.matrices[1][2] = 5;
    a.matrices[2][0] = 6;
    a.matrices[2][1] = -1;
    a.matrices[2][2] = 5;

    b = submatrix(a, 1, 0);
    d_etermiant = determinant(b);
    if (equal(d_etermiant, minor(a, 1, 0)))
        printf("Successful function!\n");
    else
        printf("Failure!\n");
}

void    testConfactor()
{
    t_matrices a;

    a = create_matrices(3, 3);
    a.matrices[0][0] = 3;
    a.matrices[0][1] = 5;
    a.matrices[0][2] = 0;
    a.matrices[1][0] = 2;
    a.matrices[1][1] = -1;
    a.matrices[1][2] = -7;
    a.matrices[2][0] = 6;
    a.matrices[2][1] = -1;
    a.matrices[2][2] = 5;

    if (equal(minor(a, 0, 0), cofactor(a, 0, 0)))
        printf("Successful test one result %f minor %f!\n", cofactor(a, 0, 0), minor(a, 0, 0));
    else
        printf("Failure teste one result %f minor %f!\n", cofactor(a, 0, 0), minor(a, 0, 0));
    
    if (!equal(minor(a, 1, 0), cofactor(a, 1, 0)))
        printf("Successful test two result %f minor %f!\n", cofactor(a, 1, 0), minor(a, 1, 0));
    else
        printf("Failure teste two result %f minor %f!\n", cofactor(a, 1, 0), minor(a, 1, 0));
}

void    testDeterminantMatrixThree()
{
    t_matrices a;

    a = create_matrices(3, 3);
    a.matrices[0][0] = 1;
    a.matrices[0][1] = 2;
    a.matrices[0][2] = 6;
    a.matrices[1][0] = -5;
    a.matrices[1][1] = 8;
    a.matrices[1][2] = -4;
    a.matrices[2][0] = 2;
    a.matrices[2][1] = 6;
    a.matrices[2][2] = 4;

    if (equal(cofactor(a, 0, 0), 56))
        printf("Successful 56\n");
    if (equal(cofactor(a, 0, 1), 12))
        printf("Successful 12\n");
    if (equal(cofactor(a, 0, 2), -46))
        printf("Successful -46\n");
    
    if (equal(determinant(a), -196))
        printf("Successful %f\n", determinant(a));
    else
        printf("error %f\n", determinant(a));

    printf("\n\nteste matrix 4x4\n\n");

    a = create_matrices(4, 4);
    a.matrices[0][0] = -2;
    a.matrices[0][1] = -8;
    a.matrices[0][2] = 3;
    a.matrices[0][3] = 5;
    a.matrices[1][0] = -3;
    a.matrices[1][1] = 1;
    a.matrices[1][2] = 7;
    a.matrices[1][3] = 3;
    a.matrices[2][0] = 1;
    a.matrices[2][1] = 2;
    a.matrices[2][2] = -9;
    a.matrices[2][3] = 6;
    a.matrices[3][0] = -6;
    a.matrices[3][1] = 7;
    a.matrices[3][2] = 7;
    a.matrices[3][3] = -9;


    if (equal(cofactor(a, 0, 0), 690))
        printf("Successful 690\n");
    if (equal(cofactor(a, 0, 1), 447))
        printf("Successful 447\n");
    if (equal(cofactor(a, 0, 2), 210))
        printf("Successful 210\n");
    if (equal(cofactor(a, 0, 3), 51))
        printf("Successful 51\n");
    if (equal(determinant(a), -4071))
        printf("Successful %f\n", determinant(a));
    else
        printf("error %f\n", determinant(a));
}

void invertableMatrix()
{
    t_matrices a;

    a = create_matrices(4, 4);
    a.matrices[0][0] = 6;
    a.matrices[0][1] = 4;
    a.matrices[0][2] = 4;
    a.matrices[0][3] = 4;
    a.matrices[1][0] = 5;
    a.matrices[1][1] = 5;
    a.matrices[1][2] = 7;
    a.matrices[1][3] = 6;
    a.matrices[2][0] = 4;
    a.matrices[2][1] = -9;
    a.matrices[2][2] = 3;
    a.matrices[2][3] = -7;
    a.matrices[3][0] = 9;
    a.matrices[3][1] = 1;
    a.matrices[3][2] = 7;
    a.matrices[3][3] = -6;

    if (equal(determinant(a), -2120))
        printf("is invertible\n");

    a.matrices[0][0] = -4;
    a.matrices[0][1] = 2;
    a.matrices[0][2] = -2;
    a.matrices[0][3] = -3;
    a.matrices[1][0] = 9;
    a.matrices[1][1] = 6;
    a.matrices[1][2] = 2;
    a.matrices[1][3] = 6;
    a.matrices[2][0] = 0;
    a.matrices[2][1] = -5;
    a.matrices[2][2] = 1;
    a.matrices[2][3] = -5;
    a.matrices[3][0] = 0;
    a.matrices[3][1] = 0;
    a.matrices[3][2] = 0;
    a.matrices[3][3] = 0;

    if (equal(determinant(a), 0))
        printf("is not invertible\n");
    
}

void    testInverse()
{
    t_matrices  a;
    t_matrices  b;

    a = create_matrices(4, 4);
    a.matrices[0][0] = -5;
    a.matrices[0][1] = 2;
    a.matrices[0][2] = 6;
    a.matrices[0][3] = -8;
    a.matrices[1][0] = 1;
    a.matrices[1][1] = -5;
    a.matrices[1][2] = 1;
    a.matrices[1][3] = 8;
    a.matrices[2][0] = 7;
    a.matrices[2][1] = 7;
    a.matrices[2][2] = -6;
    a.matrices[2][3] = -7;
    a.matrices[3][0] = 1;
    a.matrices[3][1] = -3;
    a.matrices[3][2] = 7;
    a.matrices[3][3] = 4;

    b = inverse(a);

    if (equal(determinant(a), 532))
        printf("Successfull determinant 532\n");
    else
        printf("Different determinant 532\n");
    if (equal(cofactor(a, 2, 3), -160))
        printf("Successful cofractor -160\n");
    else
        printf("different cofractor -160\n");

    if (equal(b.matrices[3][2], (float)-160/(float)532))
        printf("Successful, equal b[3,2] = -160/532\n");
    else
        printf("Different, equal b[3,2] = -160/532\n");

    if (equal(cofactor(a, 3, 2), 105))
        printf("Successful cofractor 105\n");
    else
        printf("different cofractor 105\n");
   
    if (equal(b.matrices[2][3], (float)105/(float)532))
        printf("Successful, equal b[2,3] = 105/532\n");
    else
        printf("Different, equal b[2,3] = 105/532 b.matrices %f\n", b.matrices[2][3]);

    int line = -1;
    while (++line < a.x)
    {
        int col = -1;
        while (++col < a.y)
            printf("| %f ", b.matrices[line][col]);
        printf("\n");
    }
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
    // testeMultMatrixAndTuple();
    // testIdentityMatrix();
    // teste_transpose();
    // testeDeterminant();
    // testeSubmatrix();
    // testeMinor();
    // testConfactor();
    // testDeterminantMatrixThree();
    // invertableMatrix();
    testInverse();
    return (0);
}
