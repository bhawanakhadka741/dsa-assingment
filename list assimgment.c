#include <stdlib.h>
#include <string.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

struct product {
    int pId;
    char pName[50];
    float price;
    int stockQty;
};

struct list {
    int count;
    struct product items[MAX];
};

int isFull(struct list* lst) {
    return lst->count == MAX - 1;
}

int isEmpty(struct list* lst) {
    return lst->count == -1;
}

int insertAtEnd(struct list* lst, struct product p) {
    if (isFull(lst)) {
        printf("List is full.\n");
        return FALSE;
    } else {
        lst->count++;
        lst->items[lst->count] = p;
        printf("Product inserted at the end.\n");
        return TRUE;
    }
}

int insertAtFront(struct list* lst, struct product p) {
    if (isFull(lst)) {
        printf("List is full.\n");
        return FALSE;
    } else {
        int i;
        for (i = lst->count; i >= 0; i--) {
            lst->items[i + 1] = lst->items[i];
        }
        lst->items[0] = p;
        lst->count++;
        printf("Product inserted at the front.\n");
        return TRUE;
    }
}

int insertAfterItem(struct list* lst, int itemId, struct product p) {
    if (isFull(lst)) {
        printf("List is full.\n");
        return FALSE;
    } else {
        int i;
        for (i = 0; i <= lst->count; i++) {
            if (lst->items[i].pId == itemId) {
                int j;
                for (j = lst->count; j > i; j--) {
                    lst->items[j + 1] = lst->items[j];
                }
                lst->items[i + 1] = p;
                lst->count++;
                printf("Product inserted after item with ID %d.\n", itemId);
                return TRUE;
            }
        }
        printf("Item with ID %d not found.\n", itemId);
        return FALSE;
    }
}

int insertBeforeItem(struct list* lst, int itemId, struct product p) {
    if (isFull(lst)) {
        printf("List is full.\n");
        return FALSE;
    } else {
        int i;
        for (i = 0; i <= lst->count; i++) {
            if (lst->items[i].pId == itemId) {
                int j;
                for (j = lst->count; j >= i; j--) {
                    lst->items[j + 1] = lst->items[j];
                }
                lst->items[i] = p;
                lst->count++;
                printf("Product inserted before item with ID %d.\n", itemId);
                return TRUE;
            }
        }
        printf("Item with ID %d not found.\n", itemId);
        return FALSE;
    }
}

int removeFromFront(struct list* lst) {
    if (isEmpty(lst)) {
        printf("List is empty.\n");
        return FALSE;
    } else {
        int i;
        for (i = 0; i < lst->count; i++) {
            lst->items[i] = lst->items[i + 1];
        }
        lst->count--;
        printf("Product removed from the front.\n");
        return TRUE;
    }
}

int removeFromEnd(struct list* lst) {
    if (isEmpty(lst)) {
        printf("List is empty.\n");
        return FALSE;
    } else {
        lst->count--;
        printf("Product removed from the end.\n");
        return TRUE;
    }
}

int removeItem(struct list* lst, int itemId) {
    if (isEmpty(lst)) {
        printf("List is empty.\n");
        return FALSE;
    } else {
        int i;
        for (i = 0; i <= lst->count; i++) {
            if (lst->items[i].pId == itemId) {
                int j;
                for (j = i; j < lst->count; j++) {
                    lst->items[j] = lst->items[j + 1];
                }
                lst->count--;
                printf("Product with ID %d removed.\n", itemId);
                return TRUE;
            }
        }
        printf("Item with ID %d not found.\n", itemId);
        return FALSE;
    }
}

void display(struct list* lst) {
    int i;
    if (isEmpty(lst))
        printf("List is empty.\n");
    else {
        printf("List contains:\n");
        printf("P Code\tProduct Name\tPrice\tQuantity\n");
        for (i = 0; i <= lst->count; i++) {
            printf("%d\t%s\t%.2f\t%d\n", lst->items[i].pId, lst->items[i].pName, lst->items[i].price, lst->items[i].stockQty);
        }
    }
}

int searchItemById(struct list* lst, int itemId) {
    int i;
    for (i = 0; i <= lst->count; i++) {
        if (lst->items[i].pId == itemId) {
            printf("Item found:\n");
            printf("P Code\tProduct Name\tPrice\tQuantity\n");
            printf("%d\t%s\t%.2f\t%d\n", lst->items[i].pId, lst->items[i].pName, lst->items[i].price, lst->items[i].stockQty);
            return TRUE;
        }
    }
    printf("Item with ID %d not found.\n", itemId);
    return FALSE;
}

int main() {
    struct list lst;
    lst.count = -1; // Initialize count to indicate empty list

    int choice;
    struct product p;

    while (1) {
        printf("\n1. Insert at End\n2. Insert at Front\n3. Insert After Item\n4. Insert Before Item\n");
        printf("5. Remove from Front\n6. Remove from End\n7. Remove Item\n8. Display\n9. Search by ID\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product ID, name, price, and quantity: ");
                scanf("%d %s %f %d", &p.pId, p.pName, &p.price, &p.stockQty);
                insertAtEnd(&lst, p);
                break;
            case 2:
                printf("Enter product ID, name, price, and quantity: ");
                scanf("%d %s %f %d", &p.pId, p.pName, &p.price, &p.stockQty);
                insertAtFront(&lst, p);
                break;
            case 3:
                printf("Enter product ID after which to insert, and then enter product ID, name, price, and quantity: ");
                scanf("%d %d %s %f %d", &p.pId, &choice, p.pName, &p.price, &p.stockQty);
                insertAfterItem(&lst, choice, p);
                break;
            case 4:
                printf("Enter product ID before which to insert, and then enter product ID, name, price, and quantity: ");
                scanf("%d %d %s %f %d", &p.pId, &choice, p.pName, &p.price, &p.stockQty);
                insertBeforeItem(&lst, choice, p);
                break;
            case 5:
                removeFromFront(&lst);
                break;
            case 6:
                removeFromEnd(&lst);
                break;
            case 7:
                printf("Enter product ID to remove: ");
                scanf("%d", &choice);
                removeItem(&lst, choice);
                break;
            case 8:
                display(&lst);
                break;
            case 9:
                printf("Enter product ID to search: ");
                scanf("%d", &choice);
                searchItemById(&lst, choice);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
