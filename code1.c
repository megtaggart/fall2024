#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

//function declarations
void monthlySalesReport(double sales[], const char* months[]);
void salesSummaryReport(double sales[], const char* months[]);
void sixMonthMovingAverageReport(double sales[], const char* months[]);
void salesReportDescending(double sales[], const char* months[]);

int main() {
    //declares arrays
    double sales[MONTHS];
    const char* months[MONTHS] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };
    
    FILE *file;
    char filename[100];
    
    //user input (input file path for best results)
    printf("Enter the input file name: ");
    scanf("%s", filename);
    
    //opens file, duh
    file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }
    
    //reading data from the table
    for (int i = 0; i < MONTHS; i++) {
        if (fscanf(file, "%lf", &sales[i]) != 1) {
            printf("Error reading data for month %d\n", i + 1);
            fclose(file);
            return 1;
        }
    }
    
    fclose(file);
    
    //calls declared functions
    monthlySalesReport(sales, months);
    salesSummaryReport(sales, months);
    sixMonthMovingAverageReport(sales, months);
    salesReportDescending(sales, months);

    return 0;
}

//prints a report showing the sales for each month in the year
void monthlySalesReport(double sales[], const char* months[]) {
    printf("Monthly Sales Report for 2024\n");
    printf("Month\t\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s\t$%.2f\n", months[i], sales[i]);
    }
    printf("\n");
}

//calculates and prints the min, max, and average sales, including the months 
void salesSummaryReport(double sales[], const char* months[]) {
    double min = sales[0], max = sales[0], total = 0.0, average;
    int minMonth = 0, maxMonth = 0;

    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] < min) {
            min = sales[i];
            minMonth = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = i;
        }
        total += sales[i];
    }

    average = total / MONTHS;
    
    printf("Sales Summary Report:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[minMonth]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[maxMonth]);
    printf("Average sales: $%.2f\n\n", average);
}

//calculates, prints the six-month moving average for the sales figures
void sixMonthMovingAverageReport(double sales[], const char* months[]) {
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i <= MONTHS - 6; i++) {
        double sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%-10s-%-10s\t$%.2f\n", months[i], months[i + 5], sum / 6);
    }
    printf("\n");
}

void salesReportDescending(double sales[], const char* months[]) {
    //create a copy of the sales array 
    double sortedSales[MONTHS];
    const char* sortedMonths[MONTHS];
    
    for (int i = 0; i < MONTHS; i++) {
        sortedSales[i] = sales[i];
        sortedMonths[i] = months[i];
    }

    //sort in descending order, bubble sort
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = 0; j < MONTHS - i - 1; j++) {
            if (sortedSales[j] < sortedSales[j + 1]) {
                double temp = sortedSales[j];
                sortedSales[j] = sortedSales[j + 1];
                sortedSales[j + 1] = temp;

                //swap to corresponding months
                const char* tempMonth = sortedMonths[j];
                sortedMonths[j] = sortedMonths[j + 1];
                sortedMonths[j + 1] = tempMonth;
            }
        }
    }

    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\t\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s\t$%.2f\n", sortedMonths[i], sortedSales[i]);
    }
    printf("\n");
}

