# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_vault_security.py                              :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/06/05 21:54:24 by agarcia2         #+#    #+#              #
#    Updated: 2026/06/07 17:33:15 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

def secure_archive(file_name: str,
                   mode: int = 0, content: str = "") -> tuple[bool, str]:
    f: object

    try:
        if (mode == 0):
            with (open(file_name, 'r') as f):
                return (True, f.read())
        else:
            with (open(file_name, 'w') as f):
                f.write(content)
                return (True, "Content successfully written to file")
    except Exception as e:
        return (False, str(e))


def main() -> int:
    result: tuple[bool, str]

    print("=== Cyber Archives Security ===")
    print("Using 'secure_archive' to read from a nonexistent file:")
    print(secure_archive("/not/existing/file"))
    print()
    print("Using 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("/etc/master.passwd"))
    print()
    print("Using 'secure_archive' to read from a regular file:")
    result = secure_archive("secure_archive")
    print(result)
    print()
    print("Using 'secure_archive' to write previous content to a new file:")
    print(secure_archive("new_file.txt", 1, result[1]))
    return (0)


if (__name__ == "__main__"):
    main()
