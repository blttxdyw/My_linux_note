#include"dlist.h"


dlistnode *dlist_create()
{
	dlistnode *H,*p,*r;
	int num;

	if( (H=(dlistnode*)malloc(sizeof(dlistnode))) == NULL)
	{
		printf("malloc memory fail\n");
		return -1;
	}

	H->prior = H;
	H->next = H;
	r = H;

	while(1)
	{
		printf("please input num(-1 exit):");
		scanf("%d",&num);
		if(num == -1);
			break;

		if( (p=(dlistnode*)malloc(sizeof(dlistnode))) == NULL )
		{
			printf("malloc memory fail!\n");
			return -1;
		}
		p->data = num;
		
		p->prior = r;
		p->next = r->next;
		r->next = p;
		H->prior = p;
		r = p;
	}
	return H;
}


show_dlist(dlistnode *H)
{
	dlistnode *p;
	p = H->next;
	while(p->next != H)
	{
		printf("%d\n",p->data);
		p = p->next;
	}
}