/************************************************************************************* 
* This program implements an adjancency Matrix for graph representation
* 
*
* Modified by: Mahimaa Vardini BR, Faith Aikhionbare, Samarpita Sharma 
* Date: Thursday, April 11th, 2025
*************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//creating a variable defining the matrix
#define MaxVertices 100
//creating the matrix
int AdjacencyMatrix[MaxVertices][MaxVertices];

int n, numOfnodes;
FILE *fp;

//Read graph 
void readGraph() {
    fp = fopen("graph1.txt", "r");

    fscanf(fp, "%d", &numOfnodes);

    //check if file is null
    if (fp == NULL) {
        printf("Error opening file\n");
    }

    //initilize matrix with 0's where source vertice = destination vertices and infinit everywhere else
    for(int s = 0; s < numOfnodes; s++){
        for(int d = 0; d < numOfnodes; d ++){
            //add a 0 for self loops 
            if(s == d){
                AdjacencyMatrix[s][d] = 0;
            }else{
                AdjacencyMatrix[s][d] = INT_MAX;
            }
        }
    }

    int source, destination, weight;
    //Reads the file adding the undirected edges to the adjancency matrix. 
    while (numOfnodes && fscanf(fp, "%d %d %d", &source, &destination, &weight) == 3) {
        AdjacencyMatrix[source][destination] = weight;
        AdjacencyMatrix[destination][source] = weight;
    }
    
    //close file 
    fclose(fp);
}


void printMatrix(){
    printf("Printing the matrix: \n");
    for (int i = 0; i < numOfnodes; i++) {
        for (int j = 0; j < numOfnodes; j++) {
            if (AdjacencyMatrix[i][j] == INT_MAX)
                printf("-\t"); //I need to test with terminal so using - instead of the ♾️ can change later
            else
                printf("%d\t", AdjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void allPairsShortPaths() {
    //so we used Floyd warshalls algorithm for implementing this function 
    for(int k = 0; k < numOfnodes; ++k) {
        for (int i = 0; i < numOfnodes; i++) {
            for (int j = 0; j < numOfnodes; j++) {
                if (AdjacencyMatrix[i][k] != INT_MAX && AdjacencyMatrix[k][j] != INT_MAX && 
                    AdjacencyMatrix[i][j] > AdjacencyMatrix[i][k] + AdjacencyMatrix[k][j]) {
                        AdjacencyMatrix[i][j] = AdjacencyMatrix[k][j] + AdjacencyMatrix[i][k];
                    }
            }
        }
            printf("Intermediate graphs after %d iterations\n", k+1);
            printMatrix();
    }
}

//function to find the central node of the graph 
int centralNode(){
    int NodeID = -1;
    int MinMax = INT_MAX;

    for (int i = 0; i < numOfnodes; i++) {
        int MaxDist = 0;
        for (int j = 0; j < numOfnodes; j++) {
            if(AdjacencyMatrix[i][j] > MaxDist){
                MaxDist = AdjacencyMatrix[i][j];
            }
        }
        if (MaxDist < MinMax){
            MinMax = MaxDist;
            NodeID = i;
        }
    }
    return NodeID;

}

int main(){

    readGraph();
    printf("Original graph\n");
    printMatrix();
    allPairsShortPaths();
    printf("Final Graph\n");
    printMatrix();

    int central = centralNode();
    if (central != -1){
        printf("The central node of the graph is %d\n", central);
    }
    else{
        printf("\nThe graph is not connected.\n");
    }
    return 0;
}