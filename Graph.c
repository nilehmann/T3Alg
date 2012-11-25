#include <stdio.h>
#include <stdlib.h>
#include <error.h>

#include "Graph.h"
#include "List.h"

void readGraph(char *file, int V, int E, Edge *edges[], float *M, List *graph[]){
	int i,j;
	FILE *in = fopen(file,"r");
	
	if(M != NULL){
		for(i = 0; i < V; ++i)
			*(M+V*i+i) = 0;
	}
	if(graph != NULL){
		for (i = 0; i < V; i++)
        	graph[i] = makeList();
	}
		
	for(i = 0; i < E; ++i){
		int id, start,end;
		float dist;
	
		
		fscanf(in,"%d %d %d %f\n",&id, &start, &end, &dist);
		
		if(edges != NULL){
			Edge *e = (Edge *) malloc(sizeof(Edge));
			e->weight = dist;
			e->startNode = start;
			e->endNode = end;
			edges[i] = e;
		}
		
		if(M != NULL){
			*(M+V*start+end) = dist;
			*(M+V*end+start) = dist;
		}
		
		if(graph != NULL){
			graph[start] = add(graph[start], end);
			graph[end] = add(graph[end], start);
		}
		
	}
	fclose(in);
}
