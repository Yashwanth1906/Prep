#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val, key;
    Node* next;
    Node* prev;
    Node(int val, int key) {
        this->val = val;
        this->key = key;
        next = prev = nullptr;
    }
};

class LRUCache {
public:
    void addNode(Node* newNode) {
        Node* nextNode = head->next;
        newNode->next = nextNode;
        newNode->prev = head;
        head->next = newNode;
        nextNode->prev = newNode;
    }
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete node;
    }
    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int, Node*> cache;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        head->prev = nullptr;
        tail->next = nullptr;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            deleteNode(node);
            addNode(node);
            cache[key] = head->next;
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value;
            deleteNode(node);
            addNode(node);
            cache[key] = head->next;
            return;
        } else {
            if(cache.size() == capacity) {
                Node* toDelete = tail->prev;
                cache.erase(toDelete->key);
                deleteNode(toDelete);
                delete toDelete;
            }
            Node* newNode = new Node(key, value);
            addNode(newNode);
            cache[key] = head->next;
            return;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class ListNode {
public:
  int val, key;
  ListNode* next;
  ListNode* prev;
  ListNode(int value, int key) {
    this->key = key;
    this->value = value;
    next = prev = nullptr;
  }
};



class LRUCache {
  int capacity;
  ListNode* head;
  ListNode* tail;
  unordered_map<int, ListNode*> cache;

  void addNode(ListNode* node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
  }

  void deleteNode(ListNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
  }

  LRUCache(int capacity) {
    head = new ListNode(-1);
    tail = new ListNode(-1);
    this->capacity = capacity;
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if(cache.find(key) != cache.end()) {
      int value = node->val;
      cache.erase(key);
      deleteNode(node);
      addNode(node);
      cache[key] = head->val;
      return value;
    }
    return -1;
  }
  void put(int key, int value) {
    if(cache.find(key) != cache.end()) {
      ListNode* node = cache[key];
      cache.erase(node->key);
      deleteNode(node);
      ListNode* newNode  = new ListNode(key, value);
      addNode(newNode);
      cache[key] = head->next;
      return;
    }
    if(cache.size() == capacity) {
      ListNode* toDelete = tail->prev;
      cache.erase(toDelete->key);
      deleteNode(toDelete);
      delete toDelete;
    }
    ListNode* newNode = new ListNode(key, value);
    addNode(newNode);
    cache[key] = head->next;
    return;
  }
};
