//
//  groceryItemList.hpp
//  Homework 1
//
//  Created by Jose Muniz on 2/12/18.
//  Copyright © 2018 Jose Muniz. All rights reserved.
//

#ifndef groceryItemList_hpp
#define groceryItemList_hpp
#include <string>
#include <stdio.h>
#include "groceryItem.hpp"
#include "groceryItemNode.h"
using namespace std;

class groceryItemList{
public:
    void initializeList();
    bool isEmptyList() const;
    void setMaxBudget(double budget);
    void print(ostream &os) const;
    int length() const;
    void destroyList(ostream &os);
    groceryItem front() const;
    groceryItem back() const;
    bool search(const groceryItem& searchItem) const;
    void deleteNode(const groceryItem& deleteItem, ostream &os);
    void insert(groceryItem& newItem);
    void checkBudget(ostream &os);
    void deleteHighestNode(ostream &os);
    void setLast();
    void checkLowest(ostream &os);
    groceryItemList();
    ~groceryItemList();
    
protected:
    int count;
    double budget;
    double maxBudget;
    groceryItemNode *first;
    groceryItemNode *last;
    
};

#endif /* groceryItemList_hpp */
