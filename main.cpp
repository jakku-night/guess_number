#include <iostream>

using namespace std;

bool end_game = false;
bool err = false;
int rand_number[4] = {0, 0, 0, 0};
int guess_number[4] = {0, 0, 0, 0};
char input_number[5] = {0, 0, 0, 0, 0};

bool enter_number(){
    cin >> input_number;
    bool error = true;
    for(int i = 0; i < 4; i++){
        if((int)input_number[i] < 48 || (int)input_number[i] > 58){
            // Hacer saltar error
            error = false;
        }else{
            guess_number[i] = (int)input_number[i] -48;
        }
        // Resta checkear los numeros repetidos:
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(i != j && guess_number[i] == guess_number[j]){
                    error = false;                    
                }
            }
        }
    }
    return error;
}

void generate_number(){
    for(int i = 0; i < 4; i++){
        rand_number[i] = rand() % 10;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            while(rand_number[i] == rand_number[j] && i != j){
                rand_number[i] = rand() % 10;
                // n / 10 => R = 0 - 9
            }
        }
    }
}

void compare_numbers(){
    if(!err){
        int a = 0;
        int b = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(rand_number[j] == guess_number[i]){
                    if(j == i){
                        a++;
                    }else{
                        b++;
                    }
                }
            }
        }
        printf("%iA%iB\n", a, b);
        if(a == 4){
            cout << "You Win!" << endl;
            cout << "Will you try again? [Y|N]: " << endl;
            char res;
            cin >> res;
            if(res == 'Y' || res == 'y'){
                end_game = false;
            }
            if(res == 'N' || res == 'n'){
                end_game = true;
            }
            err = true;
        }
    }
}

int main(){

    cout << "Try to guess the number!" << endl;
    while(!end_game){
        bool entry = false;
        generate_number();
        err = false;
        while(!err){
            while(!entry){
                entry = enter_number();
            }
            compare_numbers();
        }
    }

    return 0;
}
