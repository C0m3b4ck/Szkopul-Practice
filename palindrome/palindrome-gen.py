def is_leap(y):
    if y == 0: return True
    if y % 400 == 0: return True
    if y % 100 == 0: return False
    if y % 4 == 0: return True
    return False

def days_in_month(m, y):
    if m == 2: return 29 if is_leap(y) else 28
    if m in (1,3,5,7,8,10,12): return 31
    return 30

def check_date_valid(d, m, y):
    if m < 1 or m > 12: return False
    if d < 1 or d > days_in_month(m, y): return False
    if y < 0: return False
    return True

def enumerate_palindromes(total_len):
    results = []
    mid_len = total_len - 8
    if mid_len < 0:
        return results

    for mm in range(1, 13):
        for dd in range(1, 32):
            dd_str = f"{dd:02d}"
            mm_str = f"{mm:02d}"
            prefix = dd_str + mm_str
            suffix = mm_str[::-1] + dd_str[::-1]

            num_mid = 10 ** mid_len if mid_len > 0 else 1

            for mid_val in range(num_mid):
                if mid_len > 0:
                    mid_str = f"{mid_val:0{mid_len}d}"
                else:
                    mid_str = ""

                full_str = prefix + mid_str + suffix
                year_str = full_str[4:]
                year = int(year_str)

                if check_date_valid(dd, mm, year):
                    results.append(full_str)

    return results

# Expected outputs from test results
expected_8 = [
    "10022001", "10033001", "10033001", "09111190", "02111120",
    "10022001", "23111132", "10022001", "10022001", "10022001", "10033001"
]

expected_10 = [
    "1010660101", "1010660101", "1010770101", "1010990101", "1010550101",
    "1010550101", "1010440101", "1010880101", "1010770101"
]

expected_long = [
    "101043212141212340101",
    "101066131030131660101",
    "101054490868094450101",
    "101087526747625780101",
    "101089752141257980101",
    "10101000011000010101",
    "101058019171910850101",
    "101010760191067010101"
]

def find_prev(sorted_list, target):
    for i, s in enumerate(sorted_list):
        if s == target:
            if i > 0:
                return sorted_list[i-1]
            return None
    return None

# 8-digit
pals8 = enumerate_palindromes(8)
pals8.sort()
print("=== 8-digit palindromes ===")
for e in expected_8:
    prev = find_prev(pals8, e)
    print(f"  {e} -> prev: {prev}")

# 10-digit
pals10 = enumerate_palindromes(10)
pals10.sort()
print("\n=== 10-digit palindromes ===")
for e in expected_10:
    prev = find_prev(pals10, e)
    print(f"  {e} -> prev: {prev}")

# 20-digit
pals20 = enumerate_palindromes(20)
pals20.sort()
print(f"\n=== 20-digit palindromes: {len(pals20)} total ===")
for e in expected_long:
    if len(e) == 20:
        prev = find_prev(pals20, e)
        print(f"  {e} -> prev: {prev}")

# 21-digit
pals21 = enumerate_palindromes(21)
pals21.sort()
print(f"\n=== 21-digit palindromes: {len(pals21)} total ===")
for e in expected_long:
    if len(e) == 21:
        prev = find_prev(pals21, e)
        print(f"  {e} -> prev: {prev}")
