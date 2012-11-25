#include <stdlib.h>
#include <stdio.h>

#include "List.h"

List *makeList(){
	return NULL;
}

List *add(List *l, int a){
	List *ll = (List *)malloc(sizeof(List));
	ll->this = a;
	ll->next = l;
	ll->len = l != NULL? 1+l->len : 1;
	return ll;
}

List *get(List *l, int *a){
	if(l == NULL){
		printf("Empy list\n");
		exit(1);
	}
	*a = l->this;
	List *ll = l->next;
	free(l);
	return ll;
}

int len(List *l){
	if(l == NULL)
		return 0;
	return l->len;
}
