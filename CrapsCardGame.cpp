/**
 * Author: Josh Curry
 * Description: The game of Craps
 */

// Headers
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

// Prints a die with 1 dot
void diceOne(){
  cout << ",---------," << endl;
  cout << "|         |" << endl;
  cout << "|    O    |" << endl;
  cout << "|         |" << endl;
  cout << "'---------'" << endl;
}

// Prints a die with 2 dot
void diceTwo(){
  cout << ",---------," << endl;
  cout << "| O       |" << endl;
  cout << "|         |" << endl;
  cout << "|       O |" << endl;
  cout << "'---------'" << endl;
}

// Prints a die with 3 dots
void diceThree(){
  cout << ",---------," << endl;
  cout << "| O       |" << endl;
  cout << "|    O    |" << endl;
  cout << "|       O |" << endl;
  cout << "'---------'" << endl;
}

// Prints a die with 4 dots
void diceFour(){
  cout << ",---------," << endl;
  cout << "| O     O |" << endl;
  cout << "|         |" << endl;
  cout << "| O     O |" << endl;
  cout << "'---------'" << endl;
}

// Prints a die with 5 dot
void diceFive(){
  cout << ",---------," << endl;
  cout << "| O     O |" << endl;
  cout << "|    O    |" << endl;
  cout << "| O     O |" << endl;
  cout << "'---------'" << endl;
}

// Prints a die with 6 dot
void diceSix(){
  cout << ",---------," << endl;
  cout << "| O     O |" << endl;
  cout << "| O     O |" << endl;
  cout << "| O     O |" << endl;
  cout << "'---------'" << endl;
}

// Prints correct die based on number provided
void printDice(int num){
    
    switch (num)
    {
        case 1:
            diceOne();
            break;
        case 2:
            diceTwo();
            break;
        case 3:
            diceThree();
            break;
        case 4:
            diceFour();
            break;
        case 5:
            diceFive();
            break;
        case 6:
            diceSix();
            break;
    }
}

// Rolls a 6-sided die
int rollDie(){
  int die = rand() % 7;
  while(die == 0){
    die = rand() % 7;
  }
  return die;
}

int main() {
  // Variable declaration
  unsigned int seed = time(0);
  srand(seed);
  int comeOut = 0;
  int bank = 100;
  int charity = 0;
  string roll;
  
  // Game loop that runs until player is bankrupt
  while(bank > 0){

    //Prompts user for bet
    cout << "How much money would you like to donate to charity? ";
    cin >> charity;

    //Checks if user can bet that much money
    while(charity > bank){
        cout << "You don't have that much money. You only have $" << bank << ". Try again." << endl;
        cin >> charity;
    }

    //Asks user to press enter to roll
    cout << "Press enter to roll your come out: " << endl;
    roll = getchar();
    cout << endl;

    //Rolls dice and stores the sum
    int temp = rollDie();
    int temp2 = rollDie();
    printDice(temp);
    printDice(temp2);
    comeOut = temp + temp2;

    // Win/lose conditions
    if(comeOut == 2 || comeOut == 3 || comeOut == 12){
      cout << "You lose! Your come out roll was " << comeOut << "." << endl;
      bank -= charity;
      cout << "Bank: " << bank << endl;
    }
    else if(comeOut == 7 || comeOut == 11){
      cout << "You win! Your come out roll was " << comeOut << "." << endl;
      bank += charity;
      cout << "Bank: " << bank << endl;
    }
    else{
      int die = 0;
      int die1 = 0;
      int die2 = 0;
      while(die != comeOut){
        cout << "Come out roll: " << comeOut << endl;
        cout << "Bank account: " << bank << endl;
        cout << "Press enter to roll." << endl;
        roll = getchar();
        die1 = rollDie();
        die2 = rollDie();
        die = die1 + die2;
        printDice(die1);
        printDice(die2);
        cout << "You rolled: " << die << endl;
        if(die == 7){
          cout << "You rolled a 7 so your money goes to charity!" << endl;
          bank -= charity;
          charity += charity;
          cout << "Bank: " << bank << endl;
          break;
        }
      }
      if(die == comeOut){
        cout << "You rolled: " << comeOut << ", your come out roll. You win!" << endl;
        bank += charity;
        cout << "Bank: " << bank << endl;
      }
    }
    
  }
  cout << "You went bankrupt!" << endl;
}