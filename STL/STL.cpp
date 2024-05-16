#include <bits/stdc++.h>
// #include <array>
// #include <vector>
using namespace std;

pair<int, string> f();

int main()
{
	// **   STL ARRAY
	// array<int, 8> a;
	// for (int i = 0; i < 8; i++)
	// {
	// 	cin >> a[i];
	// }
	// int siz = a.size();
	// cout << siz << endl;
	// for (int i = 0; i < siz; i++)
	// {
	//     cout << a[i] << endl;
	// }
	// cout << "Element at 2: " << a.at(2) << endl;
	// (a.empty()) ? cout << "Empty" << endl : cout << "Not Empty" << endl;
	// cout << "First: " << a.front() << endl;
	// cout << "Last: " << a.back() << endl;
	// !!!!!!!!!!!!!!!!!!

	// **   STL VECTOR
	// vector<int> v;
	// vector<int> v2(50); //? a vector with 50 elements
	// vector<int> v1[50]; // ? an array of 50 vectors.
	// cout << "Capacity: " << v.capacity() << endl;
	// int m;
	// cout << "Enter the elements: " << endl;
	// for (int i = 0; i < 9; i++)
	// {
	// 	cin >> m;
	// 	v.push_back(m);
	// }
	// **  VECTOR WILL DOUBLE THE CAPACITY BY DEFAULT UNLESS SPECIFIED
	// cout << "Capacity: " << v.capacity() << endl;
	// cout << "Size: " << v.size() << endl;
	// v.pop_back();
	// cout << "Capacity: " << v.capacity() << endl;
	// cout << "Size: " << v.size() << endl;
	// for (auto i = v.begin(); i != v.end(); i++)
	// {
	// 	cout << *i << endl;
	// }
	// v.clear();
	// cout << "Capacity: " << v.capacity() << endl;
	// cout << "Size: " << v.size() << endl;
	// !!!!!!!!!!!!!!!!!!!

	// **  STL SORT FUNCTION
	// ? used to sort an array, vector, or string. Underlying algo is gcc_sort (heap, quick, insertion) O(nlogn)
	// int n;
	// cout << "Enter the number of terms";
	// cin >> n;
	// int a[n];
	// for(int i = 0; i<n; i++){
	// 	cin >> a[i];
	// }
	// sort(a, a + n);
	// for(int i = 0; i<4; i++){
	// 	cout << a[i] << endl;
	// }
	// vector<int> v;
	// int m;
	// for (int i = 0; i<n; i++){
	// 	cin >> m;
	// 	v.push_back(m);
	// }
	// sort(v.begin(), v.end());
	// for (int i = 0; i<n; i++){
	// 	cout << v[i] << endl;
	// }
	// !!!!!!!!!!!!!!!!!!!

	// ** STL PAIRS
	// ? used to create a composite datatype having 2 primitive or composite datatypes.
	// pair< vector< pair<int, vector<int> > >, string> p;
	// cout << f().first << "  " << f().second;
	// !!!!!!!!!!!!!!!!!!!

	// ** STL SORTING ARRAYS/VECTORS OF PAIRS
	// int n;
	// cin >> n;
	// pair<int, int> p[n];
	// for (int i = 0; i < n; i++)
	// {
	// 	cout << "Enter the first value: ";
	// 	cin >> p[i].first;
	// 	cout << "Enter the second value: ";
	// 	cin >> p[i].second;
	// }
	// sort(p, p + n);
	// ? sorting is done in a way such that the first value of each pair is compared to each other.
	// ? In case of a tie, the second value is checked
	// for(int i =0; i<n; i++){
	// 	cout << p[i].first << " : " << p[i].second << endl;
	// }
	// vector<pair<int, string>> v;
	// int t;
	// cin >> t;
	// for(int i =0; i<t; i++){
	// 	int sc;
	// 	cout << "Enter the score: ";
	// 	cin >> sc;
	// 	string name;
	// 	cout << "Enter the name: ";
	// 	cin >> name;
	// 	v.push_back(make_pair(sc, name));
	// }
	// sort(v.begin(), v.end());
	// ? v.end() is an iterator to a non existing element ( after the last element )
	// ? similar to arr+n
	// for(int i=0; i<v.size(); i++){
	// 	cout << v[i].first << "  " << v[i].second << endl;
	// }
	// !!!!!!!!!!!!!!!!!!!

	// ** STL ITERATORS
	//  similar to pointers
	// vector<int> v1 = {1, 2};
	// ? Below is the default datatype of the v.begin() iterator
	// vector<int>::iterator ite = v1.begin();
	// auto ite = v1.begin();  // ? this is the better way as auto deduces the datatype automatically
	// cout << *ite << endl; // ? gives the 1st element as it has been dereferenced
	// ? and can give the rest of the elements as well if the iterator is incremented
	// !!!!!!!!!!!!!!!!!!!

	// ** STL SET
	// $ a container that keeps a unique copy of each element in sorted order
	// set<int> s;
	// set<string> s1;
	// auto it = s.begin();
	// s.insert(1);
	// s.insert(2);
	// s.insert(2);
	// s.insert(2);
	// s.insert(2);
	// s.insert(67);
	// cout<< s.size()<< endl;
	// cout<< s.count(2)<< endl;
	// ? count will be 1 no matter the number of times a value is inserted.
	// s.erase(67);
	// cout<< s.size()<< endl;
	// cout<< s.count(67)<< endl;
	// s.clear();
	// cout<< s.size()<< endl;

	// ** STL SET ITERATORS
	// $ offer less features than vectors iterators.
	// ? it here points to the first element i.e. the smallest element as SET uses
	// ? the red-black trees that sorts the data automatically. So, here 2 will be
	// ? removed
	// s.erase(it);
	// cout << s.count(1);
	// if(s.count(1) == 0 ) cout<<"Not found";
	// cout << *s.find(5);
	// !!!!!!!!!!!!!!!!!!!

	// ** STL MAPS
	// $ special arrays whose indices(keys) can be anything, strings, int, +ve, -ve, etc
	// $ map<key_datatype, value_datatype> m;

	// map<string, int> m;
	// m["first"] = 50;
	// m["second"] = 80;
	// int no;
	// string name;
	// int t;
	// cin >> t;
	// pair<string, int> p;
	// map<int, int> m;
	// cout << m.size() << "\n";
	// cout << m[15];
	// cout << "\n";

	// m[1] = 50;
	// cout << m[1];
	// m[12] = 80;
	// cout << m[12];

	// cout<< m.size() << "\n";

	// map<string, int> freq;
	// int n;
	// cin>>n;
	// for(int i =0; i<n; i++){
	// 	string s;
	// 	cin >> s;
	// 	if (freq[s] == 0){
	// 		cout << "ok\n";
	// 	} else {
	// 		cout << s << freq[s] << endl;
	// 	}
	// 	freq[s]++;
	// }
	// !!!!!!!!!!!!!!!!!!!


	// ** STL DEQUES
	// $ doubly ended queues
	// deque<int> d;
	// d.push_back(8);
	// d.push_back(9);
	// d.push_front(2);
	// d.push_front(1);

	// for(int i : d){
	// 	cout << i << endl;
	// }
	// d.pop_back();
	// d.pop_front();
	// for(int i : d){
	// 	cout << i << endl;
	// }
	// cout << "Element at index 0: " << d.at(0) << endl;
	// cout << "front: " << d.front() << endl;
	// cout << "back: " << d.back() << endl;
	// cout<< "empty?: " << d.empty() << endl;
	// cout<< "before: " << d.size() << endl;
	// d.erase(d.begin(), d.end() -1 );
	// cout<< "after: " << d.size() << endl;
	// for(int i : d){
	// 	cout << i << endl;
	// }
	// !!!!!!!!!!!!!!!!!!!

	// ** STL LISTS
	// $
}


// pair<int, string> f(){
// 	pair<int, string> p1 = {78, "Sukant"};
// 	cout << p1.first << "  " << p1.second;
// 	return {p1.first, p1.second};
// }
