#ifndef MOVE
#define MOVE

#include<stack>
#include<math.h>
#include"judge.h"
using namespace std;
struct cmp {
	bool operator ()(vector<int> a, vector<int> b) {
		return a[a.size() - 1] > b[b.size() - 1];
	}
};
class clsMove {
	vector<int> state;
	clsJudge judge;
public:
	vector<int> GetState() {
		return state;
	}
	void resetState(vector<int> state) {
		this->state.clear();
		for (int i = 0; i < state.size(); i++)
			this->state.push_back(state[i]);
	}
	int findN(vector<int> v, int n) {
		for (int i = 0; i < v.size(); i++)
			if (v[i] == n)
				return i;
		return -1;
	}
	int findN(vector<int> v, int n, int maxsize) {
		for (int i = 0; i < v.size() && i < maxsize; i++)
			if (v[i] == n)
				return i;
		return -1;
	}
	bool find0(vector<int> limit) {
		if (findN(limit, findN(state, 0, N)) != -1)
			return true;
		return false;
	}
	void moveInStep(int &s1, int &s2) {
		s1 = s1 ^ s2;
		s2 = s2 ^ s1;
		s1 = s1 ^ s2;
	}
	bool movable(int op) {
		bool flag = true;
		vector<int> limit;
		switch (op)
		{
		case 0:
			for (int i = 0; i < sqrt(N); i++)
				limit.push_back(sqrt(N) * (i + 1) - 1);
			if (find0(limit))
				flag = false;
			break;
		case 1:
			for (int i = 0; i < sqrt(N); i++)
				limit.push_back(N - sqrt(N) + i);
			if (find0(limit))
				flag = false;
			break;
		case 2:
			for (int i = 0; i < sqrt(N); i++)
				limit.push_back(sqrt(N) * i);
			if (find0(limit))
				flag = false;
			break;
		default:
			for (int i = 0; i < sqrt(N); i++)
				limit.push_back(i);
			if (find0(limit))
				flag = false;
			break;
		}
		return flag;
	}
	bool swapTemp(int op) {
		if (movable(op)) {
			int i0 = findN(state, 0, N);
			switch (op) {
			case 0:
				moveInStep(state[i0], state[i0 + 1]);
				break;
			case 1:
				moveInStep(state[i0], state[i0 + 3]);
				break;
			case 2:
				moveInStep(state[i0], state[i0 - 1]);
				break;
			default:
				moveInStep(state[i0], state[i0 - 3]);
				break;
			}
			return  true;
		}
		return false;
	}
	void displayVector(vector<int> v) {
		if (v[N + 1] != -1)
			cout << v[N + 1] << "->" << endl;
		for (int i = 0; i < sqrt(N); i++) {
			for (int j = 0; j < sqrt(N); j++)
				cout << v[i * sqrt(N) + j] << '\t';
			cout << endl;
		}
	}
	void displayResult(queue<vector<int>> open, queue<vector<int>> close) {
		vector<vector<int>> f;
		f.push_back(open.back());
		int i = 0;
		int p = f[i][N];
		while (p != -1) {
			f.push_back(judge.findInQueue(close, f[i++], N + 2, p));
			p = f[i][N];
		}
		for (; i >= 0; i--) {
			displayVector(f[i]);
		}
		cout << "step: " << f.size() - 1 << endl;
		cout << "open: " << open.size() << " close: " << close.size() << endl;
	}
	void displayResult(stack<vector<int>> open, queue<vector<int>> close) {
		vector<vector<int>> f;
		f.push_back(open.top());
		int i = 0;
		int p = f[i][N];
		while (p != -1) {
			f.push_back(judge.findInQueue(close, f[i++], N + 2, p));
			p = f[i][N];
		}
		for (; i >= 0; i--) {
			displayVector(f[i]);
		}
		cout << "step: " << f.size() - 1 << endl;
		cout << "open: " << open.size() << " close: " << close.size() << endl;
	}
	void displayResult(priority_queue<vector<int>, vector<vector<int>>, cmp> open, queue<vector<int>> close) {
		vector<vector<int>> f;
		f.push_back(open.top());
		int i = 0;
		int p = f[i][N];
		while (p != -1) {
			f.push_back(judge.findInQueue(close, f[i++], N + 2, p));
			p = f[i][N];
		}
		for (; i >= 0; i--) {
			displayVector(f[i]);
		}
		cout << "step: " << f.size() - 1 << endl;
		cout << "open: " << open.size() << " close: " << close.size() << endl;
	}
};

#endif // !MOVE
#pragma once
