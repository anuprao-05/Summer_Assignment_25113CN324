#include <stdio.h>
#include <string.h>

#define MAX 100

struct Item {
    int code;
    char name[50];
    int quantity;
    float price;
};

int main() {
    struct Item items[MAX];
    int n = 0;
    int choice, i, j, code, found, qty;
    float newPrice, totalValue;

    do {
        printf("\n========================================\n");
        printf("   INVENTORY MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Add Item\n");
        printf("2. Display All Items\n");
        printf("3. Search Item by Code\n");
        printf("4. Update Item Price\n");
        printf("5. Add Stock\n");
        printf("6. Sell Stock\n");
        printf("7. Delete Item\n");
        printf("8. Display Total Inventory Value\n");
        printf("9. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (n >= MAX) {
                printf("\nInventory is full!\n");
            } else {
                printf("\nEnter Item Code     : ");
                scanf("%d", &items[n].code);
                printf("Enter Item Name     : ");
                scanf(" %[^\n]", items[n].name);
                printf("Enter Quantity      : ");
                scanf("%d", &items[n].quantity);
                printf("Enter Price per unit : ");
                scanf("%f", &items[n].price);
                n++;
                printf("\nItem added successfully!\n");
            }
        }

        else if (choice == 2) {
            if (n == 0) {
                printf("\nNo items found.\n");
            } else {
                printf("\n%-8s %-20s %-10s %-10s\n", "Code", "Name", "Quantity", "Price");
                printf("--------------------------------------------------\n");
                for (i = 0; i < n; i++) {
                    printf("%-8d %-20s %-10d %-10.2f\n",
                           items[i].code, items[i].name, items[i].quantity, items[i].price);
                }
            }
        }

        else if (choice == 3) {
            printf("\nEnter Item Code to search : ");
            scanf("%d", &code);
            found = 0;
            for (i = 0; i < n; i++) {
                if (items[i].code == code) {
                    printf("\nItem Found:\n");
                    printf("Code     : %d\n", items[i].code);
                    printf("Name     : %s\n", items[i].name);
                    printf("Quantity : %d\n", items[i].quantity);
                    printf("Price    : %.2f\n", items[i].price);
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("\nItem with code %d not found.\n", code);
        }

        else if (choice == 4) {
            printf("\nEnter Item Code : ");
            scanf("%d", &code);
            found = 0;
            for (i = 0; i < n; i++) {
                if (items[i].code == code) {
                    printf("Enter new Price : ");
                    scanf("%f", &newPrice);
                    items[i].price = newPrice;
                    printf("\nPrice updated successfully!\n");
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("\nItem with code %d not found.\n", code);
        }

        else if (choice == 5) {
            printf("\nEnter Item Code : ");
            scanf("%d", &code);
            found = 0;
            for (i = 0; i < n; i++) {
                if (items[i].code == code) {
                    printf("Enter quantity to add : ");
                    scanf("%d", &qty);
                    items[i].quantity = items[i].quantity + qty;
                    printf("\nStock added successfully!\n");
                    printf("New Quantity = %d\n", items[i].quantity);
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("\nItem with code %d not found.\n", code);
        }

        else if (choice == 6) {
            printf("\nEnter Item Code : ");
            scanf("%d", &code);
            found = 0;
            for (i = 0; i < n; i++) {
                if (items[i].code == code) {
                    found = 1;
                    printf("Enter quantity to sell : ");
                    scanf("%d", &qty);

                    if (qty > items[i].quantity) {
                        printf("\nInsufficient stock!\n");
                        printf("Available Quantity = %d\n", items[i].quantity);
                    } else {
                        items[i].quantity = items[i].quantity - qty;
                        printf("\nStock sold successfully!\n");
                        printf("Remaining Quantity = %d\n", items[i].quantity);
                    }
                    break;
                }
            }
            if (found == 0)
                printf("\nItem with code %d not found.\n", code);
        }

        else if (choice == 7) {
            printf("\nEnter Item Code to delete : ");
            scanf("%d", &code);
            found = 0;
            for (i = 0; i < n; i++) {
                if (items[i].code == code) {
                    for (j = i; j < n - 1; j++) {
                        items[j] = items[j + 1];
                    }
                    n--;
                    printf("\nItem deleted successfully!\n");
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("\nItem with code %d not found.\n", code);
        }

        else if (choice == 8) {
            totalValue = 0;
            for (i = 0; i < n; i++) {
                totalValue = totalValue + (items[i].quantity * items[i].price);
            }
            printf("\nTotal Inventory Value = %.2f\n", totalValue);
        }

        else if (choice == 9) {
            printf("\nExiting program. Goodbye!\n");
        }

        else {
            printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}