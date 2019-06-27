#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

/*
Jordan Zech
creating arrayList in C
*/


//initalizes vector
void vinit(vector * v)
{
	v->arrayP = (int *) malloc(2 * sizeof(int));
	v->numE = 0;
	v->capacity = 2;
}
//adds a value to the end of array and resizes if needed
int vadd(vector * v, int value)
{

	if (v->numE == v->capacity){
		int * temp = v->arrayP;

		v->arrayP = (int *)  malloc(v->capacity * 2 * sizeof(int));
		v->capacity *= 2;
		if (v->arrayP == NULL){
			free(temp);
			return 0;}
		for (int i = 0; i < v->numE; i++)
			v->arrayP[i] = temp[i];
	free(temp);}
	v->arrayP[v->numE] = value;
	v->numE++;
	
	
	return 1;
}
//removes an element at the idx.. checks if idx is in the size of array
int vrm(vector * v, int idx)
{
	if (idx > (v->numE - 1 ))
		return 0;
	else{
	for (int i = idx; i < v->numE - 1; i++)
		v->arrayP[i] = v->arrayP[i + 1];
	v->numE--;
	return 1;
	}
}
//cleans up memory of vector that was created
void vcleanup(vector * v)
{	if (v->arrayP != NULL){
		free(v->arrayP);
		v->numE = 0;
		v->capacity = 0;
	}
	v->arrayP = NULL;
}
//sets value of result to specified idx if allowed
int vget(vector v, int idx, int * result)
{
	if (idx < (v.numE)){
		 *result = v.arrayP[idx];
		return 1;}
	else
		return 0;
}
//sets value of value to specified idx if allowed
int vset(vector v, int idx, int value)
{
	if (idx < (v.numE)){
		v.arrayP[idx] = value;
		return 1;
		}
	else
		return 0;
}
//return number of elements in array
int vsize(vector v)
{
	return v.numE;
}
//returns the allocated size of array
int vcapacity(vector v)
{
	return v.capacity;
}
