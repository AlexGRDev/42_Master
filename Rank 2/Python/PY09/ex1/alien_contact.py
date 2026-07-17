# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    alien_contact.py                                  :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 16:48:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 16:48:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from datetime import datetime
from enum import Enum
from typing import Optional

from pydantic import BaseModel, Field, ValidationError, model_validator


class ContactType(str, Enum):
    radio = "radio"
    visual = "visual"
    physical = "physical"
    telepathic = "telepathic"


class AlienContact(BaseModel):
    contact_id: str = Field(..., min_length=5, max_length=15)
    timestamp: datetime = Field(..., strict=True)
    location: str = Field(..., min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(..., ge=0.0, le=10.0)
    duration_minutes: int = Field(..., ge=1, le=1440)
    witness_count: int = Field(..., ge=1, le=100)
    message_received: Optional[str] = Field(default=None, max_length=500)
    is_verified: bool = False

    @model_validator(mode="after")
    def check_business_rules(self) -> "AlienContact":
        if not self.contact_id.startswith("AC"):
            raise ValueError("contact_id must start with 'AC'")
        physical_unverified = (
            self.contact_type == ContactType.physical
            and not self.is_verified
        )
        if physical_unverified:
            raise ValueError("Physical contact must be verified")
        telepathic_few_witnesses = (
            self.contact_type == ContactType.telepathic
            and self.witness_count < 3
        )
        if telepathic_few_witnesses:
            raise ValueError(
                "Telepathic contact requires at least 3 witnesses"
            )
        if self.signal_strength > 7.0 and self.message_received is None:
            raise ValueError(
                "Strong signals must include a message_received"
            )
        return self


def display_contact(contact: AlienContact) -> None:
    print("Valid contact report:")
    print(f"ID: {contact.contact_id}")
    print(f"Type: {contact.contact_type.value}")
    print(f"Location: {contact.location}")
    print(f"Signal: {contact.signal_strength}/10")
    print(f"Duration: {contact.duration_minutes} minutes")
    print(f"Witnesses: {contact.witness_count}")
    print(f"Message: '{contact.message_received}'")


def main() -> None:
    print("Alien Contact Log Validation")
    print("=" * 39)

    contact = AlienContact(
        contact_id="AC_2024_001",
        timestamp=datetime(2026, 5, 1, 22, 30, 0),
        location="Area 51, Nevada",
        contact_type=ContactType.radio,
        signal_strength=8.5,
        duration_minutes=45,
        witness_count=5,
        message_received="Greetings from Zeta Reticuli",
    )
    display_contact(contact)

    print()
    print("=" * 39)
    print("Expected validation error:")
    try:
        AlienContact(
            contact_id="AC_2024_002",
            timestamp=datetime(2026, 5, 2, 3, 15, 0),
            location="Roswell, New Mexico",
            contact_type=ContactType.telepathic,
            signal_strength=6.0,
            duration_minutes=10,
            witness_count=1,
        )
    except ValidationError as error:
        print(error.errors()[0]["msg"])


if __name__ == "__main__":
    main()
