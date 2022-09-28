#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

typedef struct {
	string opers;
	int remainder; 
} expr; 

int main(void){
	int N; 
	cin >> N; // 2 - 10,000
	vector<int> vals(N); 
	for(int i=0; i<N; i++) cin >> vals[i]; // each 1 - 100

	expr init_expr; 
	init_expr.remainder = -1; 
	vector<expr> results(101, init_expr); 
	results[vals[0]].remainder = vals[0]; 
	for(int step=1; step<N; step++){
		vector<expr> res2(101, init_expr); 
		int stepval = vals[step]; 
		for(int j=0; j<=100; j++){
			int amount = results[j].remainder; 
			if (amount==-1) continue; 
			int ans1 = (amount+stepval)%101; 
			int ans2 = ((amount-stepval)+101)%101; 
			int ans3 = (amount*stepval)%101; 
			res2[ans1].remainder = ans1; 
			res2[ans2].remainder = ans2; 
			res2[ans3].remainder = ans3; 
			res2[ans1].opers = results[j].opers+"+"; 
			res2[ans2].opers = results[j].opers+"-"; 
			res2[ans3].opers = results[j].opers+"*"; 
		}
		results.swap(res2); 
	}
	cout << vals[0]; 
	const string& opstring = results[0].opers; 
	for(int i=1; i<N; i++){
		cout << opstring[i-1] << vals[i];
	}
	cout << endl; 
	return 0; 
}
