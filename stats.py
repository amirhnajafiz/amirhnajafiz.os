import os
from collections import Counter, defaultdict

plmap = {
    'c': 'C',
    'cpp': 'C++',
    'py': 'Python',
    'sql': 'SQL',
    'rs': 'Rust',
}

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

    # Prepare stats as markdown
    stats_md = []
    stats_md.append("### Problem counts by level:\n")
    stats_md.append(f"- Total: {total_problems}")
    for level in levels:
        stats_md.append(f"- {level.capitalize()}: {level_counts[level]}")

    stats_md.append("\n### Programming languages used (by percentage):\n")
    for pl, count in pl_counts.items():
        percent = (count / total_pls) * 100 if total_pls else 0
        stats_md.append(f"- {plmap[pl]}: {percent:.2f}%")

    stats_md.append("\n### Programming languages used per level:\n")
    for level in levels:
        stats_md.append(f"- {level.capitalize()}:")
        for pl, count in level_pls[level].items():
            stats_md.append(f"  - {plmap[pl]}: {count}")

    stats_content = "\n".join(stats_md)

    # Read README.md, append stats, and write back
    readme_path = os.path.join(base_path, "README.md")
    with open(readme_path, "r", encoding="utf-8") as f:
        readme = f.read().rstrip()

    new_readme = f"{readme}\n\n---\n\n{stats_content}\n"

    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(new_readme)

    # Also print to console as before
    print(stats_content)

if __name__ == "__main__":
    get_stats(os.path.dirname(os.path.abspath(__file__)))
