import sys
import random

def is_leap(y):
    if y % 400 == 0: return True
    if y % 100 == 0: return False
    if y % 4 == 0: return True
    return False

def days_in_month(m, y):
    if m == 2: return 29 if is_leap(y) else 28
    if m in (1,3,5,7,8,10,12): return 31
    return 30

def next_palindrome(dd, mm, yyyy_str):
    """Brute force: find next palindrome date after given date."""
    s = f"{dd:02d}{mm:02d}{yyyy_str}"
    # Start from next day
    d, m, y = dd, mm, int(yyyy_str)
    while True:
        d += 1
        if d > days_in_month(m, y):
            d = 1
            m += 1
            if m > 12:
                m = 1
                y += 1
        s2 = f"{d:02d}{m:02d}{y}"
        if s2 == s2[::-1]:
            return s2

def gen_tests():
    random.seed(42)
    tests = []
    # Edge cases
    tests.append("22022022")  # palindrome itself
    tests.append("010193040") # from example
    tests.append("29022092")  # Feb 29 leap year
    tests.append("28022092")
    tests.append("01011000")  # min year
    tests.append("31121000")
    
    # Random dates with various year lengths
    for ylen in [4, 5, 6, 7, 8, 9, 10, 14, 17, 18]:
        for _ in range(50):
            y = random.randint(10**(ylen-1), 10**ylen - 1)
            m = random.randint(1, 12)
            maxd = days_in_month(m, y)
            d = random.randint(1, maxd)
            tests.append(f"{d:02d}{m:02d}{y}")
    
    # Specific edge cases for Feb 29
    tests.append("29022092")
    tests.append("28022092")
    tests.append("01032092")
    tests.append("29021996")  # leap year 1996
    tests.append("28021996")
    tests.append("29022000")  # leap year 2000 (div by 400)
    tests.append("01012000")
    
    # Dates near palindrome boundaries
    tests.append("01011010")
    tests.append("10011001")
    tests.append("02011020")
    tests.append("01022010")
    
    # Large year tests
    for _ in range(100):
        y = random.randint(10**15, 10**17)
        m = random.randint(1, 12)
        maxd = days_in_month(m, y)
        d = random.randint(1, maxd)
        tests.append(f"{d:02d}{m:02d}{y}")
    
    return tests

tests = gen_tests()
# Write test input
with open('/tmp/palin_test.in', 'w') as f:
    f.write(f"{len(tests)}\n")
    for t in tests:
        f.write(f"{t}\n")

# Run brute force for small year tests only (skip large years - too slow)
small_tests = []
for t in tests:
    y_str = t[4:]
    y = int(y_str)
    if y <= 100000:
        small_tests.append(t)

brute_results = {}
for t in small_tests:
    d = int(t[0:2])
    m = int(t[2:4])
    y_str = t[4:]
    brute_results[t] = next_palindrome(d, m, y_str)

print(f"Total tests: {len(tests)}, small tests for verification: {len(small_tests)}")

# Write small tests for brute force comparison
with open('/tmp/palin_small.in', 'w') as f:
    f.write(f"{len(small_tests)}\n")
    for t in small_tests:
        f.write(f"{t}\n")
