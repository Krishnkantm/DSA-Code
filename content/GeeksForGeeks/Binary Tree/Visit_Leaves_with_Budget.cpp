/* Binary Tree Node Structure
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int x) {
		data = x;
		left = nullptr;
		right = nullptr;
	}
};
*/

class Solution {
	public:
	void solve(Node* root, int& leaf_count, int k) {
		queue<pair<Node*, int>> q; // O(n)
		
		q.push({root, 1});
		
		// O(n)
		while (!q.empty()) {
			Node* node = q.front().first;
			int level = q.front().second;
			
			q.pop();
			
			// leaf node check
			if (node->left == NULL && node->right == NULL) {
				if (k < level) {
					break;
				}
				
				leaf_count++;
				k -= level;
			}
			
			// left child
			if (node->left != NULL) {
				q.push({node->left, level + 1});
			}
			
			// right child
			if (node->right != NULL) {
				q.push({node->right, level + 1});
			}
		}
	}
	int getCount(Node *root, int k) {
		
		int leaf_count = 0;
		solve(root, leaf_count, k);
		
		// time => O(n)
		// space => O(n)
		return leaf_count;
	}
};
