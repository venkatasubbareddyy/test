#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

bool isPalindrome(const char* in_string, bool ignoreCase=true);
bool charicmp(char first, char second, bool ignore_case=true);
bool isEmptyStr(const char* str);
bool isNullStr(const char* str);
char toLower(char ch);
bool isAlphabet(char ch);

int main( int argc, char** argv )
{
    const char* in_strings[] = {
        "1881",
        "Dad",
        "Step on no pets",
        "dad",
        "step on no pets",
        NULL,
        ""
    };

    bool is_pal = false;

    for (auto input_str : in_strings)
    {
        is_pal = isPalindrome( input_str);   // for case sensitive: isPalindrome( input_str, false);

        if ( (!isNullStr(input_str))
            && (!isEmptyStr(input_str)) )
        {
            cout << "\"" << input_str << "\"" << (is_pal?" is ":" is not ") << "a palindrome" << endl;
        }
    }

    return 0;
}

// check if the in_string is a palindrome
bool isPalindrome(const char* in_string, bool ignoreCase)
{
    bool is_palindrome = false;
    if (isNullStr(in_string))
    {
        cout << "Palindrome check error: input string is NULL" << endl;
        is_palindrome = false;
    }
    else
    {
        int in_string_len = strlen(in_string);

        if (isEmptyStr(in_string))
        {
            cout << "Palindrome check warning: input string is empty" << endl;
            is_palindrome = false;
        }
        else if (1 == in_string_len)
        {
            cout << "Palindrome check warning: input string consists single character" << endl;
            is_palindrome = false;
        }
        else
        {
            int start, end;
            
            start = 0;
            end = in_string_len-1;
            
            is_palindrome = true;
            while ( start < end )
            {
                is_palindrome = is_palindrome && (charicmp(in_string[start], in_string[end], ignoreCase));
                ++start;
                --end;
            }
        }
    }
 
    return is_palindrome;
}

// check if str is any empty string
bool isEmptyStr(const char* str)
{
    return (isNullStr(str) || ("" == str));
}

// check if str is NULL
bool isNullStr(const char* str)
{
    return (NULL == str);
}

// convert ch to lower case
char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        if ('a' < 'A')
        {
            ch = ch + ('A'-'a'); // = (ch-'A')+'a'
        }
        else
        {
            ch = ch + ('a'-'A');
        }
    }

    return ch;
}

// check if ch is an alphabet or not
bool isAlphabet(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

// compare if first and second are equal
bool charicmp(char first, char second, bool ignore_case)
{
    bool result = false;

    if (ignore_case)
    {
        // ignore-case: convert first and second to the same (lower) case
        //  which would be helpful in making comparisions easy
        if (isAlphabet(first) && isAlphabet(second))
        {
            first = (first >= 'A' && first<= 'Z')? toLower(first) : first;
            second = (second >= 'A' && second<= 'Z')? toLower(second) : second;
        }
    }

    result = (first == second);

    return result;
}



/* Output:
"1881" is a palindrome
"Dad" is a palindrome
"Step on no pets" is a palindrome
"dad" is a palindrome
"step on no pets" is a palindrome
Palindrome check error: input string is NULL
Palindrome check warning: input string is empty
*/

