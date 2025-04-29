/**
 * Implement (code) a Key value store with transactions.
 * Write a Fully funcitonal code in 25-30 min in interview with test cases
 * Set
 * Get
 * Delete are methods in Key value store
 * 
 * for transactions
 * Begin
 * Commit
 * Rollback
 * 
 */

#include <bits/stdc++.h>
using namespace std;


class KVTransaction {
	unordered_map<string, string> hash;
	stack<unordered_map<string, string>> transactionStack;
	
	string DELETED_MARKER = "__<DELETED>__"; 
	
public:
	KVTransaction() {
		
	}
	
	void begin() {
		transactionStack.push(unordered_map<string, string>());
		return;
	}
	
	void set(string key, string value) {
		if (!transactionStack.empty()) {
			transactionStack.top()[key] = value;
		} else {
			hash[key] = value;
		}
		return;
	} 
	
	void deleteKey(string key) {
		if (!transactionStack.empty()) {
			transactionStack.top()[key] = DELETED_MARKER;
		} else {
			if (hash.find(key) != hash.end()) {
				hash.erase(key);
			}
		}
		return;
	}
	
	string get(string key) {
		stack<unordered_map<string, string>> temp = transactionStack;
		while (!temp.empty()) {
			unordered_map<string, string> tempHash = temp.top();
			if (tempHash.find(key) != tempHash.end()) {
				string val = tempHash[key];
				if (val == DELETED_MARKER) return "null";
				
				return val;
			}
			temp.pop();
		}
		
		if (hash.find(key) != hash.end()) { // not checking DELETED_MARKER because we are directly erasing from the hash in case of no transaction
			return hash[key];
		}
		return "null";
	}
	
	bool commit() {
		if (transactionStack.empty()) {
			cout << "no transactions to commit";
			return false;
		}
		
		unordered_map<string, string> tempHash = transactionStack.top();
		transactionStack.pop();
		
		if (!transactionStack.empty()) {
			for (auto it = tempHash.begin(); it != tempHash.end(); it++) {
				transactionStack.top()[it->first] = it->second;
			}
		} else {
			for (auto it = tempHash.begin(); it != tempHash.end(); it++) {
				if (it->second == DELETED_MARKER) {
					hash.erase(it->first);
				} else {
					hash[it->first] = it->second;
				}
			}
		}
		return true;
	}
	
	bool rollback() {
		if (transactionStack.empty()) {
			cout << "nothing to rollback" << endl;
			return false;
		}
		
		transactionStack.pop();
		return true;
	}
};

int main() {
	// your code goes here
	KVTransaction *kv = new KVTransaction();
	
	kv->begin();
	kv->set("a", "1");
	cout << "get(a) = " << kv->get("a") << endl;
	kv->commit();
	
	
	kv->set("a", "1");
    cout << kv->get("a") << endl;  // 1

    kv->begin();
    kv->set("a", "2");
    cout << kv->get("a") << endl;  // 2

    kv->begin();
    kv->deleteKey("a");
    cout << kv->get("a") << endl;  // NULL

    kv->rollback();
    cout << kv->get("a") << endl;  // 2

    kv->commit();
    cout << kv->get("a") << endl;  // 2

    kv->rollback();  // No active transaction
	
	
	return 0;
}
