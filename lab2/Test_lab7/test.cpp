#include "pch.h"
#include "alg_lab7.h"

TEST(TreapFunctionsTest, InsertTestLeft) {
	ptr_node root = new node{ 10, 5 };
	ptr_node it = new node{ 7, 3};

	insert(root, it);

	ASSERT_EQ(root->left->key, 7);
	ASSERT_EQ(root->left->priority, 3);
}
TEST(TreapFunctionsTest, InsertTestRight) {
	ptr_node root = new node{ 10, 5 };
	ptr_node it = new node{ 11, 3 };

	insert(root, it);

	ASSERT_EQ(root->right->key, 11);
	ASSERT_EQ(root->right->priority, 3);
}
TEST(TreapFunctionsTest, InsertTestUp) {
	ptr_node root = new node{ 10, 5 };
	ptr_node it = new node{ 11, 6 };

	insert(root, it);

	ASSERT_EQ(root->key, 11);
	ASSERT_EQ(root->priority, 6);
}

TEST(TreapFunctionsTest, SplitTest) {
	ptr_node root = new node{ 10, 5 };
	ptr_node it = new node{ 7, 3 };
	insert(root, it);

	ptr_node left = NULL;
	ptr_node right = NULL;
	split(root, 8, left, right);
	ASSERT_EQ(left->key, 7);
	ASSERT_EQ(right->key, 10);
}

TEST(TreapFunctionsTest, MergeTest) {
	ptr_node root1 = new node{ 7, 5 };
	ptr_node it1 = new node{ 5, 3 };
	insert(root1, it1);

	ptr_node root2 = new node{ 11, 6 };
	ptr_node it2 = new node{ 8, 4 };
	insert(root2, it2);

	ptr_node root = NULL;
	merge(root, root1, root2);

	ASSERT_EQ(root->key, 11);
	ASSERT_EQ(root->left->key, 7);
	ASSERT_EQ(root->left->right->key, 8);
	ASSERT_EQ(root->left->left->key, 5);
	
}