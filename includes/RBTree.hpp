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

#define	BLACK	false
#define	RED		true

namespace ft
{

template<class Value>
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

	node	*_root;
	node	*_nil_node;

public:

	template<
	typename T,
	bool isConst = false
	> class rbIterator
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
		rbIterator( rbIterator const &cpy ) { *this = cpy; }

		operator rbIterator<const T, true>() const
		{
			return rbIterator<const T, true> (this->_it);
		}

		rbIterator&	operator=( rbIterator const &rhs )
		{
			if ( this != &rhs )
				this->_it = rhs._it;
				//this->_val = rhs.getVal();
			return (*this);
		}

		rbIterator&	operator++( void )
		{
			//this->_val++;
			return (*this);
		}

		rbIterator	operator++( int )
		{
			rbIterator	ret = *this;
			//this->_val++;
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
			//this->_val--;
			return (*this);
		}

		rbIterator		operator--( int )
		{
			rbIterator	ret = *this;
			//this->_val--;
			return (ret);
		}

		//value_type&	operator*( void ) const { return (*this->_val); }

		pointer		operator->( void ) const { return	(&this->_it->stock); }

		//value_type*	getVal( void ) const { return (this->_val); }
	};

	typedef	rbIterator<Value, false>					iterator;
	typedef	rbIterator<const Value, true>				const_iterator;
	//typedef	ft::reverse_iterator<iterator>			reverse_iterator;
	//typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	RBTree( void )
	{
		this->_nil_node = new node;
		this->_nil_node->parent = NULL;
		this->_nil_node->left = NULL;
		this->_nil_node->right = NULL;
		this->_nil_node->color = BLACK;
		//this->_nil_node->stock = NULL;

		this->_root = this->_nil_node;
	}

	~RBTree( void )
	{
		this->delTree(this->_root);
		delete this->_nil_node;
	}

	void	deleteNode( Value srh )
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
			z->key = y->key;

		if (y->color == BLACK)
			deleteFix(x);
		delete y;
	}

	void	printTree( void ) const
	{
		int	i = 0;
		std::cout << std::endl;
		this->printAllNode( this->_root , i );
	}

	void	insertNode( Value key )
	{
		node *ins = newNode(key);
		node *y = this->_nil_node;
		node *x = this->_root;

		while (x != this->_nil_node)
		{
			y = x;
			if (key < x->stock)
				x = x->left;
			else
				x = x->right;
		}

		ins->parent = y;
		if (y == this->_nil_node)
			this->_root = ins;
		else if (key < y->stock)
			y->left = ins;
		else
			y->right = ins;

		this->insertFix(ins);
	}

	node	*minNode( void )
	{
		node *x = this->_root;

		while (x->left != this->_nil_node)
			x = x->left;
		return (x);
	}

private:

	node	*searchNode( Value search )
	{
		node *x = this->_root;

		while (x != this->_nil_node)
		{
			if (search > x->stock)
				x = x->right;
			else if (search < x->stock)
				x = x->left;
			else if (search == x->stock)
				return (x);
		}
		return (this->_nil_node);
	}

	node	*newNode( Value val ) const
	{
		node	*ret = new node;

		ret->parent = this->_nil_node;
		ret->left = this->_nil_node;
		ret->right = this->_nil_node;
		ret->color = RED;
		ret->stock = val;
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

	void	insertFix( node* z )
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

	void	deleteFix( node* x )
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
		delete nodeDel;
	}

	void	printKey( node *nodeKey, std::string name ) const
	{
		std::cout	<< name << " = ";
		if (nodeKey == this->_nil_node)
			std::cout << "NULL";
		else
			std::cout << nodeKey->stock.first;
		std::cout << std::endl;
	}

	void	printNode( node *nodePrint, int i ) const
	{
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
