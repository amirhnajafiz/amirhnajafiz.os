import os
from collections import Counter, defaultdict

def get_stats(base_path):
    levels = ['easy', 'medium', 'hard']
    level_counts = Counter()
    pl_counts = Counter()
    level_pls = defaultdict(Counter)

    for entry in os.listdir(base_path):
        dir_path = os.path.join(base_path, entry)
        if os.path.isdir(dir_path):
            for fname in os.listdir(dir_path):
                if '.' in fname:
                    name, ext = fname.rsplit('.', 1)
                    level = name.lower()
                    pl = ext.lower()
                    if level in levels:
                        level_counts[level] += 1
                        pl_counts[pl] += 1
                        level_pls[level][pl] += 1

    total_problems = sum(level_counts.values())
    total_pls = sum(pl_counts.values())

    print("### Problem counts by level:\n")
    print(f"  - Total: {total_problems}")
    for level in levels:
        print(f"  - {level.capitalize()}: {level_counts[level]}")

    print("\n### Programming languages used (by percentage):\n")
    for pl, count in pl_counts.items():
        percent = (count / total_pls) * 100 if total_pls else 0
        print(f"  - {pl}: {percent:.2f}%")

    print("\n### Programming languages used per level:\n")
    for level in levels:
        print(f"  - {level.capitalize()}:")
        for pl, count in level_pls[level].items():
            print(f"    - {pl}: {count}")

if __name__ == "__main__":
    get_stats(os.path.dirname(os.path.abspath(__file__)))
