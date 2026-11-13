 #include<iostream>
using namespace std ;
//time complexity  worst case: O(n)
void merge(int arr[], int st, int mid, int end, int n);
void mergeSort(int arr[],int st,int end,int n)
{
    if(st < end){ //if false our code hit the base case condition
        int mid = st +(end - st)/2 ;
        //sort left
        mergeSort(arr,st,mid,n) ;
        //sort right
        mergeSort(arr,mid+1,end,n) ;
        merge(arr,st,mid,end,n) ;
    }
}
void merge(int arr[],int st ,int mid ,int end,int n){
    int temp[n];
    int i = st , j = mid+1 ,k = 0;
    while(i <= mid && j <= end){//store elements in temp after comparison
        if(arr[i]<=arr[j]){//when element in left is smaller than element in right push temp element right
            temp[k] = arr[i] ;
            i++ ;
            k++ ;
        }else{
            temp[k] = arr[j] ;//when element in right is less than left push temp with element right
            j++ ;
            k++ ;
        }
    }
    while(i<= mid){     //this is for pushing remaining elements from left array
        temp[k] = arr[i] ;
        i++ ;
        k++ ;
    }
    while(j <= end){        //this is for pushing remaining elements from he right array
        temp[k] = arr[j] ;
        j++ ;
        k++ ;
    }

    //to reflect original changes from temporary to original array
    for(int idx = 0 ; idx < k ; idx++){
        arr[idx+st] = temp[idx] ;// temp starts from index 0, but the original array portion
// starts from st, so we add st to get the correct index.
    }
}
void print(int arr[] , int size ){
    for(int i = 0 ; i < size ; i++ ){
        cout << arr[i] << " " ;
    }
    cout << endl ;
}
int main(){
    int n ,st ,end;
    cout << "Enter size of array : " ;
    cin >> n ;
    int arr[n] ;
    cout << "Enter each element of array : "<<endl ;
    for(int i =0 ; i < n ; i++ ){
        cin>>arr[i] ;
    }
    print(arr,n) ;
    cout << "Sorted Array is :" ;
    st = 0 , end = n-1 ;
    mergeSort(arr,st,end,n) ;
    print(arr,n) ;
}
