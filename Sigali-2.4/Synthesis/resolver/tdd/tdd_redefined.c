
/* TDDCACHE4.C : acces au cache4 (pas de cache4 dans le resolver)
   =============================================================*/
#include "tddint.h"

void tdd_purge_cache4(iri_tdd_manager tddm)
{}

void
tdd_rehash_cache4(iri_tdd_manager tddm, integer grow)
{}

integer tdd_lookup_in_cache41(iri_tdd_manager tddm,
                              integer opcode,
                              integer d1,
                              integer d2,
                              integer d3,
                              integer d4,
                              integer *result)
{ return 0;}


void tdd_insert_in_cache41(iri_tdd_manager tddm,
                           integer opcode,
                           char type,
                           integer d1,
                           integer d2,
                           integer d3,
                           integer d4,
                           integer result)
{}

// The reordering  in not applied for the resolver.
void tdd_reorder(iri_tdd_manager tddm)
{}


