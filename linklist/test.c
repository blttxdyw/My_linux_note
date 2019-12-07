#include<stdio.h>


int main(void)
{
#if 0
	listnode n1;
	linklist p,q;//or listnode *p,*q

	n1.data = 10;
	n1.next = NULL;

	p = &n1;
	p->data = 100;//指针访问结构体成员使用箭头

	q = (linklist)malloc(sizeof(listnode));
	q->data = 100;

	free(q);
	q = NULL;
#endif


	linklist H,p;
	int n;
	list_create2();
#if 1
	H = list_create();
	list_head_insert(H,10);
	list_head_insert(H,20);
	list_head_insert(H,30);
#endif
	list_show(H);
#endif

#if 0
	printf("please input position:");
	scanf("%d\n",$n);

	if( (p=list_get(H,n)) != NULL)
		printf("you find node data is %d\n",p->data );
#endif

	printf("please input a number:");
	scanf("%d",&n);
	if( (p=list_located(H,n)) != NULL)
		printf("found data %d\n",p->data );
	else
		printf("not found data\n");


	return 0;
}