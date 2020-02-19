#include"dlist.h"

int main(int argc, char const *argv[])
{
	dlistnode *H,p;

	int pos;

	H = dlist_create();
	show_dlist(H);

	while(1)
	{
		printf("please input a position:\n");
		scanf("%d",&pos);
		p = dlist_get(H,pos);
		if(p)
		{
			printf("%d\n",p->data);
		}
	}
	return 0;
}