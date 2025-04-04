#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//creating a variable defining the matrix
#define MaxVertices 50
//creating the matrix
int AdjacencyMatrix[MaxVertices][MaxVertices];
// represents number of vertices 
int n;
int numOfnodes;
int count;
int source, destination, weight;

//Read graph 
void ReadGraph(FILE *fp) {
    fp = fopen("testGraph.txt", "r");
    fscanf(fp, "%d", &numOfnodes);
    while (count < numOfnodes && fscanf(fp, "%d %d %d", &source, &destination, &weight) == 3) {
        AdjacencyMatrix[source][destination] = weight;
        AdjacencyMatrix[destination][source] = weight;
    }
}

void PrintMatrix(){
    printf("Printing the matrix: \n");
    for (int i = 0; i < numOfnodes; i++) {
        for (int j = 0; j < numOfnodes; j++) {
            if (AdjacencyMatrix[i][j] == INT_MAX)
                printf("♾️\t");
            else
                printf("%d\t", AdjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void AllPairsShortPaths() {
    //so we used Floyd warshalls algorithm for implementing this function 
    for(int k = 0; k < numOfnodes; ++k) {
        for (int i = 0; i < numOfnodes; i++) {
            for (int j = 0; j < numOfnodes; j++) {
                if
            }
        }
    }
    