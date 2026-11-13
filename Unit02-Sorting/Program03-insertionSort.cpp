#include<iostream>
using namespace std ;
//time complexity O(n^2)
void insertionSort(int arr[],int size){
    for(int i = 1 ; i < size ; i++){// i only works with unsorted i =0 is considered sorted i =1 is the first element of sorted
        int prev = i - 1 ;
        int curr = arr[i];
        while(prev >= 0 && arr[prev] > curr){
            arr[prev+1] = arr[prev] ;
            prev-- ; // We use prev+1 because prev moves backwards while shifting elements.
                    // When the loop stops, prev+1 gives the correct position to insert curr.
        }
        arr[prev+1] = curr ;
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
    insertionSort(arr,n) ;
    print(arr,n) ;
}
