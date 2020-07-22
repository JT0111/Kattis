#include <iostream>
#include<string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    int n, m; //n -> number of switches, m -> number of photos
    cin>> n >> m;
    bool T[n][n]; //T[i][j] = true <-> switch i can be connected to light j
    bool Used[n];
    for(int i=0; i<n; i++){ //setting the table
        for(int j=0; j<n; j++)
            T[i][j] = true;
        Used[i] = false;
    }
    string p1, p2; //p1 - photo of switches, p2 - photo of lights

    for(int k=0; k<m; k++){ //updating possible connections
        cin>>p1>>p2;
        for(int i=0; i<n; i++){
            if(p1[i] == '1'){ //i'th switch is on
                for(int j=0; j<n; j++)
                    T[i][j] = T[i][j] && (p2[j]=='1');
            }
            else{ //i'th switch is off
                for(int j=0; j<n; j++)
                    T[i][j] = T[i][j] && (p2[j]=='0');
            }
        }
    }
    int k, sum=1;
    bool calculated;
    /*for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<T[i][j]<<" ";
        cout<<endl;
    }
     */
    for(int i=0; i<n; i++){
        k=0;
        calculated = false;
        for(int j=0; j<n; j++){
            if(T[i][j]){
                if(Used[j]){
                    calculated = true;
                    break;
                }
                k++;
                Used[j]=true;
            }
        }
        if(k==0 && !calculated){ //no options
            cout<<0;
            return 0;
        }
        for(int j=k; j>1; j--)
            sum = (sum*j)%1000003;
    }

    for(int j=0; j<n; j++){
        k=0;
        for(int i=0; i<n; i++){
            if(T[i][j])
                k++;
        }
        if(k==0){ //no options
            cout<<0;
            return 0;
        }
    }
    cout<<sum;
    return 0;
}
