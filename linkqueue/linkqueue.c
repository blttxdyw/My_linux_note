#include "seqqueue.h"

#if 0
seq_pqueue init_seqqueue(void) 
{
	seq_pqueue q;
	if( (q=(seq_pqueue)malloc(sizeof(seq_queue))) == NULL )
	{
		printf("malloc fail\n");
		return NULL;
	}

	q->front = q->rear = MAX_SIZE - 1;
	return q;
}
#else
void init_seqqueue(seq_pqueue q) 
{
	if( (q=(seq_pqueue)malloc(sizeof(seq_queue))) == NULL )
	{
		printf("malloc fail\n");
		return NULL;
	}
	q->front = q->rear = (MAX_SIZE - 1);
}
#endif


bool is_full_seqqueue(seq_pqueue q)
{
	if( ((q->rear+1)%MAX_SIZE) == q->front )
		return true;
	else
		return false;
}


bool in_seqqueue(seq_pqueue q, datatype data)
{
	//the seqqueue is full?
	if( is_full_seqqueue(q) )
	{
		printf("the seqqueue is full\n");
		return false;
	}

	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = data;
	return true;
}


bool is_empty_seqqueue(seq_pqueue q)
{
	if( q->rear == q->front )
		return true;
	else 
		return false;
}


bool out_seqqueue(seq_pqueue q, datatype *D)
{
	if( is_empty_seqqueue(q) )
	{
		printf("seqqueue is empty!\n");
		return false;
	}

	q->front = (q->front + 1) % MAX_SIZE;
	*D = q->data[q->front];
	return true;
}


void show_seqqueue(seq_pqueue q)
{
	if( is_empty_seqqueue(q) )
		return;

	for(int i=(q->front+1)%MAX_SIZE; i!=(q->rear+1)%MAX_SIZE; i=(i+1)%MAX_SIZE)
	{
		printf("%d\t", q->data[i]);
	}
	printf("\n");
}