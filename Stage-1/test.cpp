#include "main.cpp"
    //class --> UrlShortener
    //methods --> shorten URL, restoreURL

int main(){
    UrlShortener s;

    string short1 = s.shortenURL("https://example.com/about-us");
string short2 = s.shortenURL("https://openai.com/research");
string short3 = s.shortenURL("https://github.com/arun-dev/URLShortener");

// Retrieve original URLs
cout << "Original 1: " << s.restoreURL(short1) << endl;
cout << "Original 2: " << s.restoreURL(short2) << endl;
cout << "Original 3: " << s.restoreURL(short3) << endl;

return 0;
}