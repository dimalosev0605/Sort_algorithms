#ifndef SHELL_SORT_H
#define SHELL_SORT_H

template<typename T>
void shell_sort(T* arr, size_t l, size_t r)
{
    size_t h = 1;
    for(; h <= r - l; h = 3 * h + 1);

    for(; h > 0; h /= 3) {
        for(size_t i = l + h; i <= r; ++i) {
            size_t j = i;
            T v = move(arr[i]);
            while(j >= (l + h) && v < arr[j - h]) {
                arr[j] = arr[j - h];
                j -= h;
            }
            arr[j] = move(v);
        }
    }
}

template<typename T>
void shell_sort(T* arr, size_t l, size_t r, bool (*comparator)(const T& a, const T& b))
{
    size_t h = 1;
    for(; h <= r - l; h = 3 * h + 1);

    for(; h > 0; h /= 3) {
        for(size_t i = l + h; i <= r; ++i) {
            size_t j = i;
            T v = move(arr[i]);
            while(j >= (l + h) && comparator(v, arr[j - h])) {
                arr[j] = arr[j - h];
                j -= h;
            }
            arr[j] = move(v);
        }
    }
}

#endif // SHELL_SORT_H
