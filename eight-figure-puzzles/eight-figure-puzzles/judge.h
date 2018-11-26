#ifndef JUDGE
#define JUDGE

#include<vector>
#include<queue>
#include<iostream>
#define N 9
using namespace std;
class clsJudge {
public:
	bool vectorEqual(vector<int> v1, vector<int> v2) {
		bool flag = true;
		for (int i = 0; i < N && flag; i++)
			if (v1[i] != v2[i]) {
				flag = false;
				break;
			}
		return flag;
	}
	bool findInQueue(queue<vector<int>> q, vector<int> v) {
		bool flag = false;
		for (int i = 0; i < q.size(); i++) {
			if (vectorEqual(q.front(), v)) {
				flag = true;
				break;
			}
			q.push(q.front());
			q.pop();
		}
		return flag;
	}
	vector<int> findInQueue(queue<vector<int>> q, vector<int> v, int index, int n) {
		for (int i = 0; i < q.size(); i++) {
			if (q.front()[index] == n)
				return q.front();
			q.push(q.front());
			q.pop();
		}
		return v;
	}
};

#endif // !JUDGE
#pragma once
