#include <stdio.h>

int main() {
    int n, i, j;
    int adj[20][20];
    int indegree[20] = {0};
    int queue[20];
    int front = 0, rear = -1;
    int topo[20];
    int count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    /* Calculate indegree of each vertex */
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    /* Insert vertices with indegree 0 into queue */
    for(i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    /* Source Removal Method */
    while(front <= rear) {
        int v = queue[front++];
        topo[count++] = v;

        for(j = 0; j < n; j++) {
            if(adj[v][j] == 1) {
                indegree[j]--;

                if(indegree[j] == 0) {
                    queue[++rear] = j;
                }
            }
        }
    }

    /* Check for cycle */
    if(count != n) {
        printf("Topological ordering not possible (Graph contains cycle)\n");
    } else {
        printf("Topological Order:\n");
        for(i = 0; i < count; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}
