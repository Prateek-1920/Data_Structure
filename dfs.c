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
    struct Node **adj_list;
    bool *visited;
};

struct Stack
{
    int data[MAX];
    int top;
};

void push(struct Stack *stack, int data)
{
    stack->data[++stack->top] = data;
}

int pop(struct Stack *stack)
{
    return stack->data[stack->top--];
}

bool isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

struct Node *createnode(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct Graph *creategraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->num_vertices = vertices;
    graph->adj_list = (struct Node **)malloc(vertices * sizeof(struct Node **));

    for (int i = 0; i < graph->num_vertices; i++)
    {
        graph->adj_list[i] = NULL;
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
    newnode->next = graph->adj_list[src];
    graph->adj_list[src] = newnode;

    // undirected graph
    newnode = createnode(src);
    newnode->next = graph->adj_list[dest];
    graph->adj_list[dest] = newnode;
}

void DFS(struct Graph *graph, int startvertex)
{
    struct Stack stack;
    stack.top = -1;

    push(&stack, startvertex);
    graph->visited[startvertex] = true;

    printf("DFS: ");
    while (!isEmpty(&stack))
    {
        int currentvertex = pop(&stack);
        printf("%d  ", currentvertex);

        struct Node *temp = graph->adj_list[currentvertex];
        while (temp != NULL)
        {
            int adjvertex = temp->data;
            if (!graph->visited[adjvertex])
            {
                push(&stack, adjvertex);
                graph->visited[adjvertex] = true;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main()
{
    int vertices, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Graph *graph = creategraph(vertices);
    printf("Enter edges src to dest and -1 -1 to quit: ");
    while (1)
    {
        scanf("%d%d", &src, &dest);
        if (src == -1 && dest == -1)
        {
            break;
        }
        if (src < 0 || src > vertices || dest < 0 || dest > vertices)
        {
            continue;
        }
        addedge(graph, src, dest);
    }

    DFS(graph, 0);

    return 0;
}