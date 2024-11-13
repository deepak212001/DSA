/*
* * * * * * * 
*           *
*   * * *   *
*   *   *   *
*   * * *   *
*           * 
* * * * * * *




*/

#include <iostream>
using namespace std;

void printPattern(int size) {
    int n=(size/2)-1;
    int m=(size/2)+1;
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            if(i==0 || i==size-1 ||j==0 || j==size-1)
                cout<<"* ";
            else if(((i==n || i==m) && j>=n && j<=m) ||((j==n || j==m) && i>=n && i<=m)  )
                cout<<"* ";
            else 
                cout<<"  ";
        }
        cout << endl;
    }
}

int main() {
    int size ;  
    cin>>size;
    printPattern(size);
    return 0;
}
