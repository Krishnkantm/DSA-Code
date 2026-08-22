/* Structure of Binary Tree Node
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class Solution {
	public:
	Node* lca(Node* root, int n1, int n2) {
		// base case
		if (root == NULL) {
			return NULL;
		}
		
		if (root->data == n1 || root->data == n2) {
			return root;
		}
		
		Node* left = lca(root->left, n1, n2);
		Node* right = lca(root->right, n1, n2);
		
		if (left != NULL && right != NULL) {
			return root;
		}
		else if (left != NULL && right == NULL) {
			return left;
		}
		else if (left == NULL && right != NULL) {
			return right;
		}
		else {
			return NULL;
		}
	}
	
	int directionCount(Node* root, int target, char pre) {
		// base case
		if (root == NULL) {
			return - 1;
		}
		
		if (root->data == target) {
			return 0;
		}
		
		if (root->left != NULL) {
			int turn = directionCount(root->left, target, 'L');
			
			if (turn != -1) {
				if (pre != '#' && pre == 'R') {
					turn++;
				}
				
				return turn;
			}
		}
		
		if (root->right != NULL) {
			int turn = directionCount(root->right, target, 'R');
			
			if (turn != -1) {
				if (pre != '#' && pre == 'L') {
					turn++;
				}
				
				return turn;
			}
		}
		
		return - 1;
		
	}
	
	int numberOfTurns(Node* root, int p, int q) {
		Node* lca_node = lca(root, p, q);
		
		if (lca_node->data == p) {
			int ans = directionCount(lca_node, q, '#');
			
			return (ans == 0) ? -1 : ans;
		}
		
		if (lca_node->data == q) {
			int ans = directionCount(lca_node, p, '#');
			
			return (ans == 0) ? -1 : ans;
		}
		
		int first = directionCount(lca_node, p, '#');
		int second = directionCount(lca_node, q, '#');
		
		if (first == -1 || second == -1) {
			return - 1;
		}
		
		// time => O(n)
		// space => O(h)
		
		return (first + second + 1);
	}
};
