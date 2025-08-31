class Node{
public:
    unordered_map<char, Node*> next;
    bool data = false;
    
    void insert(string& word, Node*& root){
        Node* temp = root;
            for(auto& ch : word){
                if(!temp->next[ch]){
                    Node* tnode = new Node;
                    temp->next[ch] = tnode;
                    temp = temp->next[ch];
                }
                else{
                    temp = temp->next[ch];
                }
            }
            temp->data = true;
    }
    
    
    int check(string& word, Node*& root){
        int len = 0;
            Node* temp = root;
            for(auto& ch : word){
                if(temp->next[ch]){
                    temp = temp->next[ch];
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








