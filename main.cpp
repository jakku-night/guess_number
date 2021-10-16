// Program Name: Guess Number
// Includes:
#include <iostream>
#include <cstdlib>

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
void print_vector(int* vector);
void guess_loop();
void display_instructions();
void prompt_reset();

// Main:
int main(){

    do{
        gen_number();
        display_instructions();
        guess_loop();
    }while(!end_game);
    prompt_reset();
    return 0;
}

// Global Definitions:

void display_instructions(){
    cout << "Try to guess the number!" << endl;
    cout << "Try to guess the number by input a 4-not-repeated digit number." << endl;
    cout << "The program will give you some hints to reach the goal." << endl;
    cout << "The letter 'A' represents the digits you guessed in the correct position." << endl;
    cout << "The letter 'B' represents the digits you guessed in the wrong position." << endl;
}

void gen_number(){
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

void print_vector(int* vector, int length){
    for(int i = 0; i < length; i++){
        cout << vector[i] << endl;
    }
}

void enter_number(){
    cout << "Insert your number:" << endl;
    do{
        err = false;
        cin >> input;
        for(int i = 0; i < 4; i++){
            if((int)input[i] < 48 || (int)input[i] > 58){
                err = true;
            }
        }
        for(int i = 0; i < 4; i++){
            for(int j= 0; j < 4; j++){
                if(i != j){
                    if((int)input[i] == input[j]){
                        err = true;
                    }
                }
            }
        }
        if(err){
            cout << "Bad input. Try again." << endl;
        }else{
            for (int i = 0; i < 4; i++){
                input_number[i] = (int)input[i] - 48;
            }
        }
    }while(err);
}

bool compare_numbers(){
    for(int i = 0; i < 4; i++){
        for(int j= 0; j < 4; j++){
            if(input_number[i] == number[j]){
                if(i == j){
                    a++;
                }else{
                    b++;
                }
            }
        }
    }
    cout << "Digits in place: " << a << "A" << endl;
    cout << "Digits in the number: " << b << "B" << endl;
    if(a < 4){
        return false;
    }else{
        return true;
    }
}

void guess_loop(){
    bool end_loop = false;
    do{
        a = 0;
        b = 0;
        enter_number();
        end_loop = compare_numbers();
    }while(!end_loop);
}

void prompt_reset(){
    char res = '0';
    cout << "You Win!!!" << endl;
    cout << "Would you want to try again? [Y/n]:" << endl;
    cin >> res;
    switch (res){
        case 'Y':
            end_game = false;
            break;
        case 'y':
            end_game = false;
            break;
        case 'N':
            end_game = true;
            break;
        case 'n':
            end_game = true;
            break;
        default:
            end_game = false;
            break;
    }
}