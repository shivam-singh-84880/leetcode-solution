class node{
public:
    int _key;
    int val;
    node* prev;
    node* next;
    node(int key, int ele){
        _key = key;
        val = ele;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
node* head;
node* tail;
unordered_map<int,node*> mp;
int sz;

    void insertAtfront(node * newnode) {
        node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deletekey(node * delnode) {
        node * delprev = delnode -> prev;
        node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }

public:
    LRUCache(int capacity) {
        sz = capacity;
        head = new node(-1,-1);
        tail = new node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(mp.find(key) != mp.end()){
            node* temp = mp[key];
            deletekey(temp);
            insertAtfront(temp);
            return temp->val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node* temp = mp[key];
            deletekey(temp);
            insertAtfront(temp);
            temp->val = value;
        }
        else{
            if(mp.size() == sz){
                node* temp = tail->prev;
                mp.erase(temp->_key);
                deletekey(temp);
                insertAtfront(temp);
                temp->_key = key;
                temp->val = value;
                mp[key] = temp;
            }
            else{
                node* temp = new node(key,value);
                insertAtfront(temp);
                mp[key] = temp;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */