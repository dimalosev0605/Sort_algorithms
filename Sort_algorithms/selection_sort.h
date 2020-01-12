#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

template<typename T>
void selection_sort(T* arr, size_t l, size_t r)
{
    for(size_t i = l; i < r; ++i) {
        size_t min = i;
        for(size_t j = i + 1; j <= r; ++j) if(arr[j] < arr[min]) min = j;
        swap(arr[i], arr[min]);
    }
}

template<typename T>
void selection_sort(T* arr, size_t l, size_t r, bool (*comparator)(const T& a, const T& b))
{
    for(size_t i = l; i < r; ++i) {
        size_t min = i;
        for(size_t j = i + 1; j <= r; ++j) if(comparator(arr[j], arr[min])) min = j;
        swap(arr[i], arr[min]);
    }
}

#endif // SELECTION_SORT_H
