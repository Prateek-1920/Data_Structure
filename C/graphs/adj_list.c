#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in adjacency list
struct Node
{
    int data;
    struct Node *next;
};

// Structure to represent the adjacency list
struct Graph
{
    int numVertices;
    struct Node **adjLists;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with 'numVertices' vertices
struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Allocate memory for an array of adjacency lists
    graph->adjLists = (struct Node **)malloc(numVertices * sizeof(struct Node *));

    // Initialize each adjacency list as empty by making each head pointer NULL
    for (int i = 0; i < numVertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add an edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    // newNode = createNode(src);
    // newNode->next = graph->adjLists[dest];
    // graph->adjLists[dest] = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        struct Node *temp = graph->adjLists[i];
        printf("Adjacency list of vertex %d ", i);
        while (temp)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main()
{
    int numVertices, src, dest;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Create graph with the given number of vertices
    struct Graph *graph = createGraph(numVertices);

    // Add edges
    printf("Enter edges (src dest), -1 -1 to end:\n");
    while (1)
    {
        scanf("%d %d", &src, &dest);
        if (src == -1 || dest == -1)
            break;
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices)
        {
            printf("Invalid edge: vertex out of range.\n");
            continue;
        }
        addEdge(graph, src, dest);
    }

    // Print the adjacency list representation of the graph
    printGraph(graph);

    return 0;
}
