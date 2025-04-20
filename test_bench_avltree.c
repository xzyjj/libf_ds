#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "xstddef.h"
#include "xstdint.h"
#include "xfloat.h"
#include "xstdlib.h"
#include "avltree.h"


#undef NODE_SIZE
#define NODE_SIZE (1000000)

struct Test_avl {
	int32 key;
	struct avl_node avl;
};

static int32 avl_cmp(void *node, void *arg) {
	int32 parent_key = container_of(node, struct Test_avl, avl)->key;
	int32 new_key = container_of(arg, struct Test_avl, avl)->key;
	if (new_key < parent_key)
		return -1;
	if (new_key > parent_key)
		return 1;

	return 0;
}

static int32 avl_search_cmp(void *node, void *arg) {
	int32 parent_key = container_of(node, struct Test_avl, avl)->key;
	int32 old_key = *(int *)arg;
	if (old_key < parent_key)
		return -1;
	if (old_key > parent_key)
		return 1;

	return 0;
}

int main(void) {
	AVL_ROOT_NEW(root);
	struct Test_avl *avl = malloc(sizeof(struct Test_avl) * NODE_SIZE);
	clock_t start, end;
	float64 time;

	RANDOM_TYPE0_NEW(rand, 123456);
	for (int32 i = 0; i < NODE_SIZE; i++) {
#if 1

		XSYMBOL(random_r)(&rand, &avl[i].key);

#else

		avl[i].key = i;

#endif
	}

	/* insert */
	start = clock();
	for (int32 i = 0; i < NODE_SIZE; i++) {
		FSYMBOL(avl_insert_wrap)(&root, &avl[i].avl, avl_cmp);
	}
	end = clock();
	time = (float64)(end - start) / CLOCKS_PER_SEC;
	printf("insert: %d, time: %.6fs (%.2f/s)\n",
		NODE_SIZE, time, (float64)NODE_SIZE / time);

	/* search */
	start = clock();
	for (int32 i = 0; i < NODE_SIZE; i++) {
		FSYMBOL(avl_search_wrap)(&root, &avl[i].key, avl_search_cmp);
	}
	end = clock();
	time = (float64)(end - start) / CLOCKS_PER_SEC;
	printf("search: %d, time: %.6fs (%.2f/s)\n",
		NODE_SIZE, time, (float64)NODE_SIZE / time);

	/* erase */
	start = clock();
	for (int32 i = 0; i < (NODE_SIZE / 10); i++) {
		FSYMBOL(avl_erase2_wrap)(&root, &avl[i].avl, avl_cmp);
	}
	end = clock();
	time = (float64)(end - start) / CLOCKS_PER_SEC;
	printf("erase: %d, time: %.6fs (%.2f/s)\n",
		NODE_SIZE / 10, time, (float64)(NODE_SIZE / 10) / time);

	/* search */
	start = clock();
	for (int32 i = (NODE_SIZE / 10); i < ((NODE_SIZE / 10) + 10); i++) {
		printf("search: %d %p %p\n", avl[i - 1].key, &avl[i - 1].avl,
			FSYMBOL(avl_search_wrap)(&root, &avl[i - 1].avl, avl_cmp));
	}
	end = clock();
	time = (float64)(end - start) / CLOCKS_PER_SEC;
	printf("search: %d, time: %.6fs (%.2f/s)\n",
		10, time, (float64)10 / time);

	/* search */
	start = clock();
	for (int i = 0; i < NODE_SIZE; i++) {
		FSYMBOL(avl_search_wrap)(&root, &avl[i].key, avl_search_cmp);
	}
	end = clock();
	time = (float64)(end - start) / CLOCKS_PER_SEC;
	printf("search: %d, time: %.6fs (%.2f/s)\n",
		NODE_SIZE, time, (float64)NODE_SIZE / time);

	/* erase */
	start = clock();
	for (int i = 0; i < NODE_SIZE; i++) {
		FSYMBOL(avl_erase2_wrap)(&root, &avl[i].avl, avl_cmp);
	}
	end = clock();
	time = (float64)(end - start) / CLOCKS_PER_SEC;
	printf("erase: %d, time: %.6fs (%.2f/s)\n",
		NODE_SIZE, time, (float64)NODE_SIZE / time);

	return 0;
}
