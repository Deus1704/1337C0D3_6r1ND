class CodingChallenge {
    constructor() {
        this.problems = [];
        this.currentProblems = [];
        this.init();
    }

    async init() {
        await this.loadProblems();
        this.setupEventListeners();
        this.displayRandomProblems();
    }

    setupEventListeners() {
        document.getElementById('refresh-btn').addEventListener('click', () => {
            this.displayRandomProblems();
        });
    }

    async loadProblems() {
        try {
            // Get list of all problem directories
            const problemDirs = await this.getProblemDirectories();
            
            // Load a sample of problems to avoid overwhelming GitHub API
            const sampleSize = Math.min(50, problemDirs.length);
            const shuffled = this.shuffleArray([...problemDirs]).slice(0, sampleSize);
            
            this.problems = await Promise.all(
                shuffled.map(dir => this.loadProblemData(dir))
            );
            
            // Filter out any failed loads
            this.problems = this.problems.filter(p => p !== null);
            
        } catch (error) {
            console.error('Failed to load problems:', error);
            this.showError();
        }
    }

    async getProblemDirectories() {
        // Since we can't dynamically get directory listing, we'll use a predefined list
        // This would normally be done server-side or with a static index
        return [
            '189-rotate-array',
            '1598-crawler-log-folder', 
            '66-plus-one',
            '297-serialize-and-deserialize-binary-tree',
            '3417-zigzag-grid-traversal-with-skip',
            '54-spiral-matrix',
            '118-pascals-triangle',
            '3528-unit-conversion-i',
            '100-same-tree',
            '121-best-time-to-buy-and-sell-stock',
            '206-reverse-linked-list',
            '15-3sum',
            '53-maximum-subarray',
            '70-climbing-stairs',
            '198-house-robber',
            '300-longest-increasing-subsequence',
            '322-coin-change',
            '39-combination-sum',
            '46-permutations',
            '78-subsets',
            '200-number-of-islands',
            '207-course-schedule',
            '33-search-in-rotated-sorted-array',
            '42-trapping-rain-water',
            '84-largest-rectangle-in-histogram',
            '75-sort-colors',
            '11-container-with-most-water',
            '3-longest-substring-without-repeating-characters',
            '20-valid-parentheses',
            '21-merge-two-sorted-lists'
        ];
    }

    async loadProblemData(problemDir) {
        try {
            // Load README.md and solution file
            const [readme, solution] = await Promise.all([
                this.loadFile(`${problemDir}/README.md`),
                this.loadSolutionFile(problemDir)
            ]);

            if (!readme) return null;

            return {
                id: problemDir,
                title: this.extractTitle(problemDir),
                number: this.extractNumber(problemDir),
                content: this.parseMarkdown(readme),
                solution: solution || 'Solution not available',
                difficulty: this.estimateDifficulty(problemDir)
            };
        } catch (error) {
            console.error(`Failed to load problem ${problemDir}:`, error);
            return null;
        }
    }

    async loadFile(path) {
        try {
            const response = await fetch(path);
            if (response.ok) {
                return await response.text();
            }
            return null;
        } catch (error) {
            console.error(`Failed to load file ${path}:`, error);
            return null;
        }
    }

    async loadSolutionFile(problemDir) {
        try {
            // Try to find the C++ solution file
            const response = await fetch(`${problemDir}/`);
            if (!response.ok) return null;
            
            const html = await response.text();
            const cppMatch = html.match(/href="([^"]*\.cpp)"/);
            
            if (cppMatch) {
                const cppFile = `${problemDir}/${cppMatch[1]}`;
                return await this.loadFile(cppFile);
            }
            
            return null;
        } catch (error) {
            console.error(`Failed to load solution for ${problemDir}:`, error);
            return null;
        }
    }

    extractTitle(problemDir) {
        // Convert directory name to readable title
        const parts = problemDir.split('-');
        const number = parts[0];
        const title = parts.slice(1).join(' ')
            .replace(/\b\w/g, l => l.toUpperCase());
        return `${number}. ${title}`;
    }

    extractNumber(problemDir) {
        return problemDir.split('-')[0];
    }

    parseMarkdown(content) {
        // Simple markdown to HTML conversion
        return content
            .replace(/&lt;/g, '<')
            .replace(/&gt;/g, '>')
            .replace(/&quot;/g, '"')
            .replace(/&#39;/g, "'")
            .replace(/&amp;/g, '&');
    }

    estimateDifficulty(problemDir) {
        const number = parseInt(this.extractNumber(problemDir));
        if (number < 100) return 'Easy';
        if (number < 1000) return 'Medium';
        return 'Hard';
    }

    shuffleArray(array) {
        const shuffled = [...array];
        for (let i = shuffled.length - 1; i > 0; i--) {
            const j = Math.floor(Math.random() * (i + 1));
            [shuffled[i], shuffled[j]] = [shuffled[j], shuffled[i]];
        }
        return shuffled;
    }

    displayRandomProblems() {
        if (this.problems.length === 0) {
            // If problems haven't loaded yet or failed, show sample problems
            this.displaySampleProblems();
            return;
        }

        this.currentProblems = this.shuffleArray(this.problems).slice(0, 3);
        this.renderProblems();
    }

    displaySampleProblems() {
        // Extended sample problems for a better experience
        const sampleProblems = [
            {
                id: '189-rotate-array',
                title: '189. Rotate Array',
                number: '189',
                content: `<p>Given an integer array <code>nums</code>, rotate the array to the right by <code>k</code> steps, where <code>k</code> is non-negative.</p>

<p><strong class="example">Example 1:</strong></p>
<pre>
<strong>Input:</strong> nums = [1,2,3,4,5,6,7], k = 3
<strong>Output:</strong> [5,6,7,1,2,3,4]
<strong>Explanation:</strong>
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
</pre>

<p><strong>Constraints:</strong></p>
<ul>
    <li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
    <li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
    <li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>`,
                solution: `class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k%nums.size()==0 ) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+(k%nums.size()));
        reverse(nums.begin()+k%nums.size(), nums.end());
    }
};`,
                difficulty: 'Medium'
            },
            {
                id: '66-plus-one',
                title: '66. Plus One',
                number: '66',
                content: `<p>You are given a <strong>large integer</strong> represented as an integer array <code>digits</code>, where each <code>digits[i]</code> is the <code>i<sup>th</sup></code> digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading <code>0</code>'s.</p>

<p>Increment the large integer by one and return <em>the resulting array of digits</em>.</p>

<p><strong class="example">Example 1:</strong></p>
<pre>
<strong>Input:</strong> digits = [1,2,3]
<strong>Output:</strong> [1,2,4]
<strong>Explanation:</strong> The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
</pre>

<p><strong>Constraints:</strong></p>
<ul>
    <li><code>1 &lt;= digits.length &lt;= 100</code></li>
    <li><code>0 &lt;= digits[i] &lt;= 9</code></li>
    <li><code>digits</code> does not contain any leading <code>0</code>'s.</li>
</ul>`,
                solution: `class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};`,
                difficulty: 'Easy'
            },
            {
                id: '1598-crawler-log-folder',
                title: '1598. Crawler Log Folder',
                number: '1598',
                content: `<p>The Leetcode file system keeps a log each time some user performs a <em>change folder</em> operation.</p>

<p>The operations are described below:</p>
<ul>
    <li><code>"../"</code> : Move to the parent folder of the current folder. (If you are already in the main folder, <strong>remain in the same folder</strong>).</li>
    <li><code>"./"</code> : Remain in the same folder.</li>
    <li><code>"x/"</code> : Move to the child folder named <code>x</code> (This folder is <strong>guaranteed to always exist</strong>).</li>
</ul>

<p>You are given a list of strings <code>logs</code> where <code>logs[i]</code> is the operation performed by the user at the <code>i<sup>th</sup></code> step.</p>

<p>The file system starts in the main folder, then the operations in <code>logs</code> are performed.</p>

<p>Return <em>the minimum number of operations needed to go back to the main folder after the change folder operations.</em></p>

<p><strong class="example">Example 1:</strong></p>
<pre>
<strong>Input:</strong> logs = ["d1/","d2/","../","d21/","./"]
<strong>Output:</strong> 2
</pre>`,
                solution: `class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>sta;
        for (auto ch : logs){
            if (ch == "../"){
                if (!sta.empty()) sta.pop();
            }else if(ch == "./"){
                continue;
            }else{
                sta.push(ch);
            }
        }
        return sta.size();
    }
};`,
                difficulty: 'Easy'
            },
            {
                id: '53-maximum-subarray',
                title: '53. Maximum Subarray',
                number: '53',
                content: `<p>Given an integer array <code>nums</code>, find the <strong>subarray</strong> with the largest sum, and return <em>its sum</em>.</p>

<p><strong class="example">Example 1:</strong></p>
<pre>
<strong>Input:</strong> nums = [-2,1,-3,4,-1,2,1,-5,4]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The subarray [4,-1,2,1] has the largest sum 6.
</pre>

<p><strong class="example">Example 2:</strong></p>
<pre>
<strong>Input:</strong> nums = [1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The subarray [1] has the largest sum 1.
</pre>

<p><strong>Constraints:</strong></p>
<ul>
    <li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
    <li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p><strong>Follow up:</strong> If you have figured out the <code>O(n)</code> solution, try coding another solution using the <strong>divide and conquer</strong> approach, which is more subtle.</p>`,
                solution: `class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int cur_sum = 0;
        for (int i=0; i<nums.size(); i++){
            cur_sum += nums[i];
            max_sum = max(max_sum, cur_sum);
            if (cur_sum < 0) cur_sum = 0;
        }
        return max_sum;
    }
};`,
                difficulty: 'Medium'
            },
            {
                id: '70-climbing-stairs',
                title: '70. Climbing Stairs',
                number: '70',
                content: `<p>You are climbing a staircase. It takes <code>n</code> steps to reach the top.</p>

<p>Each time you can either climb <code>1</code> or <code>2</code> steps. In how many distinct ways can you climb to the top?</p>

<p><strong class="example">Example 1:</strong></p>
<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
</pre>

<p><strong class="example">Example 2:</strong></p>
<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
</pre>

<p><strong>Constraints:</strong></p>
<ul>
    <li><code>1 &lt;= n &lt;= 45</code></li>
</ul>`,
                solution: `class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev1 = 1, prev2 = 2;
        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }
        return prev2;
    }
};`,
                difficulty: 'Easy'
            },
            {
                id: '39-combination-sum',
                title: '39. Combination Sum',
                number: '39',
                content: `<p>Given an array of <strong>distinct</strong> integers <code>candidates</code> and a target integer <code>target</code>, return <em>a list of all <strong>unique combinations</strong> of </em><code>candidates</code><em> where the chosen numbers sum to </em><code>target</code><em>.</em> You may return the combinations in <strong>any order</strong>.</p>

<p>The <strong>same</strong> number may be chosen from <code>candidates</code> an <strong>unlimited number of times</strong>. Two combinations are unique if the <strong>frequency</strong> of at least one of the chosen numbers is different.</p>

<p>The test cases are generated such that the number of unique combinations that sum up to <code>target</code> is less than <code>150</code> combinations for the given input.</p>

<p><strong class="example">Example 1:</strong></p>
<pre>
<strong>Input:</strong> candidates = [2,3,6,7], target = 7
<strong>Output:</strong> [[2,2,3],[7]]
<strong>Explanation:</strong>
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
</pre>

<p><strong>Constraints:</strong></p>
<ul>
    <li><code>1 &lt;= candidates.length &lt;= 30</code></li>
    <li><code>2 &lt;= candidates[i] &lt;= 40</code></li>
    <li>All elements of <code>candidates</code> are <strong>distinct</strong>.</li>
    <li><code>1 &lt;= target &lt;= 40</code></li>
</ul>`,
                solution: `class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& candidates, int target, int start, 
                   vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                current.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], i, current, result);
                current.pop_back();
            }
        }
    }
};`,
                difficulty: 'Medium'
            },
            {
                id: '121-best-time-to-buy-and-sell-stock',
                title: '121. Best Time To Buy And Sell Stock',
                number: '121',
                content: `<p>You are given an array <code>prices</code> where <code>prices[i]</code> is the price of a given stock on the <code>i<sup>th</sup></code> day.</p>

<p>You want to maximize your profit by choosing a <strong>single day</strong> to buy one stock and choosing a <strong>different day in the future</strong> to sell that stock.</p>

<p>Return <em>the maximum profit you can achieve from this transaction</em>. If you cannot achieve any profit, return <code>0</code>.</p>

<p><strong class="example">Example 1:</strong></p>
<pre>
<strong>Input:</strong> prices = [7,1,5,3,6,4]
<strong>Output:</strong> 5
<strong>Explanation:</strong> Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
</pre>

<p><strong>Constraints:</strong></p>
<ul>
    <li><code>1 &lt;= prices.length &lt;= 10<sup>5</sup></code></li>
    <li><code>0 &lt;= prices[i] &lt;= 10<sup>4</sup></code></li>
</ul>`,
                solution: `class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }
        
        return maxProfit;
    }
};`,
                difficulty: 'Easy'
            },
            {
                id: '75-sort-colors',
                title: '75. Sort Colors',
                number: '75',
                content: `<p>Given an array <code>nums</code> with <code>n</code> objects colored red, white, or blue, sort them <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank"><strong>in-place</strong></a> so that objects of the same color are adjacent, with the colors in the order red, white, and blue.</p>

<p>We will use the integers <code>0</code>, <code>1</code>, and <code>2</code> to represent the color red, white, and blue, respectively.</p>

<p>You must solve this problem without using the library's sort function.</p>

<p><strong class="example">Example 1:</strong></p>
<pre>
<strong>Input:</strong> nums = [2,0,2,1,1,0]
<strong>Output:</strong> [0,0,1,1,2,2]
</pre>

<p><strong>Constraints:</strong></p>
<ul>
    <li><code>n == nums.length</code></li>
    <li><code>1 &lt;= n &lt;= 300</code></li>
    <li><code>nums[i]</code> is either <code>0</code>, <code>1</code>, or <code>2</code>.</li>
</ul>

<p><strong>Follow up:</strong> Could you come up with a one-pass algorithm using only constant extra space?</p>`,
                solution: `class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, current = 0;
        
        while (current <= right) {
            if (nums[current] == 0) {
                swap(nums[current], nums[left]);
                left++;
                current++;
            } else if (nums[current] == 2) {
                swap(nums[current], nums[right]);
                right--;
                // Don't increment current as we need to check the swapped element
            } else {
                current++;
            }
        }
    }
};`,
                difficulty: 'Medium'
            },
            {
                id: '297-serialize-and-deserialize-binary-tree',
                title: '297. Serialize And Deserialize Binary Tree',
                number: '297',
                content: `<p>Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.</p>

<p>Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.</p>

<p><strong>Clarification:</strong> The input/output format is the same as <a href="https://support.leetcode.com/hc/en-us/articles/32442719377939-How-to-create-test-cases-on-LeetCode#h_01J5EGREAW3NAEJ14XC07GRW1A" target="_blank">how LeetCode serializes a binary tree</a>. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.</p>

<p><strong class="example">Example 1:</strong></p>
<pre>
<strong>Input:</strong> root = [1,2,3,null,null,4,5]
<strong>Output:</strong> "[1,2,3,null,null,4,5]"
</pre>

<p><strong>Constraints:</strong></p>
<ul>
    <li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
    <li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>`,
                solution: `class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "null";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        string token;
        stringstream ss(data);
        while (getline(ss, token, ',')) {
            q.push(token);
        }
        return deserializeHelper(q);
    }
    
private:
    TreeNode* deserializeHelper(queue<string>& q) {
        string val = q.front();
        q.pop();
        if (val == "null") return nullptr;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(q);
        node->right = deserializeHelper(q);
        return node;
    }
};`,
                difficulty: 'Hard'
            },
            {
                id: '46-permutations',
                title: '46. Permutations',
                number: '46',
                content: `<p>Given an array <code>nums</code> of distinct integers, return <em>all the possible <strong>permutations</strong></em>. You can return the answer in <strong>any order</strong>.</p>

<p><strong class="example">Example 1:</strong></p>
<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
</pre>

<p><strong class="example">Example 2:</strong></p>
<pre>
<strong>Input:</strong> nums = [0,1]
<strong>Output:</strong> [[0,1],[1,0]]
</pre>

<p><strong>Constraints:</strong></p>
<ul>
    <li><code>1 &lt;= nums.length &lt;= 6</code></li>
    <li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
    <li>All the integers of <code>nums</code> are <strong>unique</strong>.</li>
</ul>`,
                solution: `class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, result);
            swap(nums[start], nums[i]); // backtrack
        }
    }
};`,
                difficulty: 'Medium'
            },
            {
                id: '200-number-of-islands',
                title: '200. Number Of Islands',
                number: '200',
                content: `<p>Given an <code>m x n</code> 2D binary grid <code>grid</code> which represents a map of <code>'1'</code>s (land) and <code>'0'</code>s (water), return <em>the number of islands</em>.</p>

<p>An <strong>island</strong> is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.</p>

<p><strong class="example">Example 1:</strong></p>
<pre>
<strong>Input:</strong> grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
<strong>Output:</strong> 1
</pre>

<p><strong>Constraints:</strong></p>
<ul>
    <li><code>m == grid.length</code></li>
    <li><code>n == grid[i].length</code></li>
    <li><code>1 &lt;= m, n &lt;= 300</code></li>
    <li><code>grid[i][j]</code> is <code>'0'</code> or <code>'1'</code>.</li>
</ul>`,
                solution: `class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int islands = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return islands;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0'; // mark as visited
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};`,
                difficulty: 'Medium'
            },
            {
                id: '11-container-with-most-water',
                title: '11. Container With Most Water',
                number: '11',
                content: `<p>You are given an integer array <code>height</code> of length <code>n</code>. There are <code>n</code> vertical lines drawn such that the two endpoints of the <code>i<sup>th</sup></code> line are <code>(i, 0)</code> and <code>(i, height[i])</code>.</p>

<p>Find two lines that together with the x-axis form a container, such that the container contains the most water.</p>

<p>Return <em>the maximum amount of water a container can store</em>.</p>

<p><strong>Notice</strong> that you may not slant the container.</p>

<p><strong class="example">Example 1:</strong></p>
<pre>
<strong>Input:</strong> height = [1,8,6,2,5,4,8,3,7]
<strong>Output:</strong> 49
<strong>Explanation:</strong> The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
</pre>

<p><strong>Constraints:</strong></p>
<ul>
    <li><code>n == height.length</code></li>
    <li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
    <li><code>0 &lt;= height[i] &lt;= 10<sup>4</sup></code></li>
</ul>`,
                solution: `class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;
        
        while (left < right) {
            int width = right - left;
            int minHeight = min(height[left], height[right]);
            maxWater = max(maxWater, width * minHeight);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};`,
                difficulty: 'Medium'
            },
            {
                id: '206-reverse-linked-list',
                title: '206. Reverse Linked List',
                number: '206',
                content: `<p>Given the <code>head</code> of a singly linked list, reverse the list, and return <em>the reversed list</em>.</p>

<p><strong class="example">Example 1:</strong></p>
<pre>
<strong>Input:</strong> head = [1,2,3,4,5]
<strong>Output:</strong> [5,4,3,2,1]
</pre>

<p><strong class="example">Example 2:</strong></p>
<pre>
<strong>Input:</strong> head = [1,2]
<strong>Output:</strong> [2,1]
</pre>

<p><strong>Constraints:</strong></p>
<ul>
    <li>The number of nodes in the list is the range <code>[0, 5000]</code>.</li>
    <li><code>-5000 &lt;= Node.val &lt;= 5000</code></li>
</ul>

<p><strong>Follow up:</strong> A linked list can be reversed either iteratively or recursively. Could you implement both?</p>`,
                solution: `class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        
        while (current != nullptr) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
};`,
                difficulty: 'Easy'
            }
        ];
        
        this.currentProblems = this.shuffleArray(sampleProblems).slice(0, 3);
        this.renderProblems();
    }

    renderProblems() {
        const container = document.getElementById('problems-container');
        const loading = document.getElementById('loading');
        
        loading.style.display = 'none';
        container.style.display = 'block';
        
        container.innerHTML = this.currentProblems.map((problem, index) => `
            <div class="problem-card">
                <div class="problem-header">
                    <h2 class="problem-title">${problem.title}</h2>
                    <span class="problem-number">#${problem.number}</span>
                </div>
                
                <div class="problem-content">
                    ${problem.content}
                </div>
                
                <div class="solution-section">
                    <button class="solution-toggle" onclick="toggleSolution(${index})">
                        👁️ Show Solution
                    </button>
                    <div class="solution-content" id="solution-${index}">
                        <pre><code class="language-cpp">${problem.solution}</code></pre>
                    </div>
                </div>
            </div>
        `).join('');

        // Trigger Prism highlighting
        if (typeof Prism !== 'undefined') {
            Prism.highlightAll();
        }
    }

    showError() {
        document.getElementById('loading').style.display = 'none';
        document.getElementById('error').style.display = 'block';
    }
}

// Global function for solution toggle
function toggleSolution(index) {
    const solutionContent = document.getElementById(`solution-${index}`);
    const button = solutionContent.previousElementSibling;
    
    if (solutionContent.classList.contains('show')) {
        solutionContent.classList.remove('show');
        button.textContent = '👁️ Show Solution';
    } else {
        solutionContent.classList.add('show');
        button.textContent = '🙈 Hide Solution';
    }
}

// Initialize the application
document.addEventListener('DOMContentLoaded', () => {
    new CodingChallenge();
});