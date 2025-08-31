# [Longest Valid Word with All Prefixes](https://www.geeksforgeeks.org/problems/longest-valid-word-with-all-prefixes/1)
## Medium
Given an array of strings words[], find the longest string such that every prefix of it is also present in words[]. If multiple strings have the same maximum length, return the lexicographically smallest one. 
If no such string is found, return an empty string.
Examples:
Input: words[]&nbsp;= ["p", "pr", "pro", "probl", "problem", "pros", "process", "processor"]Output: "pros"&nbsp;Explanation: "pros" is the longest word with all prefixes ("p", "pr", "pro", "pros") present.
Input: words[] = ["geeks", "gfg", "geeksforgeeks"]Output: ""Explanation:&nbsp;No valid strings for all their prefixes present in the words array.
Constraints:1 &lt;= words.size &lt;= 10001 &lt;= words[i].size &lt;= 100