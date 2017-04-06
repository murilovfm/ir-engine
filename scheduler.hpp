#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
#include <ctime>
#include <unordered_map>
#include "url.hpp"
using namespace std;

#define MAXLEN  80
#define MAXDOM  10
//max size of url (8)

class scheduler{
  public:
        scheduler();
        bool addInbound(url a);
        bool addOutbound(url a);
        void addCrawled(string &name, string &domain);
        bool checkEmpty();
        vector<int> genWeightsHash();
        url getUrl();
        int hashFunc(string &name);
        // url getInbound();
        // url getOutbound();
        bool checkCrawled(string &name, string &domain);

  private:
        unordered_map<int, double> crawledDomains;
        unordered_set<int> crawledPages; //HASH PARA DOMINIO, COM NUM CRAWLED
        vector<int> weights;
        priority_queue<url, vector<url>> inbound;
        priority_queue<url, vector<url>> outbound;
        int whichUrl;
};
