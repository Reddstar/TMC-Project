/* Memory management user-visible definitions */


#if !defined(_MEMUSERH)
#define _MEMUSERH


#include <cstdio>
#include "integer.h"
#include "pointer.h"

typedef struct rec_mgr_ *rec_mgr;


/* ALLOC_ALIGNMENT is the alignment for all storage returned by the */
/* storage allocation routines.  REQUIRED_ALIGNMENT is the alignment */
/* required by the machine hardware; it is provided for user use. */

#define ALLOC_ALIGNMENT 4
#define REQUIRED_ALIGNMENT 4


/* Round a size up for alignment */

#define ROUNDUP(size) ((((size)+ALLOC_ALIGNMENT-1)/ALLOC_ALIGNMENT)*ALLOC_ALIGNMENT)
#define ALIGN(size) ((((size)+REQUIRED_ALIGNMENT-1)/REQUIRED_ALIGNMENT)*REQUIRED_ALIGNMENT)


/* Block storage management routines */

#if defined(__STDC__)
extern pointer mem_get_block(integer);
extern void mem_free_block(pointer);
extern pointer mem_resize_block(pointer, integer);
extern void mem_copy(pointer, pointer, integer);
extern void mem_zero(pointer, integer);
extern integer mem_allocation(void);
#else
extern pointer mem_get_block();
extern void mem_free_block();
extern pointer mem_resize_block();
extern void mem_copy();
extern void mem_zero();
extern integer mem_allocation();
#endif


/* Record manager routines */

#if defined(__STDC__)
extern pointer mem_new_rec(rec_mgr);
extern void mem_free_rec(rec_mgr, pointer);
extern rec_mgr mem_new_rec_mgr(integer);
extern void mem_free_rec_mgr(rec_mgr);
#else
extern pointer mem_new_rec();
extern void mem_free_rec();
extern rec_mgr mem_new_rec_mgr();
extern void mem_free_rec_mgr();
#endif

#endif
