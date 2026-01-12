// question - https://programhelp.net/en/vo/stripe-interview-process-explained-2025-edition/


#include <bits/stdc++.h>
using namespace std;

struct LanguageTag {
	string tag;
	double q;
	int order;
	
	LanguageTag(string _tag, double _q, int _order) {
		tag = _tag;
		q = _q;
		order = _order;
	}
}



class ParseHeader {
	
public:

	ParseHeader() {
		
	}

	vector<string> splitHeader(string header) {
		vector<string> result;
		int i = 0, j = 0;
		while (i < header.size()) {
			string str = "";
			j = i;
			while (j < header.size() && header[j] != ',') {
				str += header[j];
				j++;
			}
			result.push_back(str);
			i = j+1;
		}
		return result;
	}

	vector<string> parse_accept_language(string header, vector<string> languages) {
		vector<string> headerLanguages = splitHeader(header);
		unordered_set<string> hash(languages.begin(), languages.end());
		
		vector<string> result;
		for (string str: headerLanguages) {
			if (hash.count(str) > 0) {
				result.push_back(str);
			}
		}
		return result;
	}
};

void printResult(vector<string> result) {
	for (string str: result) cout << str << " ";
	cout << endl;
}

int main() {
	// your code goes here
	ParseHeader *parseHeader = new ParseHeader();
	vector<string> result = parseHeader->parse_accept_language("en-US,fr-CA,fr-FR", {"fr-FR", "en-US"});
	printResult(result);
	// Returns: ["en-US", "fr-FR"]

	ParseHeader *parseHeader1 = new ParseHeader();
	vector<string> result1 = parseHeader1->parse_accept_language("fr-CA,fr-FR", {"en-US", "fr-FR"});
	printResult(result1);
	// Returns: ["fr-FR"]

	ParseHeader *parseHeader2 = new ParseHeader();
	vector<string> result2 = parseHeader2->parse_accept_language("en-US", {"en-US","fr-CA"});
	printResult(result2);
	
	// Returns: ["en-US"]
	
	return 0;
}
