"""
You are given a string S. Find the number of different substrings in S.

Input
One line containing a string S consisting of lowercase Latin letters.

Output
Output one integer - answer to the question.

Constraints
1 <= length of S <= 1200

SAMPLE INPUT 
abc
SAMPLE OUTPUT 
6
Time Limit: 2.0 sec(s) for each input file.
Memory Limit: 256 MB
Source Limit: 1024 KB
"""


"""
Generating all sub strings and adding in the dictionary. Then returning length of dictionary
"""

sub_dict = {}

def get_output(s):
    s_size = len(s)
    for i in range(0, s_size):
        for j in range(i+1, s_size+1):
            new_s = s[i:j]
            if new_s not in sub_dict:
                sub_dict[new_s] = 1
            else:
                sub_dict[new_s] += 1
    return len(sub_dict)


def main():
    s = input()
    print(get_output(s))
    
main()