#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
} Item;

void addItem(Item **inventory, int *count) {
    *inventory = realloc(*inventory, (*count + 1) * sizeof(Item));
    if (*inventory == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter item ID: ");
    scanf("%d", &((*inventory)[*count].id));
    printf("Enter item name: ");
    scanf(" %[^\n]", (*inventory)[*count].name);
    (*count)++;
}

void displayItems(Item *inventory, int count) {
    printf("\nInventory List:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s\n", inventory[i].id, inventory[i].name);
    }
}

void searchItem(Item *inventory, int count) {
    int searchID;
    printf("Enter item ID to search: ");
    scanf("%d", &searchID);
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == searchID) {
            printf("Item found - ID: %d, Name: %s\n", inventory[i].id, inventory[i].name);
            return;
        }
    }
    printf("Item not found.\n");
}

int main() {
    Item *inventory = NULL;
    int count = 0, choice;

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Search Item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&inventory, &count);
                break;
            case 2:
                displayItems(inventory, count);
                break;
            case 3:
                searchItem(inventory, count);
                break;
            case 4:
                free(inventory);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

