class Solution {
public:
    string simplifyPath(string path) {
        string token;
        stringstream ss(path);
        stack<string> st;
        while(getline(ss,token,'/')){
            if(token=="" || token==".") continue;
            else if(token==".."){
                if(!st.empty()) st.pop();
            }
            else st.push(token);
        }
        if(st.empty()) return "/";
        string ans = "";
        while(!st.empty()){
            ans = "/"+st.top()+ans;
            st.pop();
        }
        return ans;
    }
};