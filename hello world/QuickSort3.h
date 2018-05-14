#ifndef QUICKSORT3_H_INCLUDED
#define QUICKSORT3_H_INCLUDED

template <typename T>
void __quickSort3(T arr[],int l,int r)
{
    if(r-l<16)
    {
        InsertionSort(arr,l,r);
        return;
    }
    //partion
    //arr[l]==v,arr[l+1,lt]<v,arr[lt+1,...,i-1]=v,arr[gt,...r]>v
    int index=rand()%(r-l+1)+l;
    swap(arr[index],arr[l]);
    T temp=arr[l];

    int lt=l;
    int i=l+1;
    int gt=r+1;

    while(i<gt)
    {
        if(arr[i]<temp)
        {
            swap(arr[i],arr[lt+1]);
            lt++;
            i++;
        }
        else if(arr[i]>temp)
        {
            swap(arr[i],arr[gt-1]);
            gt--;
        }
        else
            i++;
    }
    swap(arr[l],arr[lt--]);

    __quickSort3(arr,l,lt);
    __quickSort3(arr,gt,r);
}
template<typename T>
void quickSort3(T arr[],int n)
{
    srand(time(NULL));
    __quickSort3(arr,0,n-1);
}

#endif // QUICKSORT3_H_INCLUDED
