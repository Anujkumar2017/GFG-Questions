# Distinct Elements in a Stream
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an input stream of <strong>N</strong> integers (alongwith the operation on these integers), the task is to print the number of the distinct elements in the stream after each operation.<br>
The array is will be having positive and negative values. Positive value meaning you have to append it into your database and Negative value means you have to remove it from your database if present and at every step you have to count the number of distinct character in your database.</span></p>

<pre><span style="font-size:18px"><strong>Example 1:
Input: </strong>A[] = {5, 5, 7, -5, -7, 1, 2, -2}
<strong>Output: </strong>1 1 2 2 1 2 3 2
<strong>Explanation:
</strong>Here you can see we have an array of integer as 
stated that positive number means we will adding 
it to our database and negative means we will be 
deleting one occurence of that number from our database.
So, [5, 5, 7, -5, -7, 1, 2, -2] 
Add 5, Unique Value in Data Base is 1 -&gt; [5]
Add 5, Unique Value in Data Base is 1 -&gt; [5, 5]
Add 7, Unique Value in Data Base is 2 -&gt; [5, 5, 7]
Removing 5, Unique Value in Data Base is 2 -&gt; [5, 7]
Removing 7, Unique Value in Data Base is 1 -&gt; [5]
Add 1, Unique Value in Data Base is 2 -&gt; [5, 1]
Add 2, Unique Value in Data Base is 3 -&gt; [5, 1, 2]
Removing 2, Unique Value in Data Base is 2 -&gt; [5, 1]</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>maxDistinctNum()</strong> that takes an array&nbsp;<strong>(arr)</strong>, sizeOfArray (n), and return the number of unique value at every instance. The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;O(N).<br>
Expected Auxiliary Space:&nbsp;O(N).</strong></span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Input:</strong><br>
First line of the input contains an integer <strong>T</strong> denoting the number of test cases. Then <strong>T</strong> test case follows. First line of each test case contains an integer <strong>N</strong> denoting the number of operations to be performed on a stream. Next <strong>N</strong> lines two space separated elements, the operation to be performed and the key element.</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>6</sup><br>
-10<sup>6</sup> ≤ A[] ≤ 10<sup>6</sup></span></p>
</div>