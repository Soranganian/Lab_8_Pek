#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string vowels = "AEIOUYaeiouy";

bool is_palindrome(string s)
{
    int n = s.length();
    if (n == 1) return false;
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1]) return false;
    return true;
}

bool is_it_letter(char c) {
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

bool has_palindromes(string* words, int n)
{
    for (int i = 0; i < n; i++)
        if (is_palindrome(words[i])) return true;
    return false;
}

string makelil(string string) {
    std::string s = "";
    short n = string.length();
    for (int i = 0; i < n; i++) {
        char c = string[i];
        if ('A' <= c && c <= 'Z')
            s += c + ('z' - 'Z');
        else s += c;
    }
    return s;
}

int count_vowels(string s)
{
    int counter = 0;
    for (int i = 0; i < s.length(); i++)
        if (vowels.find(s[i]) != string::npos) counter++;
    return counter;
}

void countWordsVowels(string* words, int* counts, int n) {
    for (int i = 0; i < n; i++) {
        counts[i] = count_vowels(words[i]);
    }
}

void duplicate_vowels(string& s) {
    for (int i = 0; i < s.length(); i++)
        if (vowels.find(s[i]) != string::npos) {
            s.insert(i + 1, 1, s[i]);
            i++; 
        }
}

void sort_words_by_vowelscount(string* words, int* counts, int n) {
    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n; j++) 
            if (counts[i] > counts[j]) {
                swap(words[i], words[j]);
                swap(counts[i], counts[j]);
            }
}

string towords(string s) {
    string str = "";
    s = makelil(s);
    short n = s.length();

    short start = 0;
    while (start < n && !is_it_letter(s[start])) {
        start++;
    }
    
    short end = n - 1;
    while (end >= 0 && !is_it_letter(s[end])) {
        end--;
    }

    for (int i = start; i <= end; i++) {
        str += s[i];
    }
    return str;
}

void alphabet_sort(string* words, int n) {
    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n; j++) 
            if (words[i] < words[j]) 
                std::swap(words[i], words[j]); 
}

void printWords(string* words, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << words[i] << " ";
    }
}

int main()
{
    string input;
    getline(cin, input);
    int n = input.length();
    string words[2000];
    
    int k = 0;
    int j = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n || input[i] == ' ') {
            if (i > j) {
                words[k] = towords(input.substr(j, i - j));
                k++;
            }
            j = i + 1;
        }
    }
  
    if (has_palindromes(words, k)) {
        int count_vowels[2000] = {0};
        countWordsVowels(words, count_vowels, k);
        sort_words_by_vowelscount(words, count_vowels, k);
    }
    else {
        for (int i = 0; i < k; i++) {
            duplicate_vowels(words[i]);
        }
        alphabet_sort(words, k);
    }
    
    printWords(words, k);
    return 0;
}
