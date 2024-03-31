#include <stdio.h>
#include <stdlib.h>
#include "customer.h"
#include "product.h"

#define MAX_PRODUCTS 10
#define GST_RATE 0.18 // 18% GST rate

int main() {
    Customer customer;
    storeCustomer(&customer);

    Product products[MAX_PRODUCTS] = {
        {1, "Bread", 25},
        {2, "Pasta (500g)", 40},
        {3, "Apples (1 kg)", 70},
        {4, "Chicken (1 kg)", 200},
        {5, "Fish (1 kg)", 150},
        {6, "Butter (100g)", 55},
        {7, "Cheese (250g)", 120},
        {8, "Coffee (250g)", 80},
        {9, "Tea (100g)", 50},
        {10, "Cereal (500g)", 60}
    };

    int numProducts;
    do {
        printf("Enter number of products required: ");
        scanf("%d", &numProducts);
        flushInputBuffer();
        if (numProducts <= 0 || numProducts > MAX_PRODUCTS) {
            printf("Invalid input. Please enter a positive integer less than or equal to %d.\n", MAX_PRODUCTS);
        }
    } while (numProducts <= 0 || numProducts > MAX_PRODUCTS);

    int *quantities = malloc(numProducts * sizeof(int));
    if (quantities == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    float total = enterItems(products, quantities, numProducts);
    printBill(&customer, products, quantities, numProducts, total);

    free(quantities);
    return 0;
}
