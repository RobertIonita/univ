#include <iostream>
using namespace std;

int getDistance(string str1, string str2)
{
    long int diff = 0;
    unsigned short int distance = 0,
                       strlen = 0;
    string shortest = str1;
    string longest = str2;
    if (str1.length() > str2.length())
    {
        longest = str1;
        shortest = str2;
    }
    diff += longest.length() - shortest.length();
    distance = diff;
    strlen = shortest.length();
    int gap = diff;
    for (size_t i = 0; i < strlen; i++)
        if (shortest[i] != longest[i])
        {
            if (gap <= 0)
                distance++;
            else
                while (shortest[i] != longest[i] && gap--)
                {
                    for (size_t j = i; j < strlen + diff - 1; j++)
                        longest[j] = longest[j + 1];
                    distance++;
                }
        }
    return distance;
}

string toUppercase(string str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] > 96)
            str[i] -= 32;
    return str;
}

int getNrOfVowels(string str)
{
    str = toUppercase(str);
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    int nr = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
        for (size_t j = 0; j < 5; j++)
            if (str[i] == vowels[j])
            {
                nr++;
                break;
            }
    return nr;
}

int main()
{
    cout << "\ndistance: " << getDistance("PISICA", "PIERSICA");
    cout << "\ndistance: " << getDistance("PISICA", "PISICA");
    cout << "\ndistance: " << getDistance("PISICA", "PICICA");
    cout << "\ndistance: " << getDistance("PISICA", "PIERSIIA");
    cout << "\ndistance: " << getDistance("PISICA", "PISCA");
    cout << "\ndistance: " << getDistance("Oreo", "LollyPop") << endl;;

    cout << "\nabc: " << toUppercase("abc");
    cout << "\nLol: " << toUppercase("Lol");
    cout << "\nJKUTwk: " << toUppercase("JKUTwk");
    cout << "\nOreo: " << toUppercase("Oreo");
    cout << "\nLollyPop: " << toUppercase("LollyPop") << endl;

    cout << "\nvowels: " << getNrOfVowels("PIERSICA");
    cout << "\nvowels: " << getNrOfVowels("PISICA");
    cout << "\nvowels: " << getNrOfVowels("PICICA");
    cout << "\nvowels: " << getNrOfVowels("PIERSIIA");
    cout << "\nvowels: " << getNrOfVowels("PISCA");
    cout << "\nvowels: " << getNrOfVowels("LollyPop");

    // if you found a bug - kindly ask you to report it here:
    // https://github.com/tonualexandru/univ/commit/d4995d92a1adec68daa4b04ae3fcd90e50847b0a
    return 0;
}