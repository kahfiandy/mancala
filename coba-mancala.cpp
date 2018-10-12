#include <cstdlib>
#include <iostream>
#include <string>


using namespace std;



//Array dalam pits, dan score
	void displayboard(int boardvalue[14], int score[2]);
	void makemove(int boardvalue[14],int &player, int score[2]);
	void winner(int score[2]);


int main()
{ //Array untuk menyimpan nilai-nilai pada pits, dan nilai keseluruhan jalur

	int finished[2] = {4,4};
	int score[2] = {0};
	int boardvalue[14];
	int player = 0;
	for (int i = 0; i < 14; i ++)
{
	boardvalue[i] = 4;
}
	boardvalue[0] = 0;
	boardvalue[7] = 0;


while (finished[0] > 0 && finished[1] > 0)
{
	displayboard(boardvalue, score);
	finished[0] = 0;
	finished[1] = 0;
//Looping untuk bergerak atau memulai
for (int i = 1; i < 14; i ++)
{
if((i >0 && i <7) && boardvalue[i] > 0 )
finished[0]++;
if((i >7 && i <13) && boardvalue[i] > 0 )
finished[1]++;
}
makemove(boardvalue, player, score);
player = !player;
}
}

void displayboard(int boardvalue[14], int score[2])
{
cout << "Pemain Pertama : " << score[0] << " " << "Pemain Kedua : " 
<< score[1] << endl;
cout << endl << "\tA\tB\tC\tD\tE\tF\n\t";
for (int i = 1; i < 7; i ++)
cout << boardvalue[i] << "\t";
cout << endl << " " << boardvalue[0] << "\t\t\t\t\t\t " 
<< boardvalue[7] << endl << "\t";
for (int i = 8; i < 14; i ++)
cout << boardvalue[i] << "\t";
cout << endl << "\tG\tH\tI\tJ\tK\tL";

cout << endl << endl << endl;
}

void makemove(int boardvalue[14],int &player, int score[2])
{
string Players[2] = {"Pemain 1","Pemain 2"};
bool ok;
char col;
int stones, x, pit, start_pit;
cout << Players[player] << "'Mulai" << endl;


do
{
ok = false;
cout << endl << "Anda ingin memilih kolom mana? (";
cout<<(player==0 ? " A to F " : " G to L ");
cout << ") _\b";
cin >> col;
col = toupper(col);
if(((col >= 'A' && col <= 'F') && player == 0) && 
boardvalue[col-64] > 0 || ((col >= 'G' && col <= 'L') 
&& player == 1) && boardvalue[col-63] > 0)
ok = true;
else
cout << endl << "Tidak ada pit."<<endl;

if(((col>='A'&&col<='F')&&player == 1) || ((col >= 'G' && col <= 'L') 
&& player == 0))
cout << "Batu-batu itu bukan milikmu. Coba lagi.." << endl;
if(col > 'L')
cout << "KESALAHAN: Lokasi tidak ada" << endl;
}while (!ok);

if(col-64 < 7)
{
stones = boardvalue[col-64];
boardvalue[col-64] = 0;
pit = (col-64)-1;
start_pit = (col-64);
if(pit<0)
pit = 8;
}
else
{
stones = boardvalue[col-63];
boardvalue[col-63] = 0;
pit = (col-63)+1;
start_pit = (col-63);
if(pit>13)
pit = 7;
}
cout << "Stones = " << stones << endl;

for(x = 0; x < stones; x++)
{
if(pit >= 0 && pit < 8 )
{
if(x < stones)
{

if(player == 1)
{
if(pit == 0)
{
pit = 8;
//boardvalue[pit]++;
//melanjutkan;

}
}
if(pit >= 0 && pit < 8 )
{
boardvalue[pit]++;
if(x+1 < stones)
{
pit--;
if (pit < 0)
pit = 8;
}
}
}
}

if(pit > 7 && pit < 14 )
{

if(x < stones)
{
if(player == 0)
{
if(pit+1 == 1)
{
pit = 6;
//boardvalue[pit]++;
//continue;
}
}
boardvalue[pit]++;
if(x+1 < stones)
{
pit++;
if(pit > 13)
pit = 7;
}
}
}
}

if(abs(pit-7 == start_pit) && boardvalue[start_pit] == 0 )
{
if(player == 0)
{
score[0]+= boardvalue[pit];
boardvalue[0]+= boardvalue[pit];
boardvalue[pit] = 0;
}
if(player == 1)
{
score[1]+= boardvalue[pit];
boardvalue[7]+= boardvalue[pit];
boardvalue[pit] = 0;
}
}
if(player == 1)
{
if(pit == 7 && x == stones)
{
cout << Players[player] << " memiliki giliran lain!"<<endl;
player = !player;
}
}
if(player == 0)
{
if(pit == 0 && x == stones)
{
cout << Players[player] << " memiliki giliran lain!"<<endl;
player = !player;
}
}

}

