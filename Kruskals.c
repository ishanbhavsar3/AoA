#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

int parent[MAXN + 1], rank_[MAXN + 1];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;

    if (rank_[px] < rank_[py]) parent[px] = py;
    else if (rank_[px] > rank_[py]) parent[py] = px;
    else {
        parent[py] = px;
        rank_[px]++;
    }
}

struct Edge {
    int u, v, w;
};

int compare(const void *a, const void *b) {
    const struct Edge *ea = (const struct Edge *)a;
    const struct Edge *eb = (const struct Edge *)b;
    return ea->w - eb->w;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    if (scanf("%d %d", &V, &E) != 2) return 1;

    if (V > MAXN) {
        printf("Max supported vertices = %d\n", MAXN);
        return 1;
    }

    int cost[V + 1][V + 1];
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            cost[i][j] = 0;

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        if (scanf("%d %d %d", &u, &v, &w) != 3) return 1;

        if (u < 1 || u > V || v < 1 || v > V) {
            printf("Invalid vertex in edge (%d, %d)\n", u, v);
            return 1;
        }

        cost[u][v] = w;
        cost[v][u] = w;
    }

    struct Edge edges[V * V];
    int edgeCount = 0;
    for (int i = 1; i <= V; i++)
        for (int j = i + 1; j <= V; j++)
            if (cost[i][j] != 0) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].w = cost[i][j];
                edgeCount++;
            }

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
        rank_[i] = 0;
    }

    qsort(edges, edgeCount, sizeof(struct Edge), compare);

    printf("\nEdges in MST:\n");
    int minCost = 0, count = 0;

    for (int i = 0; i < edgeCount && count < V - 1; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) != find(v)) {
            printf("(%d, %d) -> Weight: %d\n", u, v, w);
            unite(u, v);
            minCost += w;
            count++;
        }
    }

    printf("\nTotal vertices: %d\n", V);
    printf("Total edges in MST: %d\n", count);
    printf("Minimum Cost: %d\n", minCost);

    return 0;
}
