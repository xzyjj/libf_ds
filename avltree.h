/* avltree.h - avl-tree (adelson-velsky and landis) self-balancing binary tree definitions */
#ifndef LIBF_DS_AVLTREE_H
#define LIBF_DS_AVLTREE_H

#include "config.h"
#include "xstddef.h"
#include "xstdint.h"


/* @def: avltree */
struct avl_node {
	int32 bf;
	struct avl_node *parent, *left, *right;
};

struct avl_root {
	struct avl_node *node;
};

#undef AVL_ROOT_NEW
#define AVL_ROOT_NEW(x) struct avl_root x = { NULL }
#undef AVL_ROOT_INIT
#define AVL_ROOT_INIT(x) ((x)->node = NULL)

#undef AVL_HEIGHT
#define AVL_HEIGHT(x) ((x) ? (x)->bf : 0)
#undef AVL_MAX
#define AVL_MAX(a, b) (((a) > (b)) ? (a) : (b))
/* end */

#ifdef __cplusplus
extern "C" {
#endif

/* avltree.c */
void FSYMBOL(avl_change_child)(struct avl_root *root, struct avl_node *parent,
		struct avl_node *old, struct avl_node *_new);
void FSYMBOL(avl_update_height)(struct avl_node *node);
int32 FSYMBOL(avl_balance_factor)(struct avl_node *node);
void FSYMBOL(avl_left_rotate)(struct avl_root *root, struct avl_node *parent);
void FSYMBOL(avl_right_rotate)(struct avl_root *root, struct avl_node *parent);
void FSYMBOL(avl_balance)(struct avl_root *root, struct avl_node *node);
void FSYMBOL(avl_erase_fix)(struct avl_root *root, struct avl_node *node);

/* avltree_wrap.c */
struct avl_node *FSYMBOL(avl_insert_wrap)(struct avl_root *root,
		struct avl_node *_new, int32 (*cmp)(void *, void *));
struct avl_node *FSYMBOL(avl_search_wrap)(struct avl_root *root,
		void *arg, int32 (*cmp)(void *, void *));
struct avl_node *FSYMBOL(avl_erase_wrap)(struct avl_root *root,
		struct avl_node *old);
struct avl_node *FSYMBOL(avl_erase2_wrap)(struct avl_root *root,
		void *arg, int32 (*cmp)(void *, void *));

#ifdef __cplusplus
}
#endif


#endif
