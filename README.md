MCabber Slack Autocompletion
============================

Default MCabber setup can't complete names starting with `@`. That module adds
to completion list all users with leading `@` so they can be autocompleted and
two special names: `@channel` and `@everyone`.

## Installation

Package available in the AUR:
https://aur4.archlinux.org/packages/mcabber-modules-slack-completion.

**Warning!** Until [Mcabber Issue
135](https://bitbucket.org/McKael/mcabber-crew/issue/135/make-register_builtin_cat-exported)
is not resolved,
[special build of
MCabber](https://aur4.archlinux.org/packages/mcabber-crew-hg-extended) is
required.


## Usage

Just add following lines to your MCabber config:

```
module load slack_completion
```
