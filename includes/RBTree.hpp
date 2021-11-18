/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:07:59 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/09 13:32:53 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <iostream>
#include "iterator.hpp"
#include "utility.hpp"

#define	BLACK	false
#define	RED		true

namespace ft
{

template <class Value,
		class Alloc>
class RBTree
{

private:

	typedef struct	s_node
	{
		struct s_node*			parent;
		struct s_node*			left;
		struct s_node*			right;
		bool					color;
		Value					stock;
	}				node;

public:

	template<
	typename T,
	bool isConst = false
	> struct rbIterator
	{

	public:
		typedef	ptrdiff_t	difference_type;
		typedef	T			value_type;
		typedef	T*			pointer;
		typedef	T&			reference;

	private:
		node	*_it;

	public:
		rbIterator( void ): _it( NULL ) {}
		explicit rbIterator( node *it ): _it( it ) {}
		rbIterator( rbIterator const & cpy ) { *this = cpy; }

		operator rbIterator<const T, true>() const
		{
			return rbIterator<const T, true> (this->_it);
		}

		rbIterator&	operator=( rbIterator const &rhs )
		{
			if ( this != &rhs )
				this->_it = rhs._it;
			return (*this);
		}

		rbIterator&	operator++( void )
		{
			//std::cout << "incr" << std::endl;
			this->_it = this->successorNode(this->_it);
			return (*this);
		}

		rbIterator	operator++( int )
		{
			rbIterator	ret = *this;
			this->operator++();
			return (ret);
		}

		bool		operator==( rbIterator<T, false> const &b ) const
		{
			return (this->_it == b._it);
		}

		bool		operator!=( rbIterator<T, false> const &b ) const
		{
			return (this->_it != b._it);
		}

		bool		operator==( rbIterator<const T, true> const &b ) const
		{
			return (this->_it == b._it);
		}

		bool		operator!=( rbIterator<const T, true> const &b ) const
		{
			return (this->_it != b._it);
		}

		rbIterator&	operator--( void )
		{
			_it = predecessor(_it);
			return (*this);
		}

		rbIterator		operator--( int )
		{
			rbIterator	ret = *this;
			this->operator--();
			return (ret);
		}

		reference	operator*( void ) const
		{
			return (this->_it->stock);
		}

		pointer		operator->( void ) const
		{
			return	(&this->_it->stock);
		}

		//value_type*	getVal( void ) const { return (this->_val); }

		node	*successorNode(node *nd)	//edit this shit and replace with _it for void successorNode(void)
		{
			node *x = nd;

			//std::cout << "hey" << std::endl;
			if (x->right->right == NULL)
			{
				//std::cout << "choose1" << std::endl;
				x = x->parent;
				while (x->parent->right != NULL && x->stock < nd->stock)
				{
					//std::cout << "hey" << std::endl;
					x = x->parent;
				}
				if (x->stock < nd->stock)	// if x dont have successor
					x = x->parent;
				if (x == nd)	// for if root dont have successor
					x = x->parent;
			}
			else
			{
				//std::cout << "choose2" << std::endl;
				x = x->right;
				while (x->left->right != NULL)
					x = x->left;
			}
			return (x);
		}

		node	*predecessor(node *nd)
		{
			node *x = nd;

			if (x->right == NULL)
			{
				//std::cout << "choose0" << std::endl;
				x = x->parent;
				while (x->right != nd) // nd = _nil
					x = x->right;
			}
			else if (x->left->left == NULL)
			{
				//std::cout << "choose1" << std::endl;
				x = x->parent;
				while (x->parent->right != NULL && x->stock > nd->stock)
				{
					x = x->parent;
				}
				if (x->stock > nd->stock)	// if x dont have predecessor
					x = nd;
			}
			else
			{
				//std::cout << "choose2" << std::endl;
				x = x->left;
				while (x->right->left != NULL)
					x = x->right;
			}

			return (x);
			//if (!x->parent)
				//return (RBTree::minNode());
		}

	};

	typedef typename	Alloc::template rebind<node>::other		alloc_node;
	typedef rbIterator<Value, false>							iterator;
	typedef rbIterator<const Value, true>						const_iterator;
	typedef	ft::reverse_iterator<iterator>						reverse_iterator;
	typedef	ft::reverse_iterator<const_iterator>				const_reverse_iterator;
	typedef	ptrdiff_t											difference_type;
	typedef	size_t												size_type;
	typedef	Value												value_type;

private:

	node		*_root;
	node		*_nil_node;
	alloc_node	_alloc;
	size_type	_size;

public:

	RBTree( void )
	{
		node	nil;

		this->_nil_node = this->_alloc.allocate(1);
		nil.parent = NULL;
		nil.left = NULL;
		nil.right = NULL;
		nil.color = BLACK;
		this->_alloc.construct(this->_nil_node, nil);
		this->_size = 0;
		//std::cout << "CONSTRUCTOR" << std::endl;

		this->_root = this->_nil_node;
	}

	~RBTree( void )
	{
		//std::cout << "DESTRUCTOR" << std::endl;
		//this->printTree();
		this->delTree(this->_root);

		//this->printTree();
		this->_alloc.destroy(this->_nil_node);
		this->_alloc.deallocate(this->_nil_node, 1);
	}

	RBTree( RBTree const & rhs )
	{
		if (this != &rhs)
		{
			std::cout << "TODO CONSTRUCTOR COPY" << std::endl;
			//rhs._alloc = this->_alloc;
		}
	}

	/*	FUNCTION MAP */
	// Iterators:

	iterator		begin( void )
	{
		return (iterator(!this->_size ? this->_nil_node : this->minNode()));
	}

	const_iterator	begin( void ) const
	{
		return (const_iterator(!this->_size ? this->_nil_node : this->minNode()));
	}

	iterator		end( void )
	{
		return (iterator(this->_nil_node));
	}

	const_iterator	end( void ) const
	{
		return (const_iterator(this->_nil_node));
	}

	reverse_iterator	rbegin( void )
	{
		return (reverse_iterator(this->end()));
	}

	const_reverse_iterator	rbegin( void ) const
	{
		return (const_reverse_iterator(this->end()));
	}

	reverse_iterator	rend( void )
	{
		return (reverse_iterator(this->begin()));
	}

	const_reverse_iterator	rend( void ) const
	{
		return (const_reverse_iterator(this->begin()));
	}

	// Capacity:

	bool		empty( void ) const
	{
		return (this->_root == this->_nil_node);
	}

	size_type	size( void ) const
	{
		return (this->_size);
	}

	size_type	max_size( void ) const
	{
		return (this->_alloc.max_size());
	}


	// Element access:

	/*template <typename key_type>
	value_type& operator[](const key_type& k)
	{

	}*/


	// Modifiers:

	ft::pair<iterator, bool>	insert( value_type const & val )
	{
		iterator	it;

		if (this->searchNode(val) != this->_nil_node)
		{
			it = iterator(this->searchNode(val));
			return (ft::make_pair(it, false));
		}
		else
		{
			this->insertNode(this->newNode(val));
			it = iterator(this->searchNode(val));

			return (ft::make_pair(it, true));
		}
	}

	iterator	insert( iterator position, value_type const & val )
	{
		static_cast<void>(position);
		return (this->insert(val).first);
	}

	template <class InputIterator>
	void	insert( InputIterator first, InputIterator last )
	{
		for (; first != last; ++first)
			this->insert(*first);
	}

	void	erase(iterator position)
	{
		this->erase(*position);
	}

	size_type	erase( value_type const & k )
	{
		size_type ret = this->_size;

		this->deleteNode(k);
		return (ret - this->_size);
	}

	void	erase( iterator first, iterator last )
	{
		for (; first != last; ++first)
			this->erase(first);
	}

	void	clear( void )
	{
		this->delTree(this->_root);
		this->_size = 0;
		this->_root = this->_nil_node;
		this->_nil_node->parent = NULL;
	}

	// Observers:

	// Operations:

	iterator	find( value_type const & k )
	{
		return (iterator(this->searchNode(k)));
	}

	const_iterator	find( value_type const & k ) const
	{
		return (const_iterator(this->searchNode(k)));
	}

	size_type	count( value_type const & k ) const
	{
		return (this->find(k) == this->end() ? 0 : 1);
	}


private:

	void	deleteNode( value_type const & srh )
	{
		node *y = this->_nil_node;
		node *x = this->_nil_node;
		node *z = this->searchNode(srh);

		if (z == this->_nil_node)
			return ;

		if (z->left == this->_nil_node || z->right == this->_nil_node)
			y = z;
		else
		{
			y = z->right;
			while (y->left != this->_nil_node)	// successor
				y = y->left;
		}

		if (y->left != this->_nil_node)
			x = y->left;
		else
			x = y->right;

		x->parent = y->parent;

		if (y->parent == this->_nil_node)
			this->_root = x;
		else if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;

		if (y != z)
			z->stock = y->stock;

		if (y->color == BLACK)
			deleteFix(x);
		this->_alloc.destroy(y);
		this->_alloc.deallocate(y, 1);
		this->_nil_node->parent = this->_root;
		this->_size--;
	}

	void	printTree( void ) const
	{
		int	i = 0;
		std::cout << std::endl;
		this->printAllNode( this->_root , i );
	}

	void	insertNode( node *ins )
	{
		node *y = this->_nil_node;
		node *x = this->_root;

		while (x != this->_nil_node)
		{
			y = x;
			if (ins->stock.first < x->stock.first)
				x = x->left;
			else
				x = x->right;
		}

		ins->parent = y;
		if (y == this->_nil_node)
			this->_root = ins;
		else if (ins->stock.first < y->stock.first)
			y->left = ins;
		else
			y->right = ins;

		this->insertFix(ins);
		this->_nil_node->parent = this->_root;
		this->_size++;
	}

	node	*minNode( void ) const
	{
		node *x = this->_root;

		while (x->left != this->_nil_node)
			x = x->left;
		return (x);
	}

	node	*maxNode( void )
	{
		node *x = this->_root;

		while (x->right != this->_nil_node)
			x = x->right;
		return (x);
	}

	node	*searchNode( value_type const & search ) const
	{
		node *x = this->_root;

		while (x != this->_nil_node)
		{
			if (search.first > x->stock.first)
				x = x->right;
			else if (search.first < x->stock.first)
				x = x->left;
			else if (search.first == x->stock.first)
				return (x);
		}
		return (this->_nil_node);
	}

	node	*newNode( value_type const & val )
	{
		node	*ret = this->_alloc.allocate(1);
		node	tmp;

		tmp.parent = this->_nil_node;
		tmp.left = this->_nil_node;
		tmp.right = this->_nil_node;
		tmp.color = RED;
		tmp.stock = val;
		this->_alloc.construct(ret, tmp);
		return (ret);
	}

	void	leftRotate( node *x )
	{
		node	*y_right = x->right;

		x->right = y_right->left;
		if (y_right->left != this->_nil_node)
			y_right->left->parent = x;
		y_right->parent = x->parent;
		if (x->parent == this->_nil_node)
			this->_root = y_right;
		else if (x == x->parent->left)
			x->parent->left = y_right;
		else
			x->parent->right = y_right;
		y_right->left = x;
		x->parent = y_right;
	}

	void	rightRotate( node *x )
	{
		node *y_left = x->left;

		x->left = y_left->right;
		if (y_left->right != this->_nil_node)
			y_left->right->parent = x;
		y_left->parent = x->parent;
		if (x->parent == this->_nil_node)
			this->_root = y_left;
		else if (x == x->parent->right)
			x->parent->right = y_left;
		else
			x->parent->left = y_left;
		y_left->right = x;
		x->parent = y_left;
	}

	void	insertFix( node *z )
	{
		node *y;

		while (z->parent->color == RED)
		{
			if (z->parent == z->parent->parent->left)
			{
				y = z->parent->parent->right;
				if (y->color == RED)
				{
					z->parent->color = BLACK;
					y->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				else
				{
					if (z == z->parent->right)
					{
						z = z->parent;
						this->leftRotate(z);
					}
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					this->rightRotate(z->parent->parent);
				}
			}
			else
			{
				y = z->parent->parent->left;
				if (y->color == RED)
				{
					z->parent->color = BLACK;
					y->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				else
				{
					if (z == z->parent->left)
					{
						z = z->parent;
						this->rightRotate(z);
					}
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					this->leftRotate(z->parent->parent);
				}
			}
		}
		this->_root->color = BLACK;
	}

	void	deleteFix( node *x )
	{
		node *w;

		while (x != this->_root && x->color == BLACK)
		{
			if (x->parent->left == x)
			{
				w = x->parent->right;
				if (w->color == RED)
				{
					w->color = BLACK;
					x->parent->color = RED;
					this->leftRotate( x->parent );
					w = x->parent->right;
				}
				if (w->left->color == BLACK && w->right->color == BLACK)
				{
					w->color = RED;
					x = x->parent;
				}
				else
				{
					if (w->right->color == BLACK)
					{
						w->left->color = BLACK;
						w->color = RED;
						this->rightRotate( w );
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = BLACK;
					w->right->color = BLACK;
					this->leftRotate( x->parent );
					x = this->_root;
				}
			}
			else
			{
				w = x->parent->left;
				if (w->color == RED)
				{
					w->color = BLACK;
					x->parent->color = RED;
					this->rightRotate( x->parent );
					w = x->parent->left;
				}
				if (w->right->color == BLACK && w->left->color == BLACK)
				{
					w->color = RED;
					x = x->parent;
				}
				else
				{
					if (w->left->color == BLACK)
					{
						w->right->color = BLACK;
						w->color = RED;
						this->leftRotate( w );
						w = x->parent->left;
					}
					w->color = x->parent->color;
					x->parent->color = BLACK;
					w->left->color = BLACK;
					this->rightRotate( x->parent );
					x = this->_root;
				}
			}
		}
		x->color = BLACK;
	}

	void	delTree( node *nodeDel )
	{

		if (nodeDel == this->_nil_node)
			return ;

		this->delTree(nodeDel->left);
		this->delTree(nodeDel->right);
		//this->printNode(nodeDel, i);
		this->_alloc.destroy(nodeDel);
		this->_alloc.deallocate(nodeDel, 1);
		//nodeDel = this->_nil_node;
		//this->printNode(nodeDel, i);
		//std::cout << "delete" << std::endl;
	}

	void	printKey( node *nodeKey, std::string const & name ) const
	{
		std::cout	<< name << " = ";
		if (nodeKey == this->_nil_node)
			std::cout << "NULL";
		else
			std::cout << nodeKey->stock.first;
		std::cout << std::endl;
	}

	void	printNode( node *nodePrint, int const & i ) const
	{
		if (nodePrint == this->_nil_node)
		{
			std::cout << "is _nil" << std::endl;
			std::cout  << std::endl;
			return ;
		}

		std::cout << "node " << i
			<< (nodePrint->color == RED
				? " [RED] "
				: " [BLACK] ")
			<< (nodePrint->parent == this->_nil_node
				? "(root) "
				: "") << ":" << std::endl;

		std::cout << "key    = " << nodePrint->stock.first << std::endl;
		this->printKey(nodePrint->parent, "parent");
		this->printKey(nodePrint->left, "left  ");
		this->printKey(nodePrint->right, "right ");
		std::cout << "value  = " << nodePrint->stock.second << std::endl;
		std::cout << "--------------------------" << std::endl;
		std::cout << std::endl;

	}

	void	printAllNode( node *nodePrint , int & i ) const
	{
		if (this->_root == this->_nil_node)
		{
			std::cout << "(empty)" << std::endl;
			return ;
		}
		if ( nodePrint == this->_nil_node )
			return ;
		i++;
		this->printNode(nodePrint, i);
		this->printAllNode(nodePrint->left, i);
		this->printAllNode(nodePrint->right, i);
	}

};

}

#endif
