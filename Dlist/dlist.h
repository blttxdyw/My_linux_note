#ifndef __dlist_H_
#define __dlist_H_

#include<stdio.h>
#include<stdlib.h>


typedef struce node
{
	int data;
	struct node * prior;
	struct node * next;
}dlistnode;


extern dlistnode *dlist_create(void);
extern void show_dlist(dlistnode *H);

#endif










