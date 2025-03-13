#include <stdio.h>

int main(void) {
    float consumption, cost, tax, total;

    // Ask the user to enter the consumption
    printf("Enter your consumption in m³: ");
    scanf("%f%*c", &consumption);

    // Calculate the cost based on the consumption
    if (consumption <= 1) {
        cost = 20.00;  // Flat rate for consumption <= 1m³
    } else {
        cost = 20.00 + (consumption - 1) * 3.5;  // €20 for the first m³, €3.5 for each additional m³
    }

    // Calculate the tax (21% of the cost)
    tax = cost * 0.21;

    // Calculate the total amount (cost + tax)
    total = cost + tax;

    // Print the invoice
    printf("\n----- Invoice -----\n");
    printf("Consumption: %.2f m³\n", consumption);
    printf("Cost: €%.2f\n", cost);
    printf("Tax (21%%): €%.2f\n", tax);
    printf("Total amount: €%.2f\n", total);

    return 0;
}
