/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*, int> rank;
        Node* temp = head;
        int cnt = 0;
        while(temp) {
            rank[temp] = cnt++;
            temp = temp->next;
        }
        unordered_map<int, int> map_rand;
        temp = head;
        cnt = 0;
        while(temp) {
            Node* rand = temp->random;
            map_rand[cnt++] = (!rand) ? -1 : rank[rand];
            temp = temp->next;
        } 
        vector<Node*> pool;
        temp = head;
        while(temp) {
            Node* newNode = new Node(temp->val);
            pool.push_back(newNode);
            temp = temp->next;
        }
        for(int i = 0; i < cnt; i++) {
            pool[i]->next = (i == cnt - 1) ? nullptr : pool[i + 1];
            pool[i]->random = (map_rand[i] == -1) ? nullptr : pool[map_rand[i]];
        }
        return pool[0];
    }
};
