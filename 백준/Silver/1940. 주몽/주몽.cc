#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin>>N>>M;

    vector<int> arr(N, 0);
    for(int i=0; i<N; i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end()); //오름 차순 정렬

    int count=0;
    int i=0;
    int j=N-1;
    while(i<j)
    {
        if(arr[i]+arr[j]<M){
            i++;
        }
        else if(arr[i]+arr[j]==M){
            count++;
            j--;
        }
        else{
            j--;
        }
    }
    cout<<count<<endl;
}