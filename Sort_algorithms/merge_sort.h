#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "insertion_sort.h"
#include <algorithm>

static const int ignore_chunk_size = 10;

//----------------------------------------------------------------

template<typename T>
void merge(T* arr, int l, int m, int r, T* memory)
{
    int i, j;
    for(i = l, j = 0; i <= m; ++i, ++j) memory[j] = move(arr[i]);
    for(i = r; i >= m + 1; ++j, --i) memory[j] = move(arr[i]);

    i = 0;
    j = r - l;
    for(int k = l; k <= r; ++k)
        if(memory[i] < memory[j])
            arr[k] = move(memory[i++]);
        else
            arr[k] = move(memory[j--]);
}

template<typename T>
void sort_ub_r(T* arr, int l, int r, T* memory)
{
    if(r <= l) return;
    int m = (l + r) >> 1;
    sort_ub_r(arr, l, m, memory);
    sort_ub_r(arr, m + 1, r, memory);
    merge(arr, l, m, r, memory);
}

template<typename T>
void merge_sort_ub_one_mem_chunk(T* arr, int l, int r)
{
    T* memory = new T[r - l + 1];
    sort_ub_r(arr, l, r, memory);
    delete [] memory;
}

template<typename T>
void merge(T* arr, int l, int m, int r, T* memory, bool (*comparator)(const T& a, const T& b))
{
    int i, j;
    for(i = l, j = 0; i <= m; ++i, ++j) memory[j] = move(arr[i]);
    for(i = r; i >= m + 1; ++j, --i) memory[j] = move(arr[i]);

    i = 0;
    j = r - l;
    for(int k = l; k <= r; ++k)
        if(comparator(memory[i], memory[j]))
            arr[k] = move(memory[i++]);
        else
            arr[k] = move(memory[j--]);
}

template<typename T>
void sort_ub_r(T* arr, int l, int r, T* memory, bool (*comparator)(const T& a, const T& b))
{
    if(r <= l) return;
    int m = (l + r) >> 1;
    sort_ub_r(arr, l, m, memory, comparator);
    sort_ub_r(arr, m + 1, r, memory, comparator);
    merge(arr, l, m, r, memory, comparator);
}

template<typename T>
void merge_sort_ub_one_mem_chunk(T* arr, int l, int r, bool (*comparator)(const T& a, const T& b))
{
    T* memory = new T[r - l + 1];
    sort_ub_r(arr, l, r, memory, comparator);
    delete [] memory;
}

//----------------------------------------------------------------

template<typename T>
void merge(T* arr, int l, int m, int r)
{
    T* aux = new T[r - l + 1];
    int i, j;
    for(i = l, j = 0; i <= m; ++i, ++j) aux[j] = move(arr[i]);
    for(i = r; i >= m + 1; ++j, --i) aux[j] = move(arr[i]);

    i = 0;
    j = r - l;

    for(int k = l; k <= r; ++k)
        if(aux[i] < aux[j])
            arr[k] = move(aux[i++]);
        else
            arr[k] = move(aux[j--]);

    delete [] aux;
}

template<typename T>
void merge_sort_ub_mul_mem_chunks(T* arr, int l, int r) // not stable
{
    if(r <= l) return;
    int m = (l + r) >> 1;
    merge_sort_mul_mem_chunks(arr, l, m);
    merge_sort_mul_mem_chunks(arr, m + 1, r);
    merge(arr, l, m, r);
}

template<typename T>
void merge(T* arr, int l, int m, int r, bool (*comparator)(const T& a, const T& b))
{
    T* aux = new T[r - l + 1];
    int i, j;
    for(i = l, j = 0; i <= m; ++i, ++j) aux[j] = move(arr[i]);
    for(i = r; i >= m + 1; ++j, --i) aux[j] = move(arr[i]);

    i = 0;
    j = r - l;

    for(int k = l; k <= r; ++k)
        if(comparator(aux[i], aux[j]))
            arr[k] = move(aux[i++]);
        else
            arr[k] = move(aux[j--]);

    delete [] aux;
}

template<typename T>
void merge_sort_ub_mul_mem_chunks(T* arr, int l, int r, bool (*comparator)(const T& a, const T& b))
{
    if(r <= l) return;
    int m = (l + r) >> 1;
    merge_sort_mul_mem_chunks(arr, l, m, comparator);
    merge_sort_mul_mem_chunks(arr, m + 1, r, comparator);
    merge(arr, l, m, r, comparator);
}

//----------------------------------------------------------------

template<typename T>
void merge(T* c, T* a, int n, T* b, int m)
{
    for(int i = 0, j = 0, k = 0; k < n + m; ++k)
    {
        if(i == n) { c[k] = move(b[j++]); continue; }
        if(j == m) { c[k] = move(a[i++]); continue; }
        c[k] = a[i] < b[j] ? move(a[i++]) : move(b[j++]);
    }
}

template<typename T>
void sort_ub_r(T* a, T* b, int l, int r)
{
    if(r - l <= ignore_chunk_size) {
        insertion_sort(a, l, r);
        return;
    }
    int m = (l + r) >> 1;
    sort_ub_r(b, a, l, m);
    sort_ub_r(b, a, m + 1, r);
    merge(a + l, b + l, m - l + 1, b + m + 1, r - m);
}

template<typename T>
void improved_merge_sort_ub(T* arr, int l, int r)
{
    T* aux = new T[r - l + 1];
    for(int i = l; i <= r; ++i) aux[i] = arr[i];
    sort_ub_r(arr, aux, l, r);
    delete [] aux;
}

template<typename T>
void merge(T* c, T* a, int n, T* b, int m, bool (*comparator)(const T& a, const T& b))
{
    for(int i = 0, j = 0, k = 0; k < n + m; ++k)
    {
        if(i == n) { c[k] = move(b[j++]); continue; }
        if(j == m) { c[k] = move(a[i++]); continue; }
        c[k] = comparator(a[i], b[j]) ? move(a[i++]) : move(b[j++]);
    }
}

template<typename T>
void sort_ub_r(T* a, T* b, int l, int r, bool (*comparator)(const T& a, const T& b))
{
    if(r - l <= ignore_chunk_size) {
        insertion_sort(a, l, r, comparator);
        return;
    }
    int m = (l + r) >> 1;
    sort_ub_r(b, a, l, m, comparator);
    sort_ub_r(b, a, m + 1, r, comparator);
    merge(a + l, b + l, m - l + 1, b + m + 1, r - m, comparator);
}

template<typename T>
void improved_merge_sort_ub(T* arr, int l, int r, bool (*comparator)(const T& a, const T& b))
{
    T* aux = new T[r - l + 1];
    for(int i = l; i <= r; ++i) aux[i] = arr[i];
    sort_ub_r(arr, aux, l, r, comparator);
    delete [] aux;
}

//----------------------------------------------------------------

template<typename T>
void merge_sort_bu(T* arr, int l, int r)
{
    for(int m = 1; m <= r - l; m = m + m)
        for(int i = l; i <= r - m; i += m + m)
            merge(arr, i, i + m - 1, std::min(i + m + m - 1, r));
}

template<typename T>
void merge_sort_bu(T* arr, int l, int r, bool (*comparator)(const T& a, const T& b))
{
    for(int m = 1; m <= r - l; m = m + m)
        for(int i = l; i <= r - m; i += m + m)
            merge(arr, i, i + m - 1, std::min(i + m + m - 1, r), comparator);
}

#endif // MERGE_SORT_H
