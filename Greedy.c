#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "Graph.h"
#include "UnionFind.h"

#define E 18632460
#define V 6105

float compute(Edge *edges[]){
	int i, out[V];

	int parent [V+1], rank [V+1];
	for(i=0; i<V; i++){
		out[i]=0;
		parent[i]=i;
		rank[i]=0;
	}
	quicksort(edges, 0 , E-1);
	Edge *n;
	float peso=0;
	int f,g;
	for( i=0; i<E; i++){
		n=edges[i];
		f=n->startNode;
		g=n->endNode;
		
		//si estan en componentes diferentes y son extremos, agregar
		if((find(f,parent)!=find(g,parent)) && out[f]<2 && out[g]<2){
			unir(f,g,parent,rank);
			peso += n->weight;
			out[f]++;
			out[g]++;
		}
		//Si el padre tiene V-1 hijos hay solo una componente. Si ademas f y g son los extremos se completa el ciclo.
		else if(rank[find(0, parent)] == V-1 && out[f] == 1 && out[g] == 1){ 
			peso += n->weight;
			break;
		}
	}			
	return peso;
}

int main(int argc,char *argv[]){	
	Edge **edges = (Edge **)malloc(sizeof(Edge *)*E);
	readGraph("Graphs/Complete.cedge",V,E, edges, NULL, NULL);	
	printf("Fin Lectura\n");
	printf("Peso del ciclo %f\n", compute(edges));
}




