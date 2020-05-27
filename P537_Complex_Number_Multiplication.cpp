class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        //store
        vector<int> v1 = convert(a);
        vector<int> v2 = convert(b);
        int x = v1[0]*v2[0] - v1[1]*v2[1];
        int y = v1[1]*v2[0] + v1[0]*v2[1];
        return to_string(x) + "+" + to_string(y) + "i";
    }
    vector<int> convert(string s){
        string a, b;
        s.pop_back();
        int p = s.find("+");
        for(int i = 0; i < s.size(); i++){
            if(i < p) a += s[i];
            else if(i > p) b += s[i];
        }
        return {stoi(a), stoi(b)};
    }
};
