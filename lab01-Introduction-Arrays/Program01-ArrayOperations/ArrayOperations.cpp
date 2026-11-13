#include <iostream>
using namespace std;

void sumArr(int arr[],int size){ //TimeComplexity O(n)
     int sum = 0;
    for(int i = 0 ; i < size ;i++){
        sum += arr[i];
    }
    cout << "Sum of Array :" <<sum <<endl;
}
void insEleK(int arr[],int &size,int position,int element){
    if(size < 0 || size >= 100 ){
        cout << "Invalid input" ;
        return ;
    }
    for(int i = size ; i > position ; i--){
        arr[i] = arr[i-1] ;
    }
    arr[position] = element;
    size++;
}
void delEleK(int arr[],int &size,int position){
    if(size <= 0 ||position < 0  || position >= size ){
        cout << "Invalid input" ;
        return ;
    }
    for(int i = position ; i < size- 1 ; i++){
        arr[i] = arr[i+1] ;
    }
    size--;
}
void printArr(int arr[],int size){
    cout<<"Array Elements are :";
    for(int i = 0 ; i < size ; i++ ){
        cout<<arr[i]<<" ";
    }
    cout << endl ;
}
void searchEle(int arr[],int key,int size){
    for(int i = 0 ; i < size ; i++){
        if(key == arr[i]){
            cout << "key found at index: " << i <<endl ;
            return ;
        }
    }
    cout << "key not found." << endl ;
}
void rotateArr(int arr[] ,int size ){
    for(int i = 0 ; i < size/2 ; i++){
        int temp = arr[i] ;
        arr[i] = arr[size-1-i] ;
        arr[size-1-i] = temp ;
    }
}
int main() 
{
    int n ,position ,element ,key;
    cout<<"Enter array size: ";
    cin>>n;
    int *arr = new int[n+1];
    cout<<"Enter each Array Element: ";
    for(int i = 0 ; i < n ; i++ ){
        cin>>arr[i];
    }
    printArr(arr ,n);
    
    sumArr(arr,n);
    cout << "Enter Element: "<< endl ;
    cin >> element ;
    cout << "Enter position: "<< endl ;
    cin >> position ;
    insEleK(arr ,n , position ,element) ;
    printArr(arr ,n);
    cout << "Enter position: "<< endl ;
    cin >> position ;
    delEleK(arr , n ,position) ;
    printArr(arr ,n);
    cout << "Enter Key to be found : " ;
    cin >> key ;
    searchEle(arr ,key ,n );
    rotateArr(arr ,n ) ;
    cout << "Rotated array: " << endl ;
    printArr(arr ,n ) ;
    delete[] arr ;
    return 0;
}
