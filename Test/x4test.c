#include <x4sort.h>
#include <stdio.h>

//==============================================================================

const bool
ascIntCmp(const void* lhs, const void* rhs)
{
    int* ilhs = (int*) lhs;
    int* irhs = (int*) rhs;
    return *ilhs > *irhs;
}

//==============================================================================

const bool
descIntCmp(const void* lhs, const void* rhs)
{
    return ascIntCmp(rhs, lhs);
}

//==============================================================================

void
printInt(int* a, size_t size)
{
    size -= 1; // Oh, shut up!
    for (size_t i = 0; i < size; ++i)
    { printf("%d ", a[ i ]); }
    printf("%d\n", a[ size ]);
}

//==============================================================================

#define NAME_LENGTH 63

typedef struct {
    char name[NAME_LENGTH];
    unsigned char age;
} Struct;

//==============================================================================

const bool
ascStructNameCmp(const void* lhs, const void* rhs)
{
    const size_t n = NAME_LENGTH - 1;
    Struct* slhs = (Struct*) lhs;
    Struct* srhs = (Struct*) rhs;
    return strncmp(slhs->name, srhs->name, n) > 0;
}

//==============================================================================

void
printStruct(Struct* a, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    { printf("name: %s, age: %d\n", a[ i ].name, (int) a[ i ].age); }
    puts(" =============== ");
}

//==============================================================================


#define SIZE 10

int
main(int argc, char* argv[])
{
    {
        int a[SIZE] = {89, 2, -3, 33, 98, -13, -19, -1, 0, 10};
        puts("* bubble sort *");
        printInt(a, SIZE);
        x4BubbleSort(&(x4SortArguments){.collection = a,
                                        .collection_length = SIZE,
                                        .element_size = sizeof(*a),
                                        .comparator = descIntCmp});
        printInt(a, SIZE);
    }
    {
        int a[SIZE] = {89, 2, -3, 33, 98, -13, -19, -1, 0, 10};
        puts("* cocktail shaker sort *");
        printInt(a, SIZE);
        x4ShakerSort(&(x4SortArguments){.collection = a,
                                        .collection_length = SIZE,
                                        .element_size = sizeof(*a),
                                        .comparator = ascIntCmp});
        printInt(a, SIZE);
    }
    {
        int a[SIZE] = {89, 2, -3, 33, 98, -13, -19, -1, 0, 10};
        puts("* odd-even sort *");
        printInt(a, SIZE);
        x4OddEvenSort(&(x4SortArguments){.collection = a,
                                         .collection_length = SIZE,
                                         .element_size = sizeof(*a),
                                         .comparator = ascIntCmp});
        printInt(a, SIZE);
    }
    {
        Struct a[SIZE] = {
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
        puts("* odd-even sort *");
        printStruct(a, SIZE);
        x4OddEvenSort(&(x4SortArguments){.collection = a,
                                         .collection_length = SIZE,
                                         .element_size = sizeof(*a),
                                         .comparator = ascStructNameCmp});
        printStruct(a, SIZE);
    }
}

