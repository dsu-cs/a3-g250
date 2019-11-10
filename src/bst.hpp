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
    
    if( root == NULL)
    {
        return 0;
    }
    else
    {
        /*inorder(root->get_left());
        cout << root->get_data << " "; 
        inorder(root->get_right());*/
    }
    return vec;
}


template<class T>
 std::vector<T> * BST<T>::preorder()
{
    std::vector<T> *vec = new std::vector<T>;

     if( root == NULL)
    {
        return 0;
    }
    else
    {
        /*cout << root->get_data << " "; 
        preorder(root->get_left());
        preorder(root->get_right());*/
    }
    return vec;
}


template<class T>
 std::vector<T> * BST<T>::postorder()
{
    std::vector<T> *vec = new std::vector<T>;

     if( root == NULL)
    {
        return 0;
    }
    else
    {   
        /*postorder(root->get_left());
        postorder(root->get_right());
        vec = root->get_data << " "; */
    }
    

    return vec;
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
        
        if(tmp->get_data() > new_data)
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

    /*if(root == NULL)
        {
            return;
        }
        else if(root->get_data() > val)
        {
            root->set_left(remove(root->get_left(), val));
        }
        else if(root->get_data() < val)
        {
            root->set_right(remove(root->get_right(), val));
        }
        else
        {
            if(root->get_left() == NULL && root->get_right() == NULL)
            {
                delete root;
                root = NULL;
                
            }
            else if(root->get_left() == NULL)
            {
                Node<T> *tmp = root;
                root = root->get_right();
                delete tmp;
                

            }
            else if(root->get_right() == NULL)
            {
                Node<T> *tmp2 = root;
                root = root->get_left();
                delete tmp;
                

            }
            else
            {
                Node<T> *tmp3 = findmin(root->get_right());
                root = tmp3;
                root->set_right(remove(root->get_right(), tmp3->get_data()));
            }
            } 

*/




}
/*template<class T>
Node<T> *BST<T>::findmin(Node<T>* node)
{
    node = root;
   if (root == NULL) {
        return NULL;
   }
   else if (node->get_left() != NULL) {
        return FindMin(node->get_left());
   }
   else
   {
       return node->get_data();
   }
   
}*/


template<class T>
int BST<T>::get_size()
{
     if(root == NULL)
    {
        return 0;
    }
    else
    {
        //int i = get_size(root->get_left();
       // int x = get_size(root->get_right();
//int k = x + i + 1;
       // return k;
    }
    
}