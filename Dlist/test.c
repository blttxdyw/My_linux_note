#include"dlist.h"

int int main(int argc, char const *argv[])
{
	dlistnode *H;

	H = dlist_create();
	show_dlist(H);
	return 0;
}