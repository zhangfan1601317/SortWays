#ifndef HEAPSORTINDEX_H_INCLUDED
#define HEAPSORTINDEX_H_INCLUDED
#include"IndexMaxHeap.h"
#include"IndexMinHeap.h"
template<typename T>
void heapSortIndex(T arr[],int n)
{
    IndexMaxHeap<T>indexMaxHeap=IndexMaxHeap<T>(n);
    for(int i=0;i<n;i++)
        indexMaxHeap.insert(i,arr[i]);
    for(int i=n-1;i>=0;i--)
    {
        arr[i]=indexMaxHeap.extractMax();
    }
}
template<typename T>
void heapSortMinIndex(T arr[],int n)
{
    IndexMinHeap<T>indexMinHeap=IndexMinHeap<T>(n);
    for(int i=0;i<n;i++)
        indexMinHeap.insert(i,arr[i]);
    for(int i=0;i<n;i++)
        arr[i]=indexMinHeap.extractMin();
}
#endif // HEAPSORTINDEX_H_INCLUDED
