#ifndef INSERTSORT_H_INCLUDED
#define INSERTSORT_H_INCLUDED

//template<typename T>
//void InsertSort(T arr[],int n)
//{
//    for(int i=1;i<n;i++)
//    {
//        for(int j=i;j>0;j--)
//        {
//            if(arr[j]<arr[j-1])
//                swap(arr[j],arr[j-1]);
//        }
//    }
//}
template<typename T>
void InsertSort(T arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=arr[i];
        int j;
        for(j=i;j>0;j--)
        {
            if(arr[j-1]>temp)
                arr[j]=arr[j-1];
            else
                break;
        }
        arr[j]=temp;
    }
}
template<typename T>
void InsertionSort(T arr[],int l,int r)
{
    for(int i=l+1;i<=r;i++)
    {
        int temp=arr[i];
        int j;
        for(j=i;j>l;j--)
        {
            if(arr[j-1]>temp)
                arr[j]=arr[j-1];
            else
                break;
        }
        arr[j]=temp;
    }
}
#endif // INSERTSORT_H_INCLUDED
