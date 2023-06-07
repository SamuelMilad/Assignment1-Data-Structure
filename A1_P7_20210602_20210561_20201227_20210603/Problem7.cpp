
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;
bool comparison(string c1, string c2) {
	return c1 < c2;
}
vector<string> BaisedSort(vector<string> V) {
	int NUM = V.size();
	sort(V.begin(), V.end(), comparison);
	return V;
}
void DISPLAY(vector<string> songs) {
	for (int i = 0; i < songs.size(); i++) {
		cout << songs[i] << endl;
	}
	cout << endl;
}


int main()
{
	int num;
	cout << "ENTRE THE NUMBER OF SONGS : ";
	cin >> num;
	vector<string> songs;
	string name;
	cout << "ENTRE SONG'S NAME: \n";
	for (int i = 0; i < num; i++) {
		cin >> name;
		cout << "---------------- \n";
		songs.push_back(name);
	}
	cout << endl;
	cout << endl;
	cout << "---------------\n";
	songs = BaisedSort(songs);
	cout << "AFTER SORTING \n";
	cout << "---------------\n";
	DISPLAY(songs);

	return 0;
}