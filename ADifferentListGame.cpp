#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
    long long n;
    vector<int> V;
    int i=0, k=6, il=0;
    cin>>n;
    while(n%2==0){ //finding number of different prime divisors
        il++;
        n/=2;
    }
    if(il!=0){
        V.push_back(il);
        il=0;
    }
     while(n%3==0){
        il++;
        n/=3;
    }
    if(il!=0){
        V.push_back(il);
        il=0;
    }
    while(k<=n+1){
        while(n%(k-1)==0){
            il++;
            n/=k-1;
        }
        if(il!=0){
            V.push_back(il);
            il=0;
        }
        while(n%(k+1)==0){
            il++;
            n/=k+1;
        }
        if(il!=0){
            V.push_back(il);
            il=0;
        }
        k+=6;
    }
    for(int i=0; i<V.size(); i++){
        cout<<V[i]<<" ";
    }

    return 0;
}
