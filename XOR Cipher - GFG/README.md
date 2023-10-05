# XOR Cipher
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a string <strong>S</strong>&nbsp;created by a cypher algorithm. Find the original hexadecimal string.</span></p>

<p><span style="font-size:18px"><strong>The cypher algorithm</strong>: A hexadecimal string is XORed,&nbsp;<strong>N </strong>number of times, where <strong>N</strong> is the string length and&nbsp;every&nbsp;XOR operation is done after shifting the consecutive string<strong>&nbsp;</strong>to the right.<br>
For example : String: "</span><strong><span style="font-size:18px">abcd".&nbsp;</span>&nbsp;</strong><br>
<img alt="" src="https://cdncontribute.geeksforgeeks.org/wp-content/uploads/pic1-2.jpg"><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
S = A1D0A1D
<strong>Output:</strong>
ABCD
<strong>Explanation:</strong>
Look at the matrix given in the problem statement.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
S = 653CABEBD24
<strong>Output:</strong>
556F64</span>
<span style="font-size:18px"><strong>Explanation:
</strong></span><span style="font-size:18px">556F64
&nbsp;</span><span style="font-size:18px">556F64
&nbsp; </span><span style="font-size:18px">556F64
   556F64
&nbsp;   556F64
&nbsp;    556F64
653CABEBD24</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>deCypher()</strong>&nbsp;which takes the string S as input parameter&nbsp;and returns&nbsp;the original hexadecimal string.</span></p>

<p><span style="font-size:18px"><strong>Note:</strong> Alphabets are in uppercase.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity: </strong>O(N)<br>
<strong>Expected Space Complexity: </strong>O(N)</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=N&lt;=1001 &amp;&nbsp;N%2=1</span></p>
</div>