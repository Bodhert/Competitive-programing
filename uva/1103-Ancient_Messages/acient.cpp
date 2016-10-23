using namespace std;
#include <bits/stdc++.h>

char mat[405][255];

int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

string parse(char c)
{
  if(c == '0') return "0000";
  else if(c == '1') return "0001";
  else if(c == '2') return "0010";
  else if(c == '3') return "0011";
  else if(c == '4') return "0100";
  else if(c == '5') return "0101";
  else if(c == '6') return "0110";
  else if(c == '7') return "0111";
  else if(c == '8') return "1000";
  else if(c == '9') return "1001";
  else if(c == 'a') return "1010";
  else if(c == 'b') return "1011";
  else if(c == 'c') return "1100";
  else if(c == 'd') return "1101";
  else if(c == 'e') return "1110";
  else return "1111";
}

void printMatrix(int h, int w)
{
  for(int i = 0; i < h; ++i)
  {
    for(int j = 0; j < w*4; ++j)
    {
      cout << mat[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

void floodfill(int r,int R, int c, int C,  char c1, char c2)
{
  if(r < 0 || r >= R || c < 0 || c >= C) return;
  if(mat[r][c] != c1) return;
  mat[r][c] = c2;
  for(int d = 0; d < 4; d++) floodfill(r + dr[d], R, c + dc[d], C, c1,c2);
}

int floodfillHolles(int r,int R, int c, int C,  char c1, char c2)
{
  if(r < 0 || r >= R || c < 0 || c >= C) return 0;
  if(mat[r][c] != c1) return 0;
  int ans = 1;
  mat[r][c] = c2;
  for(int d = 0; d < 4; d++) ans += floodfillHolles(r + dr[d], R, c + dc[d], C, c1,c2);
  return ans;
}

int hole = 0;

int floodfillSp(int r,int R, int c, int C,  char c1, char c2)
{
  if(r < 0 || r >= R || c < 0 || c >= C) return 0;
  if(mat[r][c] != c1) return 0 ;
  int count = 0;
  mat[r][c] = c2;
  for(int d = 0; d < 4; d++)
  {
    if(mat[r + dr[d]][c + dc[d]] == '0')
    {
       if(floodfillHolles(r + dr[d], R, c + dc[d], C, '0','.')) hole++;
    }
    else
    {
      floodfillSp(r + dr[d], R, c + dc[d], C, c1,c2);
    }
  }
  return hole;
}

int main()
{
  int h,w;
  char c;
  string result;
  int cases = 0;
  while(cin >> h >> w && (h || w))
  {
    int I = 0, J = 0;
    memset(mat, 'v', sizeof(mat[0][0]) * 405 * 255);

    for(int i = 0; i < h; ++i)
    {
      for(int j = 0; j < w; ++j)
      {
        cin >> c;
        string aux = parse(c);
        for(int k = 0; k < 4; ++k )
        {
          mat[I][J] =  aux[k];
          J++;
        }
      }
      I++;
      J = 0;
    }
    // printMatrix(h,w);
    // clean bakcground ceros '0'
    for(int j = 0; j < w * 4; ++j)
    {
      if(mat[0][j] == '0') floodfill(0,h,j,w*4,'0','v');
      else if(mat[h-1][j] == '0') floodfill(h-1,h,j,w*4,'0', 'v');
    }

    for(int i = 0; i < h; ++i)
    {
      if(mat[i][0] == '0') floodfill(i,h,0,w*4,'0','v');
      else if(mat[i][(w*4)-1] == '0') floodfill(i, h ,(w*4)-1, w*4, '0', 'v');
    }
    // clean bakcground ceros '0'
    // printMatrix(h,w);
    string result = "";
    for(int i = 0; i < h; ++i)
      for(int j  = 0; j < w*4; ++j)
      {
        int ans = -1;
        if(mat[i][j] == '1')
        {
          ans = floodfillSp(i,h,j,w*4, '1', '+');
          if(ans == 0) result += "W";
          else if(ans == 1) result += "A";
          else if(ans == 2) result += "K";
          else if(ans == 3) result += "J";
          else if(ans == 4) result += "S";
          else if(ans == 5) result += "D";
          // cout << ans << endl;
          hole = 0;
        }
      }

      sort(result.begin(),result.end());
      cout << "Case " << ++cases << ": " << result << endl;
      //  printMatrix(h,w);
  }
  return 0;
}
