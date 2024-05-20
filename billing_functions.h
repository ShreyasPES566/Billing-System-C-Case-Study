#ifndef BILLING_FUNCTIONS_H
#define BILLING_FUNCTIONS_H


struct Customer {
    int cust_id;
    long long int ph;
    char name[100];
};

void get_userdata(struct Customer *customer_ptr);
void display_data(struct Customer *customer_ptr);
void display_items();
void get_input();
void gen_bill(double sum);

#endif 