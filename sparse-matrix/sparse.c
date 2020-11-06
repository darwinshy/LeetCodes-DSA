#include <stdio.h>
#include <stdlib.h>

void printSparseMatrix(int *sparseMatrix, int k);
void printMatrix(int *matrix, int r, int c);
int main()
{
    int r, c, k = 0;

    printf("\nEnter number of row      : ");
    scanf("%d", &r);
    printf("Enter number of column   : ");
    scanf("%d", &c);
    printf("\n");

    int *sparseMatrix = (int *)malloc(3 * 100 * sizeof(int));
    int *matrix = (int *)malloc(r * c * sizeof(int));

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("Enter Value at Indices [%d][%d] : ", i, j);
            scanf("%d", (matrix + i * r + j));

            if (*(matrix + i * r + j) != 0)
            {
                // Saves the Row
                *(sparseMatrix + 3 * 0 + k) = i;
                // Saves the Column
                *(sparseMatrix + 3 * 1 + k) = j;
                // Saves the Value
                *(sparseMatrix + 3 * 2 + k) = *(matrix + i * r + j);
                k++;
            }
        }
    }
    printf("\n");
    printf("Input Matrix    :\n");
    printMatrix(matrix, r, c);
    printf("Sparse Matrix   :\n");
    printSparseMatrix(sparseMatrix, k);

    return 0;
}

void printSparseMatrix(int *sparseMatrix, int k)
{

    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            printf("Row    : ");
            break;
        case 1:
            printf("Column : ");
            break;
        case 2:
            printf("Value  : ");
            break;
        }

        for (int j = 0; j < k; j++)
        {
            printf("%d ", *(sparseMatrix + i * k + j));
        }
        printf("\n");
    }
    printf("\n");
}

void printMatrix(int *matrix, int r, int c)
{
    for (int i = 0; i < c; i++)
    {

        for (int j = 0; j < r; j++)
        {
            printf("%d ", *(matrix + i * r + j));
        }
        printf("\n");
    }
    printf("\n");
}