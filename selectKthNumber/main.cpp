#include <iostream>
#include<cassert>
#include<ctime>
#include"SortTestHelper.h"
using namespace std;
template<typename T>
int __partion2(T arr[],int l,int r)
{
    int index=rand()%(r-l+1)+l;
    swap(arr[index],arr[l]);
    T temp=arr[l];

    int i=l+1,j=r;
    while(true)
    {
        while(i<=r&&arr[i]<=temp)
            i++;
        while(j>l&&arr[j]>=temp)
            j--;
        if(i>j)
            break;
        else
            swap(arr[i++],arr[j--]);
    }
    swap(arr[l],arr[j]);
    return j;
}
template<typename T>
int __partion(T arr[],int l,int r)
{
    int index=rand()%(r-l+1)+l;
    swap(arr[l],arr[index]);
    T v=arr[l];

    int j=l;
    for(int i=l+1;i<=r;i++)
    {
        if(arr[i]<v)
        {
            j++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[l]);
    return j;
}
template<typename T>
int __selectKthNumber3(T arr[],int l,int r,int k)
{
    if(l==r)
        return arr[l];
    int index=rand()%(r-l+1)+l;
    swap(arr[index],arr[l]);
    T v=arr[l];

    int lt=l;
    int i=l+1;
    int gt=r+1;

    while(i<gt)
    {
        if(arr[i]==v)
            i++;
        else if(arr[i]<v)
        {
            swap(arr[lt+1],arr[i]);
            i++;
            lt++;
        }
        else
        {
            swap(arr[gt-1],arr[i]);
            gt--;
        }
    }
    swap(arr[l],arr[lt--]);

    if(k>lt&&k<gt)
        return arr[k];
    else if(k<=lt)
    return __selectKthNumber3(arr,l,lt,k);
    else
    return __selectKthNumber3(arr,gt,r,k);
}

template<typename T>
int __selectKthNumber(T arr[],int l,int r,int k)
{
    if(l==r)
        return arr[l];
    //partion
    int p=__partion2(arr,l,r);

    if(p==k)
        return arr[p];
    else if(p<k)
        return __selectKthNumber(arr,p+1,r,k);
    else
        return __selectKthNumber(arr,l,p-1,k);
}
template<typename T>
int selectionKth(T arr[],int n,int k)
{
    assert(k>=0&&k<n);
    srand(time(NULL));
    //return __selectKthNumber(arr,0,n-1,k);
    return __selectKthNumber3(arr,0,n-1,k);
}
int main()
{
    int n=500;
    int *arr=SortTestHelper::generateOrderedArray(n);
    for(int i=0;i<n;i++)
    {
         assert(selectionKth(arr,n,i)==i);
         cout<<"test "<<i<<" complete."<<endl;
    }
    cout<<"test selection complete."<<endl;
    //cout << "Hello world!" << endl;
    return 0;
}
