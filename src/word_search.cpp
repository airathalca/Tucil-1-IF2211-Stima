#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

const int maxheight = 1000;
const int maxword = 1000;
string puzzle[maxheight];
vector<string> wordlist;

void print_puzzle(vector<string> puzzle, ofstream& a){
    for (int i=0;i<puzzle.size();i++){
        for (int j=0;j<puzzle[i].length();j++){
            a << puzzle[i][j] << " ";
        }
        a << endl;
    }
}

int main(){
    clock_t start, end;
    string filename,line,word,add = " ";
    int puzzle_h = 0,puzzle_w = 0;
    int compare = 0;
    bool isWordlist = false;
    cout << "Input nama file txt: " << endl;
    cin >> filename;
    string file_dir = "../test/"; 
    file_dir += filename; 
    ifstream word_puzzle (file_dir);
    if(word_puzzle.is_open()){
        while(getline(word_puzzle, line)){
            if(not isWordlist){
                if(line[0] == '\0'){
                    isWordlist = true;
                }
                else{
                    puzzle[puzzle_h] = "";
                    for(int i=0;i<line.length();i++){
                        if(line[i]!=' '){
                            add[0] = line[i];
                            puzzle[puzzle_h] += add;
                        }
                    }
                    puzzle_w = (int) puzzle[puzzle_h].length();
                    puzzle_h++;
                }
            }
            else{
            	word = "";
                for(int i=0;i<line.length();i++){
                    if(line[i]!=' '){
                        add[0] = line[i];
                        word += add;
                    }
                }
                wordlist.push_back(word);
            }
        }
        vector<string> nothing,answer;
        for (int i = 0;i<puzzle_h;i++){
            nothing.push_back(string(puzzle_w,'-'));
        }
        file_dir = "../test/solution";
        file_dir += filename;
        ofstream answer_file(file_dir);
        start = clock();
        for (int i=0;i<wordlist.size();i++){
            bool right,right_top,right_bot,top,bot,left,left_top,left_bot;
            right=right_top=right_bot=top=bot=left=left_top=left_bot=false;
            int word_length = wordlist[i].length();
            for (int j=0;j<puzzle_h;j++){
                for (int k=0;k<puzzle_w;k++){
                    compare++;
                    if(puzzle[j][k] == wordlist[i][0]){
                        int start_h = j;
                        int start_w = k;
                        right=right_top=right_bot=top=bot=left=left_top=left_bot=true;
                        while(right){
                            if(puzzle_w-start_w<word_length){
                                right = false;
                            }
                            else{
                                for (int l = 1;l<word_length;l++){
                                    compare++;
                                    if(puzzle[start_h][start_w+l]!=wordlist[i][l]){
                                        right = false;
                                        l = word_length;
                                    }
                                }
                                if(right){
                                    answer = nothing;
                                    for(int l=0;l<word_length;l++){
                                        answer[start_h][start_w+l]=puzzle[start_h][start_w+l];
                                    }
                                    print_puzzle(answer, answer_file);
                                    answer_file << endl;
                                    right = false;
                                }
                            }
                        }
                        while(right_top){
                            if(puzzle_w-start_w<word_length || word_length-start_h>1){
                                right_top = false;
                            }
                            else{
                                for (int l = 1;l<word_length;l++){
                                    compare++;
                                    if(puzzle[start_h-l][start_w+l]!=wordlist[i][l]){
                                        right_top = false;
                                        l = word_length;
                                    }
                                }
                                if(right_top){
                                    answer = nothing;
                                    for(int l=0;l<word_length;l++){
                                        answer[start_h-l][start_w+l]=puzzle[start_h-l][start_w+l];
                                    }
                                    print_puzzle(answer, answer_file);
                                    answer_file << endl;
                                    right_top = false;
                                }
                            }
                        }
                        while(right_bot){
                            if(puzzle_w-start_w<word_length || puzzle_h-start_h<word_length){
                                right_bot = false;
                            }
                            else{
                                for (int l = 1;l<word_length;l++){
                                    compare++;
                                    if(puzzle[start_h+l][start_w+l]!=wordlist[i][l]){
                                        right_bot = false;
                                        l = word_length;
                                    }
                                }
                                if(right_bot){
                                    answer = nothing;
                                    for(int l=0;l<word_length;l++){
                                        answer[start_h+l][start_w+l]=puzzle[start_h+l][start_w+l];
                                    }
                                    print_puzzle(answer, answer_file);
                                    answer_file << endl;
                                    right_bot = false;
                                }
                            }
                        }
                        while(left){
                            if(word_length-start_w>1){
                                left = false;
                            }
                            else{
                                for (int l = 1;l<word_length;l++){
                                    compare++;
                                    if(puzzle[start_h][start_w-l]!=wordlist[i][l]){
                                        left = false;
                                        l = word_length;
                                    }
                                }
                                if(left){
                                    answer = nothing;
                                    for(int l=0;l<word_length;l++){
                                        answer[start_h][start_w-l]=puzzle[start_h][start_w-l];
                                    }
                                    print_puzzle(answer, answer_file);
                                    answer_file << endl;
                                    left = false;
                                }
                            }
                        }
                        while(left_top){
                            if(word_length-start_w>1 || word_length-start_h>1){
                                left_top = false;
                            }
                            else{
                                for (int l = 1;l<word_length;l++){
                                    compare++;
                                    if(puzzle[start_h-l][start_w-l]!=wordlist[i][l]){
                                        left_top = false;
                                        l = word_length;
                                    }
                                }
                                if(left_top){
                                    answer = nothing;
                                    for(int l=0;l<word_length;l++){
                                        answer[start_h-l][start_w-l]=puzzle[start_h-l][start_w-l];
                                    }
                                    print_puzzle(answer, answer_file);
                                    answer_file << endl;
                                    left_top = false;
                                }
                            }
                        }
                        while(left_bot){
                            if(word_length-start_w>1 || puzzle_h-start_h<word_length){
                                left_bot = false;
                            }
                            else{
                                for (int l = 1;l<word_length;l++){
                                    compare++;
                                    if(puzzle[start_h+l][start_w-l]!=wordlist[i][l]){
                                        left_bot = false;
                                        l = word_length;
                                    }
                                }
                                if(left_bot){
                                    answer = nothing;
                                    for(int l=0;l<word_length;l++){
                                        answer[start_h+l][start_w-l]=puzzle[start_h+l][start_w-l];
                                    }
                                    print_puzzle(answer, answer_file);
                                    answer_file << endl;
                                    left_bot = false;
                                }
                            }
                        }
                        while(top){
                            if(word_length-start_h>1){
                                top = false;
                            }
                            else{
                                for (int l = 1;l<word_length;l++){
                                    compare++;
                                    if(puzzle[start_h-l][start_w]!=wordlist[i][l]){
                                        top = false;
                                        l = word_length;
                                    }
                                }
                                if(top){
                                    answer = nothing;
                                    for(int l=0;l<word_length;l++){
                                        answer[start_h-l][start_w]=puzzle[start_h-l][start_w];
                                    }
                                    print_puzzle(answer, answer_file);
                                    answer_file << endl;
                                    top = false;
                                }
                            }
                        }
                        while(bot){
                            if(puzzle_h-start_h<word_length){
                                bot = false;
                            }
                            else{
                                for (int l = 1;l<word_length;l++){
                                    compare++;
                                    if(puzzle[start_h+l][start_w]!=wordlist[i][l]){
                                        bot = false;
                                        l = word_length;
                                    }
                                }
                                if(bot){
                                    answer = nothing;
                                    for(int l=0;l<word_length;l++){
                                        answer[start_h+l][start_w]=puzzle[start_h+l][start_w];
                                    }
                                    print_puzzle(answer, answer_file);
                                    answer_file << endl;
                                    bot = false;
                                }
                            }
                        }
                    }
                }
            }
        }
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Time taken by program is : " << fixed  
            << time_taken << setprecision(5); 
        cout << " sec " << endl;
        word_puzzle.close();
        cout << "Total comparations: " << compare << endl;
        cout << "output berhasil disimpan di " << file_dir << endl;
    }
    else{
        cout << "No such file.";
    }
    getch();
}
