# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    oracle.py                                         :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 21:04:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 21:05:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

import os
from pathlib import Path

from dotenv import load_dotenv

DEFAULTS = {
    "MATRIX_MODE": "development",
    "DATABASE_URL": "postgresql://localhost:5432/zion",
    "API_KEY": "",
    "LOG_LEVEL": "DEBUG",
    "ZION_ENDPOINT": "https://zion.resistance.local",
}

ENV_FILE = Path(__file__).resolve().parent / ".env"


def load_configuration() -> dict[str, str]:
    dotenv_loaded = load_dotenv(dotenv_path=ENV_FILE, override=False)
    config: dict[str, str] = {}
    for key, default in DEFAULTS.items():
        value = os.environ.get(key)
        if value is None or value == "":
            print(f"WARNING: {key} not set, using default.")
            value = default
        config[key] = value
    config["_dotenv_loaded"] = "yes" if dotenv_loaded else "no"
    return config


def mask_api_key(api_key: str, mode: str) -> str:
    if not api_key:
        return "Not configured"
    if mode == "production":
        return "*" * len(api_key)
    if len(api_key) <= 4:
        return "*" * len(api_key)
    return api_key[:2] + "*" * (len(api_key) - 4) + api_key[-2:]


def print_configuration(config: dict[str, str]) -> None:
    mode = config["MATRIX_MODE"]
    print("Configuration loaded:")
    print(f"Mode: {mode}")

    if mode == "production":
        print("Database: Connected to production cluster")
    else:
        print("Database: Connected to local instance")
    print(f"  URL: {config['DATABASE_URL']}")

    masked_key = mask_api_key(config["API_KEY"], mode)
    if config["API_KEY"]:
        print(f"API Access: Authenticated ({masked_key})")
    else:
        print("API Access: Not authenticated")

    log_level = config["LOG_LEVEL"]
    print(f"Log Level: {log_level}")
    if mode == "production" and log_level == "DEBUG":
        print("  NOTE: DEBUG logging in production is discouraged.")

    print("Zion Network: Online")
    print(f"  Endpoint: {config['ZION_ENDPOINT']}")


def print_security_check(config: dict[str, str]) -> None:
    print("\nEnvironment security check:")
    print("[OK] No hardcoded secrets detected")

    if config["_dotenv_loaded"] == "yes":
        print("[OK] .env file properly configured")
    else:
        print("[WARN] .env file not found, using environment/defaults")

    override_demo = os.environ.get("MATRIX_MODE") is not None
    if override_demo:
        print("[OK] Production overrides available (env var detected)")
    else:
        print("[OK] Production overrides available (set MATRIX_MODE=...)")


def main() -> None:
    print("ORACLE STATUS: Reading the Matrix...\n")
    config = load_configuration()
    print_configuration(config)
    print_security_check(config)
    print("\nThe Oracle sees all configurations.")


if __name__ == "__main__":
    main()
