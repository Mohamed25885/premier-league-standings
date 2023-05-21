#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>
#include "team.hpp"

Match::Match(Team *homeT, Team *awayT, int homeGoals, int awayGoals, int week)
{
    this->homeTeam = homeT;
    this->awayTeam = awayT;
    this->homeGoals = homeGoals;
    this->awayGoals = awayGoals;
    this->week = week;
    if (homeGoals > awayGoals)
        this->points = 3;
    else if (homeGoals == awayGoals)
        this->points = 1;
}

std::vector<Team *> Match::teams(){
    std::vector<Team *> teams = {this->awayTeam, this->homeTeam};
    return teams;
}