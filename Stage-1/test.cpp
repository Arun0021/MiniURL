#include "main.cpp"
    //class --> UrlShortener
    //methods --> shorten URL, restoreURL

int main(){
    UrlShortener test;
    string s = "www.google.com";
    cout<<test.shortenURL(s)<<endl;
    cout<<test.shortenURL(s+"a")<<endl;
}