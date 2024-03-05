#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n);
void DFS(int num, int jarisu);
static int N;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);
}

void DFS(int num, int jarisu)
{
    if(isPrime(num) && jarisu==N)
    {
        cout<<num<<endl;
    }
    for(int i=0; i<10; i++)
    {
        if(i%2 ==0){
            continue;
        }
        if(isPrime(num*10+i))
             DFS(num*10+i, jarisu+1);
    }
}

bool isPrime(int num){
    for(int i=2; i<=num/2; i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}