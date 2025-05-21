#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_DISCOUNT_CODES 3

struct Product {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
};

struct DiscountCode {
    char code[20];
    float discountPercent;
};

struct Product cart[MAX_PRODUCTS];
int cartSize = 0;

struct DiscountCode discountCodes[MAX_DISCOUNT_CODES] = {
    {"SAVE10", 10},
    {"OFF20", 20},
    {"DEAL30", 30}
};

void addProductToCart() {
    if (cartSize >= MAX_PRODUCTS) {
        printf("Cart is full!\n");
        return;
    }

    struct Product p;
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    printf("Enter quantity: ");
    scanf("%d", &p.quantity);

    cart[cartSize++] = p;
    printf("Product added to cart.\n");
}

void removeProductFromCart() {
    if (cartSize == 0) {
        printf("Cart is empty.\n");
        return;
    }
    char name[MAX_NAME_LEN];
    printf("Enter the name of the product to remove: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < cartSize; i++) {
        if (strcmp(cart[i].name, name) == 0) {
            for (int j = i; j < cartSize - 1; j++) {
                cart[j] = cart[j + 1];
            }
            cartSize--;
            found = 1;
            printf("Product removed from cart.\n");
            break;
        }
    }
    if (!found) {
        printf("Product not found in cart.\n");
    }
}

float calculateTotal() {
    float total = 0;
    for (int i = 0; i < cartSize; i++) {
        total += cart[i].price * cart[i].quantity;
    }
    return total;
}

float applyDiscount(float total) {
    char inputCode[20];
    printf("Enter discount code (if any): ");
    scanf("%s", inputCode);

    for (int i = 0; i < MAX_DISCOUNT_CODES; i++) {
        if (strcmp(inputCode, discountCodes[i].code) == 0) {
            float discountAmount = (discountCodes[i].discountPercent / 100.0) * total;
            printf("Discount applied: %.2f%% (-%.2f)\n", discountCodes[i].discountPercent, discountAmount);
            return total - discountAmount;
        }
    }

    printf("Invalid discount code. No discount applied.\n");
    return total;
}

void generateReceipt(float finalAmount) {
    FILE *file = fopen("receipt.txt", "w");

    printf("\n----- Final Receipt -----\n");
    fprintf(file, "----- Final Receipt -----\n");

    for (int i = 0; i < cartSize; i++) {
        float itemTotal = cart[i].price * cart[i].quantity;
        printf("%s x %d = %.2f\n", cart[i].name, cart[i].quantity, itemTotal);
        fprintf(file, "%s x %d = %.2f\n", cart[i].name, cart[i].quantity, itemTotal);
    }

    printf("------------------------\n");
    printf("Total payable: %.2f\n", finalAmount);
    printf("Thank you for shopping with us!\n");

    fprintf(file, "------------------------\n");
    fprintf(file, "Total payable: %.2f\n", finalAmount);
    fprintf(file, "Thank you for shopping with us!\n");

    fclose(file);
    printf("Receipt saved to 'receipt.txt'.\n");
}

int main() {
    int choice;
    float total, finalAmount;

    do {
        printf("\nMini E-commerce Cart System\n");
        printf("1. Add product to cart\n");
        printf("2. Remove product from cart\n");
        printf("3. View total\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProductToCart();
                break;
            case 2:
                removeProductFromCart();
                break;
            case 3:
                total = calculateTotal();
                printf("Current total: %.2f\n", total);
                break;
            case 4:
                total = calculateTotal();
                finalAmount = applyDiscount(total);
                generateReceipt(finalAmount);
                cartSize = 0; // clear cart after checkout
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
