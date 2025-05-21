# E-Commerce-Cart-System
# 🛒 Mini E-Commerce Cart System in C

![C Language](https://img.shields.io/badge/Language-C-blue)
![License](https://img.shields.io/badge/License-MIT-green)
![Version](https://img.shields.io/badge/Version-1.0.0-orange)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Windows-lightgrey)

A lightweight command-line shopping cart system with discount codes and receipt generation, written in C.

## 🌟 Features
- 🛍️ **Add/Remove Products** with name, price, and quantity
- 💸 **Automatic Total Calculation**
- 🏷️ **Discount Codes**: `SAVE10`, `OFF20`, `DEAL30`
- 🧾 **Receipt Generation** (saved to `receipt.txt`)
- 🖥️ **Interactive Menu System**

## 📸 Demo
![Terminal Demo](demo.gif)  
*(Example workflow: adding items, applying discount, generating receipt)*

## 🚀 Getting Started

### Prerequisites
- GCC compiler
- Linux/Windows terminal

### Installation
``bash
## Clone the repository
git clone https://github.com/yourusername/ecom-cart-c.git
cd ecom-cart-c

# Compile the program
gcc cart_system.c -o cart_system

# Run the program
./cart_system
1. Add product to cart
2. Remove product from cart
3. View total
4. Checkout
5. Exit
# Add a product
Enter product name: Laptop
Enter product price: 999.99
Enter quantity: 1

# Apply discount at checkout
Enter discount code: DEAL30
Discount applied: 30.00% (-300.00)

# Generated receipt.txt contains:
Laptop x 1 = 999.99
Total payable: 699.99

ecom-cart-c/
├── cart_system.c      # Main program
├── receipt.txt        # Auto-generated receipt
├── README.md          # This document
└── demo.gif           # Usage demonstration

flowchart LR
    A[Main Menu] --> B[Add Product]
    A --> C[Remove Product]
    A --> D[Calculate Total]
    A --> E[Checkout]
    E --> F[Apply Discount]
    E --> G[Generate Receipt]

    
