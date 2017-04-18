struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

    if (!l1) return l2;
    if (!l2) return l1;

    struct ListNode *head = NULL;
    struct ListNode **tail = &head;

    while (l1 || l2) 
	{
        if (l1 && l2) 
		{
            if (l1->val <= l2->val) 
			{
                *tail = l1;
                l1 = l1->next;
            }
            else 
			{
                *tail = l2;
                l2 = l2->next;
            }
        }
        else if (l1 && !l2) 
		{
            *tail = l1;
            l1 = l1->next;
        }
        else if (l2 && !l1) 
		{
            *tail = l2;
            l2 = l2->next;
        }

        tail = &((*tail)->next);
    }

    return head;
}

struct ListNode* arrToList(int arr[], int len)
{
	struct ListNode* head = NULL, *pre = NULL, *tmp = NULL;
	int i;
	for(i=0; i<len; i++)
	{
		tmp = (struct ListNode*)malloc(sizeof(struct ListNode*));
		if (i==0) 
			head = tmp;
		else 
			pre->next = tmp;

		tmp->val = arr[i];
		tmp->next = NULL;
		pre = tmp;
	}

	return head;
}

void printfListNode(struct ListNode* head)
{
	while (head)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}


void main()
{
	int a1[] = {-10,-9,-6,-4,1,9,9};
	int a2[] = {-5,-3,0,7,8,8};

	struct ListNode* l1 = arrToList(a1, sizeof(a1)/sizeof(a1[0]));
	struct ListNode* l2 = arrToList(a2, sizeof(a2)/sizeof(a2[0]));
	struct ListNode* newList = mergeTwoLists(l1, l2);
	
	printfListNode(newList);
}