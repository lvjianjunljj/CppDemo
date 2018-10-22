#include "stdafx.h"
/*
Given a list of words, we may encode it by writing a reference string S and a list of indexes A.

For example, if the list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes = [0, 2, 5].

Then for each index, we will recover the word by reading from the reference string from that index until we reach a "#" character.

What is the length of the shortest reference string S possible that encodes the given words?

Example:

Input: words = ["time", "me", "bell"]
Output: 10
Explanation: S = "time#bell#" and indexes = [0, 2, 5].


Note:

1 <= words.length <= 2000.
1 <= words[i].length <= 7.
Each word has only lowercase letters.
*/
class Solution {
public:
	// My solution based on TrieNode is MLE, so sad.......
	int minimumLengthEncoding1(vector<string>& words) {
		// Note: Here we should use pointer, this line: 
		// TrieNode2 cur = root
		// is value passing not reference pass, modification to cur does not change root
		TrieNode2* root = new TrieNode2();
		int res = 0;
		for (string word : words) {
			TrieNode2* cur = root;
			bool not_new_word = false, not_exist = false;
			int cur_depth = 0;
			for (int i = word.length() - 1; i >= 0; i--) {
				if (cur->children.size() == 0) {
					not_exist = true;
					if (cur->end)
						not_new_word = true;
					for (int j = 0; j < 26; j++)
						cur->children.push_back(new TrieNode2());
					cur_depth++;
				}
				cur = cur->children[(int)(word[i] - 'a')];
			}
			if (cur->children.size() == 0) {
				not_exist = true;
				if (cur->end)
					not_new_word = true;
			}
			if (not_exist) {
				if (not_new_word) {
					res += cur_depth;
				}
				else {
					res += word.length() + 1;
				}
			}
			cur->end = true;
		}
		return res;
	}
	// My boring solution, TLE.....  shit......
	int minimumLengthEncoding2(vector<string>& words) {
		vector<string> dict;
		for (string word : words) {
			bool add = true;
			for (int i = 0; i < dict.size(); i++) {
				if (endswith(dict[i], word)) {
					add = false;
					break;
				}
				else if (endswith(word, dict[i])) {
					dict[i] = word;
					add = false;
					break;
				}
			}
			if (add) dict.push_back(word);
		}
		int res = 0;
		for (string word : dict) res += word.length() + 1;
		return res;
	}
	// The most boring solution, but it is approved.....
		int minimumLengthEncoding3(vector<string>& words) {
		unordered_set<string> s(words.begin(), words.end());
		for (string word : words)
			for (int i = 1; i < word.size(); i++)
				s.erase(word.substr(i));
		int res = 0;
		for (string word : s)
			res += word.length() + 1;
		return res;
	}

	// The standard solution bsead on TrieNode. 
	// Maybe we should use unordered_map not vector as children when we use TrieNode
	// to save space to avoid MLE.
	// But this solution cost more time than the most boring solution.
	int minimumLengthEncoding4(vector<string>& words) {
		TrieNode *root = new TrieNode;
		vector<pair<TrieNode *, int>> leaves;
		for (auto & w : unordered_set<string>(words.begin(), words.end())) {
			TrieNode *cur = root;
			for (int i = w.length() - 1; i >= 0; i--) {
				if (cur->next.count(w[i]) == 0) cur->next[w[i]] = new TrieNode;
				cur = cur->next[w[i]];
			}
			leaves.push_back(make_pair(cur, w.length() + 1));
		}
		int res = 0;
		for (auto leaf : leaves) if ((leaf.first->next).size() == 0) res += leaf.second;
		return res;
	}
private:
	// The difference of time cost between using struct and class is almost zero. 
	struct TrieNode2
	{
		vector<TrieNode2*> children;
		bool end = false;
	};
	bool endswith(string word, string end) {
		if (word.length() < end.length()) return false;
		for (int i = 0; i < end.length(); i++)
			if (end[end.length() - 1 - i] != word[word.length() - 1 - i])
				return false;
		return true;
	}
	class TrieNode {
	public:
		unordered_map<char, TrieNode *> next;
	};

};