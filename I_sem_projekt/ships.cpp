#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
	char board[10][10];
	for(int m=0; m<10; m++){
		for(int n=0; n<10; n++){
			board[m][n]='~';
		}
	}
	for(int m=0; m<10; m++){
		for(int n=0; n<10; n++){
			cout << ' ' << board[m][n];
		}
		cout << endl;
	}
}

