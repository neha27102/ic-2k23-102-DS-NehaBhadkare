#include<iostream>
using namespace std ;
//TimeComplexity O(n^2)
void selectionSort(int arr[],int n){
    for(int i =0 ; i < n-1 ; i++){// as the largest element automatically reaches its correct position it does not need last iteration
        int smallestIdx = i ; //unsorted part starting idx
        for(int j = i+1 ; j < n ; j++){//as the sorted part comes before j ,j only works on unsorted part hence it is initialised from i+1
            if (arr[j] < arr[smallestIdx]){
                smallestIdx = j ;
        }
    }
    //after this loop we found our smallest value
    int temp = arr[smallestIdx] ;
                arr[smallestIdx] = arr[i] ;  //indirectly we are just swapping i and j(j with diff name)
                arr[i] = temp ;
            }
    
}
void print(int arr[] , int size ){
    for(int i = 0 ; i < size ; i++ ){
        cout << arr[i] << " " ;
    }
    cout << endl ;
}
int main(){
    int n ;
    cout << "Enter size of array : " ;
    cin >> n ;
    int arr[n] ;
    cout << "Enter each element of array : "<<endl ;
    for(int i =0 ; i < n ; i++ ){
        cin>>arr[i] ;
    }
    print(arr,n) ;
    cout << "Sorted Array is :" ;
    selectionSort(arr,n) ;
    print(arr,n) ;
}
