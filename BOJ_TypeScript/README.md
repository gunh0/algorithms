# BOJ TypeScript Solutions

This directory contains TypeScript solutions for Baekjoon Online Judge (BOJ) algorithm problems.

## Running Solutions

### Method 1: Using Make (Recommended)

Create an input file with the problem number:

```bash
echo "77 77 7777" > 11382.txt
make 11382
```

### Method 2: Direct Execution

Use `npx` to run TypeScript files directly:

```bash
npx ts-node 11382_꼬마_정민.ts < 11382.txt
```

## File Structure

- `<problem_number>_<problem_name>.ts` - Solution file
- `<problem_number>.txt` - Input file for testing
- `Makefile` - Automates running solutions

## Example

```bash
# Create input file
echo "77 77 7777" > 11382.txt

# Run with make
make 11382

# Expected output: 7931
```

## Notes

- `npx ts-node` automatically downloads and runs TypeScript without any setup
- No `package.json` or configuration files needed for simple practice
- Input files must be named `<problem_number>.txt`

## BOJ Submission

⚠️ **Important**: You MUST select **Node.js** as the language, NOT C++ or TypeScript!

### Steps to submit:
1. Copy the content of `.ts` file
2. Go to BOJ problem submission page
3. **Select language: Node.js** (언어: Node.js)
4. Paste the code
5. Submit

### Common Error:
If you see errors like `'const' does not name a type` or `'console' does not name a type`, you selected **C++** instead of **Node.js**. Change the language dropdown to Node.js.
