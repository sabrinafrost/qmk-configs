# QMK Configs

This repository hosts my QMK userspace configs for my own personal keyboards. Feel free to use it for inspiration. I've added some quality of life features for working with per-key per-layer RGB.

## Setting Up

Please not that these commands are specific to this repository and my local environment.

1. Run the normal `qmk setup` procedure if you haven't already done so (see [QMK Docs](https://docs.qmk.fm/#/newbs)).
1. Clone this repository to your local machine.
1. `cd` into this repository's clone directory.
1. Set global userspace path: `qmk config user.overlay_dir="$(realpath .)"`.
    * You **must** be located in the cloned userspace location for this to work correctly.
1. Add the keyboard to the QMK userspace using `qmk new-keymap -kb keebio/iris_ce -km frost`.
1. Add your keymap(s) to the build by running `qmk userspace-add -kb keebio/iris_ce -km frost`.

## Building

> If you have Actions enabled on your repository then GitHub will build the firmware for you when you push commits.

1. Follow the steps in [Setting Up](#setting-up).
1. Compile normally: `qmk compile -kb keebio/iris_ce -km frost`.
    * Alternatively, if you configured your build targets above, you can use `qmk userspace-compile` to build all of your userspace targets at once.
