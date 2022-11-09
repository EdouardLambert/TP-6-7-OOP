#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator> // pour std::ostream_iterator

using namespace std;

void AffichageVecteur(vector<int> tab)
{
	cout << "{ ";
	for (int i : tab)
	{
		cout << i << ", ";
	}
	cout << "}" << endl;
}

int main()
{
	vector<int> v = {4, 5, 0, -2, 2, 5, 32, -3, -34, 43, 2, -1, 0, 2};
	vector<int> v2 = v;

	AffichageVecteur(v);

	// Détermine si toutes les valeurs sont positives ou nulles
	bool allNegativOrNull = none_of(v.begin(), v.end(), [](int i) { return i < 0; });
	cout << "Toutes les valeurs sont negatives ? : ";
	if (allNegativOrNull) cout << "true" << endl;
	else cout << "false" << endl;

	// Remplace toutes les valeurs négatives par 0
	replace_if(v2.begin(), v2.end(), [](int i) { return i < 0; }, 0);
	AffichageVecteur(v2);

	// Affiche toutes les valeurs positive
	cout << "{ ";
	copy_if(v.begin(), v.end(), ostream_iterator<int>(cout, ", "), [](int i) { return i > 0; });
	cout << "}" << endl;

	// Détermine la position du premier et du dernier élément négatif
	auto first = distance(v.begin(), find_if(v.begin(), v.end(), [](int i) { return i < 0; }));
	auto last = distance(v.begin(), find_if(v.rbegin(), v.rend(), [](int i) { return i < 0; }).base() - 1);
	cout << first << last << endl;

	return 0;
}