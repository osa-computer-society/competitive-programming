// Problem ID: 10142
// By Alexander Cai 13-06-2019
// Accepted! (With a bit of guilty help from https://github.com/Diusrex/UVA-Solutions/blob/master/10142%20Australian%20Voting.cpp)

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n_cases, first = true;
  cin >> n_cases;

  while (n_cases--) {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> candidates(n);
    vector<int> received_votes(n);
    vector<bool> eliminated(n, false);

    // Load in the candidate names
    for (int i = 0; i < n; i++)
      getline(cin, candidates[i]);

    string temp;
    vector<vector<int> > votes;
    while (getline(cin, temp) && temp != "") {
      // We use a stringstream to turn the line (a string) into ints
      vector<int> ballot(n);
      stringstream ss;
      ss << temp;
      for (int i = 0; i < n; i++) {
        ss >> ballot[i];
        ballot[i]--; // Reduce each one by 1 so that it matches the index of the candidate
      }
      votes.push_back(ballot);
    }

    int num_votes = votes.size();
    int winning_vote_count = -1;

    // Stores the vote which is being counted
    vector<int> vote_index(num_votes);

    // For each voter, we take their first vote and add them
    for (int i = 0; i < num_votes; i++)
      received_votes[votes[i][0]]++;
    
    // While we're still looking for a winner
    while (winning_vote_count == -1) {
      // We get rid of the first few people on a vote list if they have been eliminated
      for (int i = 0; i < num_votes; i++) {
        bool changed = false;

        while (eliminated[votes[i][vote_index[i]]]) {
          vote_index[i]++;
          changed = true;
        }

        if (changed) // We give a vote to the next person in their list
          received_votes[votes[i][vote_index[i]]]++;
      }

      // We loop through to get the most and least votes
      int least = 1000, most = 0;
      for (int i = 0; i < n; i++) {
        if (eliminated[i]) continue;
        if (received_votes[i] < least) least = received_votes[i];
        if (received_votes[i] > most) most = received_votes[i];
      }

      // If there is only one person or the max has more than 50%, we set the winning vote count
      if (least == most || most * 2 > num_votes) 
        winning_vote_count = most;
      else // We eliminate the ones with the least votes
        for (int i = 0; i < n; i++)
          if (received_votes[i] == least)
            eliminated[i] = true;
    }

    // Newline to separate answers
    if (!first) cout << endl;
    if (first) first = false;

    // List the candidates who received the most votes
    for (int i = 0; i < n; i++)
      if (received_votes[i] == winning_vote_count && !eliminated[i])
        cout << candidates[i] << endl; 
  }

  return 0;
}
