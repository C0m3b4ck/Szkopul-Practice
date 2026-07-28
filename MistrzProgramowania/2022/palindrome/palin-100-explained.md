# palin-100.cpp — Full Explanation

## Problem

Given a date written as `ddmmYYYY...` (day, month, year, no separators), find the **next**
date whose entire string representation is a **palindrome** (reads the same forwards and
backwards).

Example: `030612216030` is a palindrome because it reads the same both ways. The date
is `03/06` and the year is `12216030`.

---

## Input Format

```
N
ddmmYYYY
ddmmYYYY
...
```

- First line: number of test cases `N`.
- Each following line: one date with **no separators**, e.g. `03062024`.

---

## How the Input is Parsed

### Layer 1: Buffered I/O (`ibuf` + `fread`)

Instead of reading one character at a time from stdin (which is slow), the code grabs a
big 1 MB chunk all at once into a buffer called `ibuf`. Then it hands out characters one
by one from that buffer. When the buffer runs out, it grabs another 1 MB chunk.

Think of it like filling a glass from a bucket instead of walking to the tap for every sip.

```c
// grab up to 1 MB from stdin into ibuf
// fread returns how many bytes it actually got
ilen = fread(ibuf, 1, sizeof(ibuf), stdin);
```

### Layer 2: The Read Functions

**`readInt()`** — skips whitespace, then reads digits until it hits a non-digit, building
the number as it goes:

```
x = 0
read '3'  -> x = 3
read '\n' (not a digit) -> stop, return 3
```

**`readStr(s)`** — skips whitespace, then reads characters until the next whitespace,
copying them into array `s`:

```
read '0','3','0','6','2','0','2','4' -> s = "03062024"
read '\n' (whitespace) -> stop
```

### Layer 3: Splitting the Date String by Position

After `readStr(s)` returns, the code splits the string by **position**, not by any
separator:

```c
int ddi = (s[0]-'0')*10 + s[1]-'0';   // characters 0,1 -> day
int mmi = (s[2]-'0')*10 + s[3]-'0';   // characters 2,3 -> month
long long yi = 0;
for (int i = 4; i < L; i++)            // characters 4+   -> year
    yi = yi * 10 + (s[i] - '0');
```

`s[0]-'0'` converts a character like `'0'` to the number `0`. Then
`(s[0]-'0')*10 + (s[1]-'0')` combines two digits into one number. For example, `'0'`
and `'3'` become `0 x 10 + 3 = 3`.

For the year, it loops through the remaining characters and builds the number digit by
digit.

### Reusable Read Functions

```c
// Read a single integer from stdin (skips whitespace)
int readInt() {
    int c = readChar(), x = 0;
    while (c <= ' ') c = readChar();       // skip spaces, newlines, tabs
    while (c >= '0' && c <= '9') {         // while it's a digit
        x = x * 10 + c - '0';             // add this digit to the number
        c = readChar();
    }
    return x;
}

// Read a single string from stdin (until whitespace)
int readStr(char* s) {
    int c = readChar(), i = 0;
    while (c <= ' ') c = readChar();       // skip whitespace
    while (c > ' ') {                      // while NOT whitespace
        s[i++] = c;                        // copy this character
        c = readChar();
    }
    s[i] = 0;                              // null-terminate the string
    return i;                              // return length
}
```

---

## The Palindrome Structure

A palindrome date string looks like this:

```
ddmm  |  middle_palindrome  |  reverse(ddmm)
```

- `ddmm` is always the first 4 digits.
- `reverse(ddmm)` is always the last 4 digits (e.g. if `ddmm` = `0306`, then
  `reverse(ddmm)` = `6030`).
- Everything in between must itself be a palindrome (possibly empty).

Example:

```
0306  1221  6030
^^^^  ^^^^  ^^^^
ddmm  mid   rev(ddmm)
```

The full string `030612216030` is a palindrome.

---

## The Math Formula

### Notation

| Symbol | Meaning |
|--------|---------|
| `ddmm` | The 4-digit day+month string (e.g. `0306`) |
| `rv` | The reverse of `ddmm` as a number (e.g. `6030`) |
| `Y_min` | The smallest year that comes after the input date |
| `pal(p)` | The smallest palindrome of the required length with prefix `p` |
| `mn` | The minimum prefix value needed for the middle palindrome |

### Key Equation

The year is formed by gluing the middle palindrome in front of `rv`:

```
year = middle_palindrome x 10000 + rv
```

**Why multiply by 10000?** Because `rv` is always exactly 4 digits. When you concatenate
a number `A` followed by 4 digits `B` in a string, the numeric value is `A x 10^4 + B`.
That is just how positional number notation works.

### Finding the Minimum Middle Prefix

If `rv` is already >= `Y_min`, no middle part is needed — the year is just `rv`.

If `rv` < `Y_min`, you need a middle palindrome. The smallest prefix `mn` that works is:

```
mn = ceil((Y_min - rv) / 10000)
```

This asks: "how many groups of 10000 do I need to add to `rv` to reach at least
`Y_min`?"

Then the final year is:

```
year = pal(mn) x 10000 + rv
```

where `pal(mn)` is the smallest palindrome of the required length whose first digits are
`mn`.

### Concrete Example

Input date: `03062024` (June 3rd, 2024). Suppose the candidate is `ddmm = 0306`.

```
rv = reverse(0306) = 6030

Input date is June 3. Candidate June 3 is NOT after June 3,
so year must be >= 2025.

Y_min = 2025
rv = 6030

6030 >= 2025, so rv alone works as the year!
Final year = 6030.
Full palindrome: 0306 + 6030 = "03066030"
Date: June 3rd, year 6030.
```

Now suppose the candidate is `ddmm = 2512` (Dec 25).

```
rv = reverse(2512) = 2152

Dec 25 is NOT after June 3 (same year), so year must be >= 2025.

Y_min = 2025
rv = 2152

2152 < 2025, so we need a middle palindrome.

mn = ceil((2025 - 2152) / 10000)
   = ceil(-127 / 10000)
   = 0

pal(0) = 0 (an empty middle palindrome).
year = 0 x 10000 + 2152 = 2152.
```

Since 2152 >= 2025, this works. Full palindrome: `25122152`, date is Dec 25, 2152.

---

## Date Validation

When the code picks a candidate `(day, month, year)`, it must check whether that date
actually exists. Most dates are fine. The only tricky one is **February 29**, which only
exists in **leap years**.

### Leap Year Rule

A year is a leap year if:

- Divisible by 4, **AND**
- NOT divisible by 100, **UNLESS** also divisible by 400

```
2024 / 4 = 506, not a century year       -> leap year (Feb has 29 days)
1900 / 4 = 475, but / 100 = 19           -> NOT a leap year (Feb has 28 days)
2000 / 4 = 500, / 100 = 20, / 400 = 5   -> leap year
```

Code:

```c
static inline bool is_leap(long long y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
```

### Validation Logic

```c
int mxday;                              // max valid day for this month
if (d_mm == 2)
    mxday = is_leap(yr) ? 29 : 28;     // February: 28 or 29
else
    mxday = max_days[d_mm];             // every other month has a fixed max

if (d_dd > mxday) continue;            // date doesn't exist, skip this candidate
```

The `max_days` table:

```
month:  0   1   2   3   4   5   6   7   8   9  10  11  12
max:    0  31  29  31  30  31  30  31  31  30  31  30  31
```

If a candidate is Feb 29 in a non-leap year, `mxday = 28`, and `29 > 28` so it is
skipped.

---

## Flowchart of the Algorithm

```
+---------------------+
|   Read N test cases |
+---------------------+
          |
          v
+---------------------+
|  For each test case:|
|  read date string,  |
|  split into dd, mm, |
|  yy                 |
+---------------------+
          |
          v
+--------------------------------------------+
|  For each of the 366 valid (day, month)    |
|  pairs:                                     |
|                                              |
|   (a) Compute ddmm string and rv = rev(ddmm)|
|   (b) Is this date AFTER the input date?    |
|       Yes -> my = yy (same year OK)         |
|       No  -> my = yy+1 (must be next year)  |
|   (c) Compute mn = ceil((my - rv) / 10000)  |
|   (d) Build year = pal(mn) x 10000 + rv     |
|   (e) Validate the date exists               |
|   (f) Track the smallest valid year found    |
+--------------------------------------------+
          |
          v
+---------------------+
|  Output the ddmm +  |
|  best year found    |
+---------------------+
```

### Detailed Flowchart

```
START
  |
  v
+--------------------------+
| Read input date string   |
| Split into dd, mm, yy    |
+--------------------------+
  |
  v
+--------------------------+     +---------------------------+
| Set best_year = infinity  |     |                           |
| Set base_ml = max(0, len - 8)  |                           |
+--------------------------+     |                           |
  |                              |                           |
  v                              |                           |
+==========================================+                 |
|  FOR EACH of 366 valid (day, month)      |                 |
|  candidate pairs:                        |                 |
+==========================================+                 |
  |                                                             |
  |  +-------------------------------------------------------+ |
  |  | 1. Build ddmm string and compute rv = reverse(ddmm)   | |
  |  +-------------------------------------------------------+ |
  |  |                                                         | |
  |  | 2. Does candidate date come AFTER input date?           | |
  |  |    +--- YES: my = yy                                    | |
  |  |    +--- NO:  my = yy + 1                                | |
  |  |                                                         | |
  |  | 3. Compute: mn = ceil((my - rv) / 10000)               | |
  |  |    This is the minimum prefix needed so that            | |
  |  |    year = middle x 10000 + rv  is >= my                 | |
  |  |                                                         | |
  |  | 4. Is rv >= my?                                         | |
  |  |    +--- YES: year = rv (no middle part needed)          | |
  |  |    +--- NO:  year = pal(mn) x 10000 + rv               | |
  |  |                                                         | |
  |  | 5. Does the date exist in this year?                   | |
  |  |    (e.g. Feb 29 only in leap years)                     | |
  |  |    +--- NO:  skip this candidate                        | |
  |  |    +--- YES: continue                                   | |
  |  |                                                         | |
  |  | 6. Is year < best_year so far?                          | |
  |  |    +--- NO:  skip this candidate                        | |
  |  |    +--- YES: best_year = year, best_candidate = this    | |
  |  +-------------------------------------------------------+ |
  |                                                             |
  +=======(loop continues for all 366 candidates)===============+
                    |
                    v
          +---------------------+
          | Print ddmm + best   |
          | year                |
          +---------------------+
                    |
                   END
```

### Legend

| Symbol | Meaning |
|--------|---------|
| `dd` | Day of the month (01-31) |
| `mm` | Month number (01-12) |
| `yy` | Input year |
| `ddmm` | 4-digit string of day+month, e.g. `"0306"` |
| `rv` | Reverse of `ddmm` as a 4-digit number, e.g. `reverse("0306")` = `6030` |
| `my` | The year threshold for this candidate: `yy` if the candidate date is after the input, else `yy+1` |
| `mn` | Minimum prefix value: the smallest number whose palindrome, when placed before `rv`, makes the year >= `my` |
| `pal(p)` | Smallest palindrome of the required length starting with prefix `p` |
| `base_ml` | Minimum length of the middle palindrome, derived from total string length |
| `best_year` | The smallest valid palindrome-year found across all 366 candidates |
| `+--- YES / NO` | Branch based on a condition |
| `ceil(x)` | Ceiling function: round x up to the nearest integer |
| `reverse(s)` | Reverse the digits of a number/string |

---

## How `fstream` / `ofstream` Would Work (For Reference)

This code does **not** use `fstream` or `ofstream`. It uses manual buffered I/O for
maximum speed. But for reference:

| Class | Header | Purpose | Example |
|-------|--------|---------|---------|
| `ifstream` | `<fstream>` | Input file stream (reads from file) | `ifstream fin("palin.in"); fin >> x;` |
| `ofstream` | `<fstream>` | Output file stream (writes to file) | `ofstream fout("palin.out"); fout << answer << "\n";` |
| `fstream` | `<fstream>` | Both read and write | `fstream f("data.bin", ios::in \| ios::out);` |

They work exactly like `cin` / `cout` but with files instead of the terminal. `ifstream`
is for reading, `ofstream` is for writing, and `fstream` can do both. The file is
automatically closed when the object goes out of scope (destructor).

This code uses `fread` and `fwrite` instead because they operate on raw bytes with no
formatting overhead, making them significantly faster for competitive programming.
