#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

int calculateClassRank(string s)
{
    int num=0, i=0, sum=0, p=1;
    while(i<s.size())
    {
        num++;
        if(s[i]=='m')
            sum+=p;
        else if(s[i]=='l')
            sum+=2*p;
        i+=4; //all the words are at least 5 letters long
        while(i<s.size() && s[i]!='-') //in case I didn't reach the '-' yet
            i++;
        i++; //to get to the beggining of the next word
        p*=3;
    }
    for(i=num; i<=10; i++){
        sum*=3;
        sum+=1;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int k, n;
    string name, description;
    cin>>k;
    for(int l=0; l<k; l++)
    {
        vector<pair<int, string> > V;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>name>>description;
            pair<int, string> newPair = make_pair(calculateClassRank(description), name);
            V.push_back(newPair);
            cin>>name; //in fact that's the "class" world but we need to take it before starting the next loop
        }
        sort(V.begin(), V.end());
        for(int i=0; i<n; i++)
        {
            name=V[i].second.substr(0, V[i].second.size()-1);
            cout<<name<<endl;
        }
        for(int i=0; i<30; i++)
            cout<<"=";
        cout<<endl;
    }
}
