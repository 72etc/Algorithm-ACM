/*
5. Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"
*/

#include"../include/include.h"

class Solution {
public:

    # bruceForce solution
    string longestPalindrome_bruceForce(string s) {
        auto n = s.length();
        int st = 0;
        int rtn = 1;
        for(auto i=0 ; i<n; i++){
            for(auto j=i+1 ; j<n; j++){
                auto k = (j-i+1 >> 1) - 1;
                for(; k>=0 ; k--){
                    if(s[j-k] != s[i+k])
                        break;
                }
                if(k < 0 && j - i + 1 > rtn){
                    rtn = j - i + 1;
                    st = i;
                }
            }
            if(rtn >= n - i + 1)
                return s.substr(st, rtn);
        }
        return s.substr(st, rtn);
    }
    
    # DP solution
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        
        bool flags[s.length()][s.length()] = {false};
        int max_len=1, max_st=0;
        int len = s.length();
        for(int i=0 ; i<len; i++){
            for(int j=0 ; j<len-i ; j++){
                if((i<2 || flags[j+1][i+j-1]) && s[j] == s[i+j]){
                    flags[j][i+j] = true;
                    if(i+1 > max_len){
                        max_len = i+1;
                        max_st = j;
                    }
                }
            }
        }
        return s.substr(max_st, max_len);
    }

};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}