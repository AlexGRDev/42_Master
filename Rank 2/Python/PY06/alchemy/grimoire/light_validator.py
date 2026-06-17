# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    light_validator.py                                :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/06/15 19:07:33 by agarcia2         #+#    #+#              #
#    Updated: 2026/06/15 19:08:07 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


from alchemy.grimoire.light_spellbook import light_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    allowed = light_spell_allowed_ingredients()
    ingredients_lower = ingredients.lower()
    for ingredient in allowed:
        if ingredient in ingredients_lower:
            return f"{ingredients} - VALID"
    return f"{ingredients} - INVALID"
