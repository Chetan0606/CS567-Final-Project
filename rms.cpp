#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include "restaurant.h"

using namespace std;

Restaurant::Restaurant() 
{
    menu = {
        {"Burger", 5.99},
        {"Pizza", 8.99},
        {"Salad", 4.99},
        {"Pasta", 7.99},
        {"Pastry", 5.99},
        {"Cookies", 2.99},
        {"Shakes", 6.99},
        {"Coke", 3.99},
        {"Pepsi", 3.99}
    };
}

Restaurant::Restaurant(const std::string& opening, const std::string& closing) 
{
    menu = {
        {"Burger", 5.99},
        {"Pizza", 8.99},
        {"Salad", 4.99},
        {"Pasta", 7.99},
        {"Pastry", 5.99},
        {"Cookies", 2.99},
        {"Shakes", 6.99},
        {"Coke", 3.99},
        {"Pepsi", 3.99}
    };
    openingTime = opening;
    closingTime = closing;
}

void Restaurant::setRestaurantTimings(const string& opening, const string& closing) 
{
    openingTime = opening;
    closingTime = closing;
}

void Restaurant::displayRestaurantTimings() const 
{
    cout << "Restaurant Timings:\n";
    cout << "Opening Time: " << openingTime << endl;
    cout << "Closing Time: " << closingTime << endl;
}

void Restaurant::displayMenu() const 
{
    cout << "Menu:\n";
    cout << setw(20) << left << "Name" << setw(10) << right << "Price" << endl;
    cout << string(30, '-') << endl;
    for (const auto& item : menu) 
    {
        cout << setw(20) << left << item.name << setw(10) << right << item.price << endl;
    }
}

void Restaurant::addItem(const string& itemName, double price) 
{
    MenuItem newItem = {itemName, price};
    menu.push_back(newItem);
    cout << "Item added to the menu.\n";
}

void Restaurant::removeItem(const string& itemName) 
{
    auto it = remove_if(menu.begin(), menu.end(), [&](const MenuItem& item) 
    {
        return item.name == itemName;
    });
    if (it != menu.end()) 
    {
        menu.erase(it, menu.end());
        cout << "Item removed from the menu.\n";
    } else 
    {
        cout << "Item not found in the menu.\n";
    }
}

double Restaurant::placeOrder(const vector<pair<string, int>>& itemsOrdered) 
{
    double total = 0;
    int numPeople = 0;
    time_t now = time(0); // Get the current time

    for (const auto& item : itemsOrdered) 
    {
        for (const auto& menuItem : menu) 
        {
            if (menuItem.name == item.first) 
            {
                total += menuItem.price * item.second;
                numPeople += item.second;
                break;
            }
        }
    }
    if (numPeople > 5) 
    {
        total += total * 0.18;
    }
    double tax = total * 0.05;
    total += tax;

    // Create an Order object and add it to the orders vector
    Order newOrder;
    newOrder.itemName = "Order"; // Placeholder name for the order
    newOrder.quantity = itemsOrdered.size(); // Number of items ordered
    newOrder.totalPrice = total;
    newOrder.timestamp = now;
    orders.push_back(newOrder);

    return total;
}


void Restaurant::displayBillBreakup(double total, const vector<pair<string, int>>& itemsOrdered) const 
{
    cout << "Bill Breakup:\n";
    cout << setw(20) << left << "Item" << setw(10) << "Quantity" << setw(10) << "Price" << setw(10) << "Total" << endl;
    cout << string(50, '-') << endl;
    for (const auto& item : itemsOrdered) 
    {
        double itemPrice = 0;
        for (const auto& menuItem : menu) 
        {
            if (menuItem.name == item.first) 
            {
                itemPrice = menuItem.price;
                break;
            }
        }
        double itemTotal = itemPrice * item.second;
        cout << setw(20) << left << item.first << setw(10) << item.second << setw(10) << itemPrice << setw(10) << itemTotal << endl;
    }
    double tax = total * 0.05;
    cout << setw(40) << right << "Tax (5%): $" << setw(10) << fixed << setprecision(2) << tax << endl;
    if (itemsOrdered.size() > 5) {
        double gratuity = total * 0.18;
        cout << setw(40) << right << "Gratuity (18%): $" << setw(10) << fixed << setprecision(2) << gratuity << endl;
    }
    cout << setw(40) << right << "Total: $" << setw(10) << fixed << setprecision(2) << total << endl;
}


void Restaurant::generateReceipt(const Order& order) const 
{
    cout << "Receipt for Order at " << ctime(&order.timestamp);
    cout << "Item Name: " << order.itemName << endl;
    cout << "Quantity: " << order.quantity << endl;
    cout << "Total Price: $" << order.totalPrice << endl;
}

void Restaurant::leaveFeedback(const string& feedback) const 
{
    cout << "Thank you for your feedback:\n";
    cout << feedback << endl;
}

void Restaurant::displayPreviousOrders() const 
{
    cout << "Previous Orders:\n";
    if (orders.empty()) 
    {
        cout << "No previous orders.\n";
    } else {
        for (const auto& order : orders) 
        {
            generateReceipt(order);
            cout << endl;
        }
    }
}

double Restaurant::calculateTotalAmount() const 
{
    double total = 0;
    for (const auto& order : orders) 
    {
        total += order.totalPrice;
    }
    return total;
}

double Restaurant::calculateTotalWithTip(double tipPercentage) const 
{
    double totalAmount = calculateTotalAmount();
    double tipAmount = totalAmount * (tipPercentage / 100.0);
    return totalAmount + tipAmount;
}