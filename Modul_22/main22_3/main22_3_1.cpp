#include <iostream>
#include <map>

std::map <char, int> create_map(std::string word) {
	std::map <char, int> mw;
	for (int i = 0; i < word.length(); i++) {
		std::map<char, int>::iterator it = mw.find(word[i]);
		if (it == mw.end())
			mw[word[i]] = 1;
		else
			mw[word[i]] = it->second + 1;
	}
	return mw;
}

bool check_anagram(std::string first_word, std::string second_word) {
	std::map <char, int> mw;
	if (first_word.length() == second_word.length()) {
		mw = create_map(first_word);	

		for (int i = 0; i < second_word.length(); i++) {

			std::map<char, int>::iterator it = mw.find(second_word[i]);

			if (it == mw.end()) {
				return false;
			}
			else {
				if (it->second == 1)
					mw.erase(it);
				else
					it->second -= 1;
			}
		}
		std::map<char, int>::iterator it = mw.begin();
		if (it == mw.end())
			return true;
		else
			return false;
	}
	else
		return false;
}
int main()
{
	std::cout << "***************** Registration office *****************\n\n";


	std::string first_word, second_word;
	std::cout << "Enter two words by space for checking: ";
	std::cin >> first_word >> second_word;

	if (check_anagram(first_word, second_word))
		std::cout << "True";
	else
		std::cout << "False";
}