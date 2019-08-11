// Problem ID: 10149
// By Alexander Cai 2019-07-09
// Accepted
// With help from https://codingstrife.wordpress.com/2013/07/10/solution-uva10149-pc110208-yahtzee/

#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;
map< pair<int,int>, vector<int> > cat_memo;

int chance(int dice[5]) {
	int total = 0;
  for (int i = 0; i < 5; i++)
    total += dice[i];
  return total;
}

int score(int dice[5], int dice_count[7], int cat) {
  int longest_seq = 0, curr_seq = 0, total = 0, n;
  bool found = false, two_eq= false, three_eq = false, five_eq = false;;

  switch (cat)
  {
    case 0: case 1: case 2: case 3: case 4: case 5: 
      for (int i = 0; i < 5; i++)
        if (dice[i] == cat + 1) total += dice[i];
      return total;
      break;

    case 6:
      return chance(dice);
      break;

    case 7: case 8: case 9: // _ of a kind
      n = cat - 4;
      for (int i = 1; i < 7; i++) {
        if (dice_count[i] >= n) {
          found = true;
          break;
        }
      }

      if (n == 5 && found) return 50;
      if (found) return chance(dice);
      return 0;
      break;

    case 10: case 11: // Short/long straight
      for (int i = 1; i < 7; i++)
        if (dice_count[i] && dice_count[i+1])
          curr_seq++;
        else longest_seq = max(curr_seq + 1, longest_seq), curr_seq = 0;

      if (longest_seq >= 4 && cat == 10) return 25;
      if (longest_seq == 5 && cat == 11) return 35;
      return 0;
      break;
    
    case 12:
      for (int i = 1; i < 7; i++)
        if (dice_count[i] == 2) two_eq = true;
        else if (dice_count[i] == 3) three_eq = true;
        else if (dice_count[i] == 5) five_eq = true;

      if ((two_eq && three_eq) || five_eq) return 40;
      else return 0;
      break;
    
    default:
      return 0;
      break;
  }
}

vector<int> best_categorization(int rounds_left, int cat, int scores[13][13])
{
	pair<int,int> key;

	key.first = rounds_left;
	key.second = cat;

  map< pair<int,int>, vector<int> >::iterator
  it = cat_memo.find(key);

	if (it != cat_memo.end())
		return it->second;

	vector<int> highest_score(15), test_score(15);
	highest_score[14] = -1;

	if (cat == 0) {
    highest_score[0] = scores[(int) (log((double) rounds_left) / log(2.0))][0];
    highest_score[14] = highest_score[0];
    return highest_score;
  }

	for (int i = 0; i < 13; i++)
	{
		if (rounds_left & (int) pow(2.0,i))
		rounds_left ^= (int) pow(2.0,i);
		else continue;

		test_score = best_categorization(rounds_left, cat-1, scores);
		test_score[14] += scores[i][cat];
		test_score[cat] = scores[i][cat];
		if (cat == 5) {
      test_score[13] = (test_score[14] >= 63) ? 35 : 0;
      test_score[14] += test_score[13];
    }

		if (test_score[14] > highest_score[14]) highest_score = test_score;
		rounds_left ^= (int) pow(2.0, i);
	}

	cat_memo[key] = highest_score;
	return highest_score;
}

int main ()
{
  int dice[13][5];
	int scores[13][13];
	int counter = 0;
	while (true) {
		counter++;
		for (int i = 0; i < 13; i++)
			for (int j = 0; j < 13; j++)
				scores[i][j] = -1;

		int dice_count[13][7]={0};
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 5; j++) {
				if (!(cin >> dice[i][j])) return 0;
				else dice_count[i][dice[i][j]]++;
      }

      for (int j = 0; j < 13; j++)
        scores[i][j] = score(dice[i], dice_count[i], j);
		}

    vector<int> output = best_categorization(pow(2.0, 13)-1, 12, scores);

    for (int i = 0; i < 15; i++) {
      cout << output[i];
      if (i != 14) cout << ' ';
    }

    cout << endl;
		cat_memo.clear();
	}

	return 0;
}