#ifndef QSORT_IGNORE_SMALL_CHUNKS_H
#define QSORT_IGNORE_SMALL_CHUNKS_H

#include "qsort_basic.h"
#include "insertion_sort.h"

static const int chunk_size = 5;

template<typename T>
void qsort_ignore_small_chunks(T* arr, int l, int r)
{
    if(r - l <= chunk_size) {
        insertion_sort(arr, l, r);
        return;
    }
    int i = partition(arr, l, r);
    qsort_ignore_small_chunks(arr, l, i - 1);
    qsort_ignore_small_chunks(arr, i + 1, r);
}

template<typename T>
void qsort_ignore_small_chunks(T* arr, int l, int r, bool (*comparator)(const T& a, const T& b))
{
    if(r - l <= 5) {
        insertion_sort(arr, l, r, comparator);
        return;
    }
    int i = partition(arr, l, r, comparator);
    qsort_ignore_small_chunks(arr, l, i - 1, comparator);
    qsort_ignore_small_chunks(arr, i + 1, r, comparator);
}

#endif // QSORT_IGNORE_SMALL_CHUNKS_H
