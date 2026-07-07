# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    space_crew.py                                     :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 16:49:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 16:49:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from datetime import datetime
from enum import Enum

from pydantic import BaseModel, Field, ValidationError, model_validator


class Rank(str, Enum):
    cadet = "cadet"
    officer = "officer"
    lieutenant = "lieutenant"
    captain = "captain"
    commander = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=2, max_length=50)
    rank: Rank
    age: int = Field(..., ge=18, le=80)
    specialization: str = Field(..., min_length=3, max_length=30)
    years_experience: int = Field(..., ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    mission_id: str = Field(..., min_length=5, max_length=15)
    mission_name: str = Field(..., min_length=3, max_length=100)
    destination: str = Field(..., min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(..., ge=1, le=3650)
    crew: list[CrewMember] = Field(..., min_length=1, max_length=12)
    mission_status: str = "planned"
    budget_millions: float = Field(..., ge=1.0, le=10000.0)

    @model_validator(mode="after")
    def check_business_rules(self) -> "SpaceMission":
        if not self.mission_id.startswith("M"):
            raise ValueError("mission_id must start with 'M'")
        senior_ranks = {Rank.commander, Rank.captain}
        if not any(member.rank in senior_ranks for member in self.crew):
            raise ValueError(
                "Mission must have at least one Commander or Captain"
            )
        if self.duration_days > 365:
            experienced = sum(
                1 for member in self.crew if member.years_experience >= 5
            )
            if experienced < len(self.crew) / 2:
                raise ValueError(
                    "Long missions need at least 50% experienced crew "
                    "(5+ years)"
                )
        if not all(member.is_active for member in self.crew):
            raise ValueError("All crew members must be active")
        return self


def display_mission(mission: SpaceMission) -> None:
    print("Valid mission created:")
    print(f"Mission: {mission.mission_name}")
    print(f"ID: {mission.mission_id}")
    print(f"Destination: {mission.destination}")
    print(f"Duration: {mission.duration_days} days")
    print(f"Budget: ${mission.budget_millions}M")
    print(f"Crew size: {len(mission.crew)}")
    print("Crew members:")
    for member in mission.crew:
        print(f"- {member.name} ({member.rank.value}) - "
              f"{member.specialization}")


def main() -> None:
    print("Space Mission Crew Validation")
    print("=" * 39)

    crew = [
        CrewMember(
            member_id="CM001",
            name="Sarah Connor",
            rank=Rank.commander,
            age=42,
            specialization="Mission Command",
            years_experience=15,
        ),
        CrewMember(
            member_id="CM002",
            name="John Smith",
            rank=Rank.lieutenant,
            age=35,
            specialization="Navigation",
            years_experience=8,
        ),
        CrewMember(
            member_id="CM003",
            name="Alice Johnson",
            rank=Rank.officer,
            age=29,
            specialization="Engineering",
            years_experience=6,
        ),
    ]
    mission = SpaceMission(
        mission_id="M2024_MARS",
        mission_name="Mars Colony Establishment",
        destination="Mars",
        launch_date=datetime(2026, 9, 15, 6, 0, 0),
        duration_days=900,
        crew=crew,
        budget_millions=2500.0,
    )
    display_mission(mission)

    print()
    print("=" * 39)
    print("Expected validation error:")
    try:
        SpaceMission(
            mission_id="M2024_MOON",
            mission_name="Lunar Survey",
            destination="Moon",
            launch_date=datetime(2026, 8, 1, 6, 0, 0),
            duration_days=30,
            crew=[
                CrewMember(
                    member_id="CM010",
                    name="Bob Rookie",
                    rank=Rank.cadet,
                    age=22,
                    specialization="Logistics",
                    years_experience=1,
                ),
            ],
            budget_millions=50.0,
        )
    except ValidationError as error:
        print(error.errors()[0]["msg"])


if __name__ == "__main__":
    main()
