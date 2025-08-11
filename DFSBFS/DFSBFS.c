#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Graph_AdjMatrix {
    int** adjMatrix;
};

#define MaxVert 7
typedef struct Graph_AdjList_Node {
    int vertex;
    struct Graph_AdjList_Node* link;
} Node;
typedef struct Graph_AdjList {
    int vertexcount;
    struct Graph_AdjList_Node* adjHead[MaxVert];
    int visited[MaxVert];
} Graph;

Graph createGraphInstance() {
    Graph G1;
    G1.vertexcount = 0;
    for (int i = 0; i < MaxVert; i++)
        G1.visited[i] = 0;  // 방문 여부 초기화
    for (int i = 0; i < MaxVert; i++)
        G1.adjHead[i] = NULL;
    return G1;
}

void addVertex(Graph* G) {
    if (G->vertexcount < MaxVert)
        G->vertexcount++;
}

void addEdge(Graph* G, int u, int v) {
    Node* V = (Node*)malloc(sizeof(Node));
    V->vertex = v;
    V->link = G->adjHead[u];
    G->adjHead[u] = V;
}

void printGraph(Graph* G1) {
    Node* p;
    for (int i = 0; i < G1->vertexcount; i++) {
        p = G1->adjHead[i];
        printf("정점 %d의 인접리스트: ", i);
        while (p) {
            printf("%d ", p->vertex);
            p = p->link;
        }
        printf("\n");  // 각 인접 리스트 출력 후 개행 추가
    }
}




#define MaxStack 10
typedef struct ArrayStack {
    int top;
    int stack[MaxStack];
}Stack;
Stack* createStackInstance()
{
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->top = -1;
    return S;
}
void push(Stack* S, int item)
{
    if (S->top == MaxStack) {
        printf("overflow : Can't push item\n");
        return;
    }
    S->stack[++S->top] = item;
}
int pop(Stack* S)
{
    if (S->top == -1) {
        printf("underflow: can't pop item\n");
        return -1;
    }
    return S->stack[S->top--];
}

void dfs(Graph* G, int v)
{
    Node* w;
    Stack* S = createStackInstance();
    push(S, v);
    G->visited[v] = true;
    printf("DFS: %d ", v);

    while (S->top != -1) {
        w = G->adjHead[v];

        while (w) {
            if (G->visited[w->vertex] == false) {
                push(S, w->vertex);
                G->visited[w->vertex] = true;
                printf(" %d ", w->vertex);
                v = w->vertex;
                w = G->adjHead[v];
            }
            else w = w->link;
        }

        v = pop(S);
    }
}

#define MaxQueue 10
typedef struct CircularQueue {
    int front, rear;
    int queue[MaxQueue];
}Queue;
Queue* createQueueInstance()
{
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = 0;   Q->rear = 0;
    return Q;
}
void enQueue(Queue* Q, int item)
{
    if (((Q->rear + 1) % MaxQueue) == Q->front) {
        printf("overflow: can't enqueue item\n");
        return;
    }
    Q->rear = (Q->rear + 1) % MaxQueue;
    Q->queue[Q->rear] = item;
}
int deQueue(Queue* Q)
{
    if (Q->front == Q->rear) {
        printf("underflow: can't dequeue item\n");
        return 1;
    }
    Q->front = (Q->front + 1) % MaxQueue;
    return Q->queue[Q->front];
}



void bfs(Graph* G, int v)
{
    Node* w;
    Queue* Q = createQueueInstance();
    G->visited[v] = true;
    printf("BFS: %d", v);
    enQueue(Q, v);

    while (Q->front != Q->rear) {
        v = deQueue(Q);

        for (w = G->adjHead[v]; w; w = w->link) {
            if (!G->visited[w->vertex]) {
                G->visited[w->vertex] = true;
                printf(" %d ", w->vertex);
                enQueue(Q, w->vertex);
            }
        }
    }
}
int main() {
    Graph G1 = createGraphInstance();
    for (int i = 0; i < MaxVert; i++)
        addVertex(&G1);
    addEdge(&G1, 0, 2);
    addEdge(&G1, 0, 1);
    addEdge(&G1, 1, 4);
    addEdge(&G1, 1, 3);
    addEdge(&G1, 1, 0);
    addEdge(&G1, 2, 4);
    addEdge(&G1, 2, 0);
    addEdge(&G1, 3, 6);
    addEdge(&G1, 3, 1);
    addEdge(&G1, 4, 6);
    addEdge(&G1, 4, 2);
    addEdge(&G1, 4, 1);
    addEdge(&G1, 5, 6);
    addEdge(&G1, 6, 5);
    addEdge(&G1, 6, 4);
    addEdge(&G1, 6, 3);

    printGraph(&G1);    getchar();
    bfs(&G1, 0);        getchar();

    return 0;
}
