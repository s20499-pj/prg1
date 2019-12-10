#include <iostream>
using namespace std;
//using std::cout;
//using std::cin;
//using std::endl;

class Board{
        char board[10][10];
        public:
        Board(){
                for(int m=0; m<10; m++){
                        for(int n=0; n<10; n++){
                                board[m][n]='~';
                        }
                }
        }
        void change(char x, int m, int n){
                board[m][n]=x;
        }
        void print(int m, int n){
                cout << board[m][n];
        }
        void draw(){
                system("clear");
                for(int m=0; m<10; m++){
                        for(int n=0; n<10; n++){
                                cout << " ";
                                this->print(m,n);
                        }cout << endl;
                }
        }

        void setship(){
                int m=5;
                int n=5;
                char key=' ';
                do{
                        system("clear");
                        char cpmap[10][10];
                        for(int i=0; i<100; i++) cpmap[i/10][i%10]=board[i/10][i%10];
                        cpmap[m][n]='M';
                        for(int m=0; m<10; m++){
                                for(int n=0; n<10; n++){
                                        cout << " " << cpmap[m][n];
                                }cout << endl;
                        }
                        key=getchar();
                        switch(key){
                        case 'w':
                                if(m>0) m--;
                                break;
                        case 'a':
                                if(n>0) n--;
                                break;
                        case 's':
                                if(m<9) m++;
                                break;
                        case 'd':
                                if(n<9) n++;
                                break;
                        }
                }
                while(key!='q');
        }
};


int main(){
	system("stty raw opost");
	Board board;
	board.setship();
	system("stty sane -brkint -imaxbel iutf8");

	return 0;	
}

