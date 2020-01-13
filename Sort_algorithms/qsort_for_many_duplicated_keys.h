#ifndef QSORT_FOR_MANY_DUPLICATED_KEYS_H
#define QSORT_FOR_MANY_DUPLICATED_KEYS_H

template<typename T>
void qsort_for_many_duplicated_keys(T* arr, int l, int r)
{
    if(r <= l) return;
    T v = arr[r];
    int i = l - 1;
    int j = r;
    int p = l - 1;
    int q = r;

    for(;;) {
        while(arr[++i] < v);
        while(v < arr[--j]) if(j == l) break;
        if(i >= j) break;
        swap(arr[i], arr[j]);
        if(arr[i] == v) { ++p; swap(arr[p], arr[i]); }
        if(v == arr[j]) { --q; swap(arr[q], arr[j]); }
    }
    swap(arr[i], arr[r]);
    j = i - 1;
    ++i;
    int k;
    for(k = l; k <= p; ++k, --j) swap(arr[k], arr[j]);
    for(k = r - 1; k >= q; --k, ++i) swap(arr[k], arr[i]);
    qsort_for_many_duplicated_keys(arr, l, j);
    qsort_for_many_duplicated_keys(arr, i, r);
}

template<typename T>
void qsort_for_many_duplicated_keys(T* arr, int l, int r, bool (*comparator)(const T& a, const T& b))
{
    if(r <= l) return;
    T v = arr[r];
    int i = l - 1;
    int j = r;
    int p = l - 1;
    int q = r;

    for(;;) {
        while(comparator(arr[++i], v));
        while(comparator(v,arr[--j])) if(j == l) break;
        if(i >= j) break;
        swap(arr[i], arr[j]);
        if(arr[i] == v) { ++p; swap(arr[p], arr[i]); }
        if(v == arr[j]) { --q; swap(arr[q], arr[j]); }
    }
    swap(arr[i], arr[r]);
    j = i - 1;
    ++i;
    int k;
    for(k = l; k <= p; ++k, --j) swap(arr[k], arr[j]);
    for(k = r - 1; k >= q; --k, ++i) swap(arr[k], arr[i]);
    qsort_for_many_duplicated_keys(arr, l, j, comparator);
    qsort_for_many_duplicated_keys(arr, i, r, comparator);
}

#endif // QSORT_FOR_MANY_DUPLICATED_KEYS_H
