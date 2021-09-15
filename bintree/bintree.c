//bintree.c

#include "bintree.h"
#include <string.h>
#include <stdlib.h>

BinaryTree* bintree_initialize(int itemSize, char* type, int (*compare)(void*, void*), void (*print)(void*)) {

	BinaryTree* bintree = malloc(sizeof(*bintree));

	bintree->itemSize = itemSize;
	bintree->type = malloc(sizeof(*type));
	memcpy(bintree->type, type, sizeof(type));

	bintree->compare = compare;
	bintree->print = print;

	bintree->top = NULL;

	return bintree;
}

BinaryTreeNode* bintree_create_node(int itemSize, void* item) {

	BinaryTreeNode* binNode = malloc(sizeof(*binNode));

	binNode->data = malloc(itemSize);
	memcpy(binNode->data, item, itemSize);

	binNode->left = NULL;
	binNode->right = NULL;

	return binNode;
}

bool bintree_insert(BinaryTree* bintree, void* item) {

	if (bintree == NULL || item == NULL) {
	
		return NULL;
	}

	if (bintree->top == NULL) {
		
		BinaryTreeNode* new = bintree_create_node(bintree->itemSize, item);

		new->left = NULL;
		new->right = NULL;
		bintree->top = new;
		return true;
	}

	BinaryTreeNode* binNode = bintree->top;

	return _bintree_insert_recursive(bintree, binNode, item);
}

bool _bintree_insert_recursive(BinaryTree* bintree, BinaryTreeNode* binNode, void* item) {

	if (bintree == NULL || binNode == NULL) {
	
		return false;
	}

	BinaryTreeNode* new = bintree_create_node(bintree->itemSize, item);

	if (bintree->compare(binNode->data, item) < 0) {
		if (binNode->left == NULL) {
			
			new->left = NULL;
			new->right = NULL;
			
			binNode->left = new;
			return true;
		}
		else {
			binNode = binNode->left;
			_bintree_insert_recursive(bintree, binNode, item);
		}
	}
	else {
		if (binNode->right == NULL) {
		
			new->left = NULL;
			new->right = NULL;

			binNode->right = new;
			return true;
		}
		else {
		
			binNode = binNode->right;
			_bintree_insert_recursive(bintree, binNode, item);
		}
	}

}

//incomplte functions so written so the main will run through insert
bool bintree_search(BinaryTree* bintree, void* item) {

	if (bintree == NULL || item == NULL || bintree->top == NULL) {
	
		return false;
	}

	if (bintree->compare(bintree->top->data, item) == 0) {
	
		return true;
	}

	BinaryTreeNode* binNode = bintree->top;

	return _bintree_search_recursive(bintree, binNode, item);
}

bool _bintree_search_recursive(BinaryTree* bintree, BinaryTreeNode* binNode, void* item) {
	
	if (bintree == NULL || binNode == NULL || item == NULL) {
	
		return false;
	}

	if (bintree->compare(binNode->data, item) == 0) {
	
		return true;
	}
	else if (bintree->compare(binNode->data, item) < 0) {
	
		binNode = binNode->left;
		return _bintree_search_recursive(bintree, binNode, item);
	}
	else {
	
		binNode = binNode->right;
		return _bintree_search_recursive(bintree, binNode, item);
	}
}

void bintree_print_in_order(BinaryTree* bintree) {
	
	if (bintree == NULL) {
	
		return;
	}

	if (bintree->top == NULL) {
	
		return;
	}

	BinaryTreeNode* binNode = bintree->top;

	_bintree_in_order_recursive(bintree, binNode);

}

void _bintree_in_order_recursive(BinaryTree* bintree, BinaryTreeNode* binNode) {
	
	if (bintree == NULL || binNode == NULL) {
	
		return;
	}

	else {
		_bintree_in_order_recursive(bintree, binNode->left);
		bintree->print(binNode->data);
		_bintree_in_order_recursive(bintree, binNode->right);
	}

}


void bintree_print_pre_order(BinaryTree* bintree) {
	
	if (bintree == NULL) {
	
		return;
	}

	if (bintree->top == NULL) {
	
		return;
	}

	BinaryTreeNode* binNode = bintree->top;

	_bintree_pre_order_recursive(bintree, binNode);
}

void _bintree_pre_order_recursive(BinaryTree* bintree, BinaryTreeNode* binNode) {

	if (bintree == NULL || binNode == NULL) {
	
		return;
	}

	else {
		bintree->print(binNode->data);
		_bintree_pre_order_recursive(bintree, binNode->left);
		_bintree_pre_order_recursive(bintree, binNode->right);
	}
}

void bintree_print_post_order(BinaryTree* bintree) {

	if (bintree == NULL) {
	
		return;
	}

	if (bintree->top == NULL) {
	
		return;
	}

	BinaryTreeNode* binNode = bintree->top;

	_bintree_post_order_recursive(bintree, binNode);
}

void _bintree_post_order_recursive(BinaryTree* bintree, BinaryTreeNode* binNode) {

	if (bintree == NULL || binNode == NULL) {
		return;
	}
	else {
	
		_bintree_post_order_recursive(bintree, binNode->left);
		_bintree_post_order_recursive(bintree, binNode->right);
		bintree->print(binNode->data);
	}
}

void bintree_print_reverse_order(BinaryTree* bintree) {

	if (bintree == NULL) {
	
		return;
	}

	if (bintree->top == NULL) {
	
		return;
	}

	BinaryTreeNode* binNode = bintree->top;

	_bintree_reverse_order_recursive(bintree, binNode);
}

void _bintree_reverse_order_recursive(BinaryTree* bintree, BinaryTreeNode* binNode) {

	if (bintree == NULL || binNode == NULL) {
	
		return;
	}

	else {
	
		_bintree_reverse_order_recursive(bintree, binNode->right);
		bintree->print(binNode->data);
		_bintree_reverse_order_recursive(bintree, binNode->left);
	}
}
//djvnvn
