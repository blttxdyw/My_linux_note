#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__

#include<stdio.h>
#include<stdlib.h>

typedef int datatype;

#define MAX_SIZE 10

typedef struct 	seqqueue
{
	datatype data[MAX_SIZE];
	int front,rear;
}seq_queue,*seq_pqueue;

extern void init_seqqueue(seq_pqueue q);
extern bool is_full_seqqueue(seq_pqueue q);
extern bool in_seqqueue(seq_pqueue q, datatype data);
extern bool is_empty_seqqueue(seq_pqueue q); 
extern bool out_seqqueue(seq_pqueue q, datatype *D);
extern void show_seqqueue(seq_pqueue q);

#endif