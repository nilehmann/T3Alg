#include "List.h"

typedef struct {
	float weight;
	int startNode;
	int endNode;		
} Edge;

void readGraph(char *file, int V, int E, Edge *edges[], float *M, List *graph[]);
