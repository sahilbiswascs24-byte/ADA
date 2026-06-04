#include <stdio.h>
#include <stdlib.h>

int board[20];
int count = 0;

/* Function to check whether queen can be placed */
int place(int row, int column)
{
    int j;

    for(j = 1; j < row; j++)
    {
        if(board[j] == column ||
           abs(board[j] - column) == abs(j - row))
        {
            return 0;
        }
    }

    return 1;
}

/* Function to print solution */
void printSolution(int n)
{
    int i, j;

    printf("\nSolution %d:\n", ++count);

    for(i = 1; i <= n; i++)
        printf("%d ", board[i]);

    printf("\n\nChess Board Representation:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }

    printf("\n");
}

/* Recursive function for N-Queens */
void queen(int row, int n)
{
    int column;

    for(column = 1; column <= n; column++)
    {
        if(place(row, column))
        {
            board[row] = column;

            if(row == n)
                printSolution(n);
            else
                queen(row + 1, n);
        }
    }
}

int main()
{
    int n;

    printf("Enter value of N: ");
    scanf("%d", &n);

    queen(1, n);

    if(count == 0)
        printf("No solution exists.\n");

    return 0;
}
