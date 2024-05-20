#include <stdio.h>
#include <stdlib.h>
#include "billing_functions.h"

int main() {
    printf("\033[32m");
    struct Customer *customer_ptr;
    customer_ptr = malloc(sizeof(struct Customer));
    if (customer_ptr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    get_userdata(customer_ptr);

    write_customer_data(customer_ptr);
    free(customer_ptr);
    int search_id;
    printf("Enter the customer ID to search: ");
    scanf("%d", &search_id);

    search_customer_by_id(search_id);

    return 0;
}
