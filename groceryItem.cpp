//
//  groceryItem.cpp
//  Homework 1
//
//  Created by Jose Muniz on 2/14/18.
//  Copyright © 2018 Jose Muniz. All rights reserved.
//

#include <stdio.h>
#include <iomanip>
#include "groceryItem.hpp"
#include <iostream>
#include <string>
using namespace std;

groceryItem::groceryItem() {
    itemName = "";
    itemPrice = 0.0;
}

groceryItem::groceryItem(string name, double price){
    itemName = name;
    if (price >= 0.0) {
        itemPrice = price;
    }
    else itemPrice = 0.0;
}

string groceryItem::getName() const{
    return itemName;
}

double groceryItem::getPrice() const{
    return itemPrice;
}

void groceryItem::setName(string name){
    itemName = name;
}

void groceryItem::setPrice(double price){
    itemPrice = price;
}

void groceryItem::print(ostream &os) const{
    //Print out contents of the item to 2 decimal points
    os << itemName << ", " << fixed << setprecision(2) << itemPrice << endl;
}

groceryItem::~groceryItem() {
    itemName = "";
    itemPrice = 0.0;
}
