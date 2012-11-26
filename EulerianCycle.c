
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "Graph.h"
#include "List.h"

#define E 18632460
#define V 6105

#define SUBV 2452

List *cycle;
void eulerianCycle(int u, List *graph[]){
	while( len(graph[u]) > 0){
		int v;
		graph[u] = get(graph[u], &v);
		graph[v] = del(graph[v], u);
		eulerianCycle(v, graph);
	}
	cycle = add(cycle, u);
}

int multigraph(List *graph[]){
	FILE *match = fopen("Graphs/Match", "r");
	FILE *mapf = fopen("Graphs/SubgraphMap","r");
	
	int map[SUBV+1];
	int i;
	for(i = 0; i < SUBV; ++i){
		int a,b;
		fscanf(mapf, "%d %d\n", &a, &b);
		map[a] = b;
	}
	fclose(mapf);
	
	
	int a,b;
	fscanf(match,"%d %d\n", &a, &b);
	for(i = 0; i < V/2; ++i){
		int start, end;
		fscanf(match, "%d %d", &start, &end);
		graph[map[start]] = add(graph[map[start]], map[end]);
		graph[map[end]] = add(graph[map[end]], map[start]);
	}
	fclose(match);
}


int main(){
	srand48(time(NULL));
	List **graph = (List **) malloc(sizeof(List *) * V);
	readGraph("Graphs/MST.cedge",V,V-1, NULL, NULL, graph);
	
	float *M = (float *)malloc(sizeof(float)*V*V);
	readGraph("Graphs/Complete.cedge",V,E, NULL, M, NULL);	
	
	printf("Fin Lectura\n");
	
	multigraph(graph);
	
	
	fprintf(stderr,"Fin Multigraph\n");
	
	cycle = makeList();
	eulerianCycle(lrand48()%V, graph);
	
	fprintf(stderr,"Fin Eulerian\n");
	
	char used[V];
	int i;
	for(i = 0; i < V; ++i)
		used[i] = 0;
	
	List *path = makeList();
	
	float cost = 0;
	List *curr = cycle;
	int prev = curr->this;
	int v;
	while(curr != NULL){
		v = curr->this;
		if(!used[v]){
			path = add(path, v);
			cost += *(M+V*prev+v);
			used[v] = 1;
			prev = v;
		}
		curr = curr->next;
	}
	cost += *(M+V*prev+v); //Completar el ciclo
	printf("Costo Camino %f\n", cost);

}
