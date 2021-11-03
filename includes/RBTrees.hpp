/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTrees.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:07:59 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/03 18:40:39 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREES_HPP
# define RBTREES_HPP

#include <iostream>

#define	BLACK	0
#define	RED		1


namespace ft
{

template<class Key, class Value>
class RbTrees
{

private:

	typedef struct	s_node
	{
		struct s_node*	parent;
		struct s_node*	left;
		struct s_node*	right;
		int				color;
		Key				key;
		Value			value;
	}				node;

	node	*_root;
	node	*_null_node;

public:

	RbTrees( void )
	{
		this->_null_node = new node;
		this->_null_node->parent = NULL;
		this->_null_node->left = NULL;
		this->_null_node->right = NULL;
		this->_null_node->color = BLACK;
		this->_null_node->key = 0;
		this->_null_node->value = 0;

		this->_root = this->_null_node;
	}

	~RbTrees( void )
	{
		delete this->_null_node;
	}

	void	deleteNode(Key srh)
	{
		node *toDel = this->searchNode(srh);

		/* TODO del that shit */

	}

	void	printTree( void ) const
	{
		int	i = 0;
		std::cout << std::endl;
		this->printAllNode( this->_root , i );
	}

	void	insertNode( Key key, Value val )
	{
		node *ins = newNode(key, val);
		node *y = this->_null_node;
		node *nav = this->_root;

		while (nav != this->_null_node)
		{
			y = nav;

			if (key >= nav->key)
			{
				std::cout << "right" << std::endl;
				nav = nav->right;
			}
			else
			{
				std::cout << "left" << std::endl;
				nav = nav->left;
			}
		}

		ins->parent = y;

		if (y == this->_null_node)
			this->_root = ins;
		else if (key < y->key)
			y->left = ins;
		else
			y->right = ins;
		this->insertFix(ins);
	}

	node	*searchNode( Key search )
	{
		node *nav = this->_root;

		while (nav != this->_null_node)
		{
			if (search > nav->key)
				nav = nav->right;
			else if (search < nav->key)
				nav = nav->left;
			else if (search == nav->key)
			{
				std::cout << "find" << std::endl;
				return (nav);
			}
		}
		std::cout << "not found" << std::endl;
		return (this->_null_node);
	}


private:

	node	*newNode( Key key, Value val )
	{
		node	*ret = new node;

		ret->parent = this->_null_node;
		ret->left = this->_null_node;
		ret->right = this->_null_node;
		ret->color = RED;
		ret->key = key;
		ret->value = val;
		return (ret);
	}

	void	leftRotate( node *x )
	{
		node	*y_right = x->right;

		x->right = y_right->left;
		if (y_right->left != this->_null_node)
			y_right->left->parent = x;
		y_right->parent = x->parent;
		if (x->parent == this->_null_node)
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
		if (y_left->right != this->_null_node)
			y_left->right->parent = x;
		y_left->parent = x->parent;
		if (x->parent == this->_null_node)
			this->_root = y_left;
		else if (x == x->parent->right)
			x->parent->right = y_left;
		else
			x->parent->left = y_left;
		y_left->right = x;
		x->parent = y_left;
	}

	/* side: true=left / false=right  */
	void	insertSide( node* insert, bool side )
	{
		node *k = (side ? insert->parent->parent->left
						: insert->parent->parent->right);
		if (k->color == RED)
		{
			k->color = BLACK;
			insert->parent->color = BLACK;
			insert->parent->parent->color = RED;
			insert = insert->parent->parent;
		}
		else if ((insert == insert->parent->right && !side)
			|| (insert == insert->parent->left && side))
		{
			insert = insert->parent;
			(side ? this->rightRotate(insert)
				: this->leftRotate(insert));
		}
		else
		{
			insert->parent->color = BLACK;
			insert->parent->parent->color = RED;
			(side ? this->leftRotate(insert->parent->parent)
				: this->rightRotate(insert->parent->parent));
		}
	}

	void	insertFix( node* insert )
	{
		while (insert->parent->color == RED)
		{
			if (insert->parent == insert->parent->parent->left)
				this->insertSide(insert, false);
			else
				this->insertSide(insert, true);
		}
		this->_root->color = BLACK;
	}

	void	printKey( node *nodeKey, std::string name ) const
	{
		std::cout	<< name << " = ";
		if (nodeKey == this->_null_node)
			std::cout << "NULL";
		else
			std::cout << nodeKey->key;
		std::cout << std::endl;
	}

	void	printNode( node *nodePrint, int i ) const
	{
		std::cout << "node " << i
			<< (nodePrint->color == RED
				? " [RED] "
				: " [BLACK] ")
			<< (nodePrint->parent == this->_null_node
				? "(root) "
				: "") << ":" << std::endl;

		std::cout << "key    = " << nodePrint->key << std::endl;
		this->printKey(nodePrint->parent, "parent");
		this->printKey(nodePrint->left, "left  ");
		this->printKey(nodePrint->right, "right ");
		std::cout << "-------------------" << std::endl;
		std::cout << std::endl;

	}

	void	printAllNode( node *nodePrint , int & i ) const
	{
		if (this->_root == this->_null_node)
		{
			std::cout << "(empty)" << std::endl;
			return ;
		}
		if ( nodePrint == this->_null_node )
			return ;
		i++;
		this->printNode(nodePrint, i);
		this->printAllNode(nodePrint->left, i);
		this->printAllNode(nodePrint->right, i);
	}

};

}

#endif
