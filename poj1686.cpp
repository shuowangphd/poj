#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
string i2rp(string s){
    stack<char> sc;
    char c[100];int j=0;
    for (int i=0;i<s.length();i++){
        if(s[i]<=' ')continue;
        if(s[i]>='0') c[j++]=s[i];
        else if(sc.empty()||s[i]=='(') sc.push(s[i]);
        else if(s[i]==')'){
            while(sc.top()!='(') {c[j++]=sc.top();sc.pop();}
            sc.pop();
        }
        else{
            while(!sc.empty()&& sc.top()!='(') {c[j++]=sc.top();sc.pop();}
            sc.push(s[i]);
        }
    }
    while(!sc.empty()){c[j++]=sc.top();sc.pop();}
    c[j]='\0';
    string ss=c;
    return ss;
}
int calc(string s){
    int tmp1;
    stack<int> si;
     for (int i=0;i<s.length();i++){
         if(s[i]>='0') si.push(s[i]-'0');
         else if(s[i]=='+'){
             tmp1=si.top();si.pop();tmp1+=si.top();si.pop();si.push(tmp1);}
         else if(s[i]=='-'){
            tmp1=si.top();si.pop();tmp1=si.top()-tmp1;si.pop();si.push(tmp1);}
         else if(s[i]=='*'){
             tmp1=si.top();si.pop();tmp1*=si.top();si.pop();si.push(tmp1);}
         else break;
     }
    return si.top();
}
int main(){
    int n,r1,r2;
    string s1,s2,rp1,rp2;
    cin>>n;
    getchar();
    while(n--){
        getline(cin,s1); 
        rp1=i2rp(s1);
        getline(cin,s2);
        rp2=i2rp(s2);
        r1=calc(rp1);r2=calc(rp2);
        if (r1==r2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
