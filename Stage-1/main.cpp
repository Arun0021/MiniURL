#include<bits/stdc++.h>

using namespace std;

class UrlShortener{
    private:
        unordered_map<string,string>shortToLong;
        unordered_map<string,string>longToShort;
        int id = 0;
        string base62 = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const string domain = "http://short.url/";
        const string filePath = "data.txt";
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
        void appendToFile(const string& shortKey,const string& longUrl){
            ofstream outfile(filePath,ios::app);
            outfile<<shortKey<<" "<<longUrl<<endl;
        }
        int decodeBase62(const string& str){
            int num=0;
            for(char c:str){
                if('0'<=c && c<='9'){
                    num = num*62 + (c-'0');
                }else if('a'<=c && c<='z'){
                    num = num*62 + (c-'a')+10;
                }else if('A'<=c && c<='Z'){
                    num = num*62 + (c-'A')+10+26;
                }
            }
            return num;
        }
        void loadFromFile(){
            ifstream infile(filePath);
            string line;
            while(getline(infile,line)){
                istringstream iss(line);
                string shortKey,longURL;
                if(!(iss>>shortKey>>longURL))continue;
                shortToLong[shortKey] = longURL;
                longToShort[longURL] = shortKey;

                int decodedId = decodeBase62(shortKey);
                id = max(id,decodedId+1);
            }
        }
    public:
        UrlShortener(){
            loadFromFile();
        }
        string shortenURL(const string& longUrl){
            if(longToShort.find(longUrl)!=longToShort.end()){
                return domain+longToShort[longUrl];
            }
            string shortKey = encodeBase62(id++);
            longToShort[longUrl] = shortKey;
            shortToLong[shortKey] = longUrl;

            appendToFile(shortKey,longUrl);
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
