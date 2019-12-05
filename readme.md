# ZSA's fork of QMK Firmware 

This is my personal fork to keep my own settings in sync with ZSA maintained version of QMK.

## Supported Keyboards

* [Planck](/keyboards/planck/ez)
* [ErgoDox EZ](/keyboards/ergodox_ez/)

# Update Process

1. Check out branch from ZSA's master branch:
    1. `git remote add zsa https://github.com/ErgoDox-EZ/qmk_firmware.git`
    2. `git fetch --all`
    3. `git checkout -B branchname zsa/master`
    4. `git push -u zsa branchname`
2. Check for core changes:
    - [https://github.com/qmk/qmk_firmware/commits/master/quantum](https://github.com/qmk/qmk_firmware/commits/master/quantum)
    - [https://github.com/qmk/qmk_firmware/commits/master/tmk_core](https://github.com/qmk/qmk_firmware/commits/master/tmk_core)
    - [https://github.com/qmk/qmk_firmware/commits/master/util](https://github.com/qmk/qmk_firmware/commits/master/util)
    - [https://github.com/qmk/qmk_firmware/commits/master/drivers](https://github.com/qmk/qmk_firmware/commits/master/drivers)
    - [https://github.com/qmk/qmk_firmware/commits/master/lib](https://github.com/qmk/qmk_firmware/commits/master/lib)
    - These folders are the important ones for maintaining the repo and keeping it properly up to date. Most, but not all, changes on this list should be pulled into our repo.
3. `git cherry-pick` the commits we want
    - `git rm docs/* -r` to remove the document updates when cherry picking. Repeat for any keyboard/keymap/etc that have changes that we aren't interested in
4. Commit update
   * Include commit info in `[changelog.md](http://changelog.md)` 
5. Open Pull request, and include information about the commit

## Strategy

To keep PRs small and easier to test, they should ideally be 1:1 with commits from QMK Firmware master. They should only group commits if/when it makes sense. Such as multiple commits for a specific feature (split RGB support, for instance)

## Merging

Pull Requests should be merged/rebased, not squashed, so we can maintain a commit history that is close to QMK Firmware's, for ease of reference.
