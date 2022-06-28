/******************************************************************************
For this project I have created a binary tree and made
functions for each search and return the value as a string een though each Node
will contain int values. The challenge of this is this 
project cannot have any stl containers such as stack
*******************************************************************************/
#include<string>

class BinTree{
    
    private:
        struct Node{ 
            int key; 
            Node *left, *right; 
            Node ( int nd ){ 
               key = nd; 
               left = right = NULL; 
            } 
        };
        Node* root = NULL;
        int size_support ( Node* node ){
            if ( !node ){
                return 0;
            }
            return size_support ( node -> left ) + size_support ( node -> right ) + 1;
        }
        int level_min ( Node* node ){
            if ( !node ){
                return 0;
            }
            return 1 + level_min ( node -> right );
        }
        bool insert_support ( Node* node, int data, int level, int current ){
            if ( current == level ){
                if ( !node -> left ){
                    node -> left = new Node ( data );
                    return 1;
                }
                if ( !node -> right ){
                    node -> right = new Node ( data );
                    return 1;
                }
              return 0;
            }
            if ( insert_support ( node -> left, data, level, current +1 ) ){
                return 1;
            }
            return insert_support ( node -> right, data, level, current +1 );
        }
        int leftmost_leaf_support ( Node* node ){
            if ( !node -> left ){
                return node -> key;
            }
            return leftmost_leaf_support ( node -> left );
        }
        int righttmost_leaf_support ( Node* node ){
            if ( !node -> right ){
                return node->key;
            }
            return righttmost_leaf_support ( node -> right );
        }
        void prefix_support ( Node* node,std::string &ans ){
            if ( !node ){
                return;
            }
            ans += std::to_string ( node -> key );
            prefix_support ( node -> left, ans );
            prefix_support ( node -> right, ans );
            return;
        }
        void postfix_support ( Node* node, std::string &ans ){
            if ( !node ){
                return;
            }
            postfix_support ( node -> left, ans );
            postfix_support ( node -> right, ans );
            ans += std::to_string ( node -> key );
            return;
        }
        void infix_support ( Node* node, std::string &ans ){
            if ( !node ){
                return;
            }
            infix_support ( node -> left, ans );
            ans += std::to_string ( node -> key );
            infix_support ( node -> right, ans );
            return;
        }
        void initiate_delete ( Node* node ){
            if ( !node ){
                return;
            }
            initiate_delete ( node -> left );
            initiate_delete ( node -> right );
            delete node;
            return;
        }
        
    public:
        BinTree() {}
        ~BinTree() {
        initiate_delete ( root );
        }
        int size(){
            return size_support ( root );
        }
        void insert ( int data ){
            if ( !root ){
              root = new Node ( data );
              return;
            }
            insert_support ( root, data, level_min ( root ), 1 );
            return;
        }
        int leftmost_leaf(){
            return leftmost_leaf_support ( root );
        }
        int righttmost_leaf(){
            return righttmost_leaf_support ( root );
        }
        std::string prefix(){
            std::string ans = "";
            prefix_support ( root, ans );
            return ans;
        }
        std::string postfix(){
            std::string ans = "";
            postfix_support ( root, ans );
            return ans;
        }
        std::string infix(){
            std::string ans = "";
            infix_support ( root, ans );
            return ans;
        }
};
