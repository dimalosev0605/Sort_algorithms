#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

template<typename T>
void bubble_sort(T* arr, size_t l, size_t r)
{
    for(size_t i = l; i < r; ++i) {
        bool flag = true;
        for(size_t j = r; j > i; --j) {
            if(arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                flag = false;
            }
        }
        if(flag) return;
    }
}

template<typename T>
void bubble_sort(T* arr, size_t l, size_t r, bool(*comparator) (const T& a, const T& b))
{
    for(size_t i = l; i < r; ++i) {
        bool flag = true;
        for(size_t j = r; j > i; --j) {
            if(comparator(arr[j - 1], arr[j])) {
                swap(arr[j - 1], arr[j]);
                flag = false;
            }
        }
        if(flag) return;
    }
}

#endif // BUBBLE_SORT_H
