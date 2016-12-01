/**
    hackerrank 寻找两个数之间同孪素数的个数，同孪素数是一对素数相差值为2;
**/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool prime(int t ,int * c){
    int b=ceil(sqrt(t));
    for(int i=2;i<=b;i++){
        if(!(t%i)){
            return 0;
        }
    }
    *c=t;
    return 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m,n,k;
    cin>>n>>m;

    int up,cur,sum;
    up=0;
    sum=0;
    cur=0;

    for(int i=n;i<=m;i++){
        if(i%2){
            if(prime(i,&cur)){
                if((cur-up)==2){
                    sum++;
                }
                up=cur;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
