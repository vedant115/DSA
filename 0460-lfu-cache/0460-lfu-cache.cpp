#include <unordered_map>
using namespace std;

struct Node {
    int key, value, freq;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), freq(1), prev(nullptr), next(nullptr) {}
};

struct DoublyLinkedList {
    Node *head, *tail;
    int size;

    DoublyLinkedList() : size(0) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    ~DoublyLinkedList() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    Node* removeLeastRecent() {
        if (size == 0) return nullptr;
        Node* lru = tail->prev;
        remove(lru);
        return lru;
    }
};

class LFUCache {
private:
    int capacity, size, minFreq;
    unordered_map<int, Node*> keyToNode;
    unordered_map<int, DoublyLinkedList*> freqToList;
    void updateFreq(Node* node) {
        int freq = node->freq;
        freqToList[freq]->remove(node);
        if (freq == minFreq && freqToList[freq]->size == 0)
            minFreq++;

        node->freq++;
        if (!freqToList.count(node->freq))
            freqToList[node->freq] = new DoublyLinkedList();
        freqToList[node->freq]->addToFront(node);
    }

public:
    LFUCache(int cap) : capacity(cap), size(0), minFreq(0) {}

    int get(int key) {
        if (!keyToNode.count(key)) return -1;
        Node* node = keyToNode[key];
        updateFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyToNode.count(key)) {
            Node* node = keyToNode[key];
            node->value = value;
            updateFreq(node);
        } else {
            if (size == capacity) {
                Node* nodeToRemove = freqToList[minFreq]->removeLeastRecent();
                keyToNode.erase(nodeToRemove->key);
                delete nodeToRemove;
                size--;
            }

            Node* newNode = new Node(key, value);
            minFreq = 1;
            if (!freqToList.count(minFreq))
                freqToList[minFreq] = new DoublyLinkedList();
            freqToList[minFreq]->addToFront(newNode);
            keyToNode[key] = newNode;
            size++;
        }
    }

};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */