

#ifndef NODE__H
#define NODE__H
template <class NODE_TYPE, class EDGE_TYPE>
class Node;
#include "Edge.hpp"
#include <list>

template <class NODE_TYPE, class EDGE_TYPE>
class Node{
    private:
        int _id;
        NODE_TYPE attribute;
        //std::list<Edge<NODE_TYPE, EDGE_TYPE>* > edges;
    public:
        NODE_TYPE getAttribute();
        void setAttribute(NODE_TYPE attr);
        Node(NODE_TYPE attribute);

};


template <class NODE_TYPE, class EDGE_TYPE>
Node<NODE_TYPE, EDGE_TYPE>::Node(NODE_TYPE attribute):attribute(attribute){
}

template <class NODE_TYPE, class EDGE_TYPE>
NODE_TYPE Node<NODE_TYPE, EDGE_TYPE>::getAttribute(){
    return this->attribute;
}

template <class NODE_TYPE, class EDGE_TYPE>
void Node<NODE_TYPE, EDGE_TYPE>::setAttribute(NODE_TYPE attr){
    this->attribute = attr;
}





#endif
