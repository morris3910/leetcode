#!/usr/bin/env python3
"""Regenerate README.md by scanning Week*/ solution files and fetching
problem metadata (title, difficulty) from the LeetCode GraphQL API."""

import os
import re
import time
from pathlib import Path

import requests

REPO = os.environ.get("GITHUB_REPOSITORY", "morris3910/leetcode")
LEETCODE_GRAPHQL = "https://leetcode.com/graphql"
QUERY = """
query ($titleSlug: String!) {
    question(titleSlug: $titleSlug) {
        title
        difficulty
    }
}
"""
HEADERS = {
    "Content-Type": "application/json",
    "User-Agent": "Mozilla/5.0 (compatible; readme-bot/1.0)",
    "Referer": "https://leetcode.com",
}


def fetch_problem(slug: str, retries: int = 3) -> tuple[str, str]:
    for attempt in range(retries):
        try:
            resp = requests.post(
                LEETCODE_GRAPHQL,
                json={"query": QUERY, "variables": {"titleSlug": slug}},
                headers=HEADERS,
                timeout=15,
            )
            resp.raise_for_status()
            q = resp.json()["data"]["question"]
            return q["title"], q["difficulty"]
        except Exception:
            if attempt < retries - 1:
                time.sleep(2**attempt)

    # Fallback: derive title from slug when API is unreachable
    title = slug.replace("-", " ").title()
    return title, "Unknown"


def main() -> None:
    root = Path(__file__).resolve().parent.parent.parent

    week_dirs = sorted(
        root.glob("Week*/"),
        key=lambda p: int(re.search(r"\d+", p.name).group()),
    )

    sections: list[str] = []

    for week_dir in week_dirs:
        week_num = int(re.search(r"\d+", week_dir.name).group())
        cpp_files = sorted(week_dir.glob("*.cpp"))
        if not cpp_files:
            continue

        rows: list[str] = []
        for cpp_file in cpp_files:
            m = re.match(r"^(\d+)_(.+)$", cpp_file.stem)
            if not m:
                continue

            num = int(m.group(1))
            slug = m.group(2).lower()

            print(f"  Fetching #{num} ({slug})…")
            title, difficulty = fetch_problem(slug)
            time.sleep(0.4)  # stay polite toward LeetCode

            lc_url = f"https://leetcode.com/problems/{slug}/"
            gh_url = (
                f"https://github.com/{REPO}/blob/main/"
                f"{cpp_file.relative_to(root)}"
            )
            rows.append(f"| {num} | [{title}]({lc_url}) | [C++]({gh_url}) | {difficulty} |")

        if rows:
            table_header = "| # | Title | Solution | Difficulty |\n|---|---|---|---|"
            sections.append(f"## Week {week_num}\n{table_header}\n" + "\n".join(rows))

    content = "# Leetcode\n\n" + "\n\n".join(sections) + "\n"
    readme = root / "README.md"
    readme.write_text(content, encoding="utf-8")
    print("README.md updated.")


if __name__ == "__main__":
    main()
