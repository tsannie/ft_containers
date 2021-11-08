/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:17:10 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/03 19:45:09 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STL_HPP
# define STL_HPP

#include <memory>
#include <cstddef>
#include <iostream>
#include "iterator.hpp"
#include "algorithm.hpp"
#include "utility.hpp"
#include "string.hpp"
#include "type_traits.hpp"
#include "../vector.hpp"
#include "RBTrees.hpp"

#define NOIR 0
#define ROUGE 1
#define FEUILLE NULL

struct noeud {
	struct noeud *gauche; //Pointeur vers fils gauche
	struct noeud *droit; //Pointeur vers fils droit
	struct noeud *parent; //Pointeur vers père
	int couleur; // ROUGE ou NOIR
	int clé; // Peut être n'importe quel type, tant que les opérations de comparaison (<, = , > ) sont définies
};

/* namespace ft
{
} */

#endif
