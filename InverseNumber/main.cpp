#include <iostream>
#include"SortTestHelper.h"
using namespace std;
long long __merge(int arr[],int l,int mid,int r)
{
    int res=0;
    int *aux=new int[r-l+1];
    for(int i=l;i<=r;i++)
        aux[i-l]=arr[i];
    int i=l;
    int j=mid+1;
    for(int k=l;k<=r;k++)
    {
        if(i>mid)
        {
            arr[k]=aux[j-l];
            j++;
        }
        else if(j>r)
        {
            arr[k]=aux[i-l];
            i++;
        }
        else  if(aux[i-l]<aux[j-l])
        {
            arr[k]=aux[i-l];
            i++;
        }
        else
        {
            arr[k]=aux[j-l];
            j++;
            res+=(long long)(mid-i+1);
        }
    }
    delete[]aux;
    return res;
}
long long __inversionCount(int arr[],int l,int r)
{
    if(l>=r)
       return 0;
    int mid=l+(r-l)/2;
    int resl=__inversionCount(arr,l,mid);
    int resr=__inversionCount(arr,mid+1,r);
    if(arr[mid]>arr[mid+1])
        return resl+resr+__merge(arr,l,mid,r);
    else
        return resl+resr;
}
long long inversionCount(int arr[],int n)
{
    return __inversionCount(arr,0,n-1);
}
int main()
{
    int n=10;
    cout<<"test inversion count for random array,n="<<n<<" :"<<endl;
    int *arr=SortTestHelper::generateRandomArray(n,0,n);
    cout<<inversionCount(arr,n)<<endl;
    delete[]arr;

    cout<<"test inversion count for ordered array,n="<<n<<" :"<<endl;
    int *arr1=SortTestHelper::generateOrderedArray(n);
    cout<<inversionCount(arr1,n)<<endl;
    delete[]arr1;


     cout<<"test inversion count for reversed ordered array,n="<<n<<" :"<<endl;
    int *arr2=SortTestHelper::generateReverseOrderedArray(n);
    cout<<inversionCount(arr2,n)<<endl;
    delete[]arr2;
    //cout << "Hello world!" << endl;
    return 0;
}
