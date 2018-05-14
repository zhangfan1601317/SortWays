#ifndef QUICKSORT2_H_INCLUDED
#define QUICKSORT2_H_INCLUDED
//arr[l+1,...,i]<=v,arr[i+1,...,r]>=v
template<typename T>
int __partion2(T arr[],int l,int r)
{
    int index=rand()%(r-l+1)+l;
    swap(arr[l],arr[index]);
    T v=arr[l];

    int i=l+1;
    int j=r;
    while(true)
    {
        while(i<=r&&arr[i]<=v)
            i++;
        while(j>l&&arr[j]>=v)
            j--;
        if(i<j)
            swap(arr[i++],arr[j--]);
        else
            break;

    }
    swap(arr[l],arr[j]);
    return j;
}
template<typename T>
void __quickSort2(T arr[],int l,int r)
{
    if(l>=r)
        return;
    int p=__partion2(arr,l,r);
    __quickSort2(arr,l,p);
    __quickSort2(arr,p+1,r);
}
template<typename T>
void quickSort2(T arr[],int n)
{
    __quickSort2(arr,0,n-1);
}


#endif // QUICKSORT2_H_INCLUDED
