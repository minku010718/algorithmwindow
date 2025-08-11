#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxV 6
#define INF 99999

typedef struct Graph_AdjMatrix {
	int vertexcount;
	int adjMatrix[MaxV][MaxV];
}Graph;

Graph* createGraphInstance(int n)
{
	int i, j;
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->vertexcount = n;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			G->adjMatrix[i][j] = 0;

	return G;
}

void addEdge(Graph* G, int u, int v, int w)
{
	G->adjMatrix[u][v] = w;
}

void printGraph(Graph* G)
{
	printf("그래프(정점의 갯수: %d)\n", G->vertexcount);
	printf("\n인접행렬\n");
	for (int i = 0; i < G->vertexcount; i++) {
		for (int j = 0; j < G->vertexcount; j++) {
			printf(" %d ", G->adjMatrix[i][j]);
		}
		printf("\n");
	}
}

void Prim(Graph* G, int u)
{
	int x = 0, y = 0;
	int i, j, mindist, nextv = 0;
	int weight[MaxV][MaxV], distance[MaxV], pred[MaxV];
	int n = G->vertexcount;
	int edgecount = 0;
	int visited[MaxV];

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (G->adjMatrix[i][j] == 0)
				weight[i][j] = INF;
			else
				weight[i][j] = G->adjMatrix[i][j];
		}
	}

	for (i = 0; i < n; i++) {
		distance[i] = weight[u][i];
		pred[i] = u;
		visited[i] = 0;
	}

	distance[u] = 0;
	visited[u] = true;

	// Printing the distance
	printf("프림 MST(시작점:%d)\n", u);

	while (edgecount < n - 1) {
		// for every vertex in the set S, find the all adjacent vertices
		// , calculate the distance from the vertex selecte at step1.
		// if the vertex si already in the set S, discard ti otherwise
		// choose another vertex nearest to selected vertex a step 1.

		mindist = INF;

		for (int i = 0; i < n; i++) {
			if (visited[i]) {
				for (int j = 0; j < n; j++) {
					if (!visited[j] && weight[i][j]) { // not in selected and there is an edge
						if (mindist > weight[i][j]) {
							mindist = weight[i][j];
							x = i; y = j;
						}
					}
				}
			}
		}
		printf("%d - %d: %d\n", x, y, weight[x][y]);
		visited[y] = true;
		edgecount++;
	}

}

void Dijkstra(Graph* G, int u)
{
	int i, j, count, mindist, nextv = 0;
	int weight[MaxV][MaxV], distance[MaxV], pred[MaxV], visited[MaxV];
	int n = G->vertexcount;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (G->adjMatrix[i][j] == 0)
				weight[i][j] = INF;
			else
				weight[i][j] = G->adjMatrix[i][j];
		}
	}

	for (i = 0; i < n; i++) {
		distance[i] = weight[u][i];
		pred[i] = u;
		visited[i] = 0;
	}

	distance[u] = 0;
	visited[u] = true;
	count = 1;

	while (count < n - 1) {
		mindist = INF;

		for (i = 0; i < n; i++)
			if (distance[i] < mindist && !visited[i]) {
				mindist = distance[i];
				nextv = i;
			}

		visited[nextv] = 1;
		for (i = 0; i < n; i++)
			if (!visited[i])
				if (mindist + weight[nextv][i] < distance[i]) {
					distance[i] = mindist + weight[nextv][i];
					pred[i] = nextv;
				}
		count++;
	}

	//Printing the distance
	printf("다익스트라 최단경로(시작점:%d)\n", u);
	for (i = 0; i < n; i++)
		if (i != u) {
			printf("\nDistance from %d to %d: %d", u, i, distance[i]);
		}
}

int main() {
	Graph* G1 = createGraphInstance(6);
	addEdge(G1, 0, 1, 4);
	addEdge(G1, 0, 2, 4);
	addEdge(G1, 1, 0, 4);
	addEdge(G1, 1, 2, 2);
	addEdge(G1, 2, 0, 4);
	addEdge(G1, 2, 1, 2);
	addEdge(G1, 2, 3, 3);
	addEdge(G1, 2, 4, 2);
	addEdge(G1, 2, 5, 4);
	addEdge(G1, 3, 2, 3);
	addEdge(G1, 3, 5, 3);
	addEdge(G1, 4, 2, 2);
	addEdge(G1, 4, 5, 3);
	addEdge(G1, 5, 2, 4);
	addEdge(G1, 5, 3, 3);
	addEdge(G1, 5, 4, 3);

	printGraph(G1);		getchar();
	Prim(G1, 2);		getchar();
	printGraph(G1);		getchar();
	Dijkstra(G1, 0);	getchar();
}