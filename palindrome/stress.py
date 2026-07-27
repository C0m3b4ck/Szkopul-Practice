import random
import subprocess

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

random.seed(12345)
tests = []

# Test boundary cases around Feb 29
leap_years = [1900, 1904, 1996, 2000, 2004, 2092, 2104, 2400, 10000, 10004]
for y in leap_years:
    tests.append(f"2902{y}")
    tests.append(f"2802{y}")
    tests.append(f"0103{y}")

non_leap_years = [1900, 1901, 1999, 2001, 2093, 2101, 10001]
for y in non_leap_years:
    tests.append(f"2802{y}")
    tests.append(f"0103{y}")

# Dates near known palindromes
known_pals = ["10011001", "02011020", "01022010", "11022011",
              "22022022", "03022030", "10122101", "29022092"]
for p in known_pals:
    # date before the palindrome
    d = int(p[0:2])
    m = int(p[2:4])
    y = int(p[4:])
    if d > 1:
        tests.append(f"{d-1:02d}{m:02d}{y}")
    elif m > 1:
        tests.append(f"01{m-1:02d}{y}")
    else:
        tests.append(f"3112{y-1}")

# Random small year tests (brute-forceable)
for _ in range(300):
    y = random.randint(1000, 10000)
    m = random.randint(1, 12)
    maxd = days_in_month(m, y)
    d = random.randint(1, maxd)
    tests.append(f"{d:02d}{m:02d}{y}")

# Random medium year tests
for _ in range(1000):
    y = random.randint(100000, 10**9)
    m = random.randint(1, 12)
    maxd = days_in_month(m, y)
    d = random.randint(1, maxd)
    tests.append(f"{d:02d}{m:02d}{y}")

# Random large year tests  
for _ in range(500):
    y = random.randint(10**10, 10**17)
    m = random.randint(1, 12)
    maxd = days_in_month(m, y)
    d = random.randint(1, maxd)
    tests.append(f"{d:02d}{m:02d}{y}")

# Write input
with open('/tmp/palin_big.in', 'w') as f:
    f.write(f"{len(tests)}\n")
    for t in tests:
        f.write(f"{t}\n")

# Run the program
result = subprocess.run(['./palin'], stdin=open('/tmp/palin_big.in'), 
                       capture_output=True, text=True, timeout=30)
if result.returncode != 0:
    print(f"ERROR: {result.stderr}")
    exit(1)

output_lines = result.stdout.strip().split('\n')
print(f"Program produced {len(output_lines)} lines for {len(tests)} tests")

# Verify small year tests with brute force
errors = 0
for i, (t, r) in enumerate(zip(tests, output_lines)):
    y_val = int(t[4:])
    if y_val > 100000:
        continue  # skip brute force for large years
    d = int(t[0:2])
    m = int(t[2:4])
    y_str = t[4:]
    expected = next_palindrome(d, m, y_str)
    if r != expected:
        print(f"MISMATCH #{i}: input={t} expected={expected} got={r}")
        errors += 1
        if errors >= 20:
            break

if errors == 0:
    print(f"All verifiable tests passed!")
else:
    print(f"{errors} errors found")
