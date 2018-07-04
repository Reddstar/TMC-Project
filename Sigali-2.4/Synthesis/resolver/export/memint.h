/* Memory management internal definitions */


#if !defined(_MEMINTH)
#define _MEMINTH

/* All user-visible stuff */

#include "memuser.h"


struct segment_
{
  pointer base_address;
  integer limit;
};

typedef struct segment_ *segment;


struct block_
{
  integer used;
  integer size_index;
  struct block_ *next;
  struct block_ *prev;
  segment seg;
};

typedef struct block_ *block;

#define HEADER_SIZE ROUNDUP(sizeof(struct block_))
#define MAX_SIZE_INDEX (8*sizeof(integer)-2)
#define MAX_SEG_SIZE (1l << MAX_SIZE_INDEX)
#define MAX_SIZE (MAX_SEG_SIZE-HEADER_SIZE)
#define MIN_ALLOC_SIZE_INDEX 15

#define NICE_BLOCK_SIZE (4096l-ROUNDUP(sizeof(struct block_)))

#define MEM_COPY(dest, src, size) (void)memcpy((dest), (src), (size))
#define MEM_ZERO(ptr, size) (void)memset((ptr), 0, (size))

extern void mem_fatal(const char *);

#endif
