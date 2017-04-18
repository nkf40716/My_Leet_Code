typedef struct _ListNode {
	char data;
	struct _ListNode *next;
} ListNode;

bool ValidParent(char s1, char s2)
{
	if (s1 == '(' && s2 == ')')
		return true;
	if (s1 == '[' && s2 == ']')
		return true;
	if (s1 == '{' && s2 == '}')
		return true;
	return false;
}

void AddListNode(ListNode **root, char c)
{
	ListNode *tmp = NULL;
	if (*root == NULL)	
	{
		tmp = (ListNode *)malloc(sizeof(ListNode));
		tmp->data = c;
		tmp->next = NULL;
		*root = tmp;
		return;
	}
	else
		AddListNode(&((*root)->next), c);
}

char RemoveLastNode(ListNode **root)
{
	char r;
	ListNode *prev = *root, *current = *root;

	if ((*root)->next == NULL)
	{
		r = (*root)->data;
		free(*root);
		*root = NULL;
		return r;
	}

	while (current->next) {	
		prev = current;
		current = current->next;
	}

	r = current->data;
	free(current);
	current = NULL;
	prev->next = NULL;

	return r;
}

bool isValid(char* s) 
{
	int i, n;
	ListNode *root = NULL;
	n = strlen(s);

	if (n % 2)
		return false;

	for (i=0; i<n; i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			AddListNode(&root, s[i]);
		else if (root && ValidParent(RemoveLastNode(&root), s[i]) == false)
			return false;
	}

	if(root)
		return false;

	return true;
}