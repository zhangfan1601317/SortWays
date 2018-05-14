#ifndef SHELLSORT_H_INCLUDED
#define SHELLSORT_H_INCLUDED

template<typename T>
void shellSort(T arr[],int n)
{
    int h=1;
    while(h<n/3)
        h=3*h+1;

    while(h>=1)
    {
        for(int i=h;i<n;i++)
        {
            T e=arr[i];
            int j;
            for(j=i;j>=h&&arr[j-h]>e;j-=h)
                arr[j]=arr[j-h];
            arr[j]=e;
        }
        n/=3;
    }
}

#endif // SHELLSORT_H_INCLUDED
