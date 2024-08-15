#include <iostream>
#include <string>

// Function to display a greeting
void greetUser(const std::string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
    std::cout << "Welcome to GitHub Copilot!" << std::endl;
}

// Function to ask user if they want to continue
bool askToContinue() {
    char choice;
    std::cout << "Would you like to see a greeting again? (y/n): ";
    std::cin >> choice;
    return choice == 'y' || choice == 'Y';
}

int main() {
    std::string userName;
    bool continueGreeting = true;

    // Ask for the user's name
    std::cout << "Please enter your name: ";
    std::cin >> userName;

    // Greet the user and ask if they want to continue
    while (continueGreeting) {
        greetUser(userName);
        continueGreeting = askToContinue();
    }

    std::cout << "Goodbye, " << userName << "! Thank you for using GitHub Copilot." << std::endl;

    return 0;
}
