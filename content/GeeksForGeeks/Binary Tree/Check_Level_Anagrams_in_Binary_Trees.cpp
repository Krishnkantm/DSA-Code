/* Structure of binary tree Node
class Node {
	public:
	int data;
	Node *left, *right;
	Node(int x) {
		data = x;
		left = right = nullptr;
	}
};
*/

class Solution {
	public:
	bool areAnagrams(Node* root1, Node* root2) {
		if (root1 == NULL && root2 == NULL)
			return true;
		if (root1 == NULL || root2 == NULL)
			return false;
		
		queue<Node*> q1, q2; // O(n)
		
		q1.push(root1);
		q2.push(root2);
		
		// time => o(n)
		// space => O(n)
		while (!q1.empty() || !q2.empty()) {
			
			int n1 = q1.size();
			int n2 = q2.size();
			
			if (n1 != n2)
				return false;
			
			unordered_map<int, int> freq;
			
			for (int i = 0; i<n1; i++) {
				Node* node1 = q1.front();
				q1.pop();
				
				Node* node2 = q2.front();
				q2.pop();
				
				freq[node1->data]++;
				freq[node2->data]--;
				
				if (node1->left != NULL) {
					q1.push(node1->left);
				}
				
				if (node1-> right != NULL) {
					q1.push(node1->right);
				}
				
				if (node2->left != NULL) {
					q2.push(node2->left);
				}
				
				if (node2-> right != NULL) {
					q2.push(node2->right);
				}
			}
			
			for (auto &it : freq) {
				if (it.second != 0)
					return false;
			}
		}
		
		return true;
	}
};
