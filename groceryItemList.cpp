//
//  groceryItemList.cpp
//  Homework 1
//
//  Created by Jose Muniz on 2/12/18.
//  Copyright © 2018 Jose Muniz. All rights reserved.
//

#include "groceryItemList.hpp"
#include "groceryItem.hpp"
#include "groceryItemNode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <iomanip>
using namespace std;

void groceryItemList::initializeList(){
    count = 0;
    first = NULL;
    last = NULL;
    budget = 0.0;
    maxBudget = 0.0;
}

bool groceryItemList::isEmptyList() const{
    return (count == 0);
}

void groceryItemList::print(ostream &os) const{
    groceryItemNode *current = first;
    
    if(!isEmptyList()) {
        for(int i = 0; i <= count; i++) {  //Go through each item and call the print function
            if (current->link != NULL) {
                current->data.print(os);
                current = current->link;
            } else {
                current->data.print(os);
                break;
            }
        }
        os << endl;
        os << "Number of items: " << count << endl;
        os << "Cost: " << fixed << setprecision(2) << budget;
        
    }
    else{
     os << "" << endl;
        exit(1);
    }
}

int groceryItemList::length() const{
    return count;
}

void groceryItemList::destroyList(ostream &os){
    groceryItemNode *temp = new groceryItemNode;
    
    if (!isEmptyList()) { //Check to see that the list is not empty
        os << "" << endl;
        exit(1);
    }
    
    while (first != NULL) { //Continue to delete nodes until the list is empty
        temp = first;
        first = first->link;
        delete temp;
    }
    temp = NULL;
    last = NULL;
    count = 0;
    
}

groceryItem groceryItemList::front() const{
    assert(first != NULL); //Check that the list is not empty
    return first->data;
}

groceryItem groceryItemList::back() const{
    assert(last != NULL); //Check that the list is not empty
    return last->data;
}

bool groceryItemList::search(const groceryItem& searchItem) const{
    bool found = false;
    groceryItemNode *current = new groceryItemNode;
    
    while (first != NULL) { //Check that the list isn't empty
        current = first;
        while (current->link != NULL) { //Check that we are not at the end of the list
            if (current->data.getName() == searchItem.getName() && current->data.getPrice() == searchItem.getPrice()) {
                //Check if the two are equal
                found = true;
            }
            else current = current->link;
            //Move to the next node if they are not equal
        }
    }
    return found;
    current = NULL;
}

void groceryItemList::insert(groceryItem& newItem){
    groceryItemNode *current = new groceryItemNode; //pointer to traverse the list
    groceryItemNode *trailCurrent = new groceryItemNode; //pointer just before current
    groceryItemNode *newNode = new groceryItemNode; //pointer to create a node
    bool found;
    
    newNode->data = newItem; //store newItem in the node
    newNode->link = NULL; //set the link field of the node to NULL
    
    if (count == 0) //Insert node if list is empty
    {
        first = newNode;
        last = first;
        newNode->link = NULL;
        count++;
        budget += newItem.getPrice();
    }
    else
    {
        current = first;
        found = false;
        while (current != NULL && !found) //search the list for the item that it should go before alphabetically
            if (current->data.getName() >= newItem.getName()) {
                found = true;
            }
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        if (current == first) //Insert if the list is not empty but should go first
        {
            newNode->link = current;
            first = newNode;
            count++;
            budget = budget + newItem.getPrice();
        } else if (current != NULL){  //Insert the node at the end of the list
            trailCurrent->link = newNode;
            newNode->link = current;
            count++;
            budget = budget + newItem.getPrice();
        }
        else { //Insert the node anywhere in the middle of the list
            trailCurrent->link = newNode;
            newNode->link = NULL;
            budget += newItem.getPrice();
            count++;
        }
    }
    current = NULL;
    trailCurrent = NULL;
    newNode = NULL;
}
void groceryItemList::deleteNode(const groceryItem& deleteItem, ostream &os){
    groceryItemNode *current = new groceryItemNode; //pointer to traverse the list
    groceryItemNode *trailCurrent = new groceryItemNode; //pointer just before current
    bool found;
    
    if (first == NULL){
        os << "" << endl;
        exit(1);
    }
    else
    {
        current = first;
        found = false;
        while (current != NULL && !found) //search the list
            if (current->data.getName() >= deleteItem.getName())
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        if (current == NULL){ //If we reach the end of the list
            os << "" << endl;
            exit(1);
        }
        else
            if (current->data.getPrice() == deleteItem.getPrice() && current->data.getName() == deleteItem.getName())
                //the item to be deleted is in the list
            {
                if (first == current) //If we need to delete the first node
                {
                    first = first->link;
                    if (first == NULL)
                        last = NULL;
                    budget = budget - current->data.getPrice();
                    delete current;
                }
                else //Case 3
                {
                    trailCurrent->link = current->link;
                    if (current == last)
                        last = trailCurrent;
                    budget = budget - current->data.getPrice();
                    delete current;
                }
                count--;
            }
            else {//If the item is not in the list
                os << "" << endl;
                exit(1);
            }
    }
    current = NULL;
    trailCurrent = NULL;
}

groceryItemList::groceryItemList(){
    //Initiate all the values to zero
    count = 0;
    first = NULL;
    last = NULL;
    budget = 0.0;
    maxBudget = 0.0;
}

groceryItemList::~groceryItemList(){
    groceryItemNode *temp = new groceryItemNode;
    
    if (!isEmptyList()) { //Check to see that the list is not empty
        cout << "" << endl;
        exit(1);
    }
    
    while (first != NULL) { //Continue to delete nodes until the list is empty
        temp = first;
        first = first->link;
        delete temp;
    }
    last = NULL;
    count = 0;
    temp = NULL;
    
}

void groceryItemList::checkBudget(ostream &os) {
    if (count == 0) { //If we delete all the nodes and still not enough, print this
        os << endl;
        os << "Number of items: " << count;
        os << "Cost: " << budget;
        exit(1);
    }
    else { // Delete nodes until the budget is no longer larger than the maxBudget
        while (budget > maxBudget) {
            deleteHighestNode(os);
        }
    }
}

void groceryItemList::setMaxBudget(double budget) {
    maxBudget = budget;
}

void groceryItemList::deleteHighestNode(ostream &os) {
    groceryItemNode *trailCurrent = new groceryItemNode;
    
    if (!isEmptyList()) {
        groceryItemNode *highest = new groceryItemNode;
        groceryItemNode *current = new groceryItemNode;
        current = first;
        highest = first;
        double max = 0.0;
        
        for (int i = 0; i <= count; i++) { // Go through the list to find the highest priced item
            while (highest != NULL) {
                if (highest->data.getPrice() >= max) {
                    max = highest->data.getPrice();
                }
                else highest = highest->link;
            }
        }
        if (count == 1) { // Case for there only being one item
            budget = budget - current->data.getPrice();
            count--;
            first = NULL;
            last = NULL;
        }
        while (current->data.getPrice() != max) {  // Set current and trialCurrent around the highest for deleting purposes
            trailCurrent = current;
            current = current->link;
        }
        if (current->link == NULL) { //Case for the highest being the last item
            budget = budget - current->data.getPrice();
            last = trailCurrent;
            last->link = NULL;
            count--;
        }
        else if (current == first){ //Case for it being the first item
            first = current->link;
            budget = budget - current->data.getPrice();
            count--;
        }
        else { //Case for it being anywhere in the middle
            trailCurrent->link = current->link;
            budget = budget - current->data.getPrice();
            count--;
        }
    }
    else {
        os << "" << endl;
        exit(1);
    }
}

void groceryItemList::setLast() {
    //Go through the list and set the last pointer to the last node
    groceryItemNode *current = first;
    
    while (current->link != NULL) {
        current = current->link;
    }
    last = current;
}

void groceryItemList::checkLowest(ostream &os) {
    //Go through the list to find the lowest priced item and check that we have enough in the buddget to buy it
    groceryItemNode *highest = new groceryItemNode;
    double min = first->data.getPrice();
    highest = first;
    
    if (isEmptyList()) {
        os << "" << endl;
        exit(1);
    } else {
        for (int i = 0; i <= count; i++) {
            while (highest != NULL) {
                if (highest->data.getPrice() < min) {
                    min = highest->data.getPrice();
                }
                else highest = highest->link;
            }
        }
    }
    if (min > maxBudget) { //If we don't, print this
        os << endl;
        os << "Number of items: 0" << endl;
        os << "Cost: 0" << endl;
        exit(1);
    }
}
