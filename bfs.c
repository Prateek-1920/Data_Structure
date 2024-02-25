#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

struct Node
{
    int data;
    struct Node *next;
};

struct Graph
{
    int num_vertices;
    struct Node **adjlist;
    bool *visited;
};

struct Queue
{
    int items[MAX];
    int front;
    int rear;
};

void enqueue(struct Queue *queue, int value)
{
    if (queue->rear == MAX - 1)
    {
        return; // queue full
    }
    if (queue->front == -1)
    {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = value;
}

int dequeue(struct Queue *queue)
{
    if (queue->front == -1)
    {
        return -1;
    }

    int item = queue->items[queue->front];
    if (queue->front >= queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front++;
    }
    return item;
}

bool isempty(struct Queue *queue)
{
    return (queue->front == -1);
}

struct Node *createnode(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct Graph *creatgraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->num_vertices = vertices;

    graph->adjlist = (struct Node **)malloc(vertices * sizeof(struct Node *));

    for (int i = 0; i < graph->num_vertices; i++)
    {
        graph->adjlist[i] = NULL;
    }

    graph->visited = (bool *)malloc(vertices * sizeof(bool));
    for (int i = 0; i < vertices; i++)
    {
        graph->visited[i] = false;
    }
    return graph;
}

void addedge(struct Graph *graph, int src, int dest)
{
    struct Node *newnode = createnode(dest);
    newnode->next = graph->adjlist[src];
    graph->adjlist[src] = newnode;

    newnode = createnode(src);
    newnode->next = graph->adjlist[dest];
    graph->adjlist[dest] = newnode;
}

void BFS(struct Graph *graph, int startvertex)
{
    struct Queue queue;
    queue.front = queue.rear = -1;
    enqueue(&queue, startvertex);
    graph->visited[startvertex] = true;

    printf("BFS: ");
    while (!isempty(&queue))
    {
        int currentvertex = dequeue(&queue);
        printf("%d  ", currentvertex);
        struct Node *temp = graph->adjlist[currentvertex];
        while (temp != NULL)
        {
            int adjvertex = temp->data;
            if (!graph->visited[adjvertex])
            {
                enqueue(&queue, adjvertex);
                graph->visited[adjvertex] = true;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void printgraph(struct Graph *graph)
{
    for (int i = 0; i < graph->num_vertices; i++)
    {
        struct Node *temp = graph->adjlist[i];
        printf("%d :", i);
        while (temp != NULL)
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(int argc, char const *argv[])
{
    int vertices, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Graph *graph = creatgraph(vertices);
    printf("Enter vertices src dest and -1 -1 to exit: ");

    while (1)
    {
        scanf("%d%d", &src, &dest);
        if (src == -1 && dest == -1)
        {
            break;
        }
        else if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
        {
            continue;
        }
        addedge(graph, src, dest);
    }

    printgraph(graph);
    printf("\n");
    BFS(graph, 0);

    return 0;
}
