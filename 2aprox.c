
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "Graph.h"
#include "UnionFind.h"
#include "List.h"

#define E 18632460
#define V 6105

List *path;
int prev;
void preorden(int s, int parent, List *MST[], float *M){
	path = add(path, s);
    List *curr = MST[s];
    int v;
    while (curr != NULL){
    	v = curr->this;
        if(v != parent)
            preorden(v, s, MST, M);
        curr = curr->next;
    }
}


List **kruskal(Edge *e[]){
	int i;
	List **MST = (List **) malloc(sizeof(List *) * V);
	quicksort(e, 0, E-1);

	int parent[V+1];
	int rank[V+1];
	for(i=0; i<V; i++){
		parent[i] = i;
		rank[i] = 0;
	}
	
    for (i = 0; i < V; i++)
        MST[i] = NULL;
        
    int f, g;
    Edge *n;
    for (i=0; i<E;i++){
        n = e[i];
        f = n->startNode;
        g = n->endNode;
        if(find(f, parent) != find(g, parent)){
            unir(f, g, parent, rank);
            MST[f] = add(MST[f], g);
            MST[g] = add(MST[g], f);
        }
           
    }
    return MST;
}


int main(){
	srand48(time(NULL));

	float *M = (float *)malloc(sizeof(float)*V*V);
	Edge **edges = (Edge **)malloc(sizeof(Edge *)*E);
	readGraph("Graphs/Complete.cedge",V,E, edges, M, NULL);	
	printf("Fin Lectura\n");
	
	List **MST = kruskal(edges);
	printf("Fin kruskal\n");

	prev = lrand48()%V;
	path = makeList();
	preorden(prev, -1, MST, M);

	
	float total_weight = 0;
	List *curr = path;
	int prev = curr->this;
	while(curr != NULL){		
		int v = curr->this;
		total_weight += *(M+V*v+prev);
		prev = v;
		curr = curr->next;
	}
	total_weight += *(M+V*(path->this)+prev); //Cerrar el ciclo
	printf("Peso del ciclo %f\n", total_weight);

}
