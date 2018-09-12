#include<bits/stdc++.h>
using namespace std;

struct node{
    int count;
    node *next[26];
    node()
    {
        count = 0;
        for(int i = 0; i<26; i++)
            next[i] = NULL;
    }
}*root;

void add(string name)
{
    node *current = root;
    current->count++;
    for(int i = 0; i<name.size(); i++)
    {
        char nw = name[i];
        if(current->next[(int)nw - 'a'] == NULL)
            current->next[(int) nw - 'a'] = new node();
        current = current->next[(int) nw - 'a'];
        current->count++;
    }
}

int main()
{
    add(str);
}

