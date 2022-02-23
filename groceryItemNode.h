//
//  groceryItemNode.h
//

#ifndef groceryItemNode_h
#define groceryItemNode_h
#include "groceryItem.hpp"

//Node for groceryList

struct groceryItemNode {
    groceryItem data;
    groceryItemNode *link;
};

#endif /* groceryItemNode_h */
