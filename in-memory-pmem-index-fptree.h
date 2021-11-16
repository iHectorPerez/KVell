#ifndef IN_MEMORY_PMEM_FPTREE
#define IN_MEMORY_PMEM_FPTREE 1

#include "indexes/fptree.h"

#define INDEX_TYPE "fptree"
#define memory_index_init fptree_init
#define memory_index_add fptree_index_add
#define memory_index_lookup fptree_worker_lookup
#define memory_index_delete fptree_worker_delete
#define memory_index_scan fptree_init_scan

void fptree_init(void);
struct index_entry *fptree_worker_lookup(int worker_id, void *item);
void fptree_worker_delete(int worker_id, void *item);
struct index_scan fptree_init_scan(void *item, size_t scan_size);
void fptree_index_add(struct slab_callback *cb, void *item);

#endif

