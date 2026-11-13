#include<iostream>
using namespace std ;

void countSort(int arr[],int n ,int pos);
int getMax(int arr[],int n){
    int max = arr[0] ;
    for(int i = 0 ; i < n ; i++){
        if (arr[i] > max){
            max = arr[i] ;
        }
    }
    return max ;
}
void radixSort(int arr[],int n){
    int max = getMax(arr,n) ;
    for(int pos = 1 ; max/pos > 0 ; pos *= 10){
        countSort(arr,n,pos) ;
    }
}
void countSort(int arr[],int n ,int pos){
    int count[10] = {0} ;
    int k = n ;
    //now we need to monitor the occurence of each element
    for(int i = 0 ; i < n ; i++){
        count[(arr[i]/pos)%10]++ ;
    }
    //now for the updated count array that actually tracks the index values
    for(int i = 1 ; i < 10 ; i++){
        count[i] = count[i]+count[i-1] ;
    }
    //now for actually placing values at their correct positions in different array
    int arrB[n] ;
    for(int i = n-1 ; i >= 0 ; i--){
        arrB[--count[(arr[i]/pos)%10]] = arr[i] ;
    }
    for(int i =0 ; i < n ; i++ ){
        arr[i] = arrB[i] ;
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
    radixSort(arr,n) ;
    print(arr,n) ;
    return 0 ;
}
