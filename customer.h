#ifndef CUSTOMER_H
#define CUSTOMER_H

typedef struct {
    int id;
    char name[50];
    char contact[20];
} Customer;

void storeCustomer(Customer *customer);

#endif /* CUSTOMER_H */
