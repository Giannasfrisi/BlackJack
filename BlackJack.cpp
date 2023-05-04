#include <iostream>
#include <random>
#include <string>

// list of functions 
void playBlackjack();
int getCardPlayer(int playerScore, std:: string cardList);
int getCardValuePlayer(int card, int playerScore, std:: string cardList);
int getCardDealer(int playerScore, std::string cardList);
int getCardValueDealer(int card, int playerScore, std::string cardList);

int main()
{
    std::string input = " ";
    std::cout << "Welcome to Blackjack! Lets play :)" << "\n";
    playBlackjack();

    while (true) {

        std::string input;
        std::cout << std::endl;
        std::cout << "Type 'Yes' for another game" << "\n";
        std::cout << "Type 'No' if not" << "\n";
        std::getline(std::cin, input);
        
        if (input == "No") {
            break;
        }

        if (input == "no") {
            break;
        }

        else if (input == "yes"){
            std::cout << std::endl;
            std::cout << "Welcome back! Lets play again." << "\n";
            playBlackjack();
        }

        else if (input == "Yes") {
            std::cout << std::endl;
            std::cout << "Welcome back! Lets play again." << "\n";
            playBlackjack();
        }
    }
    return 0;
}

// initalizes the scores of the player and dealer
void playBlackjack() {
    int playerScore = 0;
    int dealerScore = 0;
    std:: string input = " ";
    std:: string cardListPlayer = " ";
    std:: string cardListDealer = " ";


    // gives the first two cards to the player and the dealer
    std::cout << "your cards: ";
    playerScore = playerScore + getCardPlayer(playerScore, cardListPlayer);
    std::cout << " and ";
    playerScore = playerScore + getCardPlayer(playerScore, cardListPlayer);
    std::cout << std::endl;

    dealerScore = dealerScore + getCardDealer(playerScore, cardListDealer) + getCardDealer(playerScore, cardListDealer);


    if (playerScore == 21) {
        printf("YOU HIT BLACKJACK!YOU WIN!!!\n");
        return;
    }

    //  players turn
    while (input != "stay"){
        // checks current score 
        if (playerScore > 21) {
            printf("You busted! You lost.\n");
            return;
        }

        // if statements for player 
        std::cout << std::endl;
        std::cout << "Type 'hit' for another card" << "\n";
        std::cout << "Type 'stay' to stop" << "\n";
        std::string input;
        std::getline(std::cin, input);
        std::cout << std::endl;

        if (input == "hit") {
            std::cout << "Next card: ";
            playerScore = playerScore + getCardPlayer(playerScore, cardListPlayer);
            std::cout << std::endl;
            std::cout << "your combined total: ";
            std::cout << playerScore;
        }
        std::cout << std::endl;

        if (input == "stay") {
            break;
        }

    }
// dealers turn
    while (dealerScore < 15) {
        dealerScore = dealerScore + getCardDealer(dealerScore, cardListDealer);
    }

    if (dealerScore > 21) {
        std::cout << "your combined total: ";
        std::cout << playerScore << "\n";
        std::cout << "dealers combined total: ";
        std::cout << dealerScore << "\n";
        printf("Dealer busted! You win!\n");
        return;
    }


    // compare scores, check who wins game
    std::cout << "your combined total: ";
    std::cout << playerScore << "\n";
    std::cout << "dealers combined total: ";
    std::cout << dealerScore << "\n";

    if (playerScore > dealerScore) {
        printf("YAY YOU WON! CONGRATS!!\n");
        return;
    }
    else if (playerScore < dealerScore) {
        printf("Goomba you lost.\n");
        return;
    }
    else {
        printf("See you next time, lets rematch its a tie.\n");
        return;
    }
}


// returns the number that will be added to the card (for player)
int getCardValuePlayer(int card, int playerScore, std::string cardList) {
    if (card > 10) {
        if (card == 11) {
           cardList = cardList + "Jack";
           std::cout << cardList;
        }

        if (card == 12) {
            cardList = cardList + "Queen";
            std::cout << cardList;
        }

        if (card == 13) {
            cardList = cardList + "King";
            std::cout << cardList;
        }

        return 10;
    }
    else if (card == 1) {
        cardList = cardList + "Ace";
        std::cout << cardList;
        if (playerScore > 10) {
            return 1;
        }
        else {
            return 11;
        }
    }
    else {
        cardList = cardList + std::to_string(card);
        std::cout << cardList;
        return card;
    }
}


int getCardPlayer(int playerScore, std:: string cardList)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 13); // define the range
    return getCardValuePlayer(distr(gen), playerScore, cardList);
}


// returns the number that will be added to the card (for dealer)
int getCardValueDealer(int card, int playerScore, std::string cardList) {
    if (card > 10) {
        return 10;
    }
    else if (card == 1) {
        if (playerScore > 10) {
            return 1;
        }
        else {
            return 11;
        }
    }
    else {
        return card;
    }
}

int getCardDealer(int playerScore, std::string cardList)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 13); // define the range
    return getCardValueDealer(distr(gen), playerScore, cardList);
}
