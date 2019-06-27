#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct vector
{
int* arrayP;
int numE;
int capacity;
} vector;

void vinit(vector * v);
int vadd(vector * v, int value);
int vrm(vector * v, int idx);
void vcleanup(vector * v);
int vget(vector v, int idx, int * result);
int vset(vector v, int idx, int value);
int vsize(vector v);
int vcapacity(vector v);


#endif
