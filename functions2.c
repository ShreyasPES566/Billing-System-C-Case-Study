#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

// Function to display all the products owned by the store
void displayProducts(Item *items, int numItems) {
    printf("\nProducts available:\n");
    printf("Items\t\t\tUnit\t\t\tPrice\n");
    printf("--------------------------------------------\n");
    
    for (int i = 0; i < numItems; i++) {
        printf("%-20s%-20s%.2f\n", items[i].name, items[i].unit, items[i].price);
    }
    
    printf("--------------------------------------------\n");
}

// Function to calculate and print the bill for a customer
void printBill(Customer customer, Item *items, int numItems) {
    float totalCost = 0;
    
    printf("\nCustomer Name: %s\n", customer.name);
    printf("Mobile Number: %s\n", customer.mobileNumber);
    printf("\nItems\t\t\tQuantity\t\tPrice\n");
    printf("--------------------------------------------\n");
    
    for (int i = 0; i < numItems; i++) {
        if (customer.quantities[i] > 0) {
            printf("%-20s%-20d%.2f\n", items[i].name, customer.quantities[i], items[i].price);
            totalCost += items[i].price * customer.quantities[i];
        }
    }

    float gst = totalCost * GST_RATE;
    float totalCostWithGST = totalCost + gst;
    
    printf("--------------------------------------------\n");
    printf("Total Cost (Excluding GST): %.2f\n", totalCost);
    printf("GST (18%%): %.2f\n", gst);
    printf("Total Cost (Including GST): %.2f\n", totalCostWithGST);
}

// Function to find the index of an item in the array based on its name
int findItemIndex(Item *items, int numItems, const char *itemName) {
    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            return i;
        }
    }
    return -1; // Item not found
}
