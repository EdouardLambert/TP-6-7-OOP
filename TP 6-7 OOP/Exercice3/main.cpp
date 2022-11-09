#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename Iter>
typename Iter::value_type
partial_dot(Iter first1, Iter last1, Iter first2, Iter last2)
{
	if (sizeof(first1 != first2))
	{
		return 1;
	}

	Iter dot;
	for (i = 0; i < sizeof(first1); i++)
	{
		dot[i] = first1[i] * first2[i];
	}
	return dot
}

int main() {
	vector<int> tab1[] = { 0, 1, 2 };
	vector<int> tab2[] = { 1, 2, 3 };
	vector<int> tab3 = partial_dot(tab1.begin(), tab1.end(), tab2.begin(), tab2.end());
	return 0;
}