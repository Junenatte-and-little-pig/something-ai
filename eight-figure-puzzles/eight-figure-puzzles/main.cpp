#include<Windows.h>
#include"bfsmove.h"
#include"dfsmove.h"
#include"ucsmove.h"
using namespace std;
int main() {
	LARGE_INTEGER f;
	LARGE_INTEGER begin, end;
	vector<int> originState = { 2,6,3,1,8,0,7,5,4,-1,-1,0 };
	vector<int> targetState = { 1,2,3,4,0,5,6,7,8 };
	
	QueryPerformanceFrequency(&f);
	
	clsBfsMove *bfsmove = new clsBfsMove(originState, targetState);
	QueryPerformanceCounter(&begin);
	bfsmove->bfsMove();
	QueryPerformanceCounter(&end);
	cout << "bfs running time: " << (double)(end.QuadPart - begin.QuadPart) / (double)f.QuadPart << "s" << endl;
	
	clsDfsMove *dfsmove = new clsDfsMove(originState, targetState);
	QueryPerformanceCounter(&begin);
	dfsmove->dfsMove();
	QueryPerformanceCounter(&end);
	cout << "dfs running time: " << (double)(end.QuadPart - begin.QuadPart) / (double)f.QuadPart << "s" << endl;
	
	clsUcsMove *ucsmove = new clsUcsMove(originState, targetState);
	QueryPerformanceCounter(&begin);
	ucsmove->ucsMove();
	QueryPerformanceCounter(&end);
	cout << "ucs running time: " << (double)(end.QuadPart - begin.QuadPart) / (double)f.QuadPart << "s" << endl;
	
	system("pause");
	return 0;
}
