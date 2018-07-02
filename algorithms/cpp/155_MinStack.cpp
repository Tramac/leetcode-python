#include <iostream>
#include <stack>

using namespace std;

class MinStack{
public:
  stack<int> m_data;
  stack<int> m_min;
  MinStack(){
  }
  void push(int x){
	  m_data.push(x);

	  if(m_min.size() == 0 || x < m_min.top())
		  m_min.push(x);
	  else
		  m_min.push(m_min.top());
  }
  void pop(){
	  m_data.pop();
	  m_min.pop();
  }
  int top(){
	  return m_data.top();
  }
  int getMin(){
	  return m_min.top();
  }
};
