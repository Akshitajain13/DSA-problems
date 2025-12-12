#include <bits/stdc++.h>
using namespace std;

int main(){
    string s="()[]{}";
    stack<char> st;
    unordered_map<char,char> mp={{')','('},{']','['},{'}','{'}};
    for(char c:s){
        if(mp.count(c)){
            if(st.empty() || st.top()!=mp[c]){
                cout<<"false"; return 0;
            }
            st.pop();
        } else st.push(c);
    }
    cout<<(st.empty()?"true":"false");
}