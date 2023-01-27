1.Two sum
@hashtable @array

A naive approach will take O(n2) time but space complexity O(1) . Loop through each element x and for each element we need to find whether its complement exists or not. In the worst case, we have to loop through every element which takes O(n) time.

A better option is to use a two pass hash table. A hash table is the best way to maintain a mapping to each element of the array to its index. Thus we can reduce the look up time O(n) to O(1) time trading space for speed. First we are gonna put every element in the hashmap. Then the same approach as previous but this time looking up will take O(1) time. But one thing to keep in mind is that collisions might happen if there is any duplicate value.

We can do it even with one pass hash table. While we are iterating every element and putting the element in the hash table, we also look back if current’s element complement already exists in the hash table or not.

2.Valid parentheses
@string

The problem is pretty much straightforward. We are going to use stack data structure because it gives last in first out properties. If it’s the entry bracket like “(“ , “[“ , “{” we will push it to the stack. If it’s the ending bracket then we will first check whether the stack is empty or not. If it’s not empty then we will match the top of the stack. If they are the same type then it's still a valid parentheses otherwise it will return false. Time complexity will be O(n).

3.Merge Two Sorted List
@LinkedList

The problem is kind of similar to merge sort where we have to combine the two sorted lists. But here we are using a linked list structure. First we are going to check the head of the two listnode. We will insert the listnode with a small value into the finalList and go to the next node of the list. We will keep doing this until one list is finished. Time complexity: O(n + m)

4.Best Time to Buy and Sell Stock
@array
We can maintain two variables - minprice and maxprofit corresponding to the smallest valley and maximum profit (maximum difference between selling price and minprice) obtained so far respectively

5.Valid Palindrome
@string

First, we have to remove all the non-alphanumeric characters from the string and also replace the uppercase to lowercase. For this we have to look through every element which will take O(n) time. Then we just check the 1st element with the last element, after that 2nd character with 2nd last character and so on. If there is any mismatch in any iteration then the string isn’t palindrome otherwise it returns true.

6.Invert Binary Tree
@bfs @dfs @binaryTree

First approach: Recursion
Base case will be the inverse of an empty tree is an empty tree. Then we recursively call the left and right subtree of the root. After the end of the recursive call, we swap the left and right tree. Time complexity O(n) as each node of the tree is visited exactly once.

Second approach: Iterative
This approach is kind of similar to the bfs algorithm. Initially only the root is in the queue. As long as the queue isn’t empty, remove the next node from the queue and insert the left and right node of the tree and swap its children. When the queue is empty just return the root.

7.Valid Anagram
@string @hashTable

Keep the occurrences of every character of the first string in an array. As there are only lowercase english characters , the length of the array will be 26. Now keep decreasing the value of the same character from the array if it is present in the second array. In the end if all the values of array is 0 then both strings are anagram otherwise not.

8.Binary Search
@binarySearch

Normal Binary search which will reduce the search length by half every time.
