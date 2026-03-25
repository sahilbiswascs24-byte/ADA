#include <stdio.h>

void kruskals();
int find(int);
void union_ij(int, int);

int cost[10][10], min, i, j, k, parent[10];
int count, n, u, v, t[10][2], sum;

int main() {
    printf("Enter no. of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskals();

    return 0;
}

void kruskals() {
    count = 0;
    k = 0;
    sum = 0;

    for(i = 0; i < n; i++)
        parent[i] = i;

    while(count != n - 1) {
        min = 999;

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(cost[i][j] < min && cost[i][j] != 0) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        i = find(u);
        j = find(v);

        if(i != j) {
            t[k][0] = u;
            t[k][1] = v;
            k++;
            count++;
            sum = sum + cost[u][v];
            union_ij(i, j);
        }

        cost[u][v] = cost[v][u] = 999;
    }

    printf("Spanning Tree:\n");
    for(i = 0; i < k; i++) {
        printf("%d -> %d\n", t[i][0], t[i][1]);
    }

    printf("Total cost = %d\n", sum);
}

void union_ij(int i, int j) {
    if(i < j)
        parent[j] = i;
    else
        parent[i] = j;
}

int find(int v) {
    while(parent[v] != v) {
        v = parent[v];
    }
    return v;
}