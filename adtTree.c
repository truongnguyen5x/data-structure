#define false 0
#define true !false
#include <stdio.h>
#include <stdlib.h>

typedef struct _treenode {
	int inf;
	struct _treenode *leftMostChild;
	struct _treenode *rightSibling;
} treenode;

int isMinHeap(int arr[], int n) {
	for (int i = 1; i <= n / 2; i++) {
		if (arr[i - 1] > arr[2 * i - 1])
			return false;
		if ((2 * i + 1) <= n)
			if (arr[i - 1] > arr[2 * i])
				return false;
	}
	return true;
}


int isMinHeap2(int A[], int i, int n) {
	if (i > n / 2)
		return 1;

	if ((A[i - 1] <= A[2 * i - 1] && isMinHeap2(A, 2 * i, n)) &&
	        ((2 * i > n - 1) ||
	         (A[i - 1] <= A[2 * i] && isMinHeap2(A, 2 * i + 1, n))))
		return 1;
	else
		return 0;
}

int count(treenode *root) {
	int sum = 0;
	if (root == NULL)
		return 0;
	if ( (root->leftMostChild != NULL)
	        && (root->leftMostChild->rightSibling != NULL)
	        && (root->leftMostChild->rightSibling->rightSibling != NULL) )
		sum++;
	sum += count(root->leftMostChild);
	sum += count(root->rightSibling);
	return sum;
}

int depth(treenode *root) {
	if (root == NULL)
		return 0;
	int a = depth(root->leftMostChild) + 1;
	int b = depth(root->rightSibling);
	return (a > b) ? a : b;
}

treenode *make(int number, treenode *leftChild, treenode *right) {
	treenode *temp = malloc(sizeof(treenode));
	temp->leftMostChild = leftChild;
	temp->inf = number;
	temp->rightSibling = right;
	return temp;
}

int kiemTra(char A[], int n, int k) {
	if (k >= n)
		return 1;
	else {
		if (A[k - 1] == A[n - 1] && kiemTra(A, n - 1, k + 1)) {
			return 1;
		} else {
			return 0;
		}
	}
}
int main() {

	// make(10, NULL, make(11, NULL, make(12, NULL, NULL)));
	// make(14, NULL, make(15, NULL, make(15, NULL, NULL)));
	// make(19, NULL, make(20, NULL, make(21, NULL, NULL)));
	// make(13, NULL, NULL);
	// make(17, NULL, make(18, NULL, NULL));

	// make(4, , make(5, , make(6, , make(7, NULL, NULL))));
	// make(8, , make(9, , NULL));
	// make(2, , make(3, NULL));
	// make(1, , NULL);
	treenode *cay = make(
	                    1,
	                    make(
	                        2,
	                        make(4, make(10, NULL, make(11, NULL, make(12, NULL, NULL))),
	                             make(5, make(13, NULL, NULL),
	                                  make(6,
	                                       make(14, NULL, make(15, NULL, make(15, NULL, NULL))),
	                                       make(7, NULL, NULL)))),
	                        make(3,
	                             make(8, make(17, NULL, make(18, NULL, NULL)),
	                                  make(9,
	                                       make(19, NULL, make(20, NULL, make(21, NULL, NULL))),
	                                       NULL)),
	                             NULL)),
	                    NULL);
	printf("%d", count(cay));
}
