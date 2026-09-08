class Solution {
public:
    int calPoints(vector<string>& s) {
        int n = s.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=="C") st.pop();
            else if(s[i]=="D") st.push(2*st.top());
            else if(s[i]=="+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a+b);
            }
            else {
                st.push(stoi(s[i]));
            }
        }
        int sum = 0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};