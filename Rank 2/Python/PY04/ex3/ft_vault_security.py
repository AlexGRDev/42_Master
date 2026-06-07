# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_vault_security.py                              :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/06/05 21:54:24 by agarcia2         #+#    #+#              #
#    Updated: 2026/06/05 22:07:02 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

def secure_archive() -> bool:
    try:
        print("Using 'secure_archive' to read from an inaccessible file:")
        with (open("secure_archive", 'rb') as f):
            f.read()
            return (False)
    except Exception as e:
        print()
    return (False)


def main() -> int:
    print("=== Cyber Archives Security ===")
    secure_archive()
    return (0)


if (__name__ == "__main__"):
    main()
