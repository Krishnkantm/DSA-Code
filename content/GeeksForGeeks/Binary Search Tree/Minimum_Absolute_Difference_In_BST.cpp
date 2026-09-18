/* Binary Tree Node Structure
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};
*/

class Solution {
	public:
	
	void inorder(Node* root, int& ans, Node*& pre) {
		// base case
		if (root == NULL)
			return ;
		
		// step1
		inorder(root->left, ans, pre);
		
		// step2
		if (pre != NULL) {
			ans = min(ans, abs(root->data - pre->data));
		}
		
		pre = root;
		
		// step 3
		inorder(root->right, ans, pre);
	}
	
	int absDiff(Node *root) {
		int ans = INT_MAX;
		Node* pre = NULL;
		
		inorder(root, ans, pre); // O(n)
		// space -> O(h)
		
		return ans;
		
	}
};
