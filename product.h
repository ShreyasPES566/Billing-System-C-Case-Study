#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct {
    int id;
    char name[50];
    float price;
} Product;

void flushInputBuffer();
float enterItems(const Product products[], int *quantities, int numProducts);
void printBill(const Customer *customer, const Product products[], const int *quantities, int numProducts, float total);

#endif /* PRODUCT_H */
