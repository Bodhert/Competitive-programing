#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  string firstname,lastname;

  cin >> n;
  vector<string> students;

  for(int i = 0; i < n; ++i)
    {
      
      cin >> firstname; cin >> lastname;
      string temp = lastname + firstname; 
      students.push_back(temp);
    }

  sort(students.begin(),students.end());

  for(int i = 0; i < n; ++i)
    {
      string tempOut =  students[i];
      int j ;
      lastname = "";
      firstname = "";
      
      lastname += tempOut[0];
      for(j = 1; islower(tempOut[j]); ++j)
	{
	  lastname += tempOut[j]; 
	}

      for(int k = j; k < tempOut.size(); ++k)
	{
	  firstname += tempOut[k];
	}

      cout << firstname << " "<< lastname << endl;
      
    }

  
  return 0;
}
