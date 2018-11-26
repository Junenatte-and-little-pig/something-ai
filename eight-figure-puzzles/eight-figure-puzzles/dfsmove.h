#ifndef DFSMOVE
#define DFSMOVE

#include"move.h"
class clsDfsMove :public clsMove {
	stack<vector<int>> open;
	queue<vector<int>> close;
	vector<int> originState;
	vector<int> targetState;
	vector<int> operators = { 0,1,2,3 };
	clsJudge judge;
public:
	clsDfsMove(vector<int> originState, vector<int> targetState) {
		originState.push_back(0);
		this->originState = originState;
		this->targetState = targetState;
	}
	void dfsMove() {
		open.push(originState);
		vector<int> nowState;
		int child = 1;
		bool success = false;
		while (!open.empty()) {
			vector<int> front = open.top();
			int parent = front[N + 2];
			int depth = front[N + 3];
			if (judge.vectorEqual(front, targetState)) {
				success = true;
				break;
			}
			else {
				close.push(front);
				open.pop();
				if (depth < 15) {
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
								nowState.push_back(depth + 1);
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

#endif // !DFSMOVE
#pragma once
