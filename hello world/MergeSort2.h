#ifndef MERGESORT2_H_INCLUDED
#define MERGESORT2_H_INCLUDED
#include"InsertionSort.h"
template<typename T>
void __merge2(T arr[],T aux[],int l,int mid,int r)
{
    for(int i=l;i<=r;i++)
        aux[i]=arr[i];

}
template<typename T>
void __mergerSort2(T arr[],T aux[],int l,int r)
{
    if(r-l<16)
    {
        InsertionSort(arr,l,r);
        return;
    }
    int mid=(l+r)/2;
    __merge2(arr,aux,l,mid);
    __merge2(arr,aux,mid+1,r);
    if(arr[mid]>arr[mid+1])
        __merge2(arr,aux,l,mid,r);

}

template<typename T>
void mergeSort2(T arr[],int n)
{
    T *aux=new T[n];
    __mergeSort2(arr,aux,0,n-1);
}

#endif // MERGESORT2_H_INCLUDED
