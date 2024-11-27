#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <numeric> // 累加函数 accumulate

using namespace std;

/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

// 方式1. 排序
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 核心思路
        unordered_map<string, vector<string>> mp;
        for (const string& str : strs){
            string key = str;
            sort(key.begin(),key.end());
            mp[key].emplace_back(str);
        }
        // ⬇️负责打印
        vector<vector<string>> result;
        for(auto it = mp.begin(); it!=mp.end(); ++it){
            result.emplace_back(it->second);
        }
        return result;
    }
};

// 方式2. 计数
// 由于互为字母异位词的两个字符串包含的字母相同，因此两个字符串中的相同字母出现的次数一定是相同的，故可以将每个字母出现的次数使用字符串表示，作为哈希表的键。
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str: strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a'] ++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

// 方式3. LeetCode 3ms最快解
class Solution {
public:
    long long getnum(string str){
        long long ascii = 1;
        for(auto ch : str){
            ascii += ch*ch*ch*ch;
        }
        return ascii;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long long ,int> hash; // 哈希表，用于存储ASCII值和对应的组索引
        vector<vector<string>> ans; // 最终的答案
        for(auto item : strs){ // 遍历输入的字符串数组
            long long key = getnum(item); // 计算当前字符串的ASCII值总和
            auto it = hash.find(key); // 在哈希表中查找这个ASCII值总和
            if(it != hash.end()){ // 如果找到了
                ans[it->second].push_back(item); // 将当前字符串添加到对应的组中
            }else{ // 如果没有找到
                int index = ans.size(); // 创建新的组，并获取它的索引
                hash[key] = index;
                ans.push_back({item});
            }
        }
        return ans;
    }
};

// 方式4. 将索引值变为字符串形式
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> mp;
        for(auto s : strs){
            string sts = string(26, '0');
            for(auto c : s) ++ sts[c-'a'];
            mp[sts].emplace_back(s);
        }
        for(auto e : mp) ans.emplace_back(e.second);
        return ans;
    }
};

// 5. 自己写的
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<int, vector<string>> mp;

        for(string& str : strs){
            long long sum = 1;
            for(char ch : str){
                sum = (long long)(ch*ch*ch*ch);
            }
            mp[sum].emplace_back(str);
        }
        for(auto it : mp){
            ans.emplace_back(it.second);
        }
        return ans;
    }
};