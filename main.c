#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_TARGET 10000

struct Expense {
    char category[50];
    int amount;
};

struct Expense e[MAX];
int n = 0;
int budget = 0;

// Global DP (avoid stack overflow)
int dp[MAX + 1][MAX_TARGET + 1];

// Set budget
void setBudget() {
    printf("Enter monthly budget: ");
    scanf("%d", &budget);
    getchar();
}

// Add expense
void addExpense() {
    if(n >= MAX) {
        printf("Expense limit reached!\n");
        return;
    }

    printf("Enter category: ");
    scanf(" %[^\n]", e[n].category);  // supports spaces

    printf("Enter amount: ");
    scanf("%d", &e[n].amount);
    getchar();

    n++;
}

// Display report
void display() {
    if(n == 0) {
        printf("No expenses added yet.\n");
        return;
    }

    int total = 0;

    printf("\n--- Expenses ---\n");
    for(int i = 0; i < n; i++) {
        printf("%s : %d\n", e[i].category, e[i].amount);
        total += e[i].amount;
    }

    printf("Total Spending: %d\n", total);
    printf("Budget: %d\n", budget);

    if(total > budget)
        printf("You exceeded budget by %d\n", total - budget);
    else
        printf("You are within budget. Savings: %d\n", budget - total);
}

// Sort descending
void sortExpenses() {
    struct Expense temp;

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(e[j].amount < e[j + 1].amount) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
}

// Suggest savings
void suggestSavings() {
    if(n == 0) {
        printf("No expenses to analyze.\n");
        return;
    }

    int total = 0;
    for(int i = 0; i < n; i++)
        total += e[i].amount;

    // 🔥 Show summary first
    printf("\n===== Expense Summary =====\n");
    printf("Total Spending: %d\n", total);

    if(budget > 0) {
        printf("Budget: %d\n", budget);

        if(total > budget)
            printf("You exceeded budget by %d\n", total - budget);
        else
            printf("You are within budget. Savings: %d\n", budget - total);
    }

    int choice, target;

    printf("\nChoose option:\n");
    printf("1. Save based on budget\n");
    printf("2. Enter custom saving goal\n");
    printf("Enter: ");
    scanf("%d", &choice);

    if(choice == 1) {
        if(budget == 0) {
            printf("Please set budget first!\n");
            return;
        }

        if(total <= budget) {
            printf("You are already within budget!\n");
            return;
        }

        target = total - budget;
    }
    else if(choice == 2) {
        printf("Enter amount you want to save: ");
        scanf("%d", &target);
    }
    else {
        printf("Invalid choice\n");
        return;
    }

    if(target > MAX_TARGET) {
        printf("Target too large! Increase limit.\n");
        return;
    }

    printf("\nYou need to save: %d\n", target);

    // -------- GREEDY --------
    sortExpenses();

    printf("\n===== Greedy Approach =====\n");
    int saved = 0;

    for(int i = 0; i < n && saved < target; i++) {
        printf("Reduce from %s (%d)\n", e[i].category, e[i].amount);
        saved += e[i].amount;
    }

    printf("Total by Greedy: %d\n", saved);

    if(saved >= target)
        printf("✔ Target achieved (may exceed)\n");
    else
        printf("✘ Target not achieved\n");

    // -------- DP --------
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= target; j++) {
            if(e[i-1].amount <= j) {
                int include = e[i-1].amount + dp[i-1][j - e[i-1].amount];
                int exclude = dp[i-1][j];
                dp[i][j] = (include > exclude) ? include : exclude;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    printf("\n===== DP Approach =====\n");

    if(dp[n][target] == 0) {
        printf("No exact combination within target.\n");
        return;
    }

    printf("Optimal saving: %d\n", dp[n][target]);
    printf("Cut expenses from:\n");

    int res = dp[n][target];
    int j = target;

    for(int i = n; i > 0 && res > 0; i--) {
        if(res != dp[i-1][j]) {
            printf("%s (%d)\n", e[i-1].category, e[i-1].amount);
            res -= e[i-1].amount;
            j -= e[i-1].amount;
        }
    }
}

// Main
int main() {
    int choice;

    while(1) {
        printf("\n===== Smart Expense Tracker =====\n");
        printf("1. Set Monthly Budget\n");
        printf("2. Add Expense\n");
        printf("3. Display Report\n");
        printf("4. Suggest Savings (Greedy + DP)\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: setBudget(); break;
            case 2: addExpense(); break;
            case 3: display(); break;
            case 4: suggestSavings(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}