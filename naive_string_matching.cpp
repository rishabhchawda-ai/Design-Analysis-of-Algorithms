#include<iostream>

using namespace std;
int main(){
    string s,p;
    cout<<"enter string to find: ";
    cin >> s;
    cout<<"enter pattern to find: ";
    cin>> p;
    int flag =0;
    int plen = p.length();
    int slen = s.length();
    for (int i=0; i <= slen-plen; i++){
        int j=0;
        while(j<plen && s[i+j] == p[j]){
            j++;
        }
        if(j==plen){
            flag =1;
            cout<<"pattern found at : "<<i<<" to "<<i+plen-1<<endl;
        }
    }
    if(flag==0){
        cout<<"no match";
    }
    return 0;
}