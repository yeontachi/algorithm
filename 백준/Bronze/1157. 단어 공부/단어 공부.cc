#include <iostream>
#include <cstring>
using namespace std;

char a[10000005];
int arr[26];

int main(void){
    int max=0;
    int size;
    char ch;

    cin>>a;
    size=strlen(a);

    for(int i=0; i<size; i++){
        if(a[i]>='a') arr[a[i]-'a']++;
        else arr[a[i]-'A']++;
    }

    for(int i=0; i<26; i++){
        if(arr[i]==max){
            ch='?';
        }
        else if(arr[i]>max){
            max=arr[i];
            ch='A'+i;
        }
    }

    cout<<ch<<endl;
    return 0;
}