#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 75
#define KEY_LEFT 77
#define KEY_RIGHT 80


struct animalsInfo {
	string nama;
	string habitat;
	string kelangkaan;
	int harga;
};

int main() {
    // Animals Hunter, With Pokemon Style Game
    //Hunting Hewan langka sebanyak mungkin di sebuah pulau rahasia
    
    /*
    KEY_MAP IN GAME
    1 = jalan
    2 = pohon
    5 = batu
    6 = semak
    7 = sungai
    8 = jembatan
	*/
    
    
    int panjangPeta = 15; // x
    int lebarPeta = 12; // y
    int posisiKarakterY = 10;
    int posisiKarakterX = 2;
    int randomAnimal;
    
    animalsInfo animals[]{
		{
			"Giant Crocodile",
			"Water",
			"Rare",
			500000000
		},
		{
			"Red Lion",
			"forest",
			"Super Rare",
			1500000000
		},
		{
			"Silver Elephant",
			"forest",
			"Rare",
			500000000
		},
		{
			"Fire Cobra",
			"bush",
			"Super Legendary",
			500000000000000
		},
		{
			"Lynx",
			"forest",
			"Common",
			2000000
		},
	
	};
    
    cout << "Movement KEY\n";
    cout << "PageUp\n";
    cout << "PageDown\n";
    cout << "ArrowRight\n";
    cout << "ArrowLeft\n";
    cout << "===================\n";
    cout << "Selamat Bermain\n";
    cout << "===================\n";
    
    cout << "Karakter ada di y:" << posisiKarakterY << ", x:" << posisiKarakterX << "\n";
    
    int peta[lebarPeta][panjangPeta] = {
        {5,5,5,5,5,5,1,1,7,7,7,7,6,6,6},
        {5,5,1,1,5,5,1,6,7,7,7,7,6,6,1},
        {1,1,1,1,1,1,1,6,7,7,7,7,5,5,1},
        {2,2,1,1,2,2,2,6,7,7,7,7,5,5,1},
        {2,2,1,1,1,1,1,1,7,7,7,7,5,5,1},
        {2,2,1,1,1,2,2,1,7,7,7,7,5,5,1},
        {2,2,1,1,2,2,2,1,7,7,7,7,6,6,1},
        {2,2,2,1,1,2,2,1,8,8,8,8,1,1,1},
        {2,2,2,1,1,2,2,1,8,8,8,8,2,2,2},
        {5,5,5,1,1,2,1,1,7,7,7,7,2,2,2},
        {1,1,1,1,2,2,6,6,7,7,7,7,2,2,2},
        {5,5,5,5,5,5,6,6,7,7,7,7,2,2,2},
    };
    
    
    int arrowKey = 0;
    
    /*
    #define KEY_UP 72
    #define KEY_DOWN 80
    #define KEY_LEFT 75
    #define KEY_RIGHT 77
    */
    
    while(1) {
    	
    	randomAnimal = rand() % 50;
        // Input Keyboard
        cout << "Input arrow key ";
        arrowKey = getch();
        cout << "Arrow key yang dimasukan " << arrowKey << "\n";
        
        //clear screen
        system("cls");
        
        if (arrowKey == 72 && posisiKarakterY > 0) {
            if (peta[posisiKarakterY - 1][posisiKarakterX] == 1 || peta[posisiKarakterY - 1][posisiKarakterX] == 6 || peta[posisiKarakterY - 1][posisiKarakterX] == 8) {
                posisiKarakterY--;
            }
        } else if (arrowKey == 75 && posisiKarakterX > 0) {
            if (peta[posisiKarakterY][posisiKarakterX - 1] == 1 || peta[posisiKarakterY][posisiKarakterX - 1] == 6 || peta[posisiKarakterY][posisiKarakterX - 1] == 8) {
                posisiKarakterX--;
            }
        } else if (arrowKey == 77 && posisiKarakterX < lebarPeta) {
            if (peta[posisiKarakterY][posisiKarakterX + 1] == 1 || peta[posisiKarakterY][posisiKarakterX + 1] == 6 || peta[posisiKarakterY][posisiKarakterX + 1] == 8) {
                posisiKarakterX++;
            }
        } else if (arrowKey == 80 && posisiKarakterY < panjangPeta) {
            if (peta[posisiKarakterY + 1][posisiKarakterX] == 1 || peta[posisiKarakterY + 1][posisiKarakterX] == 6 || peta[posisiKarakterY + 1][posisiKarakterX] == 8) {
                posisiKarakterY++;
            }
        }
        
        // Render grafik
        for(int y=0; y<lebarPeta; y++) {
            for(int x=0; x<panjangPeta; x++) {
                
                if(posisiKarakterX == x && posisiKarakterY == y) {
                    cout << 0 << " ";
                } else {
                    cout << peta[y][x] << " ";
                }
            }
            cout << "\n";
        }
        
        
        //Cek obstacle
        if (arrowKey == 72 && posisiKarakterY > 0) {
            if (peta[posisiKarakterY - 1][posisiKarakterX] == 2 || peta[posisiKarakterY - 1][posisiKarakterX] == 5 || peta[posisiKarakterY-1][posisiKarakterX] == 7 ) {
                cout << "Hati-hati ada obstacle yg menghalangi jalan!!!\n";
            }
        } else if (arrowKey == 75 && posisiKarakterX > 0) {
            if (peta[posisiKarakterY][posisiKarakterX - 1] == 2 || peta[posisiKarakterY][posisiKarakterX - 1] == 5 || peta[posisiKarakterY-1][posisiKarakterX] == 7 ) {
                cout << "Hati-hati ada obstacle yg menghalangi jalan!!!\n";
            }
        } else if (arrowKey == 77 && posisiKarakterX < (panjangPeta - 1)) {
            if (peta[posisiKarakterY][posisiKarakterX + 1] == 2 || peta[posisiKarakterY][posisiKarakterX + 1] == 5 || peta[posisiKarakterY-1][posisiKarakterX] == 7 ) {
                cout << "Hati-hati ada obstacle yg menghalangi jalan!!!\n";
            }
        } else if (arrowKey == 80 && posisiKarakterY < (lebarPeta - 1)) {
            if (peta[posisiKarakterY + 1][posisiKarakterX] == 2 || peta[posisiKarakterY + 1][posisiKarakterX] == 5 || peta[posisiKarakterY-1][posisiKarakterX] == 7 ) {
                cout << "Hati-hati ada obstacle yg menghalangi jalan!!!\n";
            }
        }
        
        //Cek lokasi player
        if(peta[posisiKarakterX][posisiKarakterY] == 1){
        	cout<<"Player Berada Dijalan!!!\n";
            if (randomAnimal == 1) {
                cout << "Anda Menemukan " << animals[0].nama << " " << animals[0].habitat << " " << animals[0].kelangkaan << " " << animals[0].harga << endl;
                
            }else if (randomAnimal == 2) {
                cout << "Anda Menemukan " << animals[1].nama << " " << animals[1].habitat << " " << animals[1].kelangkaan << " " << animals[1].harga << endl;
                
            }else if (randomAnimal == 3) {
                cout << "Anda Menemukan " << animals[2].nama << " " << animals[2].habitat << " " << animals[2].kelangkaan << " " << animals[2].harga << endl;
                
            }else if (randomAnimal == 4) {
                cout << "Anda Menemukan " << animals[3].nama << " " << animals[3].habitat << " " << animals[3].kelangkaan << " " << animals[3].harga << endl;
                
            }else if (randomAnimal == 5) {
                cout << "Anda Menemukan " << animals[4].nama << " " << animals[4].habitat << " " << animals[4].kelangkaan << " " << animals[4].harga << endl;
                
            }
            
            randomAnimal = 0;
        	
		}else if(peta[posisiKarakterX][posisiKarakterY] == 6){
			cout<<"Player Berada Disemak!!!\n";
			 if (randomAnimal == 1) {
                cout << "Anda Menemukan " << animals[0].nama << "" << animals[0].habitat << "" << animals[0].kelangkaan << "" << animals[0].harga << endl;
                
            }else if (randomAnimal == 2) {
                cout << "You found a " << animals[1].nama << "" << animals[1].habitat << "" << animals[1].kelangkaan << "" << animals[1].harga << endl;
                
            }else if (randomAnimal == 3) {
                cout << "You found a " << animals[2].nama << "" << animals[2].habitat << "" << animals[2].kelangkaan << "" << animals[2].harga << endl;
                
            }else if (randomAnimal == 4) {
                cout << "You found a " << animals[3].nama << "" << animals[3].habitat << "" << animals[3].kelangkaan << "" << animals[3].harga << endl;
                
            }else if (randomAnimal == 5) {
                cout << "You found a " << animals[4].nama << "" << animals[4].habitat << "" << animals[4].kelangkaan << "" << animals[4].harga << endl;
                
            }
            
            
            randomAnimal = 0;
            
		}else if(peta[posisiKarakterX][posisiKarakterY] == 8){
			cout<<"Player Berada Di Jembatan!!!\n";
			 if (randomAnimal == 1) {
                cout << "You found a " << animals[0].nama << animals[0].habitat << animals[0].kelangkaan << animals[0].harga << endl;
                
            }else if (randomAnimal == 2) {
                cout << "You found a " << animals[1].nama << animals[1].habitat << animals[1].kelangkaan << animals[1].harga << endl;
                
            }else if (randomAnimal == 3) {
                cout << "You found a " << animals[2].nama << animals[2].habitat << animals[2].kelangkaan << animals[2].harga << endl;
                
            }else if (randomAnimal == 4) {
                cout << "You found a " << animals[3].nama << animals[3].habitat << animals[3].kelangkaan << animals[3].harga << endl;
                
            }else if (randomAnimal == 5) {
                cout << "You found a " << animals[4].nama << animals[4].habitat << animals[4].kelangkaan << animals[4].harga << endl;
                
            }
            
            
            randomAnimal = 0;
		}
		
    }
     
    
    return 0;
}
