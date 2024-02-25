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
    int items[MAX];
    int top;
};

void push(struct Stack *stack, int element)
{
    stack->top = stack->top + 1;
    stack->items[stack->top] = element;
}

int pop(struct Stack *stack)
{
    int ele = stack->items[stack->top];
    stack->top--;
    return ele;
}

bool isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

struct Node *
createnode(int data)
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

    graph->adj_list = (struct Node **)malloc(vertices * sizeof(struct Node *));

    for (int i = 0; i < graph->num_vertices; i++)
    {
        graph->adj_list[i] = NULL;
    }

    graph->visited = (bool *)malloc(sizeof(bool));
    for (int i = 0; i < graph->num_vertices; i++)
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

    newnode = createnode(src);
    newnode->next = graph->adj_list[dest];
    graph->adj_list[dest] = newnode;
}

void DFS(struct Graph *graph, int startvertex, struct Stack *stack)
{
    graph->visited[startvertex] = true;
    struct Node *temp = graph->adj_list[startvertex];
    while (temp != NULL)
    {
        int adjvertex = temp->data;
        if (!graph->visited[adjvertex])
        {
            DFS(graph, adjvertex, stack);
        }
        temp = temp->next;
    }
    push(stack, startvertex);
}

void printgraph(struct Graph *graph)
{
    for (int i = 0; i < graph->num_vertices; i++)
    {
        struct Node *temp = graph->adj_list[i];
        printf("%d: ", i);
        while (temp != NULL)
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void topologicalsort(struct Graph *graph)
{
    struct Stack stack;
    stack.top = -1;

    for (int i = 0; i < graph->num_vertices; i++)
    {
        if (!graph->visited[i])
        {
            DFS(graph, i, &stack);
        }
    }

    printf("Topological sort: ");
    while (!isEmpty(&stack))
    {
        printf("%d  ", pop(&stack));
    }
    printf("\n");
}

int main()
{
    int vertices, src, dest;
    printf("Enter number of vertices : ");
    scanf("%d", &vertices);

    struct Graph *graph = creategraph(vertices);
    printf("Enter edges src to dest and -1 -1 to exit\n");
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

    printgraph(graph);
    printf("\n");

    topologicalsort(graph);
}