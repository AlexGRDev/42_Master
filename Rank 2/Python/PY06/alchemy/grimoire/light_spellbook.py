# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    light_spellbook.py                                :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/06/15 19:06:20 by agarcia2         #+#    #+#              #
#    Updated: 2026/06/15 19:07:07 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


from alchemy.grimoire.light_validator import validate_ingredients


def light_spell_allowed_ingredients() -> list[str]:
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    validation = validate_ingredients(ingredients)
    if "INVALID" not in validation:
        return f"Spell recorded: {spell_name} ({ingredients} - VALID)"
    return f"Spell rejected: {spell_name} ({ingredients} - INVALID)"
