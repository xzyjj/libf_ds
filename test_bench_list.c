#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "xstddef.h"
#include "xstdint.h"
#include "xfloat.h"
#include "xstdlib.h"
#include "list.h"


#undef NODE_SIZE
#define NODE_SIZE (1000000)

struct Test_list {
	int32 key;
	struct list list;
};

int main(void) {
	LIST_NEW(head);
	struct Test_list *list = malloc(sizeof(struct Test_list) * NODE_SIZE);
	clock_t start, end;
	float64 time;

	RANDOM_TYPE0_NEW(rand, 123456);
	for (int32 i = 0; i < NODE_SIZE; i++) {
		XSYMBOL(random_r)(&rand, &list[i].key);
	}

	/* add */
	start = clock();
	for (int32 i = 0; i < NODE_SIZE; i++) {
		FSYMBOL(list_add)(&head, &list[i].list);
	}
	end = clock();
	time = (float64)(end - start) / CLOCKS_PER_SEC;
	printf("add: %d, time: %.6fs (%.2f/s)\n",
		NODE_SIZE, time, (float64)NODE_SIZE / time);

	/* del */
	start = clock();
	for (int32 i = 0; i < NODE_SIZE; i++) {
		FSYMBOL(list_del)(&head, &list[i].list);
	}
	end = clock();
	time = (float64)(end - start) / CLOCKS_PER_SEC;
	printf("del: %d, time: %.6fs (%.2f/s)\n",
		NODE_SIZE, time, (float64)NODE_SIZE / time);

	/* add tail */
	start = clock();
	for (int32 i = 0; i < NODE_SIZE; i++) {
		FSYMBOL(list_add_tail)(&head, &list[i].list);
	}
	end = clock();
	time = (float64)(end - start) / CLOCKS_PER_SEC;
	printf("add_tail: %d, time: %.6fs (%.2f/s)\n",
		NODE_SIZE, time, (float64)NODE_SIZE / time);

	/* swap */
	start = clock();
	for (int32 i = 0; i < NODE_SIZE; i++) {
		FSYMBOL(list_swap)(&head, &list[0].list, &list[i].list);
	}
	end = clock();
	time = (float64)(end - start) / CLOCKS_PER_SEC;
	printf("swap: %d, time: %.6fs (%.2f/s)\n",
		NODE_SIZE, time, (float64)NODE_SIZE / time);

	return 0;
}
