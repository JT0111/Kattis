#include<iostream>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int s, n; //s -> number of patterns, n->number of steps
    int x, y, il=1; //current position, number of optimal steps
    vector<pair<int, int> > V[150][150];
    int A[150][150];
    char a; //current step
    cin>>s;
    for(int k=0; k<s; k++)
    {
        for(int i=0; i<149; i++)
        {
            for(int p=0; p<149; p++){
                V[i][p].clear();
                A[i][p]=0;
            }
        }
        cin>>n;
        x=65;
        y=65; //65 is safe as we make up to 60 steps
        for(int j=0; j<n; j++) //creating the graph
        {
            cin>>a;
            if(a=='S'){
                V[x][y].push_back(make_pair(x-1, y));
                V[x-1][y].push_back(make_pair(x, y));
                x--;
            }
            else if(a=='N'){
                V[x][y].push_back(make_pair(x+1, y));
                V[x+1][y].push_back(make_pair(x, y));
                x++;
            }
            else if(a=='W'){
                V[x][y].push_back(make_pair(x, y-1));
                V[x][y-1].push_back(make_pair(x, y));
                y--;
            }
            else if(a=='E'){
                V[x][y].push_back(make_pair(x, y+1));
                V[x][y+1].push_back(make_pair(x, y));
                y++;
            }
        }
        int x1 = 65, y1=65;
        A[65][65]=1;
        queue <pair<int, int> > Q;
        Q.push(make_pair(65, 65));
        while(x1!=x || y1!=y)
        {
            x1=Q.front().first;
            y1=Q.front().second;
            for(int i=0; i<V[x1][y1].size(); i++){
                if(A[V[x1][y1][i].first][V[x1][y1][i].second]==0){
                    Q.push(V[x1][y1][i]);
                    A[V[x1][y1][i].first][V[x1][y1][i].second]=A[x1][y1]+1;
                }
            }
            Q.pop();
        }
        cout<<A[x][y]-1<<endl;
        while(!Q.empty())
            Q.pop();
    }
    return 0;
}
