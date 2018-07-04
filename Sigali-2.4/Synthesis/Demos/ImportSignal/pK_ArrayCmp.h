#ifndef pK_ARRAYCMP_H
#define pK_ARRAYCMP_H

#define pK_ArrayEqlogical  pK_ArrayEqint 

EXTERN logical pK_ArrayEqshort ( void *t1, void* t2, int size );
EXTERN logical pK_ArrayEqint ( void *t1, void* t2, int size );
EXTERN logical pK_ArrayEqlong ( void *t1, void* t2, int size );
EXTERN logical pK_ArrayEqfloat ( void *t1, void* t2, int size );
EXTERN logical pK_ArrayEqdouble ( void *t1, void* t2, int size );
EXTERN logical pK_ArrayEqchar ( void *t1, void* t2, int size );
EXTERN logical pK_ArrayEqpK_String ( void *t1, void* t2, int size );
EXTERN logical pK_ArrayEqComplex ( void *t1, void* t2, int size );
EXTERN logical pK_ArrayEqComplexd ( void *t1, void* t2, int size );

#define pK_ArrayLeqlogical  pK_ArrayLeqint 

EXTERN logical pK_ArrayLeqshort ( void *t1, void* t2, int size );
EXTERN logical pK_ArrayLeqint ( void *t1, void* t2, int size );
EXTERN logical pK_ArrayLeqlong ( void *t1, void* t2, int size );
EXTERN logical pK_ArrayLeqfloat ( void *t1, void* t2, int size );
EXTERN logical pK_ArrayLeqdouble ( void *t1, void* t2, int size );
EXTERN logical pK_ArrayLeqchar ( void *t1, void* t2, int size );
EXTERN logical pK_ArrayLeqpK_String ( void *t1, void* t2, int size ); 

#endif
