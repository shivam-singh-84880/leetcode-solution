class Node{
public:
    Node* next[26];
    bool flag;

    Node(){
        for(int i=0; i<26; i++){
            next[i] = NULL;
        }
        flag = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(auto ch : word){
            int idx = ch - 'a';
            if(!temp->next[idx]){
                Node* tnode = new Node;
                temp->next[idx] = tnode;
                temp = temp->next[idx];
            }
            else{
                temp = temp->next[idx];
            }
        }
        temp->flag = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(auto ch : word){
            int idx = ch - 'a';
            if(!temp->next[idx]){
                return false;
            }
            else{
                temp = temp->next[idx];
            }
        }
        if(temp->flag){
            return true;
        }
        else return false;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(auto ch : prefix){
            int idx = ch - 'a';
            if(!temp->next[idx]){
                return false;
            }
            else{
                temp = temp->next[idx];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */