#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

template<typename T>
int __partion(T arr[],int l,int r)
{
    int index=rand()%(r-l+1)+l;
    swap(arr[l],arr[index]);
    T temp=arr[l];


    int j=l;
    for(int i=l+1;i<=r;i++)
    {
        if(arr[i]<temp)
        {
             swap(arr[j+1],arr[i]);
             j++;
        }
    }
    swap(arr[l],arr[j]);
    return j;
}
template<typename T>
void __quickSort(T arr[],int l,int r)
{
//    if(l>=r)
//        return;
    if(r-l<16)
    {
        InsertionSort(arr,l,r);
        return;
    }

    int p=__partion(arr,l,r);
    __quickSort(arr,l,p);
    __quickSort(arr,p+1,r);
}
template<typename T>
void quickSort(T arr[],int n)
{
    __quickSort(arr,0,n-1);
}

#endif // QUICKSORT_H_INCLUDED
