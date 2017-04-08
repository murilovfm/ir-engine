#include <iostream>
#include "scheduler.hpp"
#include "kmp.hpp"
#include <CkSpider.h>
#include <CkString.h>
#include <cstring>
#include <fstream>
#include <thread>
#include <queue>
#include <mutex>
#include <string>
using namespace std;

class crawler{
  public:
        crawler(string &path);
        void begin();
        static void crawl(string seedUrl);
        static string getUrlDomain(string &url);
        static string normalizeUrl(string &name);
        static int isBr(string &domain);
        static bool isDomain(string &subUrl);

  private:
        static int nPages;
        string pathToStore;
        static scheduler sc;
        static mutex mutexQueue;
        static mutex mutexCrawled;
        static mutex mutexNPages;
        vector<string> seeds;
        static vector<string> domainTypes;
};
