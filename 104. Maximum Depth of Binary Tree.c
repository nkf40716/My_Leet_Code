struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

// 我想用遞迴解這題，所以另外寫一個funtion
int _maxDepth(struct TreeNode* root, int currentDepth) {
	if (!root) return currentDepth;
	currentDepth ++;
	int a, b;
	a = _maxDepth(root->left, currentDepth);
	b = _maxDepth(root->right, currentDepth);
	return (a > b ? a : b);
}
	
int maxDepth(struct TreeNode* root) {
	int depth = 0, ldepth, rdepth;
    if (root) {
		depth++;
		ldepth = _maxDepth(root->left, depth);
		rdepth = _maxDepth(root->right, depth);
		depth = ldepth > rdepth ? ldepth : rdepth;
	}
	return depth;
}


// 另一種寫法，較簡潔
int maxDepth(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    int depth_left = maxDepth(root->left) + 1;
    int depth_right = maxDepth(root->right) + 1;
    return depth_left > depth_right ? depth_left : depth_right;
}