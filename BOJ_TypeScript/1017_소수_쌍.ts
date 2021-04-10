// @ts-nocheck
// Problem: 1017 - 소수 쌍
// Bipartite matching problem - pair all numbers such that each pair's sum is prime

const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = parseInt(input[0]);
const nums = input[1].split(" ").map(Number);

// Check if a number is prime
function isPrime(n) {
	if (n < 2) return false;
	if (n === 2) return true;
	if (n % 2 === 0) return false;
	for (let i = 3; i * i <= n; i += 2) {
		if (n % i === 0) return false;
	}
	return true;
}

// Build adjacency graph for indices that can be paired (sum is prime)
function buildGraph(indices) {
	const n = indices.length;
	const graph = Array.from({ length: n }, () => []);

	for (let i = 0; i < n; i++) {
		for (let j = i + 1; j < n; j++) {
			if (isPrime(nums[indices[i]] + nums[indices[j]])) {
				graph[i].push(j);
				graph[j].push(i);
			}
		}
	}

	return graph;
}

// Bipartite matching using maximum matching algorithm
function maxMatching(graph, n) {
	const match = Array(n).fill(-1);

	function dfs(u, visited) {
		for (const v of graph[u]) {
			if (visited[v]) continue;
			visited[v] = true;

			if (match[v] === -1 || dfs(match[v], visited)) {
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}

	let matchCount = 0;
	for (let i = 0; i < n; i++) {
		if (match[i] === -1) {
			const visited = Array(n).fill(false);
			visited[i] = true;
			if (dfs(i, visited)) {
				matchCount++;
			}
		}
	}

	return matchCount;
}

// Check if remaining numbers can be perfectly matched after pairing 0 with pairIdx
function canPairFirstWith(pairIdx) {
	// Get remaining indices (exclude 0 and pairIdx)
	const remaining = [];
	for (let i = 1; i < N; i++) {
		if (i !== pairIdx) {
			remaining.push(i);
		}
	}

	if (remaining.length === 0) return true;

	// Build graph for remaining numbers
	const graph = buildGraph(remaining);

	// Check if perfect matching exists (all nodes matched)
	const matchCount = maxMatching(graph, remaining.length);
	return matchCount * 2 === remaining.length;
}

// Find all possible pairs for the first number
const result = [];

for (let i = 1; i < N; i++) {
	// Check if first number and nums[i] sum to prime
	if (!isPrime(nums[0] + nums[i])) continue;

	// Check if remaining numbers can be perfectly paired
	if (canPairFirstWith(i)) {
		result.push(nums[i]);
	}
}

// Output result
if (result.length === 0) {
	console.log(-1);
} else {
	result.sort((a, b) => a - b);
	console.log(result.join(" "));
}
