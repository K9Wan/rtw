#include <stdlib.h>
#include <stdio.h>

typedef struct node_ {
	int n;
	struct node_ * l;
	struct node_ * r;
}node, *pNode;

pNode add(pNode root, int n)
{
	pNode new = malloc(sizeof *new);
	new->n = n;
	new->l = NULL;
	new->r = NULL;

	if(!root)
	{
		return new;
	}

	if(n/10 < root->n/10)
	{
		root->l = add(root->l, n);
	}
	else
	{
		root->r = add(root->r, n);
	}
	
	return root;
}

void p(pNode root)
{
	if(root)
	{
		p(root->l);
		printf("%i ", root->n);
		p(root->r);
	}
}

void free_tree(pNode root)
{
	if(root)
	{
		free_tree(root->l);
		free_tree(root->r);
		free(root);
	}
}

int main(void)
{
	int a[] = {31, 37, 45, 75, 48, 11, 85, 13, 55, 28, 56, 39, 17, 62};
	int n = sizeof a / sizeof a[0];
	pNode t = NULL;
	for(int i=0; i<n; i++)
	{
		t = add(t, a[i]);
	}

	p(t);
	
	free_tree(t);

	return 0;
}
