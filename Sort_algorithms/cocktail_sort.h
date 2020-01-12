#ifndef COCKTAIL_SORT_H
#define COCKTAIL_SORT_H

template<typename T>
void cocktail_sort(T* arr, size_t l, size_t r)
{
    while(l < r) {
        bool flag = true;
        for(size_t i = r; i > l; --i) {
            if(arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                flag = false;
            }
        }
        if(flag) break;
        ++l;

        flag = true;
        for(size_t i = l; i < r; ++i) {
            if(arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                flag = false;
            }
        }
        if(flag) break;
        --r;
    }
}

template<typename T>
void cocktail_sort(T* arr, size_t l, size_t r, bool (*comparator)(const T& a, const T& b))
{
    while(l < r) {
        bool flag = true;
        for(size_t i = r; i > l; --i) {
            if(comparator(arr[i], arr[i - 1])) {
                swap(arr[i], arr[i - 1]);
                flag = false;
            }
        }
        if(flag) break;
        ++l;

        flag = true;
        for(size_t i = l; i < r; ++i) {
            if(!comparator(arr[i], arr[i + 1])) {
                swap(arr[i], arr[i + 1]);
                flag = false;
            }
        }
        if(flag) break;
        --r;
    }
}

#endif // COCKTAIL_SORT_H
