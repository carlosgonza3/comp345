#include "OrdersList.cpp"
#include <iostream>
//test the OrdersList functionality
void testOrdersLists() {
    // Create an instance of OrdersList
    // We need to fix it to match 
    //A player has their own list of orders to be created and executed in the current turn (see Part 3).
    OrdersList orderList;

    // Create and add orders to the list
    // We need to fix it
    orderList.addOrder(new DeployOrder());
    orderList.addOrder(new AdvanceOrder());
    orderList.addOrder(new BombOrder());
    orderList.addOrder(new BlockadeOrder());
    orderList.addOrder(new AirliftOrder());
    orderList.addOrder(new NegotiateOrder());

    // Display orders
    std::cout << "Initial Orders List:" << std::endl;
    orderList.printOrders();

    char moveOrder;
    // Ask the player if they want to move an order
    do {
        std::cout << "Do you want to move an order? (y/n): ";
        std::cin >> moveOrder;
         // Check for valid input
        if (moveOrder != 'y' && moveOrder != 'Y' && moveOrder != 'n' && moveOrder != 'N') {
            std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
        }
    } while (moveOrder != 'y' && moveOrder != 'Y' && moveOrder != 'n' && moveOrder != 'N');

    if (moveOrder == 'y' || moveOrder == 'Y') {
        // Move an order
        int fromIndex, toIndex;
        
        // Loop until get a valid index
        do {
            std::cout << "Please enter the index of the order to move: ";
            std::cin >> fromIndex;
            // Validate the input
            if (fromIndex < 0 || fromIndex >= static_cast<int>(orderList.getSize())) {
                std::cout << "Invalid index. Please try again." << std::endl;
            }
        } while (fromIndex < 0 || fromIndex >= static_cast<int>(orderList.getSize()));

        // Loop until get a valid index
        do {
            std::cout << "Please enter the new index position for the order: ";
            std::cin >> toIndex;
             // Validate input
            if (toIndex < 0 || toIndex >= static_cast<int>(orderList.getSize())) {
                std::cout << "Invalid index. Please try again." << std::endl;
            }
        } while (toIndex < 0 || toIndex >= static_cast<int>(orderList.getSize()));
        // Move the order to new position
        orderList.move(fromIndex, toIndex);
        std::cout << "\nYou successfully moved the order.";
        std::cout << "\nOrders List after moving the order from position " << fromIndex << " to position " << toIndex << ":" << std::endl;
        std::cout << "\n";
        orderList.printOrders();
    }

    char removeOrder;
    // Ask the player if they want to remove an order
    do {
        std::cout << "Do you want to remove an order? (y/n): ";
        std::cin >> removeOrder;
         // Validate the input
        if (removeOrder != 'y' && removeOrder != 'Y' && removeOrder != 'n' && removeOrder != 'N') {
            std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
        }
    } while (removeOrder != 'y' && removeOrder != 'Y' && removeOrder != 'n' && removeOrder != 'N');

    if (removeOrder == 'y' || removeOrder == 'Y') {
        // Remove the order
        int removeIndex;
        
        // Loop until get a valid index
        do {
            std::cout << "Please enter the index of the order to remove: ";
            std::cin >> removeIndex;
            // Validate the input
            if (removeIndex < 0 || removeIndex >= static_cast<int>(orderList.getSize())) {
                std::cout << "Invalid index. Please try again." << std::endl;
            }
        } while (removeIndex < 0 || removeIndex >= static_cast<int>(orderList.getSize()));
        // Delete the order from List
        orderList.remove(removeIndex);
        std::cout << "\nYou successfully removed the order.";
        std::cout << "\nOrders List after removing the order at position " << removeIndex << ":" << std::endl;
        std::cout << "\n";
        orderList.printOrders();
    }
}
// Main function to call testOrdersLists()
int main() {
    testOrdersLists();
    return 0;
}
