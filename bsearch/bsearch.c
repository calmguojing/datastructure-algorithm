#include <stdlib.h>
#include <stdio.h>

/*
 * bsearch - binary search an array of elements
 * @key: pointer to item being searched for
 * @base: pointer to first element to search
 * @num: number of elements
 * @size: size of each element
 * @cmp: pointer to comparison function
 *
 * This function does a binary search on the given array.  The
 * contents of the array should already be in ascending sorted order
 * under the provided comparison function.
 *
 * Note that the key need not have the same type as the elements in
 * the array, e.g. key could be a string and the comparison function
 * could compare the string with the struct's name field.  However, if
 * the key and elements in the array are of the same type, you can use
 * the same comparison function for both sort() and bsearch().
 */
void *bsearch(const void *key, const void *base, size_t num, size_t size,
	      int (*cmp)(const void *key, const void *elt))
{
	size_t start = 0, end = num;
	int result;

	while (start < end) {
		size_t mid = start + (end - start) / 2;

		result = cmp(key, base + mid * size);
		if (result < 0)
			end = mid;
		else if (result > 0)
			start = mid + 1;
		else
			return (void *)base + mid * size;
	}

	return NULL;
}

int compare(const void *key, const void *elt){
    int *a = (int *)key;
    int *b = (int *)elt;

    if(*a < *b){
        return -1;
    }else if( *a > *b){
        return 1;
    }
    
    return 0;    
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 21;
    int *target = (int *)bsearch((void *)&key, (void *)arr, size, sizeof(int), compare);

    if(target != NULL){
        printf("find target : %d\n", *target);
    }else{
        printf("cannot find the target: %d!\n", key);
    }

    int key1 = 7;
    int *target1 = (int *)bsearch((void *)&key1, (void *)arr, size, sizeof(int), compare);

    if(target1 != NULL){
        printf("find target1 : %d\n", *target1);
    }else{
        printf("cannot find the target1: %d!\n", key1);
    }

    return 0;
}
