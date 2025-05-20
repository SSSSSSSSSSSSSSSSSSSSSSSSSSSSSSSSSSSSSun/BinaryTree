#include "BinaryTree.h"

template <class T>
CBinaryTree_const_Iterator<T> CBinaryTree<T>::cbegin() const
{
	CBinaryTree_Node* current{ m_root };
	while (current and current->left) {
		current = current->left;
	}

	return current;
}

template <class T>
CBinaryTree_const_Iterator<T> CBinaryTree<T>::cend() const
{
	return nullptr;
}

template <class T>
CBinaryTree_Iterator<T> CBinaryTree<T>::begin() const
{

	return cbegin().p;
}

template <typename T>
CBinaryTree_Iterator<T> CBinaryTree<T>::end() const
{
	return cend().p;
}

template <class T>
void CBinaryTree<T>::insert(const T& value)
{
	if (nullptr == m_root){					// 빈 트리
		m_root = new CBinaryTree_Node<T>(value);
		m_size = 1;
		m_depth = 1;
		return;
	}

	CBinaryTree_Node<T>* current = m_root;
	size_t pos{ m_size + 1 };				// 현 개수로 다음 위치 찾아가서 삽입

	m_depth = 0;
	size_t temp { pos };
	while (temp > 0) {
		temp >>= 1;
		m_depth++;
	}

	for (int i = m_depth - 2; i >= 1; --i) {
		if (pos & (1 << i)) {
			current = current->right;
		}
		else {
			current = current->left;
		}
	}

	// 최하위 노드
	if (pos & 1) {
		current->right = new CBinaryTree_Node<T>(value, current);
	}
	else {
		current->left = new CBinaryTree_Node<T>(value, current);
	}

	m_size++;
}

template <class T>
void CBinaryTree<T>::erase(const T& value)
{

}