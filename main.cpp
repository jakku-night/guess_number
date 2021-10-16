// Program Name: Guess Number
// Includes:
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Global Variables:
bool end_game = false;
bool err = false;
int a = 0, b = 0;
int number[4] = {0, 0, 0, 0};
int input_number[4] = {0, 0, 0, 0};
char input[5] = {0, 0, 0, 0, 0};

// Global Declarations:
void gen_number();
void enter_number();
bool compare_numbers();
void guess_loop();
void display_instructions();
void prompt_reset();

// Main:
int main(){ // Runs the entry program:

    do{
        srand(time(NULL));
        gen_number();
        display_instructions();
        guess_loop();
    }while(!end_game);
    return 0;
}

// Global Definitions:

void display_instructions(){ // Displays all the instructions for the program:
    cout << "Try to guess the number!" << endl;
    cout << "Try to guess the number by input a 4-not-repeated digit number." << endl;
    cout << "The program will give you some hints to reach the goal." << endl;
    cout << "The letter 'A' represents the digits you guessed in the correct position." << endl;
    cout << "The letter 'B' represents the digits you guessed in the wrong position." << endl;
}

void gen_number(){ // Generates a random 4-digit non-repeated number:
    // Charges the array with random numbers:
    for(int i = 0; i < 4; i++){
        number[i] = rand() % 10;
    }
    // Checks each element to be diffrent from each other and changes the value if equals.
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i != j){
                while(number[i] == number[j]){
                    number[i] = rand() % 10;
                }
            }
        }        
    }
    
}

void enter_number(){ // Requests and validates a number to the user:
    cout << "Insert your number:" << endl;
    do{
        err = false; // Sets no error state:
        cin >> input; // Inputs the number as a string:
        for(int i = 0; i < 4; i++){ // Validates that the input contains only numbers:
            if((int)input[i] < 48 || (int)input[i] > 58){
                err = true;
            }
        }
        for(int i = 0; i < 4; i++){ // Validates that there's not repeated digits:
            for(int j= 0; j < 4; j++){
                if(i != j){
                    if((int)input[i] == input[j]){
                        err = true;
                    }
                }
            }
        }
        if(err){ // Throws the issue to the user:
            cout << "Bad input. Try again." << endl;
        }else{ // Stores thre input as an integer format:
            for (int i = 0; i < 4; i++){
                input_number[i] = (int)input[i] - 48;
            }
        }
    }while(err); // Repeats the process if error
}

bool compare_numbers(){
    // Comparates each element of the prompt number with each element of the generated number:
    for(int i = 0; i < 4; i++){
        for(int j= 0; j < 4; j++){
            if(input_number[i] == number[j]){
                if(i == j){ // Comparates if the digit position is right or not and storages the count:
                    a++;
                }else{
                    b++;
                }
            }
        }
    }
    // Prints the hint for the user:
    cout << "Digits in place: " << a << "A" << endl;
    cout << "Digits in the number: " << b << "B" << endl;
    if(a < 4){ // Asks if player won and returns the result:
        return false;
    }else{
        return true;
    }
}

void guess_loop(){ // Executes the main input-hint loop:
    bool end_loop = false;
    do{
        a = 0; // Sets the counter to zero on each time
        b = 0;
        enter_number(); 
        end_loop = compare_numbers(); // Determinates if the loop ends
    }while(!end_loop);
    prompt_reset();
}

void prompt_reset(){ // Requests for restart the game with a Y/n question:
    char res = '0';
    cout << "You Win!!!" << endl;
    cout << "Would you want to try again? [Y/n]:" << endl;
    cin >> res;
    if(res == 'Y' || res == 'y'){
        end_game = false;
    }
    if(res == 'N' || res == 'n'){
        end_game = true;
    }else{
        end_game = false;
    }
}