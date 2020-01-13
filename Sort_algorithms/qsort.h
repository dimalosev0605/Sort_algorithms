#ifndef QSORT_H
#define QSORT_H

#include "qsort_basic.h"
#include "insertion_sort.h"

static const int block_size = 10;

template<typename T>
void hybrid(T* arr, int l, int r)
{
    if(r - l <= block_size) return;
    swap(arr[(l + r) >> 1], arr[r - 1]);

    if(arr[r - 1] < arr[l]) swap(arr[r - 1], arr[l]);
    if(arr[r] < arr[l]) swap(arr[r], arr[l]);
    if(arr[r] < arr[r - 1]) swap(arr[r], arr[r - 1]);

    int i = partition(arr, l + 1, r - 1);
    hybrid(arr, l, i - 1);
    hybrid(arr, i + 1, r);
}

template<typename T>
void qsort(T* arr, int l, int r)
{
    hybrid(arr, l, r);
    insertion_sort(arr, l, r);
}

template<typename T>
void hybrid(T* arr, int l, int r, bool (*comparator)(const T& a, const T& b))
{
    if(r - l <= block_size) return;
    swap(arr[(l + r) >> 1], arr[r - 1]);

    if(arr[r - 1] < arr[l]) swap(arr[r - 1], arr[l]);
    if(arr[r] < arr[l]) swap(arr[r], arr[l]);
    if(arr[r] < arr[r - 1]) swap(arr[r], arr[r - 1]);

    int i = partition(arr, l + 1, r - 1, comparator);
    hybrid(arr, l, i - 1, comparator);
    hybrid(arr, i + 1, r, comparator);
}

template<typename T>
void qsort(T* arr, int l, int r, bool (*comparator)(const T& a, const T& b))
{
    hybrid(arr, l, r, comparator);
    insertion_sort(arr, l, r, comparator);
}

#endif // QSORT_H
