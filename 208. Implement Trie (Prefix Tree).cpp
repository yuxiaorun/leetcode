//
// Created by yxr on 2018/8/13.
//
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode *childs[26];
    bool isleaf;
    char c;
    TrieNode(char c) : isleaf(false),c('a'){
        for (auto &a : childs) a = NULL;
        this->c=c;
    }
};
class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode('a');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p=root;
        for(int i=0;i<word.size();i++){
            if(p->childs[word[i]-'a'] == NULL){
                TrieNode* child=new TrieNode(word[i]);
                p->childs[word[i]-'a']=child;
                p=child;
            }
            else{
                p=p->childs[word[i]-'a'];
            }
        }
        p->isleaf=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p=root;
        for(int i=0;i<word.size();i++){
            p=p->childs[word[i]-'a'];
            if(p==NULL)return false;
        }
        return p->isleaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p=root;
        for(int i=0;i<prefix.size();i++){
            p=p->childs[prefix[i]-'a'];
            if(p==NULL)return false;
        }
        return true;
    }
};
