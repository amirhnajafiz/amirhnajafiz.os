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
    for pl, count in sorted(pl_counts.items(), key=lambda x: x[1], reverse=True):
        percent = (count / total_pls) * 100 if total_pls else 0
        stats_md.append(f"- {plmap[pl]}: {percent:.2f}%")

    stats_md.append("\n### Programming languages used per level:\n")
    for level in levels:
        stats_md.append(f"- {level.capitalize()}:")
        for pl, count in sorted(level_pls[level].items(), key=lambda x: x[1], reverse=True):
            stats_md.append(f"  - {plmap[pl]}: {count}")

    stats_content = "\n".join(stats_md)

    # New README header
    readme_header = (
        "# LeetCodz\n\n"
        "A collection of my LeetCode solutions. This repository is organized by problem difficulty and tracks the number of problems solved at each level. Each solution is written with clarity and efficiency in mind, aiming to help others understand different approaches to common algorithmic challenges.\n\n"
        "## Stats\n\n"
    )

    readme_path = os.path.join(base_path, "README.md")
    # Overwrite README.md with new content
    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(f"{readme_header}{stats_content}\n")

    print(stats_content)

if __name__ == "__main__":
    get_stats(os.path.dirname(os.path.abspath(__file__)))
