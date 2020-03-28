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

    //just a "helper" output - will be removed when code is complete
    for(int i=0; i<V.size(); i++){
        cout<<V[i]<<" ";
    }
    cout<<endl;


    //I have no idea if that's gonna work but the idea is:
    //->make all 1 element distinct subsets
    //then follow to 2, 3, 4 until there's just one value which will be divided as long as possible

    int il=V.size(); //number of 1-element subsets
    int end=V.size()-1;

    return 0;
}
