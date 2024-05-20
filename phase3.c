#include <stdio.h>
#include <stdlib.h>
#include "billing_functions.h"

// Defining the Customer structure
struct Customer {
    char name[100];
    int cust_id;
    long long int ph;
};

// Global arrays for items, prices, and stock
char items[][15] = {"Rice(kg)", "Dal(kg)", "Vanilla Ice(1L)", "Chocolate Ice(1L)", "Strawberry Ice(1L)", "Mango Ice(1L)", "Butter Scotch(1L)", "Kulfi(1L)", "Pista Ice(1L)", "Coffee Ice(1L)"};
int price[10] = {50, 70, 100, 120, 110, 130, 140, 150, 160, 170};
int stock[10] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
int teststock[10] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};

// Function to write customer data to a file
void write_customer_data(struct Customer *customer_ptr) {
    FILE *fp;
    fp = fopen("customer_data.txt", "a");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(fp, "%s %d %lld\n", customer_ptr->name, customer_ptr->cust_id, customer_ptr->ph);
    fclose(fp);
}

// Function to read and display customer data from the file
void read_customer_data() {
    FILE *fp;
    char name[100];
    int cust_id;
    long long int ph;

    fp = fopen("customer_data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    printf("\nCustomer Data:\n");
    while (fscanf(fp, "%s %d %lld", name, &cust_id, &ph) != EOF) {
        printf("Name: %s, ID: %d, Phone: %lld\n", name, cust_id, ph);
    }
    fclose(fp);
}

// Function to search for a customer by ID
void search_customer_by_id(int search_id) {
    FILE *fp;
    char name[100];
    long long int ph;
    int cust_id;
    int found = 0;

    fp = fopen("customer_data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    while (fscanf(fp, "%s %d %lld", name, &cust_id, &ph) != EOF) {
        if (cust_id == search_id) {
            printf("Customer found:\n");
            printf("Name: %s\tID: %d\tPhone: %lld\n", name, cust_id, ph);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Customer not found.\n");
    }
    fclose(fp);
}

// Function to get user data and write it to file
void get_userdata(struct Customer *customer_ptr) {
    printf("\nEnter your name: ");
    scanf(" %[^\n]%*c", customer_ptr->name);
    printf("Enter customer ID: ");
    scanf("%d", &customer_ptr->cust_id);
    printf("Enter phone number: ");
    scanf("%lld", &customer_ptr->ph);
    printf("-------------------------\n");
    write_customer_data(customer_ptr);
    display_data(customer_ptr);
}

// Function to display user data and confirm it
void display_data(struct Customer *customer_ptr) {
    int i = 2;
    printf("\nYour name: %s", customer_ptr->name);
    printf("Your customer ID: %d", customer_ptr->cust_id);
    printf("Your phone number: %lld\n", customer_ptr->ph);
    printf("Confirm with 1 if the data is correct else press 0\n");
    scanf("%d", &i);

    if (i == 1) {
        display_items();
    } else if (i == 0) {
        printf("-------Re-enter your data------\n");
        get_userdata(customer_ptr);
    }
}

// Function to display items, their stock, and prices
void display_items() {
    printf("\033[0m"); 
    printf("\n************\n");
    printf("|ITEMS|   \t|STOCK| |PRICE|\n");
    for(int i = 0; i < 10; i++) {
        printf("%d %s  \t:%d  \t %d\n",(i+1),items[i],stock[i],price[i]);
    }
    printf("Press 0 to exit\n");
    printf("************\n");
    get_input();
}

// Function to handle user input for purchasing items
void get_input() {
    int qty = 0;
    int choice = 0;
    int i = 1;
    double sum = 0;
    double indsum = 0;
    while(i == 1) {
        printf("\n-------------------------------\n");
        printf("---------Enter-choice----------\n");
        printf("-------------------------------\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter the quantity required for Rice: ");
                scanf("%d",&qty);
                if(qty > stock[0]) {
                    printf("OUT OF STOCK");
                    break;
                }
                indsum = price[0]*qty;
                printf("Price of item for %d Quantities: %lf\n",qty,indsum);
                sum += indsum;
                printf("Total cart Sum: %lf\n",sum);
                stock[0] -= qty;
                break;
            case 2:
                printf("Enter the quantity required for Dal: ");
                scanf("%d",&qty);
                if(qty > stock[1]) {
                    printf("OUT OF STOCK");
                    break;
                }
                indsum = price[1]*qty;
                printf("Price of item for %d Quantities: %lf\n",qty,indsum);
                sum += indsum;
                printf("Total cart Sum: %lf\n",sum);
                stock[1] -= qty;
                break;
            case 3:
                printf("Enter the quantity required for Vanilla Ice: ");
                scanf("%d",&qty);
                if(qty > stock[2]) {
                    printf("OUT OF STOCK");
                    break;
                }
                indsum = price[2]*qty;
                printf("Price of item for %d Quantities: %lf\n",qty,indsum);
                sum += indsum;
                printf("Total cart Sum: %lf\n",sum);
                stock[2] -= qty;
                break;
            case 4:
                printf("Enter the quantity required for Chocolate Ice: ");
                scanf("%d",&qty);
                if(qty > stock[3]) {
                    printf("OUT OF STOCK");
                    break;
                }
                indsum = price[3]*qty;
                printf("Price of item for %d Quantities: %lf\n",qty,indsum);
                sum += indsum;
                printf("Total cart Sum: %lf\n",sum);
                stock[3] -= qty;
                break;
            case 5:
                printf("Enter the quantity required for Strawberry Ice: ");
                scanf("%d",&qty);
                if(qty > stock[4]) {
                    printf("OUT OF STOCK");
                    break;
                }
                indsum = price[4]*qty;
                printf("Price of item for %d Quantities: %lf\n",qty,indsum);
                sum += indsum;
                printf("Total cart Sum: %lf\n",sum);
                stock[4] -= qty;
                break;
            case 6:
                printf("Enter the quantity required for Mango Ice: ");
                scanf("%d",&qty);
                if(qty > stock[5]) {
                    printf("OUT OF STOCK");
                    break;
                }
                indsum = price[5]*qty;
                printf("Price of item for %d Quantities: %lf\n",qty,indsum);
                sum += indsum;
                printf("Total cart Sum: %lf\n",sum);
                stock[5] -= qty;
                break;
            case 7:
                printf("Enter the quantity required for Butter Scotch: ");
                scanf("%d",&qty);
                if(qty > stock[6]) {
                    printf("OUT OF STOCK");
                    break;
                }
                indsum = price[6]*qty;
                printf("Price of item for %d Quantities: %lf\n",qty,indsum);
                sum += indsum;
                printf("Total cart Sum: %lf\n",sum);
                stock[6] -= qty;
                break;
            case 8:
                printf("Enter the quantity required for Kulfi: ");
                scanf("%d",&qty);
                if(qty > stock[7]) {
                    printf("OUT OF STOCK");
                    break;
                }
                indsum = price[7]*qty;
                printf("Price of item for %d Quantities: %lf\n",qty,indsum);
                sum += indsum;
                printf("Total cart Sum: %lf\n",sum);
                stock[7] -= qty;
                break;
            case 9:
                printf("Enter the quantity required for Pista Ice: ");
                scanf("%d",&qty);
                if(qty > stock[8]) {
                    printf("OUT OF STOCK");
                    break;
                }
                indsum = price[8]*qty;
                printf("Price of item for %d Quantities: %lf\n",qty,indsum);
                sum += indsum;
                printf("Total cart Sum: %lf\n",sum);
                stock[8] -= qty;
                break;
            case 10:
                printf("Enter the quantity required for Coffee Ice: ");
                scanf("%d",&qty);
                if(qty > stock[9]) {
                    printf("OUT OF STOCK");
                    break;
                }
                indsum = price[9]*qty;
                printf("Price of item for %d Quantities: %lf\n",qty,indsum);
                sum += indsum;
                printf("Total cart Sum: %lf\n",sum);
                stock[9] -= qty;
                break;
            case 0:
                i = 0;
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
}

int main() {
    struct Customer customer;
    int choice;
    printf("Welcome to the billing system!\n");
    while (1) {
        printf("1. Enter new customer data\n");
        printf("2. Read customer data\n");
        printf("3. Search customer by ID\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                get_userdata(&customer);
                break;
            case 2:
                read_customer_data();
                break;
            case 3:
                printf("Enter customer ID to search: ");
                int search_id;
                scanf("%d", &search_id);
                search_customer_by_id(search_id);
                break;
            case 0:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
