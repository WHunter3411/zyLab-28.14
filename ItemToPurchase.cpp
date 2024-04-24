#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

    //Getters and Setters

    void ItemToPurchase::SetName(string itemName) {
        this->itemName = itemName;
    }
    
    string ItemToPurchase::GetName() const{
        return itemName;
    }

    void ItemToPurchase::SetPrice(int itemPrice) {
        this->itemPrice = itemPrice;
    }

    int ItemToPurchase::GetPrice() const{
        return itemPrice;
    }

    void ItemToPurchase::SetQuantity(int itemQuantity){
        this->itemQuantity = itemQuantity;
    }

    int ItemToPurchase::GetQuantity() const{
        return itemQuantity;
    }
    
    void ItemToPurchase::SetDescription(string itemDescription) {
       this->itemDescription = itemDescription;
    }
    
    string ItemToPurchase::GetDescription() const{
       return itemDescription;
       
    }
    
    void ItemToPurchase::PrintItemCost() {
       int totalPrice;
       totalPrice = GetQuantity() * GetPrice();
       cout << GetName() << " " << GetQuantity() << " @ $" << GetPrice() << " = $" << totalPrice << endl; 

    }
    
    void ItemToPurchase::PrintItemDescription() {
       cout << GetName() << ": " << GetDescription() << endl;

    }

    //Constructor

    ItemToPurchase::ItemToPurchase() {
        itemName = "none";
        itemPrice = 0;
        itemQuantity = 0;
        itemDescription = "none";
    }
    
   ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity) {
      itemName = name;
      itemDescription = description;
      itemPrice = price;
      itemQuantity = quantity;
}
