//find con compresion de camino 
int find(int x, int * parent){
	if (x != parent[x]) 
		parent[x] = find(parent[x],parent); 
	return parent[x];
}

//union por rank 
void unir(int x, int y,int *parent, int *rank){ 
	int xRoot=find(x,parent); 
	int yRoot=find(y,parent); 
	if(xRoot == yRoot) 
		return; 
	
	if (rank[xRoot] <= rank[yRoot]){
		parent[xRoot] = yRoot; 
		rank[yRoot] += rank[xRoot] + 1;
	}
	else{
		parent[yRoot] = xRoot; 
		rank[xRoot] += rank[yRoot] + 1;
	}
}
