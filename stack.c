#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//su dung con tro
typedef struct StackNodeee {
	float item;
	struct StackNodeee *next;
} StackNode;

//phan tu top
typedef struct {
	StackNode *top;
} Stack;
//is empty
int StackEmpty(const Stack *s) {
	return (s->top == NULL);
}
//pop
float StackPop(Stack *s) {
	float item;
	StackNode *node;
	if(StackEmpty(s)) {
		printf("nn Ngan xep rong");
		return 0;
	}
	node = s->top;
	item = node->item;
	s->top = node->next;
	free(node);
	return item;
}
//khoi tao
Stack *StackInit() {
	Stack *s;
	s = (Stack *)malloc(sizeof(Stack));
	if (s == NULL) {
		return NULL;
	}
	s->top = NULL;
	return s;
}
//huy ngan xep
void StackDestroy(Stack *s) {
	while (!StackEmpty(s)) {
		StackPop(s);
	}
	free(s);
}
int StackFull() {
	printf("\n Khong con bo nho");
	getch();
	return 1;
}
//them vao ngan xep
int StackPush(Stack *s, float item) {
	StackNode *node;
	node = (StackNode *)malloc(sizeof(StackNode));
	if (node == NULL) {
		StackFull();
		return 1;
	}
	node->item = item;
	node->next = s->top;
	s->top = node;
	return 0;
}

//in
int disp(Stack *s) {
	StackNode *node;
	float m;
	printf("\n DANH SACH CAC PHAN TU CUA NGAN XEP \n");
	if(StackEmpty(s)) {
		printf("\n ngan xep rong \n");
		getch();
	} else {
		node = s->top;
		do {
			m = node->item;
			printf("% 8.3f",m);
			node = node->next;
		} while(!(node==NULL));
	}
}

int main() {
	Stack* a,*b;
//	StackInit();
	for(int i=0 ; i<10; i++) {
		StackPush(a,4.6f+i);
		if(i>7) {
			StackPop(a);
		}
	}
	disp(a);
	return 0;
}


