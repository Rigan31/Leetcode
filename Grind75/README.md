# Grind 75 Description

[Grind 75 Problem List from tech interview hand book](https://www.techinterviewhandbook.org/grind75)

## 1.Two sum

**_hashtable, array_**

A naive approach will take O(n2) time but space complexity O(1) . Loop through each element x and for each element we need to find whether its complement exists or not. In the worst case, we have to loop through every element which takes O(n) time.

A better option is to use a two pass hash table. A hash table is the best way to maintain a mapping to each element of the array to its index. Thus we can reduce the look up time O(n) to O(1) time trading space for speed. First we are gonna put every element in the hashmap. Then the same approach as previous but this time looking up will take O(1) time. But one thing to keep in mind is that collisions might happen if there is any duplicate value.

We can do it even with one pass hash table. While we are iterating every element and putting the element in the hash table, we also look back if current’s element complement already exists in the hash table or not.

## 2.Valid parentheses

**_string_**

The problem is pretty much straightforward. We are going to use stack data structure because it gives last in first out properties. If it’s the entry bracket like “(“ , “[“ , “{” we will push it to the stack. If it’s the ending bracket then we will first check whether the stack is empty or not. If it’s not empty then we will match the top of the stack. If they are the same type then it's still a valid parentheses otherwise it will return false. Time complexity will be O(n).

## 3.Merge Two Sorted List

**_linkedList_**

The problem is kind of similar to merge sort where we have to combine the two sorted lists. But here we are using a linked list structure. First we are going to check the head of the two listnode. We will insert the listnode with a small value into the finalList and go to the next node of the list. We will keep doing this until one list is finished. Time complexity: O(n + m)

## 4.Best Time to Buy and Sell Stock

**_array_**

We can maintain two variables - minprice and maxprofit corresponding to the smallest valley and maximum profit (maximum difference between selling price and minprice) obtained so far respectively

## 5.Valid Palindrome

**_string_**

First, we have to remove all the non-alphanumeric characters from the string and also replace the uppercase to lowercase. For this we have to look through every element which will take O(n) time. Then we just check the 1st element with the last element, after that 2nd character with 2nd last character and so on. If there is any mismatch in any iteration then the string isn’t palindrome otherwise it returns true.

## 6.Invert Binary Tree

**_bfs, dfs, binaryTree_**

**First approach: Recursion**

Base case will be the inverse of an empty tree is an empty tree. Then we recursively call the left and right subtree of the root. After the end of the recursive call, we swap the left and right tree. Time complexity O(n) as each node of the tree is visited exactly once.

**Second approach: Iterative**
This approach is kind of similar to the bfs algorithm. Initially only the root is in the queue. As long as the queue isn’t empty, remove the next node from the queue and insert the left and right node of the tree and swap its children. When the queue is empty just return the root.

## 7.Valid Anagram

**_string, hashTable_**

Keep the occurrences of every character of the first string in an array. As there are only lowercase english characters , the length of the array will be 26. Now keep decreasing the value of the same character from the array if it is present in the second array. In the end if all the values of array is 0 then both strings are anagram otherwise not.

## 8.Binary Search

**_binarySearch_**

Normal Binary search which will reduce the search length by half every time.

## 9.Flood Fill

**_dfs, bfs, matrix_**

Both BFS and DFS work here. We are going to use a queue to store the current node and also a matrix to store the information if we have already colored this node or not. Then we are going to check the 4 directions of the current node. If the node of the same color is found then we will add it to the queue and change the color of the node to the target color and keep doing this until the queue is empty. Time complexity: O(m\*n) because in the worst case we have to visit every cell of the matrix.

## 10.Lowest Common Ancestor of a Binary Search Tree

**_binarySearchTree, dfs_**

**Iterative Approach:**The properties that separate Binary Search Tree from a regular binary tree are All nodes of the left subtree are less than the root node and all nodes of the right subtree are greater than the root node. We can use this property to find the LCA. If both the nodes are less than the root node then we will go to the left node. If both the nodes are greater than the root node then we will go to the right node.Otherwise, p and q are on the opposite side and the current root is the LCA because after that both are going to have different parent node. Time complexity O(h) where h is the hight of the binary search tree. Space Complexity O(1) because we are not using any extra space. The height of the tree will be log(n) if the tree is balanced and n if the tree is not balanced.

**Recursive Approach:** The recursive approach is pretty much similar to the iterative approach. The only difference is that we are using the recursive call to find the LCA. Time complexity O(h) where h is the hight of the binary search tree. Space Complexity O(h) because we are using the recursive call stack.

## 11.Balanced Binary Tree

**_binaryTree, dfs_**

A binary tree is balanced if the height difference between the left and right subtree is not more than 1. So, we are going to use a recursive function to find the height of the left and right subtree. If the height difference is more than 1 then we will make the flag false. Also we need to increase the height by 1 every time when we go the next level. Time Complexity O(n) because we are visiting every node of the tree. Space Complexity O(n) because we are using the recursive call stack and we have to visit the every node once.

## 12.Linked List Cycle

**_linkedList, twoPointers hashTable_**

A classic way to traverse a linked list is to put a pointer to the head of the list and traverse the list until the pointer is null. But if the linked list has a cycle then the pointer will never be null. So, to detect the cycle we have to use a hash table. Then we will put every visited node in the hash table. If we find any node which is already in the hash table then we will return that cycle is present.
Time Complexity O(n) and Space Complexity O(n) because we are using the hash table.

**Two Pointers Approach/Floyd's Cycle Finding Algorithm/Tortoise and Hare Algorithm:**

[Video Explanation by Inside code](https://www.youtube.com/watch?v=PvrxZaH_eZ4)

We have two pointers - slow and fast. Slow pointer will move one step at a time and fast pointer will move two steps at a time. If there is no cycle in the linked list then the fast pointer will reach the end of the linked list. But if there is a cycle then the fast pointer and slow pointer will meet at some point. Time Complexity O(n) and Space Complexity O(1) because we are not using any extra space.

**Bonus: Find the starting point of the cycle**

Assume when the fast and slow pointer meet, the slow pointer has moved "s" distance and fast pointer has moved "f" distance. The distance before the starting point of the cycle is "x" and the distance between the starting point and the meeting point is "y" and the distance between the meeting point and the starting point is "z". Then we have the following equations:

```math
    l = y + z // length of the cycle
    f = x + c1*l + y // fast pointer distance
    s = x + c2*l + y // slow pointer distance
    f = 2*s // fast pointer is twice as slow pointer
    x + c1*l + y = 2*(x + c2*l + y)
    x + y = (c1 - 2*c2)*l
    x = (c1 - 2*c2 - 1)*l + z
    x = c3*l + z
```

So, after confirming that there is a cycle in the linked list, we will move the slow pointer to the head of the linked list and move both the pointers one step at a time. When they meet, the meeting point will be the starting point of the cycle.

```c++
    ListNode *detectCycle(ListNode *head){
        if(head == NULL) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                // we found the cycle.Now we have to find the starting point of the cycle
                // we will move the slow pointer to the head of the linked list
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
    }

```

## 13.Implemented Queue using Stacks

**_stack, queue_**

We are going to use two stacks. One stack will be used to store the elements and the other stack will be used to reverse the order of the elements. When we push an element to the queue, we will push it to the first stack. Time Complexity of Push operation is O(1). When we peek or pop an element from the queue, we will first check whether the second stack is empty or not. If it is empty then we will push all the elements from the first stack to the second stack until the first stack is empty. Then we will return the top element of the second stack. For pop operation, we will also pop the top element of the second stack. Time Complexity of Pop and Peek operation is amortized O(1) because we are pushing all the elements from the first stack to the second stack only once. Beacuse of this reason the rest of the pop operation will be O(1) though the first pop operation will be O(n) where n is the length of the first stack.
