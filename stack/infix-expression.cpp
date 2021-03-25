#include <bits/stdc++.h>
#define ll long long
#define mset(a) memset(a, 0, sizeof(a))
using namespace std;
stack<int> s1;
stack<char> s2;
int level(char c){
    if(c == '+' || c=='-')return 1;
    if(c=='*'|| c =='/')return 2;
    if(c=='^')return 3;
    return 0;
}
void calc(){
    int a = s1.top();s1.pop();
    int b = s1.top();s1.pop();
    char c = s2.top();s2.pop();
    if(c=='*')s1.push(a*b);
    else if(c=='-')s1.push(b-a);
    else if(c=='+')s1.push(a+b);
    else if(c=='/')s1.push(b/a);
    else if(c=='^') s1.push(pow(b,a));
}
int main(){

    string str;
    cin >> str;
    bool flag = true;
    int s = 0;
    for(int i = 0; i < str.size() - 1;i++){
       if(str[i]=='(')s++;
       if(str[i]==')')s--;
       if(i>0 &&level(str[i-1])&&level(str[i])){
           flag = false;
           break;
       };
    }
    if(s)flag = false;
    if(flag){
        for(int i = 0; i < str.size() - 1; i++){
            if(str[i]=='('){
                s2.push(str[i]);
            }else if(isdigit(str[i])){
                int n = 0, p = i;
                while(p<str.size()&&isdigit(str[p])){
                    n = n * 10 + str[p++]-'0';
                }
                s1.push(n);
                i = p - 1;
            }else if(str[i] == ')'){
               while(s2.top()!='(') calc();
               s2.pop();
            }else{
                while(s2.size()&&s2.top()!='('&&level(str[i])<=level(s2.top())){
                    calc();
                }
                if(str[i] == '-' &&(!i || str[i-1]=='(')){
                    int p = i + 1, n = 0;
                    while(p<str.size()&&isdigit(str[p])){
                        n = n * 10 + str[p++] - '0';
                    }
                    s1.push(-n);
                    i = p -1;
                }else s2.push(str[i]);
            }
        }
        while(s2.size())calc();
        cout<<s1.top()<<endl;
    }else cout<<"NO"<<endl;
    return 0;
}

