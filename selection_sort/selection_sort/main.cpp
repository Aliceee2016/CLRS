//
//  main.cpp
//  selection_sort
//
//  Created by xiuxiuGUI on 2019/5/1.
//  Copyright © 2019 xiuxiuGUI. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    int a[1000];
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0; i < n-1; i++){
        int index  = i;
        for(int j = i+1; j < n;j++){
            if(a[j] < a[index]){
                index = j;
            }
        }
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    //std::cout << "Hello, World!\n";
    return 0;
}
