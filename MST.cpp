#include <stdio.h>

#define MAX 20

int parent[MAX];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void kruskalMST(int cost[MAX][MAX], int n) {
    int mincost = 0, edges = 0, a, b, u, v, i, j;
    while (edges < n - 1) {
        int min = 9999;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            printf("Edge %d: (%d, %d) cost: %d\n", edges++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 9999;
    }
    printf("Minimum Cost: %d\n", mincost);
}

int main() {
    int cost[MAX][MAX], n, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    kruskalMST(cost, n);
    return 0;
}
