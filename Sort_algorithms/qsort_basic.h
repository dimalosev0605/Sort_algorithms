#ifndef QSORT_BASIC_H
#define QSORT_BASIC_H

template<typename T>
int partition(T* arr, int l, int r)
{
    int i = l - 1;
    int j = r;
    T v = arr[r];
    for(;;) {
        while(arr[++i] < v);
        while(v < arr[--j]) if(j == l) break;
        if(i >= j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[r]);
    return i;
}

template<typename T>
int partition(T* arr, int l, int r, bool (*comparator)(const T& a, const T& b))
{
    int i = l - 1;
    int j = r;
    T v = arr[r];
    for(;;) {
        while(comparator(arr[++i], v));
        while(comparator(v, arr[--j])) if(j == l) break;
        if(i >= j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[r]);
    return i;
}

template<typename T>
void qsort_basic(T* arr, int l, int r)
{
    if(r <= l) return;
    int i = partition(arr, l, r);
    qsort_basic(arr, l, i - 1);
    qsort_basic(arr, i + 1, r);
}

template<typename T>
void qsort_basic(T* arr, int l, int r, bool (*comparator)(const T& a, const T& b))
{
    if(r <= l) return;
    int i = partition(arr, l, r, comparator);
    qsort_basic(arr, l, i - 1, comparator);
    qsort_basic(arr, i + 1, r, comparator);
}

#endif // QSORT_BASIC_H
