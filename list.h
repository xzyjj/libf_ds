/* list.h - intrusive linked list definitions */
#ifndef LIBF_DS_LIST_H
#define LIBF_DS_LIST_H

#include "config.h"
#include "xstddef.h"
#include "xstdint.h"


/* @def: list */
struct list {
	struct list *prev, *next;
};

struct list_head {
	struct list *node;
};

#undef LIST_NEW
#define LIST_NEW(x) \
	struct list_head x = { .node = NULL }

#undef LIST_INIT
#define LIST_INIT(x) ((x)->node = NULL)

#undef LIST_FOR_EACH
#define LIST_FOR_EACH(node, name) \
	for (struct list *name = (node); \
			name; \
			name = name->next)
/* end */

#ifdef __cplusplus
extern "C" {
#endif

/* list.c */
struct list *FSYMBOL(list_add)(struct list_head *head,
		struct list *_new);
struct list *FSYMBOL(list_add_tail)(struct list_head *head,
		struct list *_new);
struct list *FSYMBOL(list_del)(struct list_head *head,
		struct list *old);
struct list *FSYMBOL(list_insert)(struct list_head *head,
		struct list *node, struct list *_new);
struct list *FSYMBOL(list_insert_tail)(struct list_head *head,
		struct list *node, struct list *_new);
void FSYMBOL(list_swap)(struct list_head *head,
		struct list *old, struct list *_new);

#ifdef __cplusplus
}
#endif


#endif
