// Problem: 11382 - 꼬마 정민
// A + B + C calculation with large numbers (up to 10^12)

const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split(" ");

// Parse input as BigInt to handle large numbers
const A = BigInt(input[0]);
const B = BigInt(input[1]);
const C = BigInt(input[2]);

// Calculate sum
const sum = A + B + C;

// Output the result
console.log(sum.toString());
