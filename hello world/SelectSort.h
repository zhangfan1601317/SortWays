#ifndef SELECTSORT_H_INCLUDED
#define SELECTSORT_H_INCLUDED

template<typename T>
void selectSort(T arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
                minIndex=j;
        }
        swap(arr[i],arr[minIndex]);
    }
}

#endif // SELECTSORT_H_INCLUDED
