#include<iostream>
using namespace std;
void merge(int arr[],int s,int e)
{
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *first=new int[len1];
    int *second=new int[len2];
    int mainIndexArray=s;
    for(int i=0;i<len1;i++)
    {
        first[i]=arr[mainIndexArray++];
    }
    mainIndexArray=mid+1;
    for(int i=0;i<len2;i++)
    {
        second[i]=arr[mainIndexArray++];
    }
    int mainIndexArray=s;
    int index1=0;
    int index2=0;
    while(index1<len1 && index2<len2)
    {
        if(first[index1]<second[index2])
        {
            arr[mainIndexArray++]=first[index1++];
        }
        else
        {
            arr[mainIndexArray++]=second[index2++];
        }
    }

}
void mergeSort(int *arr,int s,int e)
{
    if(s>=e) return;
    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}
int main()
{
    int arr[5]={3,21,4,5,6};
    int n=5;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n-1;i++)
    {
        cout << arr[i] << " ";
    }
}