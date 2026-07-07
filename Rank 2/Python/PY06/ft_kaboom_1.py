# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_kaboom_1.py                                    :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 20:23:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 20:24:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

print("=== Kaboom 1 ===")
print("Access to alchemy/grimoire/dark_spellbook.py directly")
print("Test import now - THIS WILL RAISE AN UNCAUGHT EXCEPTION")

from alchemy.grimoire.dark_spellbook import dark_spell_record  # noqa: E402

result = dark_spell_record("Curse", "bats and frogs")
print(f"Testing record dark spell: {result}")
