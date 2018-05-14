#include <iostream>
#include <algorithm>
#include<ctime>
#include "Student.h"
#include"SortTestHelper.h"
#include"SelectSort.h"
#include"InsertSort.h"
#include"BubbleSort.h"
#include"MergeSort.h"
#include"QuickSort.h"
#include"QuickSort2.h"
#include"QuickSort3.h"
#include"ShellSort.h"
using namespace std;
//template<typename T>
//void shellSort(T arr[],int n)
//{
//    int h=1;
//    while(h<n/3)
//        h=3*h+1;
//    while(h>=1)
//    {
//        for(int i=h;i<n;i++)
//        {
//            T e=arr[i];
//            int j;
//            for(j=i;j>=h&&arr[j-h]>e;j-=h)
//                arr[j]=arr[j-h];
//            arr[j]=e;
//        }
//        h/=3;
//    }
//}
int main()
{
    int n=50000;
    int *arr=SortTestHelper::generateRandomArray(n,0,n);
    //int *arr=SortTestHelper::generateNearlyOrderedArray(n,100);
    //selectSort(arr,n);
    //SortTestHelper::printArray(arr,n);
    int *arr1=SortTestHelper::copyIntArray(arr,n);
    int *arr2=SortTestHelper::copyIntArray(arr,n);
    int *arr3=SortTestHelper::copyIntArray(arr,n);
    int *arr4=SortTestHelper::copyIntArray(arr,n);
    int *arr5=SortTestHelper::copyIntArray(arr,n);
    int *arr6=SortTestHelper::copyIntArray(arr,n);
    int *arr7=SortTestHelper::copyIntArray(arr,n);
    int *arr8=SortTestHelper::copyIntArray(arr,n);

    //SortTestHelper::testSort("selection Sort",selectSort,arr,n);
    //SortTestHelper::testSort("insertion Sort",InsertSort,arr1,n);
    //SortTestHelper::testSort("bubble Sort",BubbleSort1,arr2,n);
    SortTestHelper::testSort("merge Sort",mergeSort,arr3,n);
    SortTestHelper::testSort("merge SortBU",mergeSortBU,arr4,n);
    //SortTestHelper::testSort("quick Sort",quickSort,arr5,n);
    SortTestHelper::testSort("quick Sort2",quickSort2,arr6,n);
    SortTestHelper::testSort("quick Sort3",quickSort3,arr7,n);
    SortTestHelper::testSort("shell Sort",shellSort,arr8,n);

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;

    //cout << "Hello world!" << endl;
    return 0;
}
