class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<int, vector<string>> c;
        for(int i = 0; i < list1.size(); i++){
            if(find(list2.begin(), list2.end(), list1[i]) != list2.end()){
                c[find(list2.begin(), list2.end(), list1[i])-list2.begin() + i].push_back(list1[i]);
            }
        }
        map<int, vector<string>>::iterator it = c.begin();
        return it->second;
    }
};
