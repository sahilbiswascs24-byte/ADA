#include <stdio.h>

#define MAX 100
#define INF 999

// Function to return minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n, i, j, k;
    int cost[MAX][MAX], D[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (use %d for INF):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Step 1: Initialize D matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            D[i][j] = cost[i][j];
        }
    }

    // Step 2: Floyd's Algorithm using min()
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (D[i][k] != INF && D[k][j] != INF) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }

    // Step 3: Print result
    printf("\nShortest Path Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (D[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}
