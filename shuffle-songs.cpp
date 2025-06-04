/**
 * Implement a Shuffle function
    input Provided a vector of songs, 
    output random songs => vector of songs, each consective song should be of a different artist
 */
#include <bits/stdc++.h>
using namespace std;


struct Song {
    string name;
    string artist;
    
    Song(string _n, string _a) {
        name = _n;
        artist = _a;
    }
};

struct maxPqCmp {
    bool operator()(pair<string, int>& a, pair<string, int>& b) {
        if (a.second == b.second) return a.first <= b.first;
        else return a.second < b.second;
    }
};

vector<Song*> shuffleSongs(vector<Song*> songs) {
    int n = songs.size();
    if (n <= 2) return songs;
    
    unordered_map<string, int> freq;
    unordered_map<string, list<Song*>> hash;
    
    for (int i = 0; i < songs.size(); i++) {
        freq[songs[i]->artist]++;
        hash[songs[i]->artist].push_back(songs[i]);
    }
    
    priority_queue<pair<string, int>, vector<pair<string, int>>, maxPqCmp> maxHeap;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        maxHeap.push({it->first, it->second});
    }
    
    vector<Song*> result;
    string lastArtist = "";
    
    while (maxHeap.size() >= 2) {
        pair<string, int> node = maxHeap.top();
        maxHeap.pop();
        
        pair<string, int> secondMax = maxHeap.top();
        maxHeap.pop();
        
        if (lastArtist != node.first) {
            // cout << "max" << endl;
            result.push_back(hash[node.first].front());
            hash[node.first].pop_front();
            lastArtist = node.first;
            node.second--;
            
            if (node.second > 0) {
                maxHeap.push({node.first, node.second});
            }  
            maxHeap.push({secondMax.first, secondMax.second});
        } else {
            // cout << "secondMax" << endl;
            result.push_back(hash[secondMax.first].front());
            hash[secondMax.first].pop_front();
            lastArtist = secondMax.first;
            secondMax.second--;
            
            if (secondMax.second > 0) {
                maxHeap.push({secondMax.first, secondMax.second});
            }
            
            maxHeap.push({node.first, node.second});
        }
            // if (!maxHeap.empty()) {
            //     pair<string, int> secondMax = maxHeap.top();
            //     maxHeap.pop();
                
            //     result.push_back(hash[secondMax.first].front());
            //     hash[secondMax.first].pop_front();
            //     lastArtist = secondMax.first;
            //     secondMax.second--;
                
            //     if (secondMax.second > 0) {
            //         maxHeap.push({secondMax.first, secondMax.second});
            //     }
                
            //     maxHeap.push({node.first, node.second});
            // } else {
            //     maxHeap.push({node.first, node.second});   
            // }
        // }
    }
    
    while (!maxHeap.empty()) {
        pair<string, int> node = maxHeap.top();
        for (int i = 0; i < node.second; i++) {
            result.push_back(hash[node.first].front());
            hash[node.first].pop_front();
        }
        maxHeap.pop();
    }
    
    return result;
    
}

int main() {
	// your code goes here
	Song* s1 = new Song("S1", "A1");
	Song* s2 = new Song("S2", "A1");
	Song* s3 = new Song("S3", "A1");
// 	Song* s4 = new Song("S4", "A2");
	Song* s5 = new Song("S5", "A3");
	
	vector<Song*> songs = {s1, s2, s3, s5};
	vector<Song*> shuffledSongs = shuffleSongs(songs);
	
	for (auto s: shuffledSongs) {
	    cout << s->name << " " << s->artist << endl;
	}

}
