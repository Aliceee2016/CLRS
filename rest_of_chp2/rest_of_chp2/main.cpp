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

int binary_search(int *a, int p, int r, int val) {
    int res;
    if (p > r) {
        return -1;
    }
    int q = (p + r) / 2;
    if (a[q] == val) {
        return q ;
    }
    else if (a[q] > val) {
        return binary_search(a, p, q, val);
    }
    else {
        return binary_search(a, q + 1, r, val);
    }
    

}
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    res[0] = -1;
    res[1] = -1;
    int i = 0;
    int j = nums.size() -1;
    while (i < j) {
        if (nums[i] + nums[j] == target) {
            res[0] = i;
            res[1] = j;
            break;
        }
        else if (nums[i] + nums[j] < target) {
            i++;
        }
        else {
            j = j - 1;
        }
    }
    
    return res;
}

vector<int> twoSum_nonOrder(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    res[0] = -1;
    res[1] = -1;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size();j++) {
            if (nums[i] + nums[j] == target) {
                res[0] = i;
                res[1] = j;
                break;
            }
        }
    }

    return res;
}
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    ListNode *res = new ListNode(0);
    ListNode *res1 = res;
    while (p1 != NULL && p2 != NULL) {

        int temp = (p1->val + p2->val + carry) % 10;
        carry = (p1->val + p2->val + carry) / 10;
        ListNode *lis = new ListNode(temp);
        res->next = lis;
        res = res->next;


        p1 = p1->next;
        p2 = p2->next;
    }

    if (p1 != NULL && p2 == NULL) {
        while (p1 != NULL) {
            int temp = (p1->val + carry) % 10;
            carry = (p1->val + carry) / 10;
            ListNode *lis = new ListNode(temp);
            res->next = lis;
            res = res->next;
            p1 = p1->next;
        }

    }
    if (p1 == NULL && p2 != NULL) {
        while (p2 != NULL) {
            int temp = (p2->val + carry) % 10;
            carry = (p2->val + carry) / 10;
            ListNode *lis = new ListNode(temp);
            res->next = lis;
            res = res->next;
            p2 = p2->next;
        }
    }
    if (carry != 0) {
        ListNode *lis = new ListNode(carry);
        res->next = lis;
    }



    res1 = res1->next;
    return res1;
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
