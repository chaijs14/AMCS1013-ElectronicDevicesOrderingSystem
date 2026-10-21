#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;

// Constants
const double TAX_RATE = 0.06;
const int MAX_PRODUCTS = 4;

// Global variables for tracking daily sales
int dailySales[MAX_PRODUCTS] = { 0 };
double dailyRevenue = 0.0;
double totalTaxCollected = 0.0;

// Clear console screen cross-platform
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Helper function to clear invalid cin states and leftover buffer input
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Helper function to check if string consists ONLY of digits
bool isStrictInteger(const string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

// Helper function to check if a string is a valid positive double amount
bool isValidAmount(const string& str, double& value) {
    if (str.empty()) return false;
    try {
        size_t idx;
        value = stod(str, &idx);
        return idx == str.length() && value >= 0.0;
    }
    catch (...) {
        return false;
    }
}

// Pause function with customized message
void pauseConsole(string message = "Press Enter to continue...") {
    cout << "\n" << message;
    cin.get();
}

// Display store logo
void callLogo() {
    string p = "PP";
    string ppp = "PPP";
    string a_multiple_p = "PPPPPPPPP";
    string pad = "          ";

    cout << pad << a_multiple_p << endl;
    cout << pad << ppp << "\t" << setw(3) << p << endl;
    cout << pad << ppp << "\t" << setw(3) << p << endl;
    cout << pad << ppp << "\t" << setw(3) << p << endl;
    cout << pad << a_multiple_p << endl;
    cout << pad << ppp << endl;
    cout << pad << ppp << endl;
    cout << pad << ppp << endl;
    cout << pad << ppp << endl;
}

// Specifications
void displayProductInfo(char model) {
    switch (model) {
    case '1':
        cout << "\nPineapple 1 Specifications:" << endl;
        cout << "Processor Model --- Snapdragon 6 gen 3 (5G)\n"
            << "Screen type ------- AMOLED 120Hz, 2400x1080 (6.72 inch)\n"
            << "Battery ----------- 5000mAh\n"
            << "RAM / Storage ----- 16GB / 256GB\n"
            << "Price ------------- RM 999.00\n";
        break;
    case '2':
        cout << "\nPineapple 1 Pro Specifications:" << endl;
        cout << "Processor Model --- Snapdragon 7 gen 3 (5G)\n"
            << "Screen type ------- AMOLED 120Hz, 2400x1080 (6.72 inch)\n"
            << "Battery ----------- 5000mAh\n"
            << "RAM / Storage ----- 16GB / 256GB\n"
            << "Price ------------- RM 1499.00\n";
        break;
    case '3':
        cout << "\nPineapple 1 Pro Max Specifications:" << endl;
        cout << "Processor Model --- Snapdragon 8 gen 3 (5G)\n"
            << "Screen type ------- AMOLED 144Hz, 2400x1080 (6.72 inch)\n"
            << "Battery ----------- 5400mAh\n"
            << "RAM / Storage ----- 32GB / 512GB\n"
            << "Price ------------- RM 2499.00\n";
        break;
    case '4':
        cout << "\nPineBook Specifications:" << endl;
        cout << "Processor Model --- Snapdragon 8 gen 3 (5G)\n"
            << "Screen type ------- AMOLED 144Hz, 2732x2048 (12.9 inch)\n"
            << "Battery ----------- 5400mAh\n"
            << "RAM / Storage ----- 32GB / 1TB\n"
            << "Price ------------- RM 2999.00\n";
        break;
    }
}

// Product Reviews Feature
void displayProductReviews(char model) {
    cout << "\n--------------------------------------------------------" << endl;
    cout << "                   CUSTOMER REVIEWS                     " << endl;
    cout << "--------------------------------------------------------" << endl;
    switch (model) {
    case '1':
        cout << "Overall Rating: 4.5 / 5.0 Stars (128 Reviews)\n\n"
            << "1. John D. (5/5)   : 'Best budget phone for daily work! Outstanding battery life.'\n"
            << "2. Sarah M. (4/5)  : 'Smooth 120Hz AMOLED display. Great value for RM 999.'\n"
            << "3. Alex K. (4.5/5) : 'Fast charging works as advertised.'\n";
        break;
    case '2':
        cout << "Overall Rating: 4.7 / 5.0 Stars (210 Reviews)\n\n"
            << "1. Kevin T. (5/5)  : 'Snapdragon 7 gen 3 handles gaming easily without heating.'\n"
            << "2. Lisa P. (4.5/5) : 'Sleek design, camera quality is surprisingly sharp.'\n"
            << "3. Ryan B. (4.5/5) : 'Definite upgrade over Pineapple 1!'\n";
        break;
    case '3':
        cout << "Overall Rating: 4.9 / 5.0 Stars (340 Reviews)\n\n"
            << "1. Daniel S. (5/5) : 'Absolute flagship beast! 144Hz screen looks incredible.'\n"
            << "2. Rachel W. (5/5) : '32GB RAM makes multitasking buttery smooth.'\n"
            << "3. Marcus L. (4.8/5): 'Wireless charging feature is super convenient.'\n";
        break;
    case '4':
        cout << "Overall Rating: 4.8 / 5.0 Stars (95 Reviews)\n\n"
            << "1. Tech Reviewer (5/5): 'Replaced my primary laptop with PineBook for travel work!'\n"
            << "2. Emily C. (4.5/5)   : 'Gorgeous 12.9 inch screen for drawing and editing.'\n"
            << "3. Jason V. (5/5)     : '1TB storage gives plenty of space for large projects.'\n";
        break;
    }
    cout << "--------------------------------------------------------" << endl;
    pauseConsole("Press Enter to return to product menu...");
}

double getProductPrice(char model) {
    switch (model) {
    case '1': return 999.0;
    case '2': return 1499.0;
    case '3': return 2499.0;
    case '4': return 2999.0;
    default: return 0.0;
    }
}

string getProductName(char model) {
    switch (model) {
    case '1': return "Pineapple 1";
    case '2': return "Pineapple 1 Pro";
    case '3': return "Pineapple 1 Pro Max";
    case '4': return "PineBook";
    default: return "Unknown Product";
    }
}

void paymentAndReceipt(char model, double price, int quantity) {
    double subtotal = quantity * price;
    double tax = subtotal * TAX_RATE;
    double total = subtotal + tax;
    string paymentType;
    string inputChoice;
    int paymentMethod = 0;

    cout << "\nYour order summary:" << endl;
    cout << "Subtotal: RM " << fixed << setprecision(2) << subtotal << endl;
    cout << "Tax (6%): RM " << tax << endl;
    cout << "Total:    RM " << total << endl;

    cout << "\nSelect payment method:\n"
        << "(1) Cash\n"
        << "(2) Credit/Debit Card\n"
        << "(3) eWallet\n"
        << "Choice: ";

    while (true) {
        cin >> inputChoice;
        clearInputBuffer();
        if (inputChoice == "1" || inputChoice == "2" || inputChoice == "3") {
            paymentMethod = inputChoice[0] - '0';
            break;
        }
        cout << "Invalid choice! Please enter 1, 2, or 3: ";
    }

    double cashPaid = 0.0;
    double change = 0.0;
    string cardMasked = "";
    string refNo = "";

    switch (paymentMethod) {
    case 1: {
        paymentType = "CASH";
        string cashInput;

        cout << "\nEnter Cash Received (RM): RM ";
        while (true) {
            cin >> cashInput;
            clearInputBuffer();

            if (isValidAmount(cashInput, cashPaid) && cashPaid >= total) {
                break;
            }
            cout << "Please enter the correct amount: RM ";
        }

        change = cashPaid - total;
        cout << "Change Due: RM " << fixed << setprecision(2) << change << endl;
        break;
    }
    case 2: {
        paymentType = "CARD";
        string cardNumber;
        cout << "\nEnter 16-Digit Card Number: ";
        while (true) {
            cin >> cardNumber;
            clearInputBuffer();
            if (cardNumber.length() == 16 && isStrictInteger(cardNumber)) {
                cardMasked = "**** **** **** " + cardNumber.substr(12, 4);
                break;
            }
            cout << "Invalid card number! Enter exactly 16 digits: ";
        }
        cout << "Authorizing Card payment..." << endl;
        break;
    }
    case 3: {
        paymentType = "E-WALLET";

        // Generate unique random reference number per order
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<int> dist(100000, 999999);
        refNo = "TXN-" + to_string(dist(rng));

        cout << "\nScan the QR Code below using your E-Wallet app:\n" << endl;
        cout << "   ###################" << endl;
        cout << "   # ##   ##  ##  ####" << endl;
        cout << "   ##  ##   ###  ## #" << endl;
        cout << "   #  ###  #   ##   #" << endl;
        cout << "   ###   ##  ##  ####" << endl;
        cout << "   ##  ##  ###   ## #" << endl;
        cout << "   # ##   ##   ##  ##" << endl;
        cout << "   ###################" << endl;
        cout << "\nPress Enter after completing payment on your device...";
        cin.get();
        break;
    }
    }

    int productIndex = model - '1';
    if (productIndex >= 0 && productIndex < MAX_PRODUCTS) {
        dailySales[productIndex] += quantity;
        dailyRevenue += total;
        totalTaxCollected += tax;
    }

    string productName = getProductName(model);
    cout << "\n+==========================================+" << endl;
    cout << "|            PINEAPPLE STORE               |" << endl;
    cout << "+==========================================+" << endl;
    cout << "|            ORDER RECEIPT                 |" << endl;
    cout << "+==========================================+" << endl;
    cout << "| ITEM:     " << left << setw(31) << productName << "|" << endl;
    cout << "| QUANTITY: " << left << setw(31) << quantity << "|" << endl;
    cout << "| PRICE:    RM " << left << setw(28) << fixed << setprecision(2) << price << "|" << endl;
    cout << "| SUBTOTAL: RM " << left << setw(28) << subtotal << "|" << endl;
    cout << "| TAX (6%): RM " << left << setw(28) << tax << "|" << endl;
    cout << "+==========================================+" << endl;
    cout << "| TOTAL:    RM " << left << setw(28) << total << "|" << endl;

    if (paymentMethod == 1) {
        cout << "| CASH PAID:RM " << left << setw(28) << cashPaid << "|" << endl;
        cout << "| CHANGE:   RM " << left << setw(28) << change << "|" << endl;
    }
    else if (paymentMethod == 2) {
        cout << "| CARD NO:  " << left << setw(31) << cardMasked << "|" << endl;
    }
    else if (paymentMethod == 3) {
        cout << "| REF NO:   " << left << setw(31) << refNo << "|" << endl;
    }

    cout << "| PAYMENT:  " << left << setw(31) << paymentType << "|" << endl;
    cout << "| STATUS:   " << left << setw(31) << "PAID" << "|" << endl;
    cout << "+==========================================+" << endl;
    cout << "|            THANK YOU FOR SHOPPING        |" << endl;
    cout << "|            AT PINEAPPLE STORE!           |" << endl;
    cout << "+==========================================+" << endl;

    pauseConsole("Press Enter to return to main menu...");
}

void displayDailyReport() {
    clearScreen();
    callLogo();
    cout << "\n----------------------------" << endl;
    cout << "----- DAILY SALES REPORT ---" << endl;
    cout << "----------------------------" << endl;

    double totalPreTaxSales = 0.0;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        string productName = getProductName('1' + i);
        double price = getProductPrice('1' + i);
        double productRevenue = dailySales[i] * price;
        totalPreTaxSales += productRevenue;

        cout << productName << ": " << dailySales[i] << " units, RM "
            << fixed << setprecision(2) << productRevenue << endl;
    }

    cout << "----------------------------" << endl;
    cout << "PRE-TAX SALES: RM " << fixed << setprecision(2) << totalPreTaxSales << endl;
    cout << "TAX COLLECTED: RM " << fixed << setprecision(2) << totalTaxCollected << endl;
    cout << "TOTAL REVENUE: RM " << fixed << setprecision(2) << dailyRevenue << endl;
    cout << "----------------------------" << endl;

    pauseConsole("Press Enter to return to main menu...");
}

void customerService() {
    clearScreen();
    callLogo();
    cout << "\n----------------------------" << endl;
    cout << "---------CONTACT US---------" << endl;
    cout << "----------------------------" << endl;
    cout << "Email: pineapple@pmail.com" << endl;
    cout << "Phone: 012-224-5556" << endl;
    cout << "Hours: Mon-Fri 9AM-6PM" << endl;
    cout << "----------------------------" << endl;

    pauseConsole("Press Enter to return to main menu...");
}

void getFeedback() {
    clearScreen();
    callLogo();
    string feedbackInput;
    cout << "\nPlease provide your feedback: ";
    getline(cin, feedbackInput);

    // Save feedback to external file
    ofstream outFile("feedback.txt", ios::app);
    if (outFile.is_open()) {
        outFile << feedbackInput << "\n";
        outFile.close();
    }

    cout << "Thank you for your feedback! (Saved)" << endl;
    pauseConsole("Press Enter to return to main menu...");
}

int main() {
    string menuInput;
    bool running = true;

    while (running) {
        clearScreen();
        callLogo();
        cout << "Welcome to Pineapple Store! Find your best devices here!" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "(1) Begin shopping\n"
            << "(2) Customer service\n"
            << "(3) Feedback\n"
            << "(4) Daily Report\n"
            << "(5) Quit\n"
            << "--------------------------------------------------------" << endl;
        cout << "Enter your option: ";

        cin >> menuInput;
        clearInputBuffer();

        if (menuInput.length() != 1) {
            cout << "\nInvalid option! Please enter a single number between 1-5.\n";
            pauseConsole("Press Enter to continue...");
            continue;
        }

        char menuChoice = menuInput[0];

        switch (menuChoice) {
        case '1': {
            bool shopping = true;
            while (shopping) {
                clearScreen();
                callLogo();
                string phoneInput;
                cout << "\nAvailable Products:" << endl;
                cout << "(1) Pineapple 1 - RM 999\n"
                    << "(2) Pineapple 1 Pro - RM 1499\n"
                    << "(3) Pineapple 1 Pro Max - RM 2499\n"
                    << "(4) PineBook - RM 2999\n"
                    << "(5) Back to Main Menu\n"
                    << "Select a product: ";
                cin >> phoneInput;
                clearInputBuffer();

                if (phoneInput.length() == 1 && phoneInput[0] >= '1' && phoneInput[0] <= '4') {
                    char phone = phoneInput[0];
                    displayProductInfo(phone);
                    double price = getProductPrice(phone);

                    string actionChoice;
                    cout << "\nSelect Action:\n"
                        << "(1) Place an order\n"
                        << "(2) Check customer reviews\n"
                        << "(3) Cancel and return\n"
                        << "Choice: ";

                    while (true) {
                        cin >> actionChoice;
                        clearInputBuffer();
                        if (actionChoice == "1" || actionChoice == "2" || actionChoice == "3") {
                            break;
                        }
                        cout << "Invalid choice! Please enter 1, 2, or 3: ";
                    }

                    if (actionChoice == "2") {
                        displayProductReviews(phone);
                        continue; // Stay in shopping loop to choose again
                    }
                    else if (actionChoice == "3") {
                        cout << "Order cancelled." << endl;
                        pauseConsole("Press Enter to continue...");
                        continue;
                    }

                    int quantity = 0;
                    string qtyInput;
                    cout << "Enter quantity (1-20): ";

                    while (true) {
                        cin >> qtyInput;
                        clearInputBuffer();

                        if (isStrictInteger(qtyInput)) {
                            try {
                                quantity = stoi(qtyInput);
                                if (quantity >= 1 && quantity <= 20) {
                                    break;
                                }
                            }
                            catch (...) {}
                        }
                        cout << "Invalid quantity! Please enter a whole integer between 1 and 20: ";
                    }

                    paymentAndReceipt(phone, price, quantity);
                    shopping = false;
                }
                else if (phoneInput == "5") {
                    shopping = false;
                }
                else {
                    cout << "Invalid product selection!" << endl;
                    pauseConsole("Press Enter to continue...");
                }
            }
            break;
        }
        case '2':
            customerService();
            break;
        case '3':
            getFeedback();
            break;
        case '4':
            displayDailyReport();
            break;
        case '5':
            cout << "\nThank you for shopping with us!\n";
            running = false;
            break;
        default:
            cout << "\nInvalid option! Please enter a number between 1-5.\n";
            pauseConsole("Press Enter to return to main menu...");
            break;
        }
    }

    return 0;
}