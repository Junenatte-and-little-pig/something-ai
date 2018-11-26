#ifndef BFSMOVE
#define BFSMOVE

#include"move.h"
using namespace std;
class clsBfsMove :public clsMove {
	queue<vector<int>> open;
	queue<vector<int>> close;
	vector<int> originState;
	vector<int> targetState;
	vector<int> operators = { 0,1,2,3 };
	clsJudge judge;
public:
	clsBfsMove(vector<int> originState, vector<int> targetState) {
		this->originState = originState;
		this->targetState = targetState;
	}
	void bfsMove() {
		open.push(originState);
		vector<int> nowState;
		int child = 1;
		bool success = false;
		while (!open.empty()) {
			vector<int> front = open.front();
			int parent = front[N + 2];
			if (judge.vectorEqual(front, targetState)) {
				success = true;
				break;
			}
			else {
				close.push(front);
				open.pop();
				for (int i = 0; i < 4; i++) {
					resetState(front);
					nowState.clear();
					if (swapTemp(operators[i])) {
						for (int s = 0; s < N; s++)
							nowState.push_back(GetState()[s]);
						nowState.push_back(parent);
						nowState.push_back(i);
						if (!judge.findInQueue(close, nowState)) {
							nowState.push_back(child++);
							open.push(nowState);
							if (judge.vectorEqual(nowState, targetState)) {
								success = true;
								break;
							}
							for (int j = 0; j < nowState.size(); j++)
								cout << nowState[j] << '\t';
							cout << endl;
						}
					}
				}
			}
			if (success) {
				cout << "success" << endl;
				break;
			}
		}
		if (open.empty())
			cout << "fail" << endl;
		else
			displayResult(open, close);
	}
};

#endif // !BFSMOVE
#pragma once
