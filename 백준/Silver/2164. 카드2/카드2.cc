#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    int N; //카드의 개수
    cin >> N;

    queue<int> myqueue;

    for(int i=1; i < N+1; i++)
    {
        myqueue.push(i);
    }

    while(myqueue.size()>1)//카드가 한장 남을 때 까지 size함수로 큐에 남아있는 개수 파악
    {
        myqueue.pop();//가장 위에 카드 버림
        myqueue.push(myqueue.front());
        myqueue.pop();//두번째 위에 카드를 가장 아래에다 넣음
    }

    cout<<myqueue.front()<<endl;
    return 0;
}