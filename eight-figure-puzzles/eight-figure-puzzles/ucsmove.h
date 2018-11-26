#ifndef UCSMOVE
#define UCSMOVE

#include"move.h"
class clsUcsMove :public clsMove {
	priority_queue<vector<int>, vector<vector<int>>, cmp> open;
	queue<vector<int>> close;
	vector<int> originState;
	vector<int> targetState;
	vector<int> operators = { 0,1,2,3 };
	clsJudge judge;
public:
	clsUcsMove(vector<int> originState, vector<int> targetState) {
		this->targetState = targetState;
		originState.push_back(costCount(originState));
		this->originState = originState;
	}
	int costCount(vector<int> v) {
		int count = 0;
		for (int i = 0; i < N; i++)
			if (v[i] != targetState[i])
				count++;
		return count;
	}
	void ucsMove() {
		open.push(originState);
		vector<int> nowState;
		int child = 1;
		bool success = false;
		while (!open.empty()) {
			vector<int> front = open.top();
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
							nowState.push_back(costCount(nowState));
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
		if (open.empty())
			cout << "fail" << endl;
		else
			displayResult(open, close);
	}
};

#endif // !UCSMOVE
#pragma once
