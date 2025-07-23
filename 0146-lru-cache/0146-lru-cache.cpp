class Node {
public:
	int key, val;
	Node* next;
	Node* prev;
    
    // Constructors
	Node() {
		key = val = -1;
		next = prev = NULL;
	}

	Node(int k, int value) {
		key = k;
		val = value;
		next = prev = NULL;
	}
};

class LRUCache {
private:
    map<int, Node*> cache;
    int capacity;
    Node *head, *tail;

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        Node* node = cache[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
            return;
        }
        if (cache.size() == capacity) {
            Node* lru = tail->prev;
            cache.erase(lru->key);
            deleteNode(lru);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insertAfterHead(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */