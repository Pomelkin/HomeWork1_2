#include <fstream>
#include <windows.h>
#pragma hdrstop
#include "pt4.h"
using namespace std;
/*
const int NMAX = 15;
char M[NMAX][NMAX];
int N;
int K(0);
int XC, YC;
int MAX(0);

void GetLen(int X, int Y) {
	M[X][Y] = '+';
	K++;
	if (X == XC && Y == YC && K > MAX)
		MAX = K;
	else {
		if (X != 0 && M[X-1][Y] == ' ') GetLen(X-1, Y);
		if (Y != N-1 && M[X][Y+1] == ' ') GetLen(X, Y+1);
		if (X != N-1 && M[X+1][Y] == ' ') GetLen(X+1, Y);
		if (Y != 0 && M[X][Y-1] == ' ') GetLen(X, Y-1);
	}
	M[X][Y] = ' ';
	K--;
}

void ReadLab(ifstream &fin) { string line; int j;
	for (int i = 0; i < N; i++) {
		getline(fin, line);
		for (j = 0; j < line.length(); j++)
			M[i][j] = line[j];
	}
}
*/
const int NMAX = 15;

bool M[NMAX][NMAX];

int N, K(0);

int XC, YC;

int MAX(0);

void Step(int X, int Y) {
	if (M[X][Y]) { K++;
		M[X][Y] = false;
		if (X == XC && Y == YC) {
			if (K > MAX)
				MAX = K;
		}
		else {
			Step(X, Y+1);
			Step(X+1, Y);
			Step(X, Y-1);
			Step(X-1, Y);
		}
		M[X][Y] = true;
		K--;
	}
}

void ReadM(ifstream &fin) { string line;
	for (int i = 0; i < N; i++) {
		getline(fin, line);
		for (int j = 0; j < N; j++)
			M[i][j] = line[j]-77;
	}
}


void Solve()
{
    Task("BackTrack11");
	/*
	string fname; pt >> fname;
	ifstream fin(fname);
	int X, Y;
	pt >> N >> X >> Y >> XC >> YC;
	ReadLab(fin); X--; Y--; XC--; YC--;
	GetLen(X, Y);
	pt << MAX;
	fin.close();
	*/
	string fname; pt >> fname;
	int X, Y; pt >> N >> X >> Y;
	pt >> XC >> YC; XC--; YC--;
	X--; Y--;
	ifstream fin(fname);
	ReadM(fin);
	Step(X, Y);
	pt << MAX;
}
