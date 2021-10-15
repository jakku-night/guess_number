#include <iostream>

using namespace std;

bool end_game = false;
bool err = false;
int rand_number[4] = {0, 0, 0, 0};
int guess_number[4] = {0, 0, 0, 0};
char input_number[5] = {0, 0, 0, 0, 0};

void enter_number(){
    cin >> input_number;
    for(int i = 0; i < 4; i++){
        guess_number[i] = (int)input_number[i] - 48;
    }
}

void generate_number(){
    for(int i = 0; i < 4; i++){
        rand_number[i] = rand() % 10;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            while(rand_number[i] == rand_number[j] && i != j){
                rand_number[i] = rand() % 10;
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
        generate_number();
        err = false;
        while(!err){
            enter_number();
            compare_numbers();
        }
    }

    return 0;
}
