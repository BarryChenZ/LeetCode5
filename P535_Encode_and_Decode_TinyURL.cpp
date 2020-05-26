class Solution {
public:
     string base = "http://tinyurl.com/";
    unordered_map<string, string> shorttolong;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
    
        string s = to_string(hash<string>{}(longUrl));
        shorttolong[base + s] = longUrl;
        return base + s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shorttolong[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
