/* rbtree.h - rb-tree (red-black) self-balancing binary tree definitions */
#ifndef LIBF_DS_RBTREE_H
#define LIBF_DS_RBTREE_H

#include "config.h"
#include "xstddef.h"
#include "xstdint.h"


/* @def: rbtree */
struct rb_node {
	int32 color;
	struct rb_node *parent, *left, *right;
};

struct rb_root {
	struct rb_node *node;
};

#undef RB_ROOT_NEW
#define RB_ROOT_NEW(x) struct rb_root x = { NULL }
#undef RB_ROOT_INIT
#define RB_ROOT_INIT(x) ((x)->node = NULL)

#undef RB_RED
#define RB_RED 0
#undef RB_BLACK
#define RB_BLACK 1
/* end */

#ifdef __cplusplus
extern "C" {
#endif

/* rbtree.c */
void FSYMBOL(rb_change_child)(struct rb_root *root, struct rb_node *parent,
		struct rb_node *old, struct rb_node *_new);
void FSYMBOL(rb_left_rotate)(struct rb_root *root, struct rb_node *parent);
void FSYMBOL(rb_right_rotate)(struct rb_root *root, struct rb_node *parent);
void FSYMBOL(rb_insert_fix)(struct rb_root *root, struct rb_node *node);
void FSYMBOL(rb_erase_fix)(struct rb_root *root, struct rb_node *node);

/* rbtree_wrap.c */
struct rb_node *FSYMBOL(rb_insert_wrap)(struct rb_root *root,
		struct rb_node *_new, int32 (*cmp)(void *, void *));
struct rb_node *FSYMBOL(rb_search_wrap)(struct rb_root *root,
		void *arg, int32 (*cmp)(void *, void *));
struct rb_node *FSYMBOL(rb_erase_wrap)(struct rb_root *root,
		struct rb_node *old);
struct rb_node *FSYMBOL(rb_erase2_wrap)(struct rb_root *root,
		void *arg, int32 (*cmp)(void *, void *));

#ifdef __cplusplus
}
#endif


#endif
