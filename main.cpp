//
//  main.cpp
//  Homework 1
//
//  Created by Jose Muniz.
//  Copyright © 2018 Jose Muniz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <iomanip>
#include "groceryItemNode.h"
#include "ArgumentManager.h"
#include "groceryItemList.hpp"
#include "groceryItem.hpp"
using namespace std;

int main(int argc, char * argv[]) {
    
    ArgumentManager am(argc, argv);
    string infilename = am.get("A");
    string outfilename = am.get("C");
    
    ifstream inFile(infilename);
    ofstream ofs(outfilename);
    groceryItemList *newList = new groceryItemList;
    char comma = ',';
    string first;
    string name;
    double price;
    double maxBudget;
    
    
    if (!inFile) { //Check if the file can be opened
        ofs << "Unable to open file" << endl;;
        exit(1);
    }
    
    //Save first line in the list in first
    //inFile >> first;
    string line;
    getline(inFile, line);
    
    
    if (!isdigit(line[0])) { //Check if the first thing in the list is a number
        ofs << "";
        exit(1);
    }
    else { //Set the maxBudget for the groceery list
        try{
            maxBudget = stod(line);
        }
        catch(...){
            ofs << "";
            exit(1);
        }
        newList->setMaxBudget(maxBudget);
    }

    while (inFile) { //Keep reading from file and creating items if price > 0
        getline(inFile, line);
        int index = line.find(',');
        if(index < 1){
            continue;
        }
        name = line.substr(0, index);
        index++;
        if(line[index] == ' '){
            index++;
        }
        first = line.substr(index);
        try{
            price = stod(first);
            if(price < 0){
                continue;
            }
        }
        catch(...){
            continue;
        }
        groceryItem newItem(name, price);
        newList->insert(newItem);
        
    }
    //Set the last node at the end
    newList->setLast();
    //Check that we have enough to purchase the cheapest thing
    newList->checkLowest(ofs);
    //Check that we are under budget or delete highest node until we are
    newList->checkBudget(ofs);
    //Print the list
    newList->print(ofs);
    
    ofs.close();
}
