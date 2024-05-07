#include <deepstate/DeepState.hpp>
#include "restaurant.h"

using namespace deepstate;

TEST(Restaurant, AddAndDisplayItem) {
  // Create a Restaurant instance
  Restaurant restaurant;

  // Add an item to the menu with random details
  string itemName = DeepState_CStrUpToLen(10); // Generate a random item name
  double price = DeepState_Double(); // Generate a random price
  restaurant.addItem(itemName, price);

  // Display the menu
  restaurant.displayMenu();
}

TEST(Restaurant, PlaceOrder) {
  // Create a Restaurant instance
  Restaurant restaurant;

  // Generate random items to order
  vector<pair<string, int>> itemsOrdered;
  int numItems = DeepState_UIntInRange(1, 5); // Choose a random number of items to order
  for (int i = 0; i < numItems; ++i) {
    string itemName = DeepState_CStrUpToLen(10); // Generate a random item name
    int quantity = DeepState_UInt(); // Choose a random quantity for each item
    itemsOrdered.push_back(make_pair(itemName, quantity));
  }

  // Place the order
  double total = restaurant.placeOrder(itemsOrdered);

  // Display the bill breakup
  restaurant.displayBillBreakup(total, itemsOrdered);
}

TEST(Restaurant, RemoveItem) {
  // Create a Restaurant instance
  Restaurant restaurant;

  // Add an item to the menu first (to remove it later)
  string itemName = DeepState_CStrUpToLen(10); // Generate a random item name
  double price = DeepState_Double(); // Generate a random price
  restaurant.addItem(itemName, price);

  // Remove the added item
  restaurant.removeItem(itemName);

  // Display the menu after removal
  restaurant.displayMenu();
}

TEST(Restaurant, CalculateTotalAmount) {
  // Create a Restaurant instance
  Restaurant restaurant;

  // Add some random orders to calculate total amount
  vector<pair<string, int>> itemsOrdered;
  int numItems = DeepState_UIntInRange(1, 5); // Choose a random number of items to order
  for (int i = 0; i < numItems; ++i) {
    string itemName = DeepState_CStrUpToLen(10); // Generate a random item name
    int quantity = DeepState_UInt(); // Choose a random quantity for each item
    itemsOrdered.push_back(make_pair(itemName, quantity));
  }
  restaurant.placeOrder(itemsOrdered);

  // Calculate the total amount of all previous orders
  double totalAmount = restaurant.calculateTotalAmount();

  LOG(TRACE) << "Total Amount: " << totalAmount;

  // Make an assertion to ensure the total amount is non-negative
  ASSERT_GE(totalAmount, 0.0);
}

TEST(Restaurant, CalculateTotalWithTip) {
  // Create a Restaurant instance
  Restaurant restaurant;

  // Generate a random tip percentage
  double tipPercentage = DeepState_DoubleInRange(0.0, 30.0); // Tip percentage range: 0% to 30%

  // Calculate total amount with tip
  double totalWithTip = restaurant.calculateTotalWithTip(tipPercentage);

  LOG(TRACE) << "Total Amount with Tip (" << tipPercentage << "%): " << totalWithTip;

  // Make an assertion to ensure the total amount with tip is non-negative
  ASSERT_GE(totalWithTip, 0.0);
}

TEST(Restaurant, DisplayPreviousOrders) {
  // Create a Restaurant instance
  Restaurant restaurant;

  // Display previous orders
  restaurant.displayPreviousOrders();
}

TEST(Restaurant, SetAndDisplayTimings) {
  // Create a Restaurant instance
  Restaurant restaurant;

  // Set restaurant timings
  string openingTime = "09:00 AM";
  string closingTime = "10:00 PM";
  restaurant.setRestaurantTimings(openingTime, closingTime);

  // Display restaurant timings
  restaurant.displayRestaurantTimings();
}

TEST(Restaurant, LeaveFeedback) {
  // Create a Restaurant instance
  Restaurant restaurant;

  // Leave feedback
  string feedback = "The food was delicious!";
  restaurant.leaveFeedback(feedback);
}
