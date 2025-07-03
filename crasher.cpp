#include <bits/stdc++.h>
using namespace std;
#define int long long
string tHash(string str){
	vector<char> ht(str.size());
	srand(time(0));
	int M=rand()%32767+str.size();
	int a=rand()%999+1;
	int b=rand()%999+1;
	int c=rand()%999+1;
	for (int i=0;i<ht.size();i++)
		ht[i]=-1;
	for (int i=0;i<str.size();i++){
		int h=(str[i]+a*i+b*i*i+c*i*i*i)%M%str.size();
		while(ht[h]!=-1) h=(h+1)%str.size();
		ht[h]=str[i];
	}
	string ans;
	for (int i=0;i<ht.size();i++)
		if(ht[i]!=-1) ans+=ht[i];
	return ans;
}
signed main(signed argc, char** argv){
	if(argc>1){
		string text;
		ifstream fin(argv[1]);
		string linestr;
		while(getline(fin,linestr)) text+=linestr+"\n";
		text.pop_back();
		text=tHash(text);
		fin.close();
		ofstream fout(argv[1]);
		fout<<text;
		fout.close();
		//system(("del "+string(argv[1])).c_str());
	}
	return 0;
}

