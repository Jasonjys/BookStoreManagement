Author:
Yaoshen Jiang
Shane Loong Deng-Young

This is a bookstore Management program. User class has a BuyBehaviour and user switch buy behaviour if their membership rank up
- There are 3 types of memberships, bronze, silver and gold.
- If user's total purchases reach $100 and above, he/she will get promoted to silver rank.
- If user's total purchases reach $300 and above, he/she will get promoted to gold rank.
- NOTE: User is not allowed to rank up twice in one transaction.

- Bronze user gets on discount.
- Silver user gets 10% off.
- Gold user gets 25% off.

- When the user wants to buy a product, he/she can search the product by their brand and if
the user wants to buy a book, he/she can search books by title.

- User can check their member function from the main menu.

Source files:
- main.cc
- BMScontrol.cc
- UImanager.cc
- Book.cc
- BookArray.cc
- Course.cc
- Dlist.cc
- Eraser.cc
- Laptop.cc
- Pencil.cc
- User.cc
- BuyBehaviour.cc

Header file:
- defs.h
- BMScontrol.h
- UImanager.h
- Book.h
- BookArray.h
- Course.h
- Dlist.h
- Eraser.h
- Laptop.h
- Pencil.h
- User.h
- BuyBehabiour.h

Compilation command:
make

Launching instructions:
Run the program by using command: ./bms

Operation instructions:
1. Add course
2. Delete course
3. List all the courses (From head to back and back to head)
4. Add textbook
5. List course textbook
6. Add product
7. List all products
8. Buy product
9. View membership status
0. Exit
