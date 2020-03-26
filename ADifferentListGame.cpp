#include<iostream>
#include<cmath>

using namespace std;

int solution(int min, long long value)
{
    int sum=1;
    long long s = sqrt(value);
    if(value%s==0)
        s--;
    if(min>value)
        sum=0;
    for(int i=min; i<=s; i++)
    {
        if(value%i==0)
        {
            sum+=solution(i+1, value/i);
            break;
        }
    }
    return sum;
}
int main()
{
    long long n;
    cin>>n;
    cout<<solution(2, n);
    return 0;
}
