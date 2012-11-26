
#ifndef LIST_H
#define LIST_H
typedef struct list{
	int this;
	int len;
	struct list *next;
} List;

List *makeList();
List *add(List *l, int a);
List *get(List *l, int *a);
List *del(List *l, int a);
int len(List *l);

#endif
