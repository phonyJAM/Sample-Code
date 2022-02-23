//
//  groceryItemNode.h
//  Homework 1
//
//  Created by Jose Muniz on 2/14/18.
//  Copyright © 2018 Jose Muniz. All rights reserved.
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
