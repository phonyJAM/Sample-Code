//
//  groceryItem.hpp
//
//

#ifndef groceryItem_hpp
#define groceryItem_hpp
#include <string>
#include <iostream>
using namespace std;


class groceryItem{
    
public:
    groceryItem();
    groceryItem(string name, double price);
    string getName() const;
    double getPrice() const;
    void setName(string name);
    void setPrice(double price);
    void print(ostream &os) const;
    ~groceryItem();

    
private:
    string itemName;
    double itemPrice;
    
};



#endif /* groceryItem_hpp */
