#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

int main() {
    Item items[MAX_ITEMS] = {{"Apple", "each", 2.50}, {"Banana", "each", 1.20}, {"Orange", "each", 1.80}, {"Milk", "liters", 3.50},
                             {"Bread", "loaf", 2.00}, {"Eggs", "dozen", 1.50}, {"Chicken", "kg", 5.00}, {"Rice", "kg", 10.00},
                             {"Vanilla Ice Cream", "scoop", 3.00}, {"Chocolate Ice Cream", "scoop", 3.50}, {"Strawberry Ice Cream", "scoop", 4.00}};
    
    int numItems = sizeof(items) / sizeof(items[0]);

    Customer customer;

    // Display all the products owned by the store
    displayProducts(items, numItems);
    
    // Input customer details
    printf("\nEnter your name: ");
    fgets(customer.name, sizeof(customer.name), stdin);
    customer.name[strcspn(customer.name, "\n")] = '\0'; // Remove newline character
    
    printf("Enter your mobile number: ");
    fgets(customer.mobileNumber, sizeof(customer.mobileNumber), stdin);
    customer.mobileNumber[strcspn(customer.mobileNumber, "\n")] = '\0'; // Remove newline character
    
    // Input items and quantities for the customer
    printf("\nEnter the quantities for each item:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s: ", items[i].name);
        int quantity;
        scanf("%d", &quantity);
        getchar(); // Consume newline character
        customer.quantities[i] = quantity;
    }

    // Print bill for the customer
    printBill(customer, items, numItems);

    return 0;
}
