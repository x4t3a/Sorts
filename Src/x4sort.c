#include <x4sort.h>

//==============================================================================

x4SortStatusCode
x4CheckSortArguments(const x4SortArguments* args)
{
    if (args == NULL)             { return X4_SSC_NULL_ARGS_PTR; }
    if (args->collection == NULL) { return X4_SSC_NULL_COLL_PTR; }
    if (args->comparator == NULL) { return X4_SSC_NULL_CMP_PTR;  }
    return X4_SSC_ARGS_GOOD;
}

//==============================================================================

void
x4GenericSwap(void* lhs, void* rhs, const x4ElementSize element_size)
{
    char tmp[ element_size ];
    memcpy(tmp, lhs, element_size);
    memcpy(lhs, rhs, element_size);
    memcpy(rhs, tmp, element_size);
}

//==============================================================================

x4SortStatusCode
x4BubbleSort(const x4SortArguments* args)
{
    x4SortStatusCode status = x4CheckSortArguments(args);
    if (status != X4_SSC_ARGS_GOOD) { return status; }

    const size_t len = args->collection_length - 1;
    for (size_t i = 0; i < len; ++i)
    {
        for (size_t j = 0; j < len - i; ++j)
        {
            void* lhs = (args->collection + j * args->element_size);
            void* rhs = (args->collection + (j + 1) * args->element_size);
            if (args->comparator(lhs, rhs))
            {
                x4GenericSwap(lhs, rhs, args->element_size);
            }
        }
    }

    return X4_SSC_OK;
}

//==============================================================================

x4SortStatusCode
x4ShakerSort(const x4SortArguments* args)
{
    x4SortStatusCode status = x4CheckSortArguments(args);
    if (status != X4_SSC_ARGS_GOOD) { return status; }

    for (size_t i = 1; i < args->collection_length; ++i)
    {
        bool swapped = false;
        for (size_t j = i - 1; j < args->collection_length - i; ++j)
        {
            void* lhs = (args->collection + j * args->element_size);
            void* rhs = (args->collection + (j + 1) * args->element_size);
            if (args->comparator(lhs, rhs))
            {
                x4GenericSwap(lhs, rhs, args->element_size);
                swapped = true;
            }
        }

        for (size_t j = args->collection_length - i - 1; j >= i; --j)
        {
            void* lhs = (args->collection + (j - 1) * args->element_size);
            void* rhs = (args->collection + j * args->element_size);
            if (args->comparator(lhs, rhs))
            {
                x4GenericSwap(lhs, rhs, args->element_size);
                swapped = true;
            }
        }

        if (!swapped) { break; }
    }
}

//==============================================================================

x4SortStatusCode
x4OddEvenSort(const x4SortArguments* args)
{
    x4SortStatusCode status = x4CheckSortArguments(args);
    if (status != X4_SSC_ARGS_GOOD) { return status; }

    size_t size = args->collection_length - 1;
    for (bool sorted = false; !sorted; )
    {
        sorted = true;
        for (size_t i = 1; i < size; i += 2)
        {
            void* lhs = (args->collection + i * args->element_size);
            void* rhs = (args->collection + (i + 1) * args->element_size);
            if (args->comparator(lhs, rhs))
            {
                x4GenericSwap(lhs, rhs, args->element_size);
                sorted = false;
            }
        }

        for (size_t i = 0; i < size; i += 2)
        {
            void* lhs = (args->collection + i * args->element_size);
            void* rhs = (args->collection + (i + 1) * args->element_size);
            if (args->comparator(lhs, rhs))
            {
                x4GenericSwap(lhs, rhs, args->element_size);
                sorted = false;
            }
        }
    }

    return X4_SSC_OK;
}

//==============================================================================

