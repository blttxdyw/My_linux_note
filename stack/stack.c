#include"stack.h"

seqstack *stack_create(int len)
{
	if( (s=(seqstack*)malloc(sizeof(seqstack))) == NULL )
	{
		printf("malloc memory fail\n");
		return NULL;
	}

	if( (s->data = (data_t*)malloc(len * sizeof(data_t))) == NULL )
	{
		printf("malloc data memory fail\n");
		return NULL;
	}

	s->maxlen = len;
	s->top = -1;//-1 -> 空

	return s;
}


/*
  ret:-1 empty 0:not empty
*/
data_t stack_empty(seqstack *s)
{
	return ( s->top == -1 ? 1 : 0);
}


//s->top == 1 则代表stack为空  即使stack有数据也就无意义了
void stack_clear(seqstack *s)
{
	s->top = -1;
}

//ret:1 is full
//ret:0 is not full
data_t seqstack_full(seqstack *s)
{
	return (s->top == (s->maxlen-1) ? 1 : 0);
}


data_t stack_push(seqstack *s,data_t value)
{
	if(s->top == s->maxlen-1)
	{
		printf("stack is full\n");
		return -1;
	}

	s->data[s->top+1] = value;
	s->top++;

	return 1;
}


data_t stack_pop(seqstack *s)
{
	s->top --;
	return s->data[s->top+1];//返回出栈的元素
}


data_t stack_top(seqstack *s)
{
	return s->data[s->top];//返回栈顶的元素
}


void stack_free(seqstack *s)
{
	free(s->data);
	s->data = NULL;
	free(s);
	s = NULL;
}