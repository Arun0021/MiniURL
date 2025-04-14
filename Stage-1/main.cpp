#include<bits/stdc++.h>

using namespace std;

class UrlShortener{
    private:
        unordered_map<string,string>shortToLong;
        unordered_map<string,string>longToShort;
        int id = 0;
        string base62 = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const string domain = "http://short.url/";

        string encodeBase62(int num){
            string res;
            while(num>0){
                res = base62[num%62]+res;
                num/=62;
            }
            while(res.size()<6){
                res = "0"+res;
            }
            return res;
        }
    public:
        string shortenURL(const string& longUrl){
            if(longToShort.find(longUrl)!=longToShort.end()){
                return domain+longToShort[longUrl];
            }
            string shortKey = encodeBase62(id++);
            longToShort[longUrl] = shortKey;
            shortToLong[shortKey] = longUrl;
            return domain + shortKey;
        }
        string restoreURL(const string& shortUrl){
            string key = shortUrl.substr(domain.length());
            if(shortToLong.find(key)!=shortToLong.end()){
                return shortToLong[key];
            }
            return "URL not found!";
        }
};
