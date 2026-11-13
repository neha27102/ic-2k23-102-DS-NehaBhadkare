#include<iostream>
using namespace std ;

int binarySearch(int arr[] , int size , int key){
    int start = 0 ;
    int end = size -1 ;
    int mid = start + (end - start) / 2 ;

    while(start <= end){
        if(arr[mid] == key ){
            return mid ;
        }
        //go to right part and search there
        if(key > arr[mid]){
            start = mid+1 ;
        }
        //go to left part and search there
        if(key< arr[mid]){
            end = mid - 1 ;
        }
        mid = start + (end-start)/2 ;
    }
    return -1 ;
}
void input(int arr[] , int size ){
    cout<<"Enter elements of array one by one : " ;
    for(int i = 0 ; i < size ; i++ ){
        cin >> arr[i];
    }
}
void print(int arr[] , int size ){
    cout << "Your array elements are : " ;
    for(int i = 0 ; i < size ; i++ ){
        cout << arr[i] << " " ;
    }
    cout << endl ;
}

int main(){
    int n ;
    cout << "Enter size of array : " ;
    cin >> n ;
    int key ;
    cout << "Enter key : " ;
    cin >> key ;
    int arr[n] ;
    input(arr ,n) ;
    print(arr,n) ;
    int index = binarySearch(arr , n , key) ;
    cout << "Index of " << key << "is : "<< index << endl ;
    return 0 ;
}
