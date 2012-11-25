#include <stdio.h>
#include <stdlib.h>


#include "Graph.h"
#include "UnionFind.h"
#include "List.h"

#define E 18632460
#define V 6105


List **kruskal(Edge *e[]){
	FILE *FMST = fopen("Graphs/MST.cedge","w");
	
	int i;
	List **MST = (List **) malloc(sizeof(List *) * V);
	quicksort(e, 0, E-1);

	int parent[V+1];
	int rank[V+1];
	for(i=0; i<V; i++){
		parent[i]=i;
		rank[i]=0;
	}
	
    for (i = 0; i < V; i++)
        MST[i] = NULL;
        
    int f, g;
    Edge *n;
    int count = 0;
	float ca = 0;
    for (i=0; i<E;i++){
        n = e[i];
        f = n->startNode;
        g = n->endNode;
        if(find(f, parent)!=find(g, parent)){
            unir(f, g, parent, rank);
            fprintf(FMST,"%d %d %d %f\n", count++, f, g, n->weight);
            ca += n->weight;
            MST[f] = add(MST[f], g);
            MST[g] = add(MST[g], f);
        }
           
    }
    printf("Peso MST %f\n", ca);
    fclose(FMST);
    return MST;
}

List *oddNodes;
void OddNodes(int n, int parent, List *MST[]){
	if((MST[n]->len & 1) != 0)
		oddNodes = add(oddNodes, n);
		
	List *curr = MST[n];
    int v;
    while (curr != NULL){
    	v = curr->this;
        if(v != parent)
            OddNodes(v, n, MST);
        curr = curr->next;
    }	
}


float *M;
void printSubGraph(){
	FILE *out = fopen("Graphs/Subgraph","w");
	FILE *map = fopen("Graphs/SubgraphMap","w");
	int len = oddNodes->len;

	List *curr = oddNodes;
	int i,j, v, u;
	
	i = 0;
	fprintf(out,"%d %d\n", len, len*(len-1)/2);
	while(curr != NULL){
		v = curr->this;
		
		fprintf(map, "%d %d\n", i, v);
		
		List *curr2 = curr->next;
		j = i+1;
		while(curr2 != NULL){
			u = curr2->this;
			fprintf(out,"%d %d %f\n",i, j,*(M+V*u+v));
			++j;
			curr2 = curr2->next;
		}
		curr = curr->next;
		++i;
	}
	fclose(out);
	fclose(map);
}


int main(int argc,char *argv[]){

	M = (float *)malloc(sizeof(int)*V*V);	
	Edge **edges = (Edge **)malloc(sizeof(Edge *)*E);
	readGraph("Graphs/Complete.cedge",V,E, edges,M, NULL);
	printf("Fin Lectura\n");
	
	List **MST = kruskal(edges);
	printf("Fin MST\n");
	oddNodes = makeList();
	OddNodes(0, -1, MST);	
	printf("Fin odd nodes. Largo %d\n", len(oddNodes));
	
	printSubGraph();
	printf("Fin SubGraph\n");
	
	return 0;
}

