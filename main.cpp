#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

#include "ShoppingCart.h"

void PrintMenu() {
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl;
   
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
    if (option == 'o') {
        cout << "OUTPUT SHOPPING CART" << endl;
        cout << theCart.GetCustomerName() << "'s Shopping Cart - " << theCart.GetDate() << endl;
        cout << "Number of Items: " << theCart.GetNumItemsInCart() << endl;
        cout << endl;
        theCart.PrintTotal();
        cout << endl;
        cout << "Total: $" << theCart.GetCostOfCart() << endl;
        cout << endl;
    }
    if (option == 'i') {
        cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
    }
    if (option == 'a') {
        int itemQuantity;
        string itemName, itemDescription;
        int itemPrice;

        cout << "ADD ITEM TO CART" << endl;
        cout << "Enter the item name:" << endl;
        cin.ignore(); 
        getline(cin, itemName);

        cout << "Enter the item description:" << endl;;
        getline(cin, itemDescription);

        cout << "Enter the item price:" << endl;;
        cin >> itemPrice;

        cout << "Enter the item quantity:" << endl;;
        cin >> itemQuantity;
        cout << endl;

        ItemToPurchase item;
        item.SetName(itemName);
        item.SetDescription(itemDescription);
        item.SetPrice(itemPrice);
        item.SetQuantity(itemQuantity);

        theCart.AddItem(item);  
    }
    if (option == 'd') {
        string name = "none";
        cout << "REMOVE ITEM FROM CART" << endl;
        cout << "Enter name of item to remove:" << endl;
        getline(cin, name);
        theCart.RemoveItem(name);
        
    }
    if (option == 'c') {
        cout << "CHANGE ITEM QUANTITY" << endl;
        
    }
}


int main() {
    string name, date;

    cout << "Enter customer's name:" << endl;
    getline(cin, name);

    cout << "Enter today's date:" << endl;
    getline(cin, date);
    
    cout << endl;
    cout << "Customer name: " << name << endl;
    cout << "Today's date: " << date << endl;
    cout << endl;

    ShoppingCart cart1(name, date);
    char option = '\0';
   PrintMenu();
   cout << endl;
   
   while (option != 'q') {
      cout << "Choose an option:" << endl;
      cin >> option;
      if (option == 'q') {
         break;
      }    else if (option == 'a' || option == 'd' || option == 'c' || option == 'i' || option == 'o') {
         ExecuteMenu(option, cart1);
         PrintMenu();
         cout<<endl;
      }
    // No need for an else statement to handle invalid inputs
   }



    return 0;
}

