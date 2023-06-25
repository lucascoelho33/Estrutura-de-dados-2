#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de um n� da lista de adjac�ncias
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Definindo a estrutura de uma lista de adjac�ncias
struct AdjList {
    struct AdjListNode* head;
};

// Definindo a estrutura do grafo
struct Graph {
    int V;
    struct AdjList* array;
};

// Fun��o para criar um novo n� da lista de adjac�ncias
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Fun��o para criar um grafo com V v�rtices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    
    
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    
    
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }
    
    return graph;
}


void addEdge(struct Graph* graph, int src, int dest) {
    
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    
    
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Fun��o para imprimir o grafo
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("Adjac�ncias do v�rtice %d: ", v);
        while (pCrawl) {
            printf("%d ", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main() {
    int V = 6; 
    
    struct Graph* graph = createGraph(V);
    
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    
    printGraph(graph);
    
    return 0;
}
