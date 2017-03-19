#ifndef X4_SORT_HEADER_GUARD
#   define X4_SORT_HEADER_GUARD

#   include <stdio.h>
#   include <stdbool.h>
#   include <string.h>

//==============================================================================

typedef enum {
    X4_SSC_OK,
    X4_SSC_ARGS_GOOD,
    X4_SSC_SWAP_GOOD,
    X4_SSC_NULL_ARGS_PTR,
    X4_SSC_NULL_COLL_PTR,
    X4_SSC_NULL_CMP_PTR,
    X4_SSC_WEIRD,
    X4_SSC_SIZE,
} x4SortStatusCode;

typedef size_t x4ElementSize;
typedef size_t x4CollectionLength;
typedef void*  x4Collection;
typedef const bool (*x4Comparator)(const void*, const void*);

typedef struct {
    const x4Collection       collection;
    const x4CollectionLength collection_length;
    const x4ElementSize      element_size;
    const x4Comparator       comparator;
} x4SortArguments;

//==============================================================================

x4SortStatusCode x4CheckSortArguments(const x4SortArguments*);
void x4GenericSwap(void*, void*, const x4ElementSize);

x4SortStatusCode x4BubbleSort(const x4SortArguments*);
x4SortStatusCode x4ShakerSort(const x4SortArguments*);
x4SortStatusCode x4OddEvenSort(const x4SortArguments*);

#endif // X4_SORT_HEADER_GUARD
