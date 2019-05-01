//
//  main.cpp
//  add_two_binary_intergers
//
//  Created by xiuxiuGUI on 2019/5/1.
//  Copyright © 2019 xiuxiuGUI. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    int n;
    cin >> n;
    int a[1000];
    int b[1000];
    int c[1001];
    for(int i = 0; i< n ;i++){
        cin >> a[i];
    }
    for(int i = 0; i< n ;i++){
        cin >> b[i];
    }
    int carry = 0;
    // my answer
//    for(int i = n-1; i >= 0 ; i--){
//        if(a[i] + b[i] + carry == 2){
//            carry = 1;
//            c[i+1] = 0;
//        }
//        else if(a[i] + b[i] + carry == 3){
//            carry = 1;
//            c[i+1] = 1;
//        }
//        else{
//            c[i+1] = a[i] + b[i];
//            carry  = 0;
//        }
//    }
    for(int i = n-1; i >=0; i-- ){
        c[i + 1] = (a[i] + b[i] + carry)%2;
        if(a[i] + b[i] + carry >= 2){
            carry = 1;
        }
        else{
            carry = 0;
        }
    }
    c[0] = carry;
    for(int i = 0; i < n+1; i++){
        cout << c[i] << " ";
    }
    return 0;
}
