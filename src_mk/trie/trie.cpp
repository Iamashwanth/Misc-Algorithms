#include <iostream>
#include <map>

using namespace std;

struct trie_node {
	map <char, struct trie_node*> children;
	bool end_of_word;

	trie_node() {
		end_of_word = 0;
	}
};

class trie {
	trie_node *root;

	public:

	trie() {
		root = new trie_node();
	}

	void insert(const string &word) {
		string::const_iterator it = word.begin();
		trie_node *cur_node = root;
		trie_node *new_node = NULL;

		if (word.length() == 0)
			return;

		while (it != word.end()) {
			if (!cur_node->children[*it])
				cur_node->children[*it] = new trie_node();

			cur_node = cur_node->children[*it];
			it++;
		}

		cur_node->end_of_word = true;
	}

	bool search(const string &word) {
		string::const_iterator it = word.begin();
		trie_node *cur_node = root;

		if (word.length() == 0)
			return false;

		while (it != word.end()) {
			cur_node = cur_node->children[*it];

			if (!cur_node)
				return false;

			it++;
		}

		return cur_node->end_of_word;
	}

	void delete_word (const string &word) {
		if (word.length() == 0)
			return;
		delete_word(root, word.begin(), word.end());
	}

	private:

	bool delete_word(trie_node* node, string::const_iterator it, string::const_iterator end) {
		int del;

		if (it == end) {
			if (!node->end_of_word)
				return false;
			else if (node->children.size() == 0) {
				delete node;
				return true;
			} else
				return false;
		}

		trie_node *leaf = node->children[*it];

		if (!leaf)
			return false;

		del = delete_word(leaf, it+1, end);

		if (del) {
			node->children.erase(*it);
			if (node->children.size() == 0 && !node->end_of_word) {
				delete node;
				return true;
			}
		}

		return false;
	}

};
