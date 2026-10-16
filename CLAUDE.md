# CLAUDE.md

Instructions for Claude Code when working in this repository.

## Project overview

test-water-motor — <describe what this project does>

## Tech stack

- <language / framework>

## Commands

- Install: `<command>`
- Run: `<command>`
- Test: `<command>`
- Lint: `<command>`

## Project structure

- `<dir>/` — <purpose>

## Conventions

- **Split sketches into multiple `.ino` files.** Don't put all the code in a single `.ino` file. Use one `.ino` file per module or feature (e.g. `pump.ino`, `sensors.ino`, `display.ino`) inside the sketch folder.
  - The main file must have the same name as the sketch folder (e.g. `water_motor/water_motor.ino`). Keep it small: shared constants, pin definitions, global state, `setup()` and `loop()`, which call into the module files.
  - The Arduino IDE combines the files with the main `.ino` first, then the others in alphabetical order. Declare anything shared between files (globals, constants) in the main `.ino` so it's defined before the other files use it.
  - Each module file holds only the functions for its feature, e.g. `pumpSetup()`, `pumpUpdate()` in `pump.ino`.

## Rules for Claude

1. Do not reference Claude anywhere: no mentions of Claude, Claude Code, or Anthropic in commit messages, commit trailers (e.g. no `Co-Authored-By: Claude`), PR titles or descriptions, code, comments, or docs. Commits should read as authored solely by the repo owner.
2. All commits from this machine must be made under the `shauryarchs` GitHub account: author and committer must be `Shaurya Varshnay <shauryarchs@gmail.com>`. Before committing, verify with `git config user.email`; never commit with any other identity (e.g. a work email). Pushes must be authenticated as `shauryarchs` (check with `gh auth status`).
3. Before starting any new piece of work, first log a GitHub issue for it in this repo (`gh issue create`). Then create a branch from the latest `main` named `shaurya/<issue-number>-<issue-title>`, where `<issue-title>` is the issue title in lowercase with spaces and special characters replaced by hyphens (e.g. issue #12 "Add pump timer" → `shaurya/12-add-pump-timer`). Do all work for that issue on its branch, not on `main`.
4. When the work on a branch is done, push the branch and open a pull request into `main` (`gh pr create --base main`). The PR description must link the issue with `Closes #<issue-number>` so merging it closes the issue. Do not merge the PR yourself; leave it for the repo owner to review and merge.
5. When a PR is merged, ask the repo owner whether to clean up the branch. If they agree: switch to `main`, pull the latest changes, delete the merged local branch (`git branch -d`), delete the remote branch if it still exists (`git push origin --delete <branch>`), and prune stale remote refs (`git fetch --prune`).
