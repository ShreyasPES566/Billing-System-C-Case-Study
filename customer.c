#include <stdio.h>
#include <string.h>
#include "customer.h"

void storeCustomer(Customer *customer) {
    printf("Enter your name: ");
    fgets(customer->name, sizeof(customer->name), stdin);
    customer->name[strcspn(customer->name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter phone number: ");
    fgets(customer->contact, sizeof(customer->contact), stdin);
    customer->contact[strcspn(customer->contact, "\n")] = '\0'; // Remove trailing newline
}
