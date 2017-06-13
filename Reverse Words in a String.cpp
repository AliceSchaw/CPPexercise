#include <stack>
#include <iostream>
#include <string>
#include <iterator>
using namespace std;
class Solution{
public:
	void reverseWords(string &s){
		stack<int> word;
		stack<int> sentence;

		int i=0;
		while(i<=s.size()){
			if(i==s.size()||s[i]==' '){
				if(!word.empty()){
					if(!sentence.empty()){
						sentence.push(' ');
					}
					while(!word.empty()){
						sentence.push(word.top());
						
						word.pop();
					}
				}
			}else{
				word.push(s[i]);
			}
			i++;
		}
		s.clear();
		while(!sentence.empty()){
			s.push_back(sentence.top());
			
			sentence.pop();
		}
    
	}
};


int main(void)
{
    string s="the sky is blue";
    //cout<<s<<endl;
    Solution *p=new Solution;
    p->reverseWords(s);
    cout<<s<<endl;
    
}