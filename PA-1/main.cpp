#include "LinkedList.cpp"
#include "luckyDraw.cpp"
#include <iostream>
#include <cstdlib>
#include <memory>
using namespace std;

int main(){

    
    int arr[5]  = {1,2,3,4,5};
    luckyDraw l(5);
    l.populateTable(arr);
    //l.transferStack(); 

    for(int i=0;i<5;i++){
        cout << l.table_1.pop()<<endl;
    }
    // cout << "---"<<endl;
    // cout << l.table_1.pop();
    

}