class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        auto cmp = [](const auto& s1, const auto& s2){ return s1.size() > s2.size() || (s1.size() == s2.size() && s1 < s2);};
        sort(d.begin(), d.end(), cmp);
        auto it = find_if(d.begin(), d.end(), [&s](const auto& t){ return can_form(s, t);});
        return it == d.end() ? "" : *it;
    }
    
    static bool can_form(const string& s, const string& t){
        int l = 0;
        for(int i = 0; i < s.length() && l < t.size(); i++){
            if(s[i] == t[l]) l++;
        }
        return l == t.size();
    }
};
