#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"
#include "customer.h"

void flushInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

float enterItems(const Product products[], int *quantities, int numProducts) {
    float total = 0;
    printf("Products:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d: %s - Rs%.2f\n", products[i].id, products[i].name, products[i].price);
        printf("Enter quantity for product %d: ", i + 1);
        scanf("%d", &quantities[i]);
        total += products[i].price * quantities[i];
        flushInputBuffer();
    }
    return total;
}

void printBill(const Customer *customer, const Product products[], const int *quantities, int numProducts, float total) {
    float gstAmount = total * GST_RATE;
    float totalWithGST = total + gstAmount;

    printf("\nCustomer Information:\n");
    printf("Name: %s\n", customer->name);
    printf("Contact: %s\n", customer->contact);
    printf("\nProducts Purchased:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s - Quantity: %d\n", products[i].name, quantities[i]);
    }
    printf("\nTotal Bill (Excluding GST): Rs%.2f\n", total);
    printf("GST Amount (18%%): Rs%.2f\n", gstAmount);
    printf("Total Bill (Including GST): Rs%.2f\n", totalWithGST);
}
