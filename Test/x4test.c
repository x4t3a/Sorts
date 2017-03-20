#include <x4sort.h>
#include <stdio.h>

//==============================================================================

const bool ascIntCmp(const void* lhs, const void* rhs);
const bool descIntCmp(const void* lhs, const void* rhs);
void printInt(int* a, size_t size);

//==============================================================================

const bool ascDoubleCmp(const void* lhs, const void* rhs);
void printDouble(double* a, size_t size);

//==============================================================================

#define NAME_LENGTH 63

typedef struct {
    char name[NAME_LENGTH];
    unsigned char age;
} Struct;

const bool ascStructNameCmp(const void* lhs, const void* rhs);
void printStruct(Struct* a, size_t size);

//==============================================================================

#define ARRSZ(arr) (sizeof(arr) / sizeof(*arr))

int
main(int argc, char* argv[])
{
    {
        int arr[] = { 89, 2, -3, 33, 98, -13, -19, -1, 0, 10 };
        size_t arrsz = ARRSZ(arr);
        puts("* bubble sort *");
        printInt(arr, arrsz);
        x4BubbleSort(&(x4SortArguments){.collection = arr,
                                        .collection_length = arrsz,
                                        .element_size = sizeof(*arr),
                                        .comparator = descIntCmp});
        printInt(arr, arrsz);
    }
    {
        double arr[] = { 89.2, 2.3, -3.9, 33.1, 98.8, -13.1, -19.3, -1.6, 10.4};
        size_t arrsz = ARRSZ(arr);
        puts("* cocktail shaker sort *");
        printDouble(arr, arrsz);
        x4ShakerSort(&(x4SortArguments){.collection = arr,
                                        .collection_length = arrsz,
                                        .element_size = sizeof(*arr),
                                        .comparator = ascDoubleCmp});
        printDouble(arr, arrsz);
    }
    {
        int arr[] = {89, 2, -3, 33, 98, -13, -19, -1, 0, 10};
        size_t arrsz = ARRSZ(arr);
        puts("* odd-even sort *");
        printInt(arr, arrsz);
        x4OddEvenSort(&(x4SortArguments){.collection = arr,
                                         .collection_length = arrsz,
                                         .element_size = sizeof(*arr),
                                         .comparator = descIntCmp});
        printInt(arr, arrsz);
    }
    {
        Struct arr[] = {
            {.name = "Valera", .age = 59},
            {.name = "Sasha", .age = 37},
            {.name = "Egor", .age = 31},
            {.name = "Marina", .age = 21},
            {.name = "Anna", .age = 22},
            {.name = "Lena", .age = 42},
            {.name = "Dima", .age = 34},
            {.name = "Nikita", .age = 33},
            {.name = "Boris", .age = 20},
            {.name = "Sergei", .age = 19},
        };
        size_t arrsz = ARRSZ(arr);
        puts("* odd-even sort *");
        printStruct(arr, arrsz);
        x4OddEvenSort(&(x4SortArguments){.collection = arr,
                                         .collection_length = arrsz,
                                         .element_size = sizeof(*arr),
                                         .comparator = ascStructNameCmp});
        printStruct(arr, arrsz);
    }
    {
        int arr[] = { 89, 2, -3, 33, 98, -13, -19, -1, 0, 10 };
        size_t arrsz = ARRSZ(arr);
        puts("* selection sort *");
        printInt(arr, arrsz);
        x4SelectionSort(&(x4SortArguments){.collection = arr,
                                           .collection_length = arrsz,
                                           .element_size = sizeof(*arr),
                                           .comparator = ascIntCmp});
        printInt(arr, arrsz);
    }
}

//==============================================================================

const bool
ascIntCmp(const void* lhs, const void* rhs)
{
    int* ilhs = (int*) lhs;
    int* irhs = (int*) rhs;
    return *ilhs > *irhs;
}

const bool
descIntCmp(const void* lhs, const void* rhs)
{
    return ascIntCmp(rhs, lhs);
}

void
printInt(int* a, size_t size)
{
    size -= 1; // Oh, shut up!
    for (size_t i = 0; i < size; ++i)
    { printf("%d ", a[ i ]); }
    printf("%d\n", a[ size ]);
}

//==============================================================================

const bool
ascDoubleCmp(const void* lhs, const void* rhs)
{
    double* ilhs = (double*) lhs;
    double* irhs = (double*) rhs;
    return *ilhs > *irhs;
}

void
printDouble(double* a, size_t size)
{
    size -= 1; // Oh, shut up!
    for (size_t i = 0; i < size; ++i)
    { printf("%.1lf ", a[ i ]); }
    printf("%.1lf\n", a[ size ]);
}

//==============================================================================

const bool
ascStructNameCmp(const void* lhs, const void* rhs)
{
    const size_t n = NAME_LENGTH - 1;
    Struct* slhs = (Struct*) lhs;
    Struct* srhs = (Struct*) rhs;
    return strncmp(slhs->name, srhs->name, n) > 0;
}

void
printStruct(Struct* a, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    { printf("name: %s, age: %d\n", a[ i ].name, (int) a[ i ].age); }
    puts(" =============== ");
}

//==============================================================================

