#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "xstddef.h"
#include "xstdint.h"
#include "xfloat.h"
#include "xstdlib.h"
#include "rbtree.h"


#undef NODE_SIZE
#define NODE_SIZE (1000000)

struct Test_rb {
	int32 key;
	struct rb_node rb;
};

static int32 rb_cmp(void *node, void *arg) {
	int32 parent_key = container_of(node, struct Test_rb, rb)->key;
	int32 new_key = container_of(arg, struct Test_rb, rb)->key;
	if (new_key < parent_key)
		return -1;
	if (new_key > parent_key)
		return 1;

	return 0;
}

static int32 rb_search_cmp(void *node, void *arg) {
	int32 parent_key = container_of(node, struct Test_rb, rb)->key;
	int32 old_key = *(int *)arg;
	if (old_key < parent_key)
		return -1;
	if (old_key > parent_key)
		return 1;

	return 0;
}

int main(void) {
	RB_ROOT_NEW(root);
	struct Test_rb *rb = malloc(sizeof(struct Test_rb) * NODE_SIZE);
	clock_t start, end;
	float64 time;

	RANDOM_TYPE0_NEW(rand, 123456);
	for (int32 i = 0; i < NODE_SIZE; i++) {
#if 1

		XSYMBOL(random_r)(&rand, &rb[i].key);

#else

		rb[i].key = i;

#endif
	}

	/* insert */
	start = clock();
	for (int32 i = 0; i < NODE_SIZE; i++) {
		FSYMBOL(rb_insert_wrap)(&root, &rb[i].rb, rb_cmp);
	}
	end = clock();
	time = (float64)(end - start) / CLOCKS_PER_SEC;
	printf("insert: %d, time: %.6fs (%.2f/s)\n",
		NODE_SIZE, time, (float64)NODE_SIZE / time);

	/* search */
	start = clock();
	for (int32 i = 0; i < NODE_SIZE; i++) {
		FSYMBOL(rb_search_wrap)(&root, &rb[i].key, rb_search_cmp);
	}
	end = clock();
	time = (float64)(end - start) / CLOCKS_PER_SEC;
	printf("search: %d, time: %.6fs (%.2f/s)\n",
		NODE_SIZE, time, (float64)NODE_SIZE / time);

	/* erase */
	start = clock();
	for (int32 i = 0; i < (NODE_SIZE / 10); i++) {
		FSYMBOL(rb_erase2_wrap)(&root, &rb[i].rb, rb_cmp);
	}
	end = clock();
	time = (float64)(end - start) / CLOCKS_PER_SEC;
	printf("erase: %d, time: %.6fs (%.2f/s)\n",
		NODE_SIZE / 10, time, (float64)(NODE_SIZE / 10) / time);

	/* search */
	start = clock();
	for (int32 i = (NODE_SIZE / 10); i < ((NODE_SIZE / 10) + 10); i++) {
		printf("search: %d %p %p\n", rb[i - 1].key, &rb[i - 1].rb,
			FSYMBOL(rb_search_wrap)(&root, &rb[i - 1].rb, rb_cmp));
	}
	end = clock();
	time = (float64)(end - start) / CLOCKS_PER_SEC;
	printf("search: %d, time: %.6fs (%.2f/s)\n",
		10, time, (float64)10 / time);

	/* search */
	start = clock();
	for (int i = 0; i < NODE_SIZE; i++) {
		FSYMBOL(rb_search_wrap)(&root, &rb[i].key, rb_search_cmp);
	}
	end = clock();
	time = (float64)(end - start) / CLOCKS_PER_SEC;
	printf("search: %d, time: %.6fs (%.2f/s)\n",
		NODE_SIZE, time, (float64)NODE_SIZE / time);

	/* erase */
	start = clock();
	for (int i = 0; i < NODE_SIZE; i++) {
		FSYMBOL(rb_erase2_wrap)(&root, &rb[i].rb, rb_cmp);
	}
	end = clock();
	time = (float64)(end - start) / CLOCKS_PER_SEC;
	printf("erase: %d, time: %.6fs (%.2f/s)\n",
		NODE_SIZE, time, (float64)NODE_SIZE / time);

	return 0;
}
