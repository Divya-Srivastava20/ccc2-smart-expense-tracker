## ----- Smart Expense Tracker -----

## Introduction: 
The Smart Expense Tracker is a console-based application developed in C that helps users manage and analyze their daily expenses. The system allows users to set a monthly budget, record expenses under different categories, and evaluate whether their spending stays within the defined budget. If the spending exceeds the budget, the program suggests ways to reduce expenses using algorithmic approaches.

## Case-Based Scenario:
Consider a student with a monthly budget of ₹10,000 who spends on categories like food, travel, rent, and entertainment. After recording all expenses, the total spending becomes ₹10,500, which exceeds the budget by ₹500. In such a situation, the system analyzes the expenses and suggests how to reduce spending. Instead of giving random suggestions, it uses algorithms to determine the most effective way to cut expenses, making the solution practical and realistic.

## Working of the System:
The system first takes the monthly budget as input, followed by multiple expenses entered by the user. It then calculates the total expenditure and compares it with the budget. If the total is within budget, the system displays the remaining savings. If the budget is exceeded, the system calculates the exact amount that needs to be saved and provides suggestions using both Greedy and Dynamic Programming approaches. This allows users to understand different strategies for minimizing expenses.

## Flowchart:
Start
  ↓
Set Monthly Budget
  ↓
Add Expenses
  ↓
Calculate Total Spending
  ↓
Compare with Budget
  ↓
Is Spending > Budget?
   ↓ Yes
   Calculate Required Savings
   ↓
   Apply Greedy Algorithm
   ↓
   Apply Dynamic Programming
  ↓
Display Suggestions
  ↓
End


## Algorithms Used:
1) Greedy Algorithm
Selects highest expense first
Simple and fast approach
May exceed required savings
Steps:
Sort expenses in descending order
Pick highest values until target is reached

2) Dynamic Programming (0/1 Knapsack)
Finds optimal combination of expenses
Ensures best result within constraint
Steps:
Create DP table
For each expense:
Include or exclude
Choose maximum value ≤ target

## Algorithm Steps:
1) Greedy Algorithm
1. Sort all expenses in descending order
2. Select the highest expense
3. Keep adding expenses until the target saving is reached
4. Display selected expenses

2) Dynamic Programming Algorithm
1. Create a DP table based on number of expenses and target value
2. For each expense, decide whether to include or exclude it
3. Store maximum achievable value at each step
4. Backtrack to find selected expenses
5. Display optimal combination

## Solution Approach:
The solution combines both Greedy and Dynamic Programming techniques to provide a comprehensive savings strategy. While the Greedy method offers a quick and straightforward approach, Dynamic Programming ensures optimal decision-making. By displaying both results, the system allows users to compare efficiency versus accuracy and choose the most suitable approach for their needs. This dual-algorithm strategy enhances the reliability and practical usability of the system.

## Project Structure:
smart-expense-tracker-c/
│
├── main.c
├── README.md
├── sample_run.txt
├── expenses.txt

## How to Run:
gcc main.c -o tracker
./tracker

## Conclusion:
This project demonstrates how fundamental algorithms like Greedy and Dynamic Programming can be applied to solve real-world problems such as expense management. It not only helps users track their spending but also provides intelligent suggestions for financial planning. The project highlights the importance of algorithmic thinking in everyday decision-making and improves understanding of efficiency and optimality in problem-solving.
