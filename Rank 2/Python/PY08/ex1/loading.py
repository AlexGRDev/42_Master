# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    loading.py                                        :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 21:02:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 21:03:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

import importlib.metadata
import importlib.util
import sys
from typing import Optional

REQUIRED_PACKAGES = {
    "pandas": "Data manipulation ready",
    "numpy": "Numerical computation ready",
    "requests": "Network access ready",
    "matplotlib": "Visualization ready",
}

DATA_POINTS = 1000
OUTPUT_FILE = "matrix_analysis.png"


def package_version(name: str) -> Optional[str]:
    try:
        return importlib.metadata.version(name)
    except importlib.metadata.PackageNotFoundError:
        return None


def check_dependencies() -> dict[str, bool]:
    print("Checking dependencies:")
    status: dict[str, bool] = {}
    for name, purpose in REQUIRED_PACKAGES.items():
        found = importlib.util.find_spec(name) is not None
        status[name] = found
        if found:
            version = package_version(name) or "unknown"
            print(f"[OK] {name} ({version}) - {purpose}")
        else:
            print(f"[MISSING] {name} - {purpose}")
    print()
    return status


def print_install_instructions(missing: list[str]) -> None:
    if not missing:
        return
    joined = " ".join(missing)
    print("Some dependencies are missing. Install them with:\n")
    print(f"pip install {joined}")
    print(f"poetry add {joined}")
    print()


def print_version_comparison() -> None:
    print("Installed package versions:")
    for name in REQUIRED_PACKAGES:
        version = package_version(name)
        display = version if version is not None else "not installed"
        print(f"  {name}: {display}")
    print()


def run_analysis() -> bool:
    try:
        import numpy as np
        import pandas as pd
        import matplotlib
        matplotlib.use("Agg")
        import matplotlib.pyplot as plt
    except ImportError as exc:
        print(f"Cannot run analysis, missing dependency: {exc}")
        return False

    print("Analyzing Matrix data...")
    print(f"Processing {DATA_POINTS} data points...")

    rng = np.random.default_rng(seed=42)
    matrix_stream = rng.normal(loc=0.0, scale=1.0, size=DATA_POINTS)
    data = pd.DataFrame({"signal": matrix_stream})

    print("Generating visualization...")
    figure, axis = plt.subplots()
    axis.hist(data["signal"], bins=30, color="green")
    axis.set_title("Matrix Data Stream")
    axis.set_xlabel("Signal value")
    axis.set_ylabel("Frequency")
    figure.savefig(OUTPUT_FILE)
    plt.close(figure)

    print("\nAnalysis complete!")
    print(f"Results saved to: {OUTPUT_FILE}")
    return True


def main() -> None:
    print("LOADING STATUS: Loading programs...\n")

    status = check_dependencies()
    missing = [name for name, found in status.items() if not found]
    print_install_instructions(missing)

    if not run_analysis():
        print_version_comparison()
        sys.exit(1)


if __name__ == "__main__":
    main()
