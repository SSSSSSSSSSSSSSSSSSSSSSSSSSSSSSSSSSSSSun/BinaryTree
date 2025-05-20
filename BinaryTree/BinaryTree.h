#pragma once
#include <memory>

template <class T>
struct CBinaryTree_Node {
	T data;
	CBinaryTree_Node* parent{ nullptr };
	CBinaryTree_Node* left{ nullptr };
	CBinaryTree_Node* right{ nullptr };

	CBinaryTree_Node(const T& value) : data{ value } {}
	CBinaryTree_Node(const T& value, CBinaryTree_Node* parent) : data{ value }, parent{ parent } {}
};

template <class T>
class CBinaryTree_const_Iterator {
public:
	using difference_type = ptrdiff_t;
	using value_type = const CBinaryTree_Node<T>;
	using pointer = const CBinaryTree_Node<T>*;
	using reference = const CBinaryTree_Node<T>&;
	using iterator_category = std::bidirectional_iterator_tag;

public:
	CBinaryTree_const_Iterator(CBinaryTree_Node<T>* p) : m_p{ p } {};

	reference operator*() const {
		return const_cast<reference>(_Mybase::operator*());
	}

	pointer operator->() const {
		return m_p;
	}

	bool operator== CBinaryTree_const_Iterator();
	CBinaryTree_const_Iterator operator++();
	CBinaryTree_const_Iterator operator--();

	CBinaryTree_const_Iterator operator++(int);
	CBinaryTree_const_Iterator operator--(int);

	
protected:
	CBinaryTree_Node<T>* m_p;
};

template <class T>
class CBinaryTree_Iterator : public CBinaryTree_const_Iterator<T> {
public:
	using difference_type = ptrdiff_t;
	using value_type = CBinaryTree_Node<T>;
	using pointer = CBinaryTree_Node<T>*;
	using reference = CBinaryTree_Node<T>&;
	using iterator_category = std::bidirectional_iterator_tag;

public:
	CBinaryTree_Iterator() = default;
	CBinaryTree_Iterator(CBinaryTree_Node<T>* p) : CBinaryTree_const_Iterator<T>(p) {};



};

template <class T>
class CBinaryTree
{
public:
	using const_iterator = CBinaryTree_const_Iterator<T>;
	using iterator = CBinaryTree_Iterator<T>;

public:
	


	const_iterator cbegin() const;
	const_iterator cend() const;
	iterator begin() const;
	iterator end() const;

	int depth() const { return m_depth; };
	size_t size() const { return m_size; };
	void insert(const T& value);
	void erase(const T& value);

private:
	

	CBinaryTree_Node<T>* m_root{ nullptr };
	int m_depth{ 0 };
	size_t m_size{ 0 };
};

