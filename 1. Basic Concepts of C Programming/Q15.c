#include <stdio.h>

int main(void) {
    int invoiceNumber, numberOfProducts, pricePerUnit, totalAmount;

    // Ask the user for the invoice number, number of products, and price per unit
    printf("Enter invoice number: ");
    scanf("%d%*c", &invoiceNumber);

    printf("Enter the number of products ordered: ");
    scanf("%d%*c", &numberOfProducts);

    printf("Enter the price per unit: ");
    scanf("%d%*c", &pricePerUnit);

    // Calculate the total amount
    totalAmount = numberOfProducts * pricePerUnit;

    // Print the invoice details in the requested format
    printf("\nINVOICE     NUMBER     PRICE/UNIT     TOTAL\n");
    printf("%-7d     %-6d     %-10d     %-5d\n", invoiceNumber, numberOfProducts, pricePerUnit, totalAmount);

    return 0;
}
