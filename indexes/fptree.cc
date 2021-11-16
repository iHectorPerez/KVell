#include <KVell_NVM_Indexes/fptree.h>
#include "fptree.h"

using namespace std;
using namespace nvindex::FP_tree;

extern "C"
{
   fptree_t *fptree_create() {
      Btree<uint64_t, struct index_entry, 1000000> *fp = new Btree<uint64_t, struct index_entry, 1000000>();
      return fp;
   }

   int fptree_find(fptree_t *t, unsigned char* k, size_t len, struct index_entry *e) {
      uint64_t hash = *(uint64_t*)k;
      Btree<uint64_t, struct index_entry, 1000000> *fp =  static_cast< Btree<uint64_t, struct index_entry, 1000000> * >(t);

      double latency_breaks[3];
      auto i = fp->get(hash, latency_breaks);
      if (i.slab == NULL)
          return 0;
      else{
          *e = i;
          return 1;
      }
   }

   void fptree_delete(fptree_t *t, unsigned char*k, size_t len) {
      uint64_t hash = *(uint64_t*)k;
      Btree<uint64_t, struct index_entry, 1000000> *fp =  static_cast< Btree<uint64_t, struct index_entry, 1000000> * >(t);
      fp->remove(hash);
   }

   void fptree_insert(fptree_t *t, unsigned char*k, size_t len, struct index_entry *e) {
      uint64_t hash = *(uint64_t*)k;
      Btree<uint64_t, struct index_entry, 1000000> *fp =  static_cast< Btree<uint64_t, struct index_entry, 1000000> * >(t);
      fp->insert(hash, *e);
   }

   struct index_scan fptree_find_n(fptree_t *t, unsigned char* k, size_t len, size_t n) {

      struct index_scan res;
//      res.hashes = (uint64_t*) malloc(n*sizeof(*res.hashes));
//      res.entries = (struct index_entry*) malloc(n*sizeof(*res.entries));
//      res.nb_entries = 0;
//
//      uint64_t hash = *(uint64_t*)k;
//      Btree<uint64_t, struct index_entryt, 1000000> *fp =  static_cast< Btree<uint64_t, struct index_entryt, 1000000> * >(t);
//      fp->find_n(hash, n, res.hashes, sizeof(*res.hashes), res.entries, sizeof(*res.entries), &res.nb_entries);
      return res;
   }

   void fptree_forall_keys(fptree_t *t, void (*cb)(uint64_t h, void *data), void *data) {

       // Not needed by the index API, left this signature to conform to the pseudo interface
//      Btree<uint64_t, struct index_entry, 1000000> *fp =  static_cast< Btree<uint64_t, struct index_entry, 1000000> * >(t);

//      auto i = b->begin();
//      while(i != b->end()) {
//         cb(i->first, data);
//         i++;
//      }
      return;
   }

   void fptree_free(fptree_t *t) {
      Btree<uint64_t, struct index_entry, 1000000> *fp =  static_cast< Btree<uint64_t, struct index_entry, 1000000> * >(t);
      delete fp;
   }

}
