#ifndef BUBBLESORT_H_INCLUDED
#define BUBBLESORT_H_INCLUDED

template<typename T>
void BubbleSort(T arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }

        }
    }
}
//���ñ�ʶλ�Ż��ɣ�
template<typename T>
void BubbleSort1(T arr[],int n)
{
    int flag=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag=1;
                swap(arr[j],arr[j+1]);
            }

        }
        if(flag==0)
            break;
    }
}
#endif // BUBBLESORT_H_INCLUDED
