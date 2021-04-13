// @ts-nocheck
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/);

let ptr = 0;
const out: string[] = [];

class HopcroftKarp {
	adj: number[][];
	nLeft: number;
	nRight: number;
	pairU: Int32Array;
	pairV: Int32Array;
	dist: Int32Array;

	constructor(adj: number[][], nLeft: number, nRight: number) {
		this.adj = adj;
		this.nLeft = nLeft;
		this.nRight = nRight;
		this.pairU = new Int32Array(nLeft);
		this.pairV = new Int32Array(nRight);
		this.dist = new Int32Array(nLeft);
		this.pairU.fill(-1);
		this.pairV.fill(-1);
	}

	bfs(): boolean {
		const q = new Int32Array(this.nLeft);
		let head = 0;
		let tail = 0;
		let found = false;

		for (let u = 0; u < this.nLeft; u++) {
			if (this.pairU[u] === -1) {
				this.dist[u] = 0;
				q[tail++] = u;
			} else {
				this.dist[u] = -1;
			}
		}

		while (head < tail) {
			const u = q[head++];
			const du = this.dist[u];
			for (const v of this.adj[u]) {
				const u2 = this.pairV[v];
				if (u2 === -1) {
					found = true;
				} else if (this.dist[u2] === -1) {
					this.dist[u2] = du + 1;
					q[tail++] = u2;
				}
			}
		}
		return found;
	}

	dfs(u: number): boolean {
		for (const v of this.adj[u]) {
			const u2 = this.pairV[v];
			if (
				u2 === -1 ||
				(this.dist[u2] === this.dist[u] + 1 && this.dfs(u2))
			) {
				this.pairU[u] = v;
				this.pairV[v] = u;
				return true;
			}
		}
		this.dist[u] = -1;
		return false;
	}

	maxMatching(): number {
		let matching = 0;
		while (this.bfs()) {
			for (let u = 0; u < this.nLeft; u++) {
				if (this.pairU[u] === -1 && this.dfs(u)) {
					matching++;
				}
			}
		}
		return matching;
	}
}

function solveCase(n: number, e: number, grid: string[]): string[] {
	const leftId: number[][] = Array.from({ length: n }, () =>
		Array(e).fill(-1),
	);
	const rightId: number[][] = Array.from({ length: n }, () =>
		Array(e).fill(-1),
	);
	const cellsLeft: Array<[number, number]> = [];
	const cellsRight: Array<[number, number]> = [];

	for (let r = 0; r < n; r++) {
		for (let c = 0; c < e; c++) {
			if (grid[r][c] === "X") continue;
			if (((r + c) & 1) === 0) {
				leftId[r][c] = cellsLeft.length;
				cellsLeft.push([r, c]);
			} else {
				rightId[r][c] = cellsRight.length;
				cellsRight.push([r, c]);
			}
		}
	}

	const nLeft = cellsLeft.length;
	const nRight = cellsRight.length;
	const adj: number[][] = Array.from({ length: nLeft }, () => []);
	const dr = [1, -1, 0, 0];
	const dc = [0, 0, 1, -1];

	for (let u = 0; u < nLeft; u++) {
		const [r, c] = cellsLeft[u];
		for (let k = 0; k < 4; k++) {
			const nr = r + dr[k];
			const nc = c + dc[k];
			if (nr < 0 || nr >= n || nc < 0 || nc >= e) continue;
			const v = rightId[nr][nc];
			if (v !== -1) adj[u].push(v);
		}
	}

	const hk = new HopcroftKarp(adj, nLeft, nRight);
	hk.maxMatching();
	const pairU = hk.pairU;
	const pairV = hk.pairV;

	const canUnmatchLeft = new Uint8Array(nLeft);
	const canUnmatchRight = new Uint8Array(nRight);

	{
		const visL = new Uint8Array(nLeft);
		const visR = new Uint8Array(nRight);
		const qType = new Uint8Array(nLeft + nRight + 5); // 0: left, 1: right
		const qId = new Int32Array(nLeft + nRight + 5);
		let head = 0;
		let tail = 0;

		for (let u = 0; u < nLeft; u++) {
			if (pairU[u] === -1) {
				visL[u] = 1;
				qType[tail] = 0;
				qId[tail++] = u;
			}
		}

		while (head < tail) {
			const t = qType[head];
			const id = qId[head++];
			if (t === 0) {
				const u = id;
				for (const v of adj[u]) {
					if (pairU[u] === v) continue; // only unmatched edges L -> R
					if (!visR[v]) {
						visR[v] = 1;
						qType[tail] = 1;
						qId[tail++] = v;
					}
				}
			} else {
				const v = id;
				const u = pairV[v];
				if (u !== -1 && !visL[u]) {
					visL[u] = 1;
					qType[tail] = 0;
					qId[tail++] = u;
				}
			}
		}

		for (let i = 0; i < nLeft; i++) canUnmatchLeft[i] = visL[i];
	}

	// The second traversal needs reverse adjacency to follow unmatched R -> L edges.
	const revAdj: number[][] = Array.from({ length: nRight }, () => []);
	for (let u = 0; u < nLeft; u++) {
		for (const v of adj[u]) revAdj[v].push(u);
	}

	{
		const visL = new Uint8Array(nLeft);
		const visR = new Uint8Array(nRight);
		const qType = new Uint8Array(nLeft + nRight + 5); // 0: left, 1: right
		const qId = new Int32Array(nLeft + nRight + 5);
		let head = 0;
		let tail = 0;

		for (let v = 0; v < nRight; v++) {
			if (pairV[v] === -1) {
				visR[v] = 1;
				qType[tail] = 1;
				qId[tail++] = v;
			}
		}

		while (head < tail) {
			const t = qType[head];
			const id = qId[head++];
			if (t === 1) {
				const v = id;
				for (const u of revAdj[v]) {
					if (pairV[v] === u) continue; // only unmatched edges R -> L
					if (!visL[u]) {
						visL[u] = 1;
						qType[tail] = 0;
						qId[tail++] = u;
					}
				}
			} else {
				const u = id;
				const v = pairU[u];
				if (v !== -1 && !visR[v]) {
					visR[v] = 1;
					qType[tail] = 1;
					qId[tail++] = v;
				}
			}
		}

		for (let i = 0; i < nRight; i++) canUnmatchRight[i] = visR[i];
	}

	const ans: string[] = Array.from({ length: n }, () => "");
	for (let r = 0; r < n; r++) {
		let line = "";
		for (let c = 0; c < e; c++) {
			if (grid[r][c] === "X") {
				line += "X";
			} else {
				if (((r + c) & 1) === 0) {
					const u = leftId[r][c];
					line += canUnmatchLeft[u] ? "B" : "A";
				} else {
					const v = rightId[r][c];
					line += canUnmatchRight[v] ? "B" : "A";
				}
			}
		}
		ans[r] = line;
	}

	return ans;
}

while (ptr < tokens.length) {
	const n = Number(tokens[ptr++]);
	const e = Number(tokens[ptr++]);
	if (n === 0 && e === 0) break;

	const grid: string[] = [];
	for (let i = 0; i < n; i++) grid.push(tokens[ptr++]);

	const res = solveCase(n, e, grid);
	for (const line of res) out.push(line);
	out.push("");
}

process.stdout.write(out.join("\n"));
