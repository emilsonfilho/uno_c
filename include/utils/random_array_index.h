#ifndef RANDOM_ARRAY_INDEX_H
#define RANDOM_ARRAY_INDEX_H

#include <stdlib.h>

/**
 * Generates a random index within the range of the given array size.
 *
 * @param arr_size The size of the array for which a random index is to be generated.
 * @return         A random integer index within the range [0, arr_size-1].
 */
int random_array_index(int arr_size);

#endif