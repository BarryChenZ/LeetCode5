class Solution {
public:
    string reverseStr(string s, int k) {
       int i=0;
        if(s.length()>k){
            for(i=0;i<s.length()-k;i+=2*k){
                reverse(s.begin()+i,s.begin()+i+k);
            }
        }
        reverse(s.begin()+i,s.end());
        return s;
    }
};
