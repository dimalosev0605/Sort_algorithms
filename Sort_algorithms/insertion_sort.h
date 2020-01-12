#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

template<typename T>
void insertion_sort(T* arr, size_t l, size_t r)
{
    for(size_t i = r; i > l; --i)
        if(arr[i] < arr[i - 1]) swap(arr[i], arr[i - 1]);

    for(size_t i = l + 2; i <= r; ++i) {
        size_t j = i;
        T v = move(arr[i]);
        while(v < arr[j - 1]) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = move(v);
    }
}

template<typename T>
void insertion_sort(T* arr, size_t l, size_t r, bool (*comparator)(const T& a, const T& b))
{
    for(size_t i = r; i > l; --i)
        if(comparator(arr[i], arr[i - 1])) swap(arr[i], arr[i - 1]);

    for(size_t i = l + 2; i <= r; ++i) {
        size_t j = i;
        T v = move(arr[i]);
        while(comparator(v, arr[j - 1])) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = move(v);
    }
}

#endif // INSERTION_SORT_H
