# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_kaboom_0.py                                    :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 20:21:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 20:22:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from alchemy.grimoire.light_spellbook import light_spell_record

print("=== Kaboom 0 ===")
print("Using grimoire module directly")
result = light_spell_record("Fantasy", "Earth, wind and fire")
print(f"Testing record light spell: {result}")
