#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100


typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES];
int visited[MAX_VERTICES];


Node* createNode(int vertex) {
  
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;    
    
    
}


void addEdge(int u, int v) {
 
    Node* newNode = createNode(v);
    newNode->next = adjList[u];

    adjList[u] = newNode;    
    
    
}


void sortAdjList(int V) {
  
    for (int i = 0; i < V; i++) {
        Node *head = adjList[i];
        if (!head) continue;
        for (Node *p1 = head; p1 != NULL; p1 = p1->next) {
            for (Node *p2 = p1->next; p2 != NULL; p2 = p2->next) {
                if (p1->vertex > p2->vertex) {
                    int temp = p1->vertex;
                    p1->vertex = p2->vertex;
                    p2->vertex = temp;
                }
            }
        }

	}    
    
    
}


void DFS(int start) {
  
    visited[start] = 1;
    printf("%d ", start);

    Node* temp = adjList[start];
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) {
            DFS(connectedVertex);
        }
        temp = temp->next;

	}    
    
    
}

int main() {
    int V, E;
    int u, v, start;

    scanf("%d %d", &V, &E);


    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

   
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    sortAdjList(V);


    scanf("%d", &start);

   
    DFS(start);

    return 0;
}
