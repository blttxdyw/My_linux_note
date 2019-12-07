#include "linklist.h"

linklist list_create()
{
	linklist H;

	if( (H = malloc(sizeof(listnode))) = NULL )
	{
		printf("allot memory fail!\n");
		return H;
	}
	H->data = 0;
	H->next = NULL;
	return H;
}


linklist list_create2()
{
	linklist H,r,p;
	datatype value;

	if( (H = malloc(sizeof(listnode))) = NULL )
	{
		printf("allot memory fail!\n");
		return H;
	}
	H->data = 0;
	H->next = NULL;
	r = H;

	while(1)
	{
		printf("please input a number(-1 exit)\n");
		scanf("%d",&value);
		if(value == -1)
			break;

		if( (p=(linklist)malloc(sizeof(listnode))) == NULL)//1.创建新的节点p
		{
			printf("allot memory fail!\n");
			return H;	
		}
		p->data = value;
		p->next = NULL;

		r->next = p;//2.r指向p
		r = p;//3.r指向p新的表尾
	}
	return H;
}


void list_show(linklist H)
{
	while(H->next)
	{
		printf("%d\n",H->next.data);
		H = H->next;//指针循环移动
	}
	printf("data was printf\n");
}


int list_head_insert(linklist H, datatype value)
{
	linklist p;
	if((p = (linklist)malloc(sizeof(listnode))) == NULL)
	{
		printf("allot memory fail\n");
		return -1;
	}
	p->data = value;
	p->next = H->next;
	H->next = p;
	return 0;
}


int linklist_insert(linklist H,int pos,datatype value)
{
	linklist p,q;
	if(pos == 0)
	{
		p = H;
	}
	else
	{
		p = list_get(H,pos-1);
	}

	if(p == NULL)
	{
		printf("para is invalid\n");
		return -1;
	}
	else
	{
		if( (q=(linklist)malloc(sizeof(listnode))) == NULL)
		{
			printf("malloc memory fail\n");
			return -1;
		}
		else
		{
			q->data = value;
			q->next = p->next;
			p->next = q;
			return 0;
		}
	}
}


int list_order_insert(linklist H,datatype value)
{
	linklist p,q;

	if( (p=(linklist)malloc(sizeof(listnode))) == NULL)
	{
		printf("mallo memory fail!\n");
		return -1;
	}

	q = H;
	while(q->next && q->next->data<value)
	{
		q = q->next;
	}
	q->next = p->next;
	p->next = q;
}


void list_sort(linklist H)
{
	linklist p,q,r;
	p->next = H->next;
	H->next = NULL;

	while(p)
	{
		q = p;
		p = p->next;

		r = H;
		while(r->next && r->next->data < p->data)
		{
			r = r->next;
		}
		q->next = r->next;
		r->next = q;
	}
}


linklist list_get(linklist H,int pos)
{
	int i = -1;
	linklist p = H;
	if(pos < 0)printf("position is v=invalid\n");

	while(p->next && i<pos)
	{
		p = p->next;
		i++;
	}

	//p->next == NULL or i==pos
	if(i == pos)
	{
		return p;
	}
	else
	{
		printf("position is invalid:>linklist length\n");
		return NULL;
	}
}


linklist list_located(linklist H, datatype value)
{
	linklist p = H->next;
	while(p && p->data != value)
	{
		p = p->next;
	}
	return p;
}