# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    dark_spellbook.py                                 :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/06/15 19:08:16 by agarcia2         #+#    #+#              #
#    Updated: 2026/06/17 21:46:11 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


from alchemy.grimoire.dark_validator import validate_ingredients


def dark_spell_allowed_ingredients() -> list[str]:
    return ["bats", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str) -> str:
    validation = validate_ingredients(ingredients)
    if "INVALID" not in validation:
        return f"Spell recorded: {spell_name} ({ingredients} - VALID)"
    return f"Spell rejected: {spell_name} ({ingredients} - INVALID)"
