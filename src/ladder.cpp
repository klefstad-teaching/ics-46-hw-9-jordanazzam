#include "ladder.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <cctype>

void error(string word1, string word2, string msg)
{
    std::cerr << "an error has occured"  << msg << "word1: " << word1 << "word2: " << word2 << std::endl;
    return;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{
    int str1len = str1.length(), str2len = str2.length();
    if (str1len > str2len + 1 || str2len > str1len + 1) return false;
    if(d == 1)
    {
        if(str1len == str2len)
        {
            int dif = 0;
            for(int i = 0; i < str1len; i++)
            {
                if(str1[i] != str2[i])
                {
                    dif+=1;
                    if(dif > 1) return false;
                } 
            }
            return true;
        }
        else if(str1len > str2len)
        {
            int a = 0, b = 0, dif = 0;
            while(a < str1len && b < str2len)
            {
                if(str1[a] != str2[b])
                {
                    dif +=1;
                    a++;
                    if(dif>1)return false;
                }
                else
                {
                    a++;
                    b++;
                }
            }
            return true;
        }
        else if(str2len > str1len)
        {
            int a = 0, b = 0, dif = 0;
            while(a< str1len && b < str2len)
            {
                if(str1[a] != str2[b])
                {
                    dif +=1;
                    b++;
                    if(dif >1)return false;
                }
                else
                {
                    a++;
                    b++;
                }
            }
            return true;
        }
    }
    return false;  
}

bool is_adjacent(const string& word1, const string& word2)
{
    return(edit_distance_within(word1, word2, 1));
}


vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list)
{
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    while(!ladder_queue.empty())
    {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        for(const std::string &word : word_list)
        {
            if(is_adjacent(last_word, word))
            {
                if (visited.find(word) == visited.end())
                {
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if(word == end_word){
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return {}; 
}

void load_words(set<string> & word_list, const string& file_name)
{
    std::ifstream infile(file_name);
    string words;
    while(infile >> words)
    {
        for(char& c : words)
        {
            c = std::tolower(c);
        }
        word_list.insert(words);
    }
    infile.close();
}

void print_word_ladder(const vector<string>& ladder)
{
    if (ladder.empty())
    {
        cout << "No word ladder found." << endl;
        return;
    }
    cout << "Word ladder found: ";
    for (size_t i = 0; i < ladder.size(); ++i)
    {
        cout << ladder[i];
        if (i < ladder.size())
        {
            cout << " ";
        }
    }
    cout << endl;
}

void verify_word_ladder()
{
}