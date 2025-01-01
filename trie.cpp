#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::string;
using std::vector;
using namespace std;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string>& patterns)
{
    trie t;
    t.push_back(edges()); // Add the root node



    for (size_t i = 0; i < patterns.size(); i++)
    {
        size_t currentNode = 0; 
        for (size_t j = 0; j < patterns[i].size(); j++)
        {
            char currentSymbol = patterns[i][j];

   
            auto it = t[currentNode].find(currentSymbol);

            if (it != t[currentNode].end())
            {
               
                currentNode = it->second;
            }
            else
            {
                

                t[currentNode][currentSymbol] = t.size();
                currentNode = t.size();
                t.push_back(edges());

            }
        }


    }
    //t.push_back(edges());

    return t;
}

int main()
{
    size_t n;
    std::cin >> n;
    vector<string> patterns;
    for (size_t i = 0; i < n; i++)
    {
        string s;
        std::cin >> s;
        patterns.push_back(s);
    }

    trie t = build_trie(patterns);
    for (size_t i = 0; i < t.size(); ++i)
    {

        for (const auto& j : t[i])
        {
            //cout << "Size: T: " << t.size() << endl;
            std::cout << i << "->" << j.second << ":" << j.first << "\n";
        }
    }

    return 0;
}
