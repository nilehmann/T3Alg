
clean: cleangreedy cleancedge

cleangreedy:
	rm greedy

cleancedge:
	rm cedge_to_wm

cedge_to_wm: cedge_to_wm.c
	gcc -o cedge_to_wm cedge_to_wm.c

greedy: Greedy.c UnionFind.c Graph.c quicksort.c List.c
	gcc -o greedy Greedy.c Graph.c UnionFind.c quicksort.c List.c -pg

2aprox: 2aprox.c UnionFind.c Graph.c quicksort.c List.c
	gcc -o 2aprox 2aprox.c Graph.c UnionFind.c quicksort.c List.c -pg
	

MST: MST.c UnionFind.c Graph.c quicksort.c List.c
	gcc -o MST MST.c Graph.c UnionFind.c quicksort.c List.c -pg
	
	
eulerian: EulerianCycle.c Graph.c List.c
	gcc -o eulerian EulerianCycle.c Graph.c List.c -pg
	
christofides: christofides.c UnionFind.c Graph.c quicksort.c List.c
	gcc -o christofides christofides.c Graph.c UnionFind.c quicksort.c List.c -pg
