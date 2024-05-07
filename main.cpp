#include "restaurant.h"
#include "rms.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Create a Restaurant instance
    Restaurant restaurant("09:00 AM", "10:00 PM");

    // Display the menu
    cout << "Displaying Menu:\n";
    restaurant.displayMenu();
    cout << endl;

    // Add an item to the menu
    cout << "Adding an item to the menu\n";
    restaurant.addItem("Sandwich", 6.99);
    cout << endl;

    // Display the menu after addition
    cout << "Displaying Menu after addition:\n";
    restaurant.displayMenu();
    cout << endl;

    // Remove an item from the menu
    cout << "Removing an item from the menu:\n";
    restaurant.removeItem("Salad");
    cout << endl;

    // Display the menu after removal
    cout << "Displaying Menu after removal:\n";
    restaurant.displayMenu();
    cout << endl;

    // Place an order
    cout << "Placing an order:\n";
    vector<pair<string, int>> itemsOrdered = {{"Burger", 2}, {"Pizza", 1}};
    double total = restaurant.placeOrder(itemsOrdered);
    cout << "Total amount for the order: $" << total << endl;
    cout << endl;

    // Display the bill breakup
    cout << "Displaying Bill Breakup:\n";
    restaurant.displayBillBreakup(total, itemsOrdered);
    cout << endl;

    // Display previous orders
    cout << "Displaying Previous Orders:\n";
    restaurant.displayPreviousOrders();
    cout << endl;

    // Calculate total amount
    cout << "Calculating Total Amount of all orders:\n";
    double totalAmount = restaurant.calculateTotalAmount();
    cout << "Total amount of all orders: $" << totalAmount << endl;
    cout << endl;

    // Calculate total amount with tip
    double tipPercentage = 15.0;
    cout << "Calculating Total Amount with Tip (" << tipPercentage << "%):\n";
    double totalWithTip = restaurant.calculateTotalWithTip(tipPercentage);
    cout << "Total amount with " << tipPercentage << "% tip: $" << totalWithTip << endl;
    cout << endl;

    // Leave feedback
    cout << "Leaving Feedback:\n";
    string feedback = "The service was excellent!";
    restaurant.leaveFeedback(feedback);
    cout << endl;

    return 0;
}
