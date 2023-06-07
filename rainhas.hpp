#include <bits/stdc++.h>
using namespace std;

struct rainha; 
int codigo(string teste);
bool validateBoard(const vector<rainha>& queens);
bool checkAttack(const rainha& q1, const rainha& q2);