#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string arrangement) {
	stack<char> chstack;
	int answer = 0;
	for (int i = 0; i < arrangement.length(); i++)
	{
		if (arrangement[i] == '(') chstack.push(arrangement[i]);
		else{
			chstack.pop();
			if (arrangement[i - 1] == '(')
				answer += chstack.size();
			else
				answer++;
		}
	}
	
	return answer;
}