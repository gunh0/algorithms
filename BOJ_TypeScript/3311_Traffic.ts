// @ts-nocheck
// Problem: BOJ 3311 - Traffic

const fs = require("fs");
const data = fs.readFileSync(0);

class FastScanner {
	constructor(buf) {
		this.buf = buf;
		this.idx = 0;
	}

	nextInt() {
		const n = this.buf.length;
		while (this.idx < n) {
			const c = this.buf[this.idx];
			if (c > 32) break;
			this.idx++;
		}

		let sign = 1;
		if (this.buf[this.idx] === 45) {
			sign = -1;
			this.idx++;
		}

		let num = 0;
		while (this.idx < n) {
			const c = this.buf[this.idx];
			if (c < 48 || c > 57) break;
			num = num * 10 + (c - 48);
			this.idx++;
		}
		return num * sign;
	}
}

const sc = new FastScanner(data);

const n = sc.nextInt();
const m = sc.nextInt();
const A = sc.nextInt();
sc.nextInt();

const x = new Int32Array(n + 1);
const y = new Int32Array(n + 1);

const west = [];
const east = [];

for (let i = 1; i <= n; i++) {
	const xi = sc.nextInt();
	const yi = sc.nextInt();
	x[i] = xi;
	y[i] = yi;
	if (xi === 0) west.push(i);
	if (xi === A) east.push(i);
}

const maxDirEdges = 2 * m + 5;

const head = new Int32Array(n + 1);
const rhead = new Int32Array(n + 1);
head.fill(-1);
rhead.fill(-1);

const from = new Int32Array(maxDirEdges);
const to = new Int32Array(maxDirEdges);
const next = new Int32Array(maxDirEdges);

const rto = new Int32Array(maxDirEdges);
const rnext = new Int32Array(maxDirEdges);

let edgeCnt = 0;

function addEdge(u, v) {
	from[edgeCnt] = u;
	to[edgeCnt] = v;
	next[edgeCnt] = head[u];
	head[u] = edgeCnt;

	rto[edgeCnt] = u;
	rnext[edgeCnt] = rhead[v];
	rhead[v] = edgeCnt;

	edgeCnt++;
}

for (let i = 0; i < m; i++) {
	const c = sc.nextInt();
	const d = sc.nextInt();
	const k = sc.nextInt();
	addEdge(c, d);
	if (k === 2) addEdge(d, c);
}

// 1) SCC decomposition (Kosaraju, iterative)
const visited = new Uint8Array(n + 1);
const order = [];

for (let s = 1; s <= n; s++) {
	if (visited[s]) continue;

	const stNode = [s];
	const stEdge = [head[s]];
	visited[s] = 1;

	while (stNode.length > 0) {
		const top = stNode.length - 1;
		const u = stNode[top];
		let e = stEdge[top];

		while (e !== -1 && visited[to[e]]) e = next[e];

		if (e !== -1) {
			stEdge[top] = next[e];
			const v = to[e];
			visited[v] = 1;
			stNode.push(v);
			stEdge.push(head[v]);
		} else {
			stNode.pop();
			stEdge.pop();
			order.push(u);
		}
	}
}

const comp = new Int32Array(n + 1);
let compCnt = 0;

for (let i = order.length - 1; i >= 0; i--) {
	const s = order[i];
	if (comp[s] !== 0) continue;

	compCnt++;
	const st = [s];
	comp[s] = compCnt;

	while (st.length > 0) {
		const u = st.pop();
		for (let e = rhead[u]; e !== -1; e = rnext[e]) {
			const v = rto[e];
			if (comp[v] !== 0) continue;
			comp[v] = compCnt;
			st.push(v);
		}
	}
}

// East boundary ordering by y-coordinate
east.sort((a, b) => y[a] - y[b]);
const eastRank = new Int32Array(n + 1);
for (let i = 0; i < east.length; i++) eastRank[east[i]] = i + 1;

const INF = 1 << 30;
const minReach = new Int32Array(compCnt + 1);
const maxReach = new Int32Array(compCnt + 1);
for (let i = 1; i <= compCnt; i++) {
	minReach[i] = INF;
	maxReach[i] = 0;
}

for (let i = 1; i <= n; i++) {
	const rank = eastRank[i];
	if (rank === 0) continue;
	const c = comp[i];
	if (rank < minReach[c]) minReach[c] = rank;
	if (rank > maxReach[c]) maxReach[c] = rank;
}

// 2) Build condensation DAG
const chead = new Int32Array(compCnt + 1);
chead.fill(-1);
const cto = new Int32Array(edgeCnt);
const cnext = new Int32Array(edgeCnt);
const indeg = new Int32Array(compCnt + 1);

let cEdgeCnt = 0;
for (let e = 0; e < edgeCnt; e++) {
	const u = comp[from[e]];
	const v = comp[to[e]];
	if (u === v) continue;
	cto[cEdgeCnt] = v;
	cnext[cEdgeCnt] = chead[u];
	chead[u] = cEdgeCnt;
	indeg[v]++;
	cEdgeCnt++;
}

// 3) Topological order + reverse DP for reachable east interval
const queue = new Int32Array(compCnt);
let qh = 0;
let qt = 0;

for (let c = 1; c <= compCnt; c++) {
	if (indeg[c] === 0) queue[qt++] = c;
}

const topo = new Int32Array(compCnt);
let tlen = 0;

while (qh < qt) {
	const u = queue[qh++];
	topo[tlen++] = u;

	for (let e = chead[u]; e !== -1; e = cnext[e]) {
		const v = cto[e];
		indeg[v]--;
		if (indeg[v] === 0) queue[qt++] = v;
	}
}

for (let i = tlen - 1; i >= 0; i--) {
	const u = topo[i];
	let mn = minReach[u];
	let mx = maxReach[u];

	for (let e = chead[u]; e !== -1; e = cnext[e]) {
		const v = cto[e];
		if (minReach[v] < mn) mn = minReach[v];
		if (maxReach[v] > mx) mx = maxReach[v];
	}

	minReach[u] = mn;
	maxReach[u] = mx;
}

// Output for western boundary junctions in decreasing y
west.sort((a, b) => y[b] - y[a]);

// Mark junctions reachable from at least one western junction
const reachableFromWest = new Uint8Array(n + 1);
for (const s of west) {
	if (reachableFromWest[s]) continue;
	const st = [s];
	reachableFromWest[s] = 1;
	while (st.length > 0) {
		const u = st.pop();
		for (let e = head[u]; e !== -1; e = next[e]) {
			const v = to[e];
			if (reachableFromWest[v]) continue;
			reachableFromWest[v] = 1;
			st.push(v);
		}
	}
}

const eastPrefix = new Int32Array(east.length);
if (east.length > 0) {
	eastPrefix[0] = reachableFromWest[east[0]] ? 1 : 0;
	for (let i = 1; i < east.length; i++) {
		eastPrefix[i] =
			eastPrefix[i - 1] + (reachableFromWest[east[i]] ? 1 : 0);
	}
}

const out = [];
for (const w of west) {
	const c = comp[w];
	if (minReach[c] === INF) out.push("0");
	else {
		const left = minReach[c] - 1;
		const right = maxReach[c] - 1;
		const cnt =
			left === 0
				? eastPrefix[right]
				: eastPrefix[right] - eastPrefix[left - 1];
		out.push(String(cnt));
	}
}

process.stdout.write(out.join("\n"));
