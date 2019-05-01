//
//  main.cpp
//  rest_of_chp2
//
//  Created by xiuxiuGUI on 2019/5/1.
//  Copyright © 2019 xiuxiuGUI. All rights reserved.
//

#include <iostream>
using namespace std;
void merge_sentinels(int *a,int p, int q,int r){
    int n1 = q - p;
    int n2 = r - q;
    int L[100];
    int R[100];
    for(int i = 0; i < n1; i++){
        L[i] = a[p + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = a[q + i];
    }
    int i = 0;
    int j = 0;
    int k = p;
    L[n1] = 111111;
    R[n2] = 111111;
    for(; k < r;){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i ++;
        }else{
            a[k] = R[j];
            j ++;
        }
        k ++;
    }
}
void merge(int *a,int p, int q,int r){
    int n1 = q - p;
    int n2 = r - q;
    int L[100];
    int R[100];
    for(int i = 0; i < n1; i++){
        L[i] = a[p + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = a[q + i];
    }
    int i = 0;
    int j = 0;
    int k = p;
    for(; i < n1 && j < n2;){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i ++;
        }else{
            a[k] = R[j];
            j ++;
        }
        k ++;
    }
    if(i == n1 && j != n2){
        for(;j < n2;k++,j++){
            a[k] = R[j];
        }
    }
    if(i != n1 && j == n2 ){
        for(; i < n1; k++,i++){
            a[k] = L[i];
        }
    }
}
void MERGE_SORT(int *a,int p, int r){
    if(r - p <= 1){
        return;
    }
    if(p < r){
        int q = (p+r)/2;
        //cout << q << endl;
        MERGE_SORT(a, p, q);
        MERGE_SORT(a, q, r);
        //merge(a, p, q, r);
        merge_sentinels(a, p, q, r);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    int *a = new int[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cout << a[i] << " " ;
    cout << endl;
    MERGE_SORT(a, 0, n);
    
    for(int i = 0; i < n; i++)
        cout << a[i] << " " ;
    cout << endl;
    delete []a;
    return 0;
}
