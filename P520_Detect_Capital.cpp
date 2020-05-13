class Solution {
public:
    bool detectCapitalUse(string word) {
        int caps = 0;
        for(int i = 0; i < word.size(); i++){
            if(isupper(word[i])) caps++;
        }
        if(caps == 0) return true;
        if(caps == word.size()) return true;
        if(caps == 1 && isupper(word[0])){
            return true;
        }
        return false;
    }
};
