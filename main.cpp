#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu() {
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' description" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl;
   
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
   if (option == 'o') {
    cout << "OUTPUT SHOPPING CART" << endl;
   }
   if (option == 'i') {
    cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
   }
   if (option == 'a') {
    cout << "ADD ITEM TO CART" << endl;
   }
   if (option == 'd') {
    cout << "REMOVE ITEM FROM CART" << endl;
   }
   if (option == 'c') {
    cout << "CHANGE ITEM QUANTITY" << endl;
   }
   
}

int main() {
   
   string name;
   string date;
   
   
   cout << "Enter customer's name:" << endl;
   getline(cin, name);
   
   cout << "Enter today's date:" << endl;
   getline(cin, date);
   cin.ignore();
   
   cout << endl;
   
   cout << "Customer name: " << name << endl;
   cout << "Today's date: " << date << endl;
   
   ShoppingCart cart1;
   cout << endl;
   
   PrintMenu();
   
   return 0;
}
