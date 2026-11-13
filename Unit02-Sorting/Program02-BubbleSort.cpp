#include<iostream>
using namespace std ;
//time complexity : O(n^2)
//check adjacent elements
//why n-i-1 => because the last element automatically reaches its correct position
//hence elements at last in reltaion to outer loop iteration need not to be cheked

void bubbleSort(int arr[],int n){
    bool isSwap =  false ;
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < n - i - 1 ; j++ ){
            if(arr[j] < arr[j+1]){
            int temp = arr[j] ;
            arr[j] =  arr[j+1] ;
            arr[j+1] = temp ;
            isSwap = true ;
            }
        }
        if(!isSwap){
        cout<< "Array is already sorted " ;
        return ;
    }
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
    bubbleSort(arr,n) ;
    print(arr,n) ;
}
