#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    //budowanie i sortowanie vectora
    ios_base::sync_with_stdio;
    long long a, M, jt, n,sec, il=2, iln, sum=0, gdzie=2, koniec, k;
    vector<long long> V;
    cin>>n;
    cin>>jt;
    for(int i=1; i<n; i++)
    {
        cin>>a;
        V.push_back(jt-a);
    }
    koniec=V.size();
    sort(V.begin(), V.end());
    M=V[0];

    //zwiesza il do przynajmniej 2
    sum+=V[1]-V[0];
    while(gdzie!=koniec && V[gdzie]==V[1])
    {
        il++;
        gdzie++;
    }
    k=log2(il);
    while(k<=M && gdzie!=koniec)
    {
        a=V[gdzie]-M-sum; //dlaczego to coœ zienia
        if(M-(a*k)>=0)
        {
            sum+=a*(k+1);
            M-=a*k;
        }
        else
            break;
        while(gdzie!=koniec && V[gdzie]<=M+sum)
        {
            il++;
            gdzie++;
        }
        k=log2(il);
    }
    if(M>=k)
    {
        a=M/k;
        M-=a*k;
        sum+=a*(k+1);
    }
    if(M==0)
    {
        cout<<sum;
        return 0;
    }
    if(k<=M)
    {
        sum+=(2*(M+1))-k-1;
        M=0;
    }
    sum+=M;
    cout<<sum;
    return 0;
}
