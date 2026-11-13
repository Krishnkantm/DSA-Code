/* Structure of a Binary Search Tree node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};
*/

class Solution {
	public:
	void inorder(Node* root, vector<int>& v) {
		// base case
		if (root == NULL)
			return;
		
		// LNR LEFT NODE RIGHT
		inorder(root->left, v);
		v.push_back(root->data);
		inorder(root->right, v);
		
	}
	
	vector<int> findCommon(Node* r1, Node* r2) {
		// base case
		if (r1 == NULL || r2 == NULL) {
			return {};
		}
		
		vector<int> v1, v2;
		
		inorder(r1, v1); // O(h1)
		inorder(r2, v2); // O(h2)
		
		vector<int> ans; // O(n+m)
		
		int i = 0;
		int j = 0;
		
		int n = v1.size();
		int m = v2.size();
		
		// k = min(n,m)
		while (i<n && j < m) {
			if (v1[i] == v2[j]) {
				ans.push_back(v1[i]);
				i++;
				j++;
			}
			else if (v1[i] < v2[j]) {
				i++;
			}
			else {
				j++;
			}
		}
		
		// time -> O(k) + O(h1) + o(h2)
		// space -> O(n) + O(m)
		
		return ans;
	}
};
