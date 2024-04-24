#include <iostream>
#include "ShoppingCart.h"

using namespace std;

unsigned i;

//Getters and Setters

string ShoppingCart::GetCustomerName() const{
   return customerName;
}

string ShoppingCart::GetDate() const {
   return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
   cartItems.push_back(item);
}

//Methods

void ShoppingCart::RemoveItem(string name) {
   for (i = 0; i < cartItems.size(); i++) {
      if (cartItems.at(i).GetName() == name) {
         cartItems.erase(cartItems.begin() + i);
         break;
      }
   }
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
    bool itemFound = false;
    for ( i = 0; i < cartItems.size(); i++) {
        if (cartItems.at(i).GetName() == item.GetName()) {
            itemFound = true;
            if (item.GetDescription() != "none") {
                cartItems.at(i).SetDescription(item.GetDescription());
            }
            if (item.GetPrice() != 0) {
                cartItems.at(i).SetPrice(item.GetPrice());
            }
            if (item.GetQuantity() != 0) {
                cartItems.at(i).SetQuantity(item.GetQuantity());
            }
            break;
        }
    }
    
    if (!itemFound) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

int ShoppingCart::GetNumItemsInCart() {
   int quantSum =0;
   for (i =0; i < cartItems.size(); i++) {
      quantSum = cartItems.at(i).GetQuantity() + quantSum;
   }
   return quantSum;
}

double ShoppingCart::GetCostOfCart() {
   double totalPrice = 0.0;
   double priceAndQuant = 0.0;
   for (i =0; i < cartItems.size(); i++) {
      priceAndQuant = cartItems.at(i).GetQuantity()*cartItems.at(i).GetPrice();
      totalPrice = totalPrice + priceAndQuant;
   }
   return totalPrice;
}

void ShoppingCart::PrintTotal() {
    if (cartItems.size() == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    } else {
        //int totalItems = GetNumItemsInCart();
        //cout << customerName << "'s Shopping Cart - " << currentDate << endl;
        //cout << "Number of Items: " << totalItems << endl << endl;

        double totalCost = 0;
        for (i = 0; i < cartItems.size(); i++) {
            cartItems.at(i).PrintItemCost();
            totalCost += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
        }

        //if (totalItems > 0) {
            //cout << "Total: $" << totalCost << endl;
        //}
    }
}

void ShoppingCart::PrintDescriptions() {
    if (cartItems.size() == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    } else {
        cout << "Item Descriptions:" << endl;
        for (i = 0; i < cartItems.size(); i++) {
            cout << cartItems.at(i).GetName() << ": " << cartItems.at(i).GetDescription() << endl;
        }
    }
}

//Constructors

ShoppingCart::ShoppingCart() {
   customerName = "none";
   currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date) {
 customerName = name;
 currentDate = date;
}
