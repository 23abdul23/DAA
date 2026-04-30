/*
Basic Question: Multiply two integers using Karatsuba's divide-and-conquer algorithm.
Topic: Divide and Conquer
Idea Used: Split each number into high and low halves and reduce multiplication count using the Karatsuba formula.
*/
#include <bits/stdc++.h>
#include <string>
#include <math.h>

using namespace std;

typedef long long ll;


ll sizeInBase(ll n){
	string s = to_string(n);
	return s.length();
}

pair<ll, ll> splitNum(ll n, ll d){
	
	pair<ll ,ll> ans;

	ans.first = n / (pow(10,d));
	ll p = 1;
	for (int i = 0; i < d; i++) p *= 10;

	ans.second = n % p;

	return ans;

}

ll kasturba(ll high, ll low){
	if (high < 10LL || low < 10LL)
		return high * low;

	ll m = max(sizeInBase(high), sizeInBase(low));

	ll m2 = floor(m/2);

	pair<ll, ll> one, two;

	one = splitNum(high, m2);
	two = splitNum(low, m2);

	ll h1, h2, l1,l2;

	h1 = one.first, h2 = two.first;
	l1 = one.second, l2 = two.second;
	
	ll z1, z2, z3;

	z1 = kasturba(l1, l2);
	z2 = kasturba (l1 + h1,h2 + l2);
	z3 = kasturba(h1,h2);

	return ((z3 * pow(10, m2*2)) + (z2-z3-z1)* pow(10,m2) + z1);
}
int main(){
	ll a ,b ;
	cin >> a>> b;

	cout << kasturba(a, b) << endl;

	return 0;
}
