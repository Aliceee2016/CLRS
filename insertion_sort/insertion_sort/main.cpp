//
//  main.cpp
//  insertion_sort
//
//  Created by xiuxiuGUI on 2019/4/30.
//  Copyright © 2019 xiuxiuGUI. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    int n;
    int a[100];
    cin >> n;
    cout << n;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    //non-decreasing order
//    for(int j = 1; j< n;j++){
//        int key = a[j];
//        int i = j - 1;
//        while( i >=0 && a[i] > key){
//            a[i + 1] = a[i];
//            i --;
//        }
//        a[i + 1] = key;
//
//    }
    //nonincreasing order
    for(int j = 0;j < n;j++){
        int key = a[j];
        int i = j -1;
        while(i >=0 && a[i] < key){
            a[i + 1] = a[i];
            i --;
        }
        a[i + 1] = key;
    }
    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
