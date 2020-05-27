class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int ans = INT_MAX;
        vector<pair<int,int>> v;
        for(int i = 0; i < timePoints.size(); i++){
            v.push_back(convert(timePoints[i]));
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            int j = (i + 1 == v.size())? 0 : i + 1;
            pair<int, int> p1 = (v[i].first > v[j].first) ? v[j] : v[i];//p2 > p1
            pair<int, int> p2 = (v[i].first > v[j].first) ? v[i] : v[j];
            int tmp;
            int diffH = min(p2.first - p1.first, 24 - p2.first + p1.first - 0);
            int type = (p2.first - p1.first > 24 - p2.first + p1.first - 0) ? 2 : 1;
            cout << diffH << " " << type << endl;;
            cout << p1.second << " " << p2.second << endl;
            if(diffH == 0) tmp = abs(p2.second - p1.second);
            else if(type == 1) tmp = abs(60 * (diffH - 1) + (60 - p1.second) + (p2.second - 0));
            else if(type == 2) tmp = abs(60 * (diffH - 1) + (p1.second - 0) + (60 - p2.second));
            if(tmp < ans) ans = tmp;
        }
        return ans;
        
    }
    pair<int,int> convert(string s){
        string a, b;
        int p = s.find(":");
        for(int i = 0; i < s.size(); i++){
            if(i < p) a += s[i];
            else if(i > p) b += s[i];
        }
        return make_pair(stoi(a), stoi(b));
    }
};
