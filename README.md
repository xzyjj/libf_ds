# libf_ds
  libf_ds is libf project's data structure implemented extract

## libf_ds:
  - AVL-Tree
    - [avltree.c](https://github.com/xzyjj/libf_ds/blob/main/avltree.c)
    - [avltree.h](https://github.com/xzyjj/libf_ds/blob/main/avltree.h)
  - RB-Tree
    - [rbtree.c](https://github.com/xzyjj/libf_ds/blob/main/rbtree.c)
    - [rbtree.h](https://github.com/xzyjj/libf_ds/blob/main/rbtree.h)
  - Linked List
    - [list.c](https://github.com/xzyjj/libf_ds/blob/main/list.c)
    - [list.h](https://github.com/xzyjj/libf_ds/blob/main/list.h)

## Compile:
	$ make all

## Benchmark:
  AVL-Tree:

	$ make test_bench_avltree && ./test_bench_avltree

  RB-Tree:

	$ make test_bench_rbtree && ./test_bench_rbtree

  Linked List:

	$ make test_bench_list && ./test_bench_list
