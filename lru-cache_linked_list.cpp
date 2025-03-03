//https://leetcode.com/problems/lru-cache/submissions/
//important 
//medium please check again



class LRUCache {
public:

    class Node{
        public:
            Node* prev;
            Node* next;
            int key;
            int val;
            Node(int k,int v){
                key=k;
                val=v;
            }   
    };
    int cap;
    Node* left=new Node(-1,-1);
    Node* right=new Node(-1,-1);
    unordered_map<int,Node*>cache;
    void insert(Node* n){
        Node* nextT=left->next;
        left->next=n;
        n->next=nextT;
        n->prev=left;
        nextT->prev=n;
    }
    void remove(Node* n){
        Node* pret=n->prev;
        Node* nextt=n->next;
        pret->next=nextt;
        nextt->prev=pret;
    }
    LRUCache(int capacity) {
        cap=capacity;
        left->next=right;
        right->prev=left;
    }
    
    int get(int key) {
     if(cache.find(key)!=cache.end()){
        Node* temp=cache[key];
        remove(temp);
        insert(temp);
        return (temp->val);
     }   
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            Node* temp=cache[key];
            cache.erase(key);
            remove(temp);
        }
        if(cache.size()==cap){
            cache.erase(right->prev->key);
            remove(right->prev);
        }
        insert(new Node(key,value));
        cache[key]=left->next;
    }
};
