#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include "node.hpp"

template<class T>
class BST{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);
    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);
    
private:
    // the root node of the tree
    Node<T> *root;
    // the number of nodes in the tree
    int node_count;
    
    Node<T>*inserthelper(T, Node<T> *node);
    Node<T>*searchhelper(T, Node<T>* node);
    Node<T>*removehelper(T, Node<T>* node);
    int sizehelper(Node<T>* node);
    std::vector<T> *inorderhelper(Node<T>* node, std::vector<T> *vec);
    std::vector<T> *preorderhelper(Node<T>* node, std::vector<T> *vec);
    std::vector<T> *postorderhelper(Node<T>* node, std::vector<T> *vec);
    //Node<T>*findmin(Node<T>* node);
};

template<class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}

template<class T>
BST<T>::~BST()
{
    root = NULL;
    while(root != NULL)
    {
        remove(root->get_data());
    }
}

template<class T>
  std::vector<T> * BST<T>::inorder()
{
    std::vector<T> *vec = new std::vector<T>;

    vec = inorderhelper(root, vec);
    
    return vec;
}
template<class T>
  std::vector<T> * BST<T>::inorderhelper(Node<T>* node, std::vector<T> *vec)
{
    
    if( node == NULL)
    {
        return NULL; 
    }
    else
    {
        
        inorderhelper(node->get_left(), vec);

        vec->push_back(node->get_data());

        inorderhelper(node->get_right(), vec);
    
    return vec;
    }
}

template<class T>
 std::vector<T> * BST<T>::preorder()
{
    std::vector<T> *vec = new std::vector<T>;

    vec = preorderhelper(root, vec);

    return vec;
}

template<class T>
  std::vector<T> * BST<T>::preorderhelper(Node<T>* node, std::vector<T> *vec)
{
    
    if( node == NULL)
    {
        return NULL; 
    }
    else
    {
        vec->push_back(node->get_data());

        preorderhelper(node->get_left(), vec);

        preorderhelper(node->get_right(), vec);
    
    return vec;
    }
}

template<class T>
 std::vector<T> * BST<T>::postorder()
{
    std::vector<T> *vec = new std::vector<T>;

    vec = postorderhelper(root, vec);

    return vec;
}

template<class T>
  std::vector<T> * BST<T>::postorderhelper(Node<T>* node, std::vector<T> *vec)
{
    
    if( node == NULL)
    {
        return NULL; 
    }
    else
    {
        

        postorderhelper(node->get_left(), vec);
        
        postorderhelper(node->get_right(), vec);

        vec->push_back(node->get_data());

    return vec;
    }
}

template<class T>
void BST<T>::insert(T new_data)
{
    root = inserthelper(new_data, root);    
}

template<class T>
Node<T> *BST<T>::inserthelper(T new_data, Node<T>* node)
{
    Node<T> *tmp = new Node<T>;
    

    if(node == NULL)
    {
        tmp->set_data(new_data);
        tmp->set_left(NULL);
        tmp->set_right(NULL);
        return tmp;
    }
    else 
    {
        
        if(node->get_data() > new_data)
        {
            node->set_left(inserthelper( new_data, node->get_left()));
        }
        else
        {
            node->set_right(inserthelper( new_data, node->get_right()));
        }
    }
    
}

template<class T>
Node<T> *BST<T>::search(T val)
{
    root = searchhelper(val, root);
    return root;
}

template<class T>
Node<T> *BST<T>::searchhelper(T val, Node<T>* node)
{    
    if(node == NULL)
    {
        return NULL;
    }
    else if(node->get_data() == val)
    {
        return node;
    }
    else
    {
        if(node->get_data() > val)
        {
            return searchhelper(val, node->get_left());
        }
        else
        {
            return searchhelper(val, node->get_right());
        } 
    }
}


template<class T>
void BST<T>::remove(T val)
{
    root = removehelper(val, root);
}

template<class T>
Node<T> *BST<T>::removehelper(T val, Node<T>* node)
{
    
    Node<T> *tmp1;

    if(node == NULL)
    {
        return NULL;
    }
    else if(node->get_data() > val)
    {
        node->set_left(removehelper(val, node->get_left()));
    }
    else if(node->get_data() < val)
    {
        node->set_right(removehelper(val, node->get_right()));
    }
    else
    {
        if(node->get_left() == NULL && node->get_right() == NULL)
        {
            delete node;
            node = NULL;
            
        }
        else if(node->get_left() == NULL)
        {
            Node<T> *tmp = node;
            node = node->get_right();
            delete tmp;
            

        }
        else if(node->get_right() == NULL)
        {
            Node<T> *tmp = node;
            node = node->get_left();
            delete tmp;
            

        }
        else
        {
            //duplicates
            //node = tmp1;
           // node->set_right(removehelper(val, node->get_right()));
        }
        } 

    return node;

}

template<class T>
int BST<T>::get_size()
{
    return sizehelper(root);
}
template<class T>
int BST<T>::sizehelper(Node<T>* node)
{
    int i, k, x;
    
    if(node == NULL)
    {
        return 0;
    }
    else
    {
        x = sizehelper(node->get_left());
    
        k = sizehelper(node->get_right());

        i = x + k;

        return i + 1;

        
    }
}