#include<iostream>
using namespace std;

void print(int **mat ,int r ,int c){
    cout << "the elements of matrix are : "<<endl ;
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ;j++){
            cout << mat[i][j] << " " ;
        }
        cout << endl ;
    }
}
void insert(int **mat ,int rows ,int cols ,int key){
    int r ,c ;
    cout << "Enter both row and column index: ";
    cin >> r >> c ;
    cout << endl ;
    if (r < 0 || r >= rows || c < 0 || c >= cols){
        cout << "Invalid index" ;
        return ;
    }
    mat[r][c] = key ;
    cout << "Element inserted successfully!" << endl;

}
void search(int **mat ,int rows,int cols){
    int key ;
    cout << "enter element to be found : ";
    cin >> key ;
    for(int i = 0 ; i < rows ; i++ ){
        for(int j = 0 ; j < cols ; j++ ){
            if(mat[i][j] == key){
                cout << "Element found at row :"<< i << " col : "<< j <<endl ;
                return ;
            }
        }
    }
    cout << "element not found ";
    return ;
}
void del(int **mat , int rows ,int cols){
    int r ,c ;
    cout << "Enter row and column for index that has to be deleted" ;
    cin >> r >> c ;
    if(r < 0 || r >= rows || c < 0 || c >= cols){
        cout<<"Invalid index"<<endl ;
        return ;
    }
    mat[r][c] = 0 ;
}
void rotate(int **mat,int r,int c){//90 degree clockwise
    if (r != c){
        cout<<"matrix should be n*n" ;
        return ;
    }
//step1:transpose of a matrix
    for(int i = 0 ; i < r ; i++ ){
        for(int j = i+1 ; j <c ; j++){
            int temp = mat[i][j];
            mat[i][j] = mat[j][i] ;
            mat[j][i] = temp ;

        }
    }
//step2:reverse a matrix
for(int i = 0 ; i < r ; i++){
    int startcol = 0 ;
    int endcol =  r- 1 ;
    while(startcol < endcol){
        int temp = mat[i][startcol] ;
        mat[i][startcol] = mat[i][endcol] ;
        mat[i][endcol] = temp ;
        startcol++ ;
        endcol-- ;
    }
}
}
int main(){
int rows, cols ,key ;
cout << "Enter number of rows: " ;
cin >> rows ;
cout << "Enter number of columns: " ;
cin >> cols ;
int **mat = new int*[rows] ;
for(int i = 0 ;i < rows ;i++){
    mat[i] = new int[cols] ;
}
cout<<"Enter elements for each cell : " ;
for(int i =0 ; i < rows ; i++){
    for(int j = 0 ; j < cols ; j++){
        cin >> mat[i][j] ;
    }
}
print(mat,rows,cols) ;
cout << "Enter key to be inserted: ";
cin >> key ;
insert(mat,rows,cols,key);
print(mat,rows,cols);
del(mat,rows,cols) ;
print(mat,rows,cols) ;
search(mat ,rows ,cols ) ;
rotate(mat,rows,cols) ;
print(mat ,rows,cols) ;
for(int i = 0; i < rows; i++) {
        delete[] mat[i];
    }

    delete[] mat;

return 0 ;
}
