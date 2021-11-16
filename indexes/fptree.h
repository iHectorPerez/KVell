#ifndef FPTREE_H
#define FPTREE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "memory-item.h"
typedef void fptree_t;

fptree_t *fptree_create();
int fptree_find(fptree_t *t, unsigned char*k, size_t len, struct index_entry *e);
void fptree_delete(fptree_t *t, unsigned char*k, size_t len);
void fptree_insert(fptree_t *t, unsigned char*k, size_t len, struct index_entry *e);
struct index_scan fptree_find_n(fptree_t *t, unsigned char* k, size_t len, size_t n);

void fptree_forall_keys(fptree_t *t, void (*cb)(uint64_t h, void *data), void *data);
void fptree_free(fptree_t *t);

#ifdef __cplusplus
}
#endif

#endif
