// Problem ID: 10196
// By Alexander Cai 13-06-2019
// Accepted

#include <iostream>
#define BLACK 0
#define WHITE 1
using namespace std;

// Black is lowercase
// White is uppercase

int game = 1;
bool finished;
char board[8][8];

// Coordinates for how the pieces move
const int rook_dr[4] = { 0, -1, 0, 1 };
const int rook_dc[4] = { -1, 0, 1, 0 };
const int bishop_dr[4] = { -1, 1, 1, -1 };
const int bishop_dc[4] = { 1, 1, -1, -1 };
const int queen_dr[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
const int queen_dc[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int knight_dr[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int knight_dc[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// Read in an 8x8 chessboard from the input and returns false if they're all blank
bool get_board() {
  bool not_blank = false;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> board[i][j];
      if (board[i][j] != '.') not_blank = true;
    }
  }
  return not_blank;
}

// Checks if a king is in check and stops the current loop by setting finished to true.
// I didn't use if/else if/else since it'll stop anyways when it returns.
bool is_king(int r, int c, int color) {
  if (board[r][c] == 'K' && color == BLACK) {
    cout << "Game #" << game << ": white king is in check." << endl;
    finished = true;
    return true;
  }
  
  if (board[r][c] == 'k' && color == WHITE) {
    cout << "Game #" << game << ": black king is in check." << endl;
    finished = true;
    return true;
  }

  return false;
}

// Checks if a certain piece is attacking a king.
void check(int r, int c) {
  int color = isupper(board[r][c]) ? WHITE : BLACK;
  int tr, tc;

  switch (board[r][c]) {
  case '.':
    break;

  case 'P':
    if (r < 1) break;
    if (c > 0) is_king(r-1, c-1, color);
    if (c < 7) is_king(r-1, c+1, color);
    break;

  case 'p':
    if (r > 6) break;
    if (c > 0) is_king(r+1, c-1, color);
    if (c < 7) is_king(r+1, c+1, color);
    break;

  case 'R':
  case 'r':
    for (int i = 0; i < 4 && !finished; i++) { // 4 directions
      // The board is only 8 wide so that's the longest we'll need to loop.
      // We check along the whole path and break when it hits something
      for (int j = 1; j < 8; j++) {
        tr = r + j * rook_dr[i];
        tc = c + j * rook_dc[i];
        if (tr < 0 || tr > 7 || tc < 0 || tc > 7) break;
        if (is_king(tr, tc, color)) break;
        else if (board[tr][tc] != '.') break;
      }
    }
    break;

  case 'B':
  case 'b':
    bool blocked;
    for (int i = 0; i < 4 && !finished; i++) { // 4 directions
      for (int j = 1; j < 8; j++) {
        tr = r + j * bishop_dr[i];
        tc = c + j * bishop_dc[i];
        if (tr < 0 || tr > 7 || tc < 0 || tc > 7) break;
        if (is_king(tr, tc, color)) break;
        else if (board[tr][tc] != '.') break;
      }
    }
    break;

  case 'Q':
  case 'q':
    for (int i = 0; i < 8 && !finished; i++) { // 8 directions
      for (int j = 1; j < 8; j++) {
        tr = r + j * queen_dr[i];
        tc = c + j * queen_dc[i];
        if (tr < 0 || tr > 7 || tc < 0 || tc > 7) break;
        if (is_king(tr, tc, color)) break;
        else if (board[tr][tc] != '.') break;
      }
    }
    break;

  // I got rid of the K/k case since a king can never be next to another king

  case 'N':
  case 'n':
    for (int i = 0; i < 8 && !finished; i++) { // 8 directions
      tr = r + knight_dr[i];
      tc = c + knight_dc[i];
      if (tr < 0 || tr > 7 || tc < 0 || tc > 7) continue;
      is_king(tr, tc, color);
    }
    break;
  }
}

int main() {
  while (get_board()) {
    finished = false;
    for (int r = 0; r < 8 && !finished; r++)
      for (int c = 0; c < 8 && !finished; c++)
        check(r, c);
    if (!finished) cout << "Game #" << game << ": no king is in check." << endl;
    game++;
  }
  
  return 0;
}
