class Node{
public:
    bool data;
    Node* next[26];
    
    Node(){
        for(int i=0; i<26; i++){
            next[i] = NULL;
        }
        data = false;
    }
    
    void insert(string& word, Node*& root){
        Node* temp = root;
            for(auto& ch : word){
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
            temp->data = true;
    }
    
    
    int check(string& word, Node*& root){
        int len = 0;
            Node* temp = root;
            for(auto& ch : word){
                int idx = ch - 'a';
                if(temp->next[idx]){
                    temp = temp->next[idx];
                    if(temp->data){
                        len++;
                    }
                    else{
                        break;
                    }
                }
            }
            return len;
    }
    
};
class Solution {
    Node* root;
public:
    Solution(){
        root = new Node();
    }
    
    
    string longestValidWord(vector<string>& words) {
        for(auto& word : words){
            root->insert(word,root);
        }
        
        string str = "";
        int maxi = 0;
        for(auto& word : words){
            int len = root->check(word,root);
            
            if(len > maxi){
                maxi = len;
                str = word;
            }
            else if(len == maxi){
                if(word < str){
                    str = word;
                }
            }
        }
        return str;
    }
};








