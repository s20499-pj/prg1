#include <iostream>

using std::cout;
using std::cin;
using std::endl;

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
        void setships(int size){
                int m=5;
                int n=5;
		int r=0;
                char key=' ';
                char cpmap[10][10];
                do{
                        system("clear");
                        for(int i=0; i<100; i++) cpmap[i/10][i%10]=board[i/10][i%10];
			if(r==0){
				for(int i=0; i<size; i++) cpmap[m][n+i]='M';
        	                for(int i=0; i<100; i++){
					cout << " " << cpmap[i/10][i%10];
	                               	if(i%10==9) cout << endl;
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
        	                        if(n<(10-size)) n++;
                	                break;
				case 'r':
					m=5;
					n=5;
					if(r==0) r++;
					else r--;
					break;
				case 13:	//enter
					for(int i=0; i<size; i++) board[m+i][n]=cpmap[m][n+i];
					break;
        	                }
			}
			else{
				for(int i=0; i<size; i++) cpmap[m+i][n]='M';
         	                for(int i=0; i<100; i++){
					cout << " " << cpmap[i/10][i%10];
	                               	if(i%10==9) cout << endl;
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
                	                if(m<(10-size)) m++;
                        	        break;
	                        case 'd':
        	                        if(n<9) n++;
                	                break;
				case 'r':
					m=5;
					n=5;
					if(r==0) r++;
					else r--;
					break;
				case 13:	//enter
					for(int i=0; i<size; i++) board[m+i][n]=cpmap[m+i][n];
					key='q';
        	                }
			}
                }
                while(key!='q' && key!=13);
        }



};

int main(){
	system("stty raw opost");
	Board board;
	board.setships(4);
	board.setships(3);
	board.setships(2);
	system("stty sane -brkint -imaxbel iutf8");

	return 0;	
}

