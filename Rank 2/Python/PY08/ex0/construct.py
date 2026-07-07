# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    construct.py                                      :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 21:00:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 21:01:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

import os
import site
import sys


def is_in_venv() -> bool:
    if hasattr(sys, "real_prefix"):
        return True
    return sys.prefix != getattr(sys, "base_prefix", sys.prefix)


def venv_name() -> str:
    venv_path = os.environ.get("VIRTUAL_ENV")
    if venv_path:
        return os.path.basename(venv_path.rstrip("/"))
    return os.path.basename(sys.prefix.rstrip("/"))


def site_packages_path() -> str:
    try:
        paths = site.getsitepackages()
        if paths:
            return paths[0]
    except (AttributeError, OSError):
        pass
    return os.path.join(sys.prefix, "lib", "site-packages")


def print_outside_venv() -> None:
    print("MATRIX STATUS: You're still plugged in\n")
    print(f"Current Python: {sys.executable}")
    print("Virtual Environment: None detected\n")
    print("WARNING: You're in the global environment!")
    print("The machines can see everything you install.\n")
    print("To enter the construct, run:")
    print("python -m venv matrix_env")
    print("source matrix_env/bin/activate # On Unix")
    print("matrix_env\\Scripts\\activate  # On Windows\n")
    print("Then run this program again.")


def print_inside_venv() -> None:
    venv_path = os.environ.get("VIRTUAL_ENV", sys.prefix)
    print("MATRIX STATUS: Welcome to the construct\n")
    print(f"Current Python: {sys.executable}")
    print(f"Virtual Environment: {venv_name()}")
    print(f"Environment Path: {venv_path}\n")
    print("SUCCESS: You're in an isolated environment!")
    print("Safe to install packages without affecting")
    print("the global system.\n")
    print("Package installation path:")
    print(site_packages_path())


def main() -> None:
    if is_in_venv():
        print_inside_venv()
    else:
        print_outside_venv()


if __name__ == "__main__":
    main()
