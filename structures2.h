#ifndef STRUCTURES_H
#define STRUCTURES_H

#define MAX_ITEMS 11
#define MAX_NAME_LENGTH 50
#define MAX_MOBILE_LENGTH 15
#define GST_RATE 0.18 // 18% GST rate

// Define a structure to represent an item
typedef struct {
    char *name;
    char *unit;
    float price;
} Item;

// Define a structure to represent a customer
typedef struct {
    char name[MAX_NAME_LENGTH];
    char mobileNumber[MAX_MOBILE_LENGTH];
    Item *items[MAX_ITEMS];
    int quantities[MAX_ITEMS];
} Customer;

void displayProducts(Item *items, int numItems);
void printBill(Customer customer, Item *items, int numItems);
int findItemIndex(Item *items, int numItems, const char *itemName);

#endif
