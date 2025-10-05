#include <stdio.h>
#include <string.h>

// Maksimum jumlah barang
#define MAX_ITEMS 100

// Struktur data untuk barang
struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

// Deklarasi array dan variabel global
struct Item inventory[MAX_ITEMS];
int itemCount = 0;

// --- Fungsi-fungsi utama ---

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("\nInventory is full! Cannot add more items.\n");
        return;
    }

    struct Item newItem;
    printf("\nEnter Item ID: ");
    scanf("%d", &newItem.id);
    printf("Enter Item Name: ");
    scanf(" %[^\n]", newItem.name);
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    // Cek duplikasi ID
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == newItem.id) {
            printf("\nError: Item ID already exists!\n");
            return;
        }
    }

    inventory[itemCount++] = newItem;
    printf("\nItem added successfully!\n");
}

void viewItems() {
    if (itemCount == 0) {
        printf("\nNo items in inventory.\n");
        return;
    }

    printf("\n================ INVENTORY LIST ================\n");
    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%-10d %-20s %-10d $%-10.2f\n",
               inventory[i].id,
               inventory[i].name,
               inventory[i].quantity,
               inventory[i].price);
    }
    printf("================================================\n");
}

void updateItem() {
    int id;
    printf("\nEnter Item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", inventory[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);

            printf("\nItem updated successfully!\n");
            return;
        }
    }
    printf("\nItem not found!\n");
}

void deleteItem() {
    int id;
    printf("\nEnter Item ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("\nItem deleted successfully!\n");
            return;
        }
    }
    printf("\nItem not found!\n");
}

void searchItem() {
    int id;
    printf("\nEnter Item ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            printf("\nItem Found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: $%.2f\n",
                   inventory[i].id,
                   inventory[i].name,
                   inventory[i].quantity,
                   inventory[i].price);
            return;
        }
    }
    printf("\nItem not found!\n");
}

// --- Fungsi utama program ---
int main() {
    int choice;

    do {
        printf("\n===== RETAIL INVENTORY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Item\n");
        printf("2. Update Item\n");
        printf("3. Delete Item\n");
        printf("4. View Inventory\n");
        printf("5. Search Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: updateItem(); break;
            case 3: deleteItem(); break;
            case 4: viewItems(); break;
            case 5: searchItem(); break;
            case 6: printf("\nExiting program. Thank you!\n"); break;
            default: printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}