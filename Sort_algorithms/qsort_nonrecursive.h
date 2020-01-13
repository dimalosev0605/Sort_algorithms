#ifndef QSORT_NONRECURSIVE_H
#define QSORT_NONRECURSIVE_H

#include "qsort_basic.h"
#include <stack>

void push(std::stack<int>& s, int a, int b)
{
    s.push(b);
    s.push(a);
}

template<typename T>
void qsort_nonrecursive(T* arr, int l, int r)
{
    std::stack<int> s;
    push(s, l, r);
    while(!s.empty()) {
        l = s.top();
        s.pop();
        r = s.top();
        s.pop();
        int i = partition(arr, l, r);
        if(i - l > r - i) {
            if(i - 1 <= l) continue;
            push(s, l, i - 1);
            if(r <= i + 1) continue;
            push(s, i + 1, r);
        }
        else {
            if(r <= i + 1) continue;
            push(s, i + 1, r);
            if(i - 1 <= l) continue;
            push(s, l, i - 1);
        }
    }
}

template<typename T>
void qsort_nonrecursive(T* arr, int l, int r, bool (*comparator)(const T& a, const T& b))
{
    std::stack<int> s;
    push(s, l, r);
    while(!s.empty()) {
        l = s.top();
        s.pop();
        r = s.top();
        s.pop();
        int i = partition(arr, l, r, comparator);
        if(i - l > r - i) {
            if(i - 1 <= l) continue;
            push(s, l, i - 1);
            if(r <= i + 1) continue;
            push(s, i + 1, r);
        }
        else {
            if(r <= i + 1) continue;
            push(s, i + 1, r);
            if(i - 1 <= l) continue;
            push(s, l, i - 1);
        }
    }
}

#endif // QSORT_NONRECURSIVE_H
