#!/usr/bin/env bash
# One-time: turn this folder into a git repo and push it to a new private GitHub repo.
set -e
cd "$(dirname "$0")"
REPO_NAME="${1:-exam-rank-05}"
[ -d .git ] || git init -q -b main
git add -A
git commit -q -m "Set up exam rank 05 study repo" || true
if command -v gh >/dev/null && gh auth status >/dev/null 2>&1; then
  gh repo create "$REPO_NAME" --private --source . --remote origin --push
  echo "Done: $(gh repo view --json url -q .url)"
else
  echo "GitHub CLI not installed or not logged in."
  echo "  Option A: sudo apt install gh && gh auth login   then rerun this script"
  echo "  Option B: create an empty repo named $REPO_NAME on github.com, then:"
  echo "    git remote add origin git@github.com:<your-user>/$REPO_NAME.git && git push -u origin main"
fi
