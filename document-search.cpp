/**
  *
You are given a list of documents with id and text.
Eg :-
DocId, Text
1, "Cloud computing is the on-demand availability of computer system resources."
2, "One integrated service for metrics uptime cloud monitoring dashboards and alerts reduces time spent navigating between systems."
3, "Monitor entire cloud infrastructure, whether in the cloud computing is or in virtualized data centers."

Search a given phrase in all the documents in a efficient manner. Assume that you have more than 1 million docs.
Eg :-
search("cloud") >> This should output [1,2,3]
search("cloud monitoring") >> This should output [2]
search("Cloud computing is") >> This should output [1,3]
  */

#include <bits/stdc++.h>

using namespace std;

class SearchEngine {
    // {word -> {docId -> [index/position of word in docId]
    unordered_map<string, unordered_map<int, vector<int>>> index;
    
public:
    vector<string> tokenize(string text) {
        vector<string> result;
        int i = 0, j = 0;
        while (i < text.size()) {
            string str = "";
            j = i;
            while (j < text.size() && text[j] != ' ') {
                str += tolower(text[j]);
                j++;
            }
            result.push_back(str);
            i = j+1;
        }
        return result;
    }
    
    bool doesPhraseExists(int docId, vector<string> words) {
        vector<int> firstWordPositions = index[words[0]][docId];
        
        // for each position of the first word in doc = docId,
        // check if the subsequenet words are at position
        // prev_word position+1 and so on
        for (int pos: firstWordPositions) {
            bool match = true;
            
            // iterate over all the subsequent words
            for (int i = 1; i < words.size(); i++) {
                auto mp = index[words[i]]; // get the map of docid to positions of the subsequent words
                if (mp.find(docId) == mp.end()) {
                    // the next word is not present in the current 
                    // doc being checked
                    match = false;
                    break;
                }
                
                vector<int> positionsOfNextWord = mp[docId];
                // now we want to check if there is a 
                // position = pos+1 present in the positionsofNextWord
                // We will use binary search for that, as positions
                // are sorted
                if (!binary_search(positionsOfNextWord.begin(), positionsOfNextWord.end(), pos+i)) {
                    // position is not next of pos
                    match = false;
                    break;
                }
            }
            
            if (match) return true;
        }
        return false;
    }

    void addDocument(int docId, string text) {
        vector<string> words = tokenize(text);
        for (int i = 0; i < words.size(); i++) {
            index[words[i]][docId].push_back(i);
        }
        return;
    }
    
    vector<int> search(string query) {
        vector<string> words = tokenize(query);
        if (words.size() == 0) return {};
        
        for (string w: words) {
            if (index.find(w) == index.end()) return {}; // all words not present in the index
        }
        
        // for the first word, get all the potential doc ids
        vector<int> potentialDocs;
        for (auto mp: index[words[0]]) {
            potentialDocs.push_back(mp.first);
        }
        
        vector<int> result;
        for (int docId: potentialDocs) {
            if (doesPhraseExists(docId, words)) {
                result.push_back(docId);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};



int main() {
    // Write C++ code here
    SearchEngine engine;

    engine.addDocument(1, "Cloud computing is the on-demand availability of computer system resources.");
    engine.addDocument(2, "One integrated service for metrics uptime cloud monitoring dashboards and alerts reduces time spent navigating between systems.");
    engine.addDocument(3, "Monitor entire cloud infrastructure, whether in the cloud computing is or in virtualized data centers.");

    // Test queries
    auto printResult = [&](auto v) {
        for (int x : v) cout << x << " ";
        cout << "\n";
    };

    cout << "search(\"cloud\") -> ";
    printResult(engine.search("cloud"));

    cout << "search(\"cloud monitoring\") -> ";
    printResult(engine.search("cloud monitoring"));

    cout << "search(\"Cloud computing is\") -> ";
    printResult(engine.search("Cloud computing is"));

    return 0;
}
